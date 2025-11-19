#include "FrameBLPostProc.h"
#include "ui_FrameBLPostProc.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>


FrameBLPostProc::FrameBLPostProc(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameBLPostProc)
{
    ui->setupUi(this);

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    {
        //ui->tableViewGrid->setStyleSheet("{}");
        //ui->tableViewGrid->setFixedSize(353,353);
        m_pGModel = new QStandardItemModel(9,9,this) ;
        ui->tableViewGrid->setModel(m_pGModel) ;

        ui->tableViewGrid->horizontalHeader()->hide();
        ui->tableViewGrid->verticalHeader()->hide();

        ui->tableViewGrid->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;
        ui->tableViewGrid->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                QStandardItem *item = new QStandardItem("0") ;

                item->setEditable(i <= 4 && j <= 4) ;
                item->setTextAlignment(Qt::AlignCenter);
                item->setBackground(QBrush(Qt::white));
                m_pGModel->setItem(i,j,item);

                if(j<=4 && i<=4)
                {
                    if(i==0 || j==0)
                        item->setForeground(QBrush(QColor(Qt::darkCyan)));

                    else if(i==1 || j==1)
                        item->setForeground(QBrush(QColor(Qt::blue)));

                    else if(i==2 || j==2)
                        item->setForeground(QBrush(QColor(Qt::green)));

                    else if(i==3 || j==3)
                        item->setForeground(QBrush(QColor(Qt::red)));

                    if(i==4 && j==4)
                        item->setForeground(QBrush(QColor(Qt::yellow)));
                }
                else
                {
                    item->setForeground(QBrush(QColor(Qt::gray)));
                    item->setEditable(false) ;
                    item->setSelectable(false) ;
                }
            }
        }
    }

    {
        m_pDModel = new QStandardItemModel(25,2,this) ;
        ui->tableView->setModel(m_pDModel) ;

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;
        ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed) ;
        ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;

        ui->tableView->horizontalHeader()->hide();
        ui->tableView->verticalHeader()->hide();
        for(int i=0; i<25; i++)
        {
            QStandardItem *pItem0= new QStandardItem() ;
            pItem0->setText("expand_weight" + QString::number(i+1)) ;
            pItem0->setEditable(false) ;
            m_pDModel->setItem(i,0,pItem0);

            QStandardItem *pItem1= new QStandardItem() ;
            pItem1->setText("0") ;
            m_pDModel->setItem(i,1,pItem1);
            ui->tableView->setRowHeight(i,20) ;

            if(i>=20)
                pItem1->setForeground(QBrush(QColor(Qt::yellow)));
            else if(i>=15)
                pItem1->setForeground(QBrush(QColor(Qt::red)));
            else if(i>=10)
                pItem1->setForeground(QBrush(QColor(Qt::green)));
            else if(i>=5)
                pItem1->setForeground(QBrush(QColor(Qt::blue)));
            else
                pItem1->setForeground(QBrush(QColor(Qt::darkCyan)));
        }

        ui->tableView->setFixedSize(222,627);
        ui->tableView->setColumnWidth(0,160);
        //ui->tableView->setColumnWidth(1,60);

        connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](){
            if(m_pSet)
                delete m_pSet ;
            m_pSet = new QSettings(m_pCOMDlg->getDataPath() + "expand_weight.ini",QSettings::IniFormat);
            QStringList EWs = m_pSet->value("expand_weights").toStringList() ;
            if(EWs.isEmpty())
                EWs = QString("0,0,0,0,0,0,0,0,0,0,0,0,6,32,96,0,0,32,96,233,0,0,96,233,255").split(',') ;
            for(int i=0; i<25; i++)
                m_pDModel->item(i,1)->setText(EWs[i]) ;
            fillGrid() ;
        });
    }
    {
        srand(time(nullptr)) ;
        m_pMModel = new QStandardItemModel(3,3,this) ;
        ui->tableViewGM->setModel(m_pMModel) ;
        ui->tableViewGM->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;
        ui->tableViewGM->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                qreal val = (rand()%20000)/10000.0 * (rand()%2 ? 1:-1);
                QStandardItem *item = new QStandardItem(QString::number(val,'g',3)) ;
                item->setTextAlignment(Qt::AlignCenter);
                m_pMModel->setItem(i,j,item);
            }
        }
    }

    ui->tableView->setFocusPolicy(Qt::NoFocus) ;
    ui->tableViewGrid->setFocusPolicy(Qt::NoFocus) ;
    ui->tableViewGM->setFocusPolicy(Qt::NoFocus) ;

    connect(m_pDModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) { Q_UNUSED(item)  fillGrid(false) ; });
    connect(m_pGModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) { Q_UNUSED(item)  fillGrid(true)  ; });

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        quint8 *pData = m_pCOMDlg->GetDataBody() ;
        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }

        if(pHD->len == 25 || pHD->len == 24)
        {
            for(int i=0; i<pHD->len; i++)
                m_pDModel->item(i,1)->setText(QString::number(pData[i])) ;

            fillGrid(false) ;
        }

        if(pHD->len == 18)
        {
            if(0x109F == pHD->addr)
            {
                qint16 *pMVal = (qint16 *)pData ;
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        qreal value = pMVal[i*3 + j]  ;
                        if(value > 2048)
                            value = (value - 2048) * -1 ;
                        m_pMModel->item(i,j)->setText(QString("%1").arg(value / 512)) ;
                    }
                }
            }
        }
    });


