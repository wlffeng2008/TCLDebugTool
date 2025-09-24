#include "DialogAgingTest.h"
#include "ui_DialogAgingTest.h"

#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QProcess>

DialogAgingTest::DialogAgingTest(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAgingTest)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    //flags |= Qt::WindowMinimizeButtonHint ;
    flags &= ~Qt::WindowContextHelpButtonHint ;
    setWindowFlags(flags);

    m_pModel = new QStandardItemModel(this);
    m_pModel->setHorizontalHeaderLabels({"方案名称","读取间隔(ms)","起始地址(Hex)","读取个数","开始时间","持续时长(S)","测试次数","状态","操作"}) ;
    ui->tableView->setModel(m_pModel) ;

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Fixed);
    header->setSectionResizeMode(0,QHeaderView::Stretch);

    header->resizeSection(1,100) ;
    header->resizeSection(2,100) ;
    header->resizeSection(3,80) ;
    header->resizeSection(4,140) ;
    header->resizeSection(5,100) ;
    header->resizeSection(6,70) ;
    header->resizeSection(7,80) ;
    header->resizeSection(8,80) ;

    connect(ui->tableView,&QTableView::clicked,this,[=](const QModelIndex &index){
        int row = index.row() ;
        int col = index.column() ;
        m_selectItem = row ;

        if(col == 8)
        {
            if(m_testItem != -1)
            {
                if(m_testItem == row)
                {
                    if(QMessageBox::question(this,"提示","确定要停止测试吗？") == QMessageBox::Yes)
                    {
                        m_TMTest.stop() ;
                        m_pModel->item(m_testItem,8)->setData(0);
                        m_testItem = -1 ;
                    }
                }
                else
                {
                    QMessageBox::information(this,"提示","请停止其他正在进行测试的方案!");
                }
                return ;
            }
            else
            {
                if(!m_pCOMDlg->isConnected())
                {
                    return ;
                }
            }

            m_testItem = row ;
            m_pModel->item(row,8)->setData(1);
            m_pModel->item(row,6)->setText("0") ;
            m_pModel->item(row,4)->setData(time(nullptr));
            m_pModel->item(row,4)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) ;
            m_TMTest.start(10) ;
        }
    }) ;

    connect(m_pModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) {
        int nRow = item->row() ;
        int nCol = item->column() ;
        if(nCol == 8)
        {
            m_strBak.clear() ;
            int status = m_pModel->item(nRow,8)->data().toInt() ;
            m_pModel->item(nRow,8)->setText(status==1?"停止测试":"开始测试");
            m_pModel->item(nRow,7)->setText(status==1?"正在测试":"已经停止");
            m_pModel->item(nRow,7)->setForeground(QBrush(status==1?Qt::green:Qt::red));
        }

        if(nCol == 1)
        {
            quint32 inter = item->text().toUInt(nullptr,16) ;
            quint32 old = inter ;
            if(inter<100)
                inter = 100 ;
            if(old != inter)
                item->setText(QString::asprintf("%d",inter));
        }

        if(nCol == 2)
        {
            quint32 addr = item->text().toUInt(nullptr,16) ;
            item->setText(QString::asprintf("%04X",addr));
        }

        if(nCol == 3)
        {
            quint32 count = item->text().toUInt() ;
            quint32 old = count ;
            if(count<1)
                count=1;
            if(count>1000)
                count=1000;

            if(old != count)
                item->setText(QString::asprintf("%d",count));
        }
    });

    connect(&m_TMTest,&QTimer::timeout,this,[=]{
        m_TMTest.stop() ;
        int row = m_testItem ;
        if(row != -1)
        {
            QString strFile = QString("%1/AgingTest/%2--[%3].txt").arg(m_pCOMDlg->dataPath(),
                                        QDateTime::currentDateTime().toString("yyyy-MM-dd"),
                                        m_pModel->item(m_testItem,0)->text().trimmed());

            ui->labelFile->setText(strFile) ;

            quint32 count = m_pModel->item(row,6)->text().trimmed().toInt() + 1;
            int start = m_pModel->item(row,4)->data().toInt() ;
            quint32 dura = time(nullptr) - start;
            m_pModel->item(row,5)->setText(QString::number(dura)) ;
            m_pModel->item(row,6)->setText(QString::number(count)) ;

            quint32 addr = m_pModel->item(row,2)->text().trimmed().toInt(nullptr,16) ;
            quint32 len  = m_pModel->item(row,3)->text().trimmed().toInt() ;
            m_pCOMDlg->readRegData(addr,len,this) ;

            quint32 inter = m_pModel->item(row,1)->text().trimmed().toInt() ;
            m_TMTest.start(inter) ;
        }
    });

    connect(ui->pushButtonAdd,&QPushButton::clicked,this,[=]{
        addNew(QString("老化测试%1, 1000, 0000, 50, 0000-00-00 00:00:00, 0, 0").arg(m_pModel->rowCount()+1) );
    });

    connect(ui->pushButtonDelete,&QPushButton::clicked,this,[=]{
        if(m_selectItem != -1)
        {
            if(QMessageBox::question(this,"提示","确定要删除吗？") == QMessageBox::Yes)
            {
                m_pModel->removeRow(m_selectItem);
                m_selectItem = -1 ;
            }
        }
    });

    connect(ui->pushButtonGoto,&QPushButton::clicked,this,[=]{
        QString strFile = ui->labelFile->text() ;
        if(!strFile.isEmpty())
            QProcess::startDetached("notepad.exe", QStringList() << strFile);
    });

    connect(ui->pushButtonSave,&QPushButton::clicked,this,[=]{
        QFile file(m_pCOMDlg->dataPath() + "AgingTest.txt" );
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return ;

        QTextStream out(&file);

        int nCount = m_pModel->rowCount();
        for(int i=0; i<nCount; i++)
        {
            QString strLine = QString("%1,%2,%3,%4,%5,%6,%7\n")
                .arg(m_pModel->item(i,0)->text().trimmed(),
                     m_pModel->item(i,1)->text().trimmed(),
                     m_pModel->item(i,2)->text().trimmed(),
                     m_pModel->item(i,3)->text().trimmed(),
                     m_pModel->item(i,4)->text().trimmed(),
                     m_pModel->item(i,5)->text().trimmed(),
                     m_pModel->item(i,6)->text().trimmed()) ;
            out << strLine ;
        }
        QMessageBox::information(this,"提示","老化测试配置已保存！") ;
    });

    {
        m_pRegModel = new QStandardItemModel(this) ;
        m_pRegModel->setHorizontalHeaderLabels({"ADDR","VALUE"}) ;
        ui->tableViewReg->setModel(m_pRegModel);
        QHeaderView *header = ui->tableViewReg->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
    }

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;
        quint8 *pData   = m_pCOMDlg->GetDataBody() ;
        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return;
        }

        QString strData ;
        if(pHD->type == TYPE_REG_READ)
        {
            char szLine[20] = {0};
            quint8 *pSub = pData ;

            m_pRegModel->setRowCount(0) ;

            for(int j=0; j<pHD->len; j++)
            {
                sprintf(szLine,"%04X",pHD->addr + j);
                QStandardItem *item0 = new QStandardItem(szLine) ;

                sprintf(szLine,"%02X(%3d)",pSub[j],pSub[j]);
                QStandardItem *item1 = new QStandardItem(szLine) ;

                item0->setEditable(false) ;
                item1->setEditable(false) ;

                m_pRegModel->appendRow({item0,item1}) ;

                sprintf(szLine,"%04X,%02X\n",pHD->addr + j,pSub[j]);
                strData.append(szLine) ;
            }

            QString strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") ;
            ui->labelTime->setText(strTime) ;
            if(strData != m_strBak)
            {
                m_strBak = strData ;

                if(ui->checkBoxSave->isChecked())
                {
                    QString strFile =  ui->labelFile->text().trimmed();

                    QFile LogFile(strFile) ;
                    if(LogFile.open(QIODevice::Append | QIODevice::Text) || LogFile.open(QIODevice::WriteOnly | QIODevice::Text))
                    {
                        QString strLine = QString("[%1]\n").arg(strTime) ;
                        LogFile.write(strLine.toStdString().c_str()) ;
                        LogFile.write(strData.toStdString().c_str()) ;
                        LogFile.write("\n") ;
                        LogFile.flush() ;
                        LogFile.close() ;
                    }
                }
            }
        }
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](const QString &strModel){
        Q_UNUSED(strModel)

        QString strPath = m_pCOMDlg->dataPath()+"/AgingTest" ;
        QDir ADir(strPath) ;
        if(!ADir.exists()) ADir.mkdir(strPath) ;

        QFile file(m_pCOMDlg->dataPath() + "AgingTest.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->pushButtonAdd->click() ;
            ui->pushButtonAdd->click() ;
            return ;
        }

        QTextStream in(&file);
        while (!in.atEnd()) addNew(in.readLine().trimmed());
        file.close();
    });

    ui->tableView->installEventFilter(this) ;
    ui->tableView->setMouseTracking(true) ;

    QList<QPushButton *> btns = findChildren<QPushButton *>() ;
    for (QPushButton *btn:qAsConst(btns)) {
        btn->setCursor(Qt::PointingHandCursor) ;
        btn->setFocusPolicy(Qt::NoFocus) ;
    }
}