#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    connect(ui->buttonGroup1, &QButtonGroup::idClicked, this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_pushButtonWriteM_clicked() ;
    });

    connect(ui->buttonGroup2, &QButtonGroup::idClicked, this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_checkBoxBLPostProc_clicked();
    });

    connect(ui->buttonGroup3, &QButtonGroup::idClicked, this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_pushButtonWriteGM_clicked();
    });
#else

    connect(ui->buttonGroup1, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_pushButtonWriteM_clicked() ;
    });

    connect(ui->buttonGroup2, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_checkBoxBLPostProc_clicked();
    });

    connect(ui->buttonGroup3, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_pushButtonWriteGM_clicked();
    });

#endif

    connect(ui->checkBoxGMEnable,&QCheckBox::clicked,this,[=](bool checked){
        m_pCOMDlg->sendSwitch(0x109E,checked,this);
        m_pCOMDlg->sendSwitch(0x129E,checked,this);
    }) ;
}

FrameBLPostProc::~FrameBLPostProc()
{
    delete ui;
}


void FrameBLPostProc::fillGrid(bool bSelf)
{
    int i=0;
    int j=0;
    QStringList  EWs;

    if(!bSelf)
    {
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                QString strText = m_pDModel->item(i*5 + j,1)->text() ;
                m_pGModel->item(i, j)->setText(strText);
                m_pGModel->item(i, 8-j)->setText(strText);

                EWs.push_back(strText) ;
            }
        }
    }
    else
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                QString strText = m_pGModel->item(i,j)->text() ;
                m_pGModel->item(i, 8-j)->setText(strText);
            }
        }

        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                EWs.push_back(m_pGModel->item(i,j)->text()) ;
            }
        }

        for(i=0; i<25; i++)
            m_pDModel->item(i,1)->setText(EWs[i]) ;
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<9; j++)
        {
            QString strText = m_pGModel->item(i, j)->text() ;
            m_pGModel->item(8-i, j)->setText(strText);
        }
    }

    EWs.clear() ;
    for(i=0; i<25; i++)
    {
        EWs.push_back(m_pDModel->item(i,1)->text()) ;
    }
    m_pSet->setValue("expand_weights",EWs);
}

void FrameBLPostProc::on_checkBoxBLPostProc_clicked()
{
    bool bEnable = ui->checkBoxBLPostProc->isChecked() ;
    quint8 value = bEnable?2:0 ;

    quint32 nAddrLeft  = 0x1036;
    quint32 nAddrRight = 0x1236;

    if(ui->radioButtonE1->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE2->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }

    if(ui->radioButtonE3->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE4->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }
}


void FrameBLPostProc::on_checkBoxProcoeSW_clicked()
{
    bool bEnable = ui->checkBoxProcoeSW->isChecked() ;
    quint8 value = bEnable?1:0 ;

    quint32 nAddrLeft  = 0x1100;
    quint32 nAddrRight = 0x1300;

    if(ui->radioButtonE1->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE2->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }

    if(ui->radioButtonE3->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE4->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }
}


void FrameBLPostProc::on_checkBoxProBblbadjEn_clicked()
{
    bool bEnable = ui->checkBoxProBblbadjEn->isChecked() ;
    quint8 value = bEnable?1:0 ;

    quint32 nAddrLeft  = 0x1101;
    quint32 nAddrRight = 0x1301;

    if(ui->radioButtonE1->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE2->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,value,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }

    if(ui->radioButtonE3->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,value,this) ;
    }

    if(ui->radioButtonE4->isChecked())
    {
        m_pCOMDlg->sendInt8(nAddrLeft,0,this) ;
        m_pCOMDlg->sendInt8(nAddrRight,0,this) ;
    }
}

void FrameBLPostProc::on_pushButtonWriteWBL_clicked()
{
    quint16 value = ui->doubleSpinBox->value() * 1024 ;
    m_pCOMDlg->sendInt16(0x1037,value,this) ;
    m_pCOMDlg->sendInt16(0x1237,value,this) ;
}

void FrameBLPostProc::on_pushButtonWriteWB_clicked()
{
    quint16 value = ui->spinBoxWB->value()  ;
    m_pCOMDlg->sendInt16(0x1102,value,this) ;
    m_pCOMDlg->sendInt16(0x1302,value,this) ;
}


void FrameBLPostProc::on_pushButtonWriteM_clicked()
{
    char empty[64] = {0} ;

    QByteArray buf ;
    for(int i=0; i<25; i++)
    {
        quint8 val = m_pDModel->item(i,1)->text().toInt() ;
        buf.append(val) ;
    }

    quint32 nAddrLeft  = ui->lineEditAddrLeft->text().trimmed().toUInt(nullptr,16);
    quint32 nAddrRight = ui->lineEditAddrRight->text().trimmed().toUInt(nullptr,16);
    int nWriteCount = ui->lineEditWriteCount->text().toInt() ;

    if(ui->radioButtonM1->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,buf.data(),nWriteCount,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,buf.data(),nWriteCount,this) ;
    }

    if(ui->radioButtonM2->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,buf.data(),nWriteCount,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,empty,nWriteCount,this) ;
    }

    if(ui->radioButtonM3->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,empty,nWriteCount,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,buf.data(),nWriteCount,this) ;
    }

    if(ui->radioButtonM4->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,empty,nWriteCount,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,empty,nWriteCount,this) ;
    }
}


void FrameBLPostProc::on_pushButtonRead_clicked()
{
    int nWriteCount = ui->lineEditWriteCount->text().toInt() ;
    quint32 nAddrLeft = ui->lineEditAddrLeft->text().trimmed().toUInt(nullptr,16);
    m_pCOMDlg->readRegData(nAddrLeft,nWriteCount,this) ;
}


void FrameBLPostProc::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开expand_weights文件", m_pCOMDlg->getDataPath(),
                                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;
    m_strCurFile = strFile ;

    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,"提示","文件打开失败，请重试！");
        return ;
    }

    int j = 0 ;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QStringList items = in.readLine().trimmed().split(',');
        if(items.count() != 9)
        {
            QMessageBox::critical(this,"提示","文件格式错误，请重试！");
            break;
        }
        for(int i=0; i<9; i++)
            m_pGModel->item(j,i)->setText(items[i]) ;
        j++ ;
        if(j >= 9)
            break;
    }
    fillGrid(true) ;
    file.close();
}


void FrameBLPostProc::on_pushButtonSave_clicked()
{
    QString strFile = QFileDialog::getSaveFileName(this,"保存expand_weights文件", m_pCOMDlg->getDataPath(),
                                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;
    m_strCurFile = strFile ;


    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件创建失败：" << file.errorString() << strFile;
        return ;
    }
    QTextStream out(&file);

    int nCount = m_pGModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9\n")
                              .arg(m_pGModel->item(i,0)->text().trimmed(),
                                   m_pGModel->item(i,1)->text().trimmed(),
                                   m_pGModel->item(i,2)->text().trimmed(),
                                   m_pGModel->item(i,3)->text().trimmed(),
                                   m_pGModel->item(i,4)->text().trimmed(),
                                   m_pGModel->item(i,5)->text().trimmed(),
                                   m_pGModel->item(i,6)->text().trimmed(),
                                   m_pGModel->item(i,7)->text().trimmed(),
                                   m_pGModel->item(i,8)->text().trimmed());
        out << strLine ;
    }
    file.close() ;

    QMessageBox::information(this,"提示","数据保存完毕！");
}


void FrameBLPostProc::on_pushButtonWriteGM_clicked()
{
    char empty[64] = {0} ;

    QByteArray buf ;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            qint16 val = m_pMModel->item(i,j)->text().toDouble() * 512 ;
            if(val < 0.0)
                val = abs(val) + 2048 ;

            buf.append((char *)&val,2) ;
        }
    }
    qDebug() << buf.toHex(' ')  ;

    quint32 nAddrLeft  = 0x109F;
    quint32 nAddrRight = 0x129F;

    if(ui->radioButtonGM1->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,buf.data(),18,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,buf.data(),18,this) ;
    }

    if(ui->radioButtonGM2->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,buf.data(),18,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,empty,18,this) ;
    }

    if(ui->radioButtonGM3->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,empty,18,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,buf.data(),18,this) ;
    }

    if(ui->radioButtonGM4->isChecked())
    {
        m_pCOMDlg->writeRegData(nAddrLeft,empty,18,this) ;
        m_pCOMDlg->writeRegData(nAddrRight,empty,18,this) ;
    }
}


void FrameBLPostProc::on_pushButtonReadGM_clicked()
{
    m_pCOMDlg->readRegData(0,18,this) ;
}


void FrameBLPostProc::on_pushButtonWriteGMEn_clicked()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            qreal val = (rand()%2000)/1000.0 * (rand()%2 ? 1:-1);
            QStandardItem *item = new QStandardItem(QString::number(val)) ;
            item->setTextAlignment(Qt::AlignCenter);
            m_pMModel->setItem(i,j,item);
        }
    }
}