DialogAgingTest::~DialogAgingTest()
{
    delete ui;
}

void DialogAgingTest::addNew(const QString&strLine)
{
    QStringList items = strLine.split(',') ;
    QStandardItem *item0 = new QStandardItem(items[0]) ;
    QStandardItem *item1 = new QStandardItem(items[1]) ;
    QStandardItem *item2 = new QStandardItem(items[2]) ;
    QStandardItem *item3 = new QStandardItem(items[3]) ;
    QStandardItem *item4 = new QStandardItem(items[4]) ;
    QStandardItem *item5 = new QStandardItem(items[5]) ;
    QStandardItem *item6 = new QStandardItem(items[6]) ;
    QStandardItem *item7 = new QStandardItem("") ;
    QStandardItem *item8 = new QStandardItem("") ;

    item4->setEditable(false) ;
    item5->setEditable(false) ;
    item6->setEditable(false) ;
    item7->setEditable(false) ;
    item8->setEditable(false) ;
    item7->setTextAlignment(Qt::AlignCenter);
    item8->setTextAlignment(Qt::AlignCenter);

    QFont font = this->font() ;
    font.setBold(true) ;
    font.setPointSize(10);
    item0->setFont(font) ;
    item7->setFont(font) ;
    item8->setFont(font) ;

    m_pModel->appendRow({item0,item1,item2,item3,item4,item5,item6,item7,item8}) ;
    item8->setData(0);
}

bool DialogAgingTest::eventFilter(QObject *watched, QEvent *event)
{
    QApplication::restoreOverrideCursor();

    if(watched == ui->tableView)
    {
        if( event->type() == QEvent::Paint ||
            event->type() == QEvent::ToolTip)
        {
            QPoint clp = ui->tableView->viewport()->mapFromGlobal(QCursor::pos())  ;
            QModelIndex index = ui->tableView->indexAt(clp) ;
            if(index.column() == 8)
            {
                QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
                return true ;
            }
        }
    }

    return QDialog::eventFilter(watched, event);
}

