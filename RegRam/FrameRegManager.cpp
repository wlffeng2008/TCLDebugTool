#include "FrameRegManager.h"
#include "SerialTestDialog.h"
#include "ui_FrameRegManager.h"

#include <QDir>
#include <QDebug>
#include <QThread>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QMenu>

#include <QSettings>

#include "global.h"

FrameRegManager::FrameRegManager(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameRegManager)
{
    ui->setupUi(this);

    QStringList headers = {"Reg地址(Hex)","Reg名称" ,"Byte(Hex-W)","Byte(Dec-W)","Byte(Hex-R)","Byte(Dec-R)", "Reg用途描述","双字节"};

    m_pTVModel = new QStandardItemModel(this) ;
    m_pTVModel->setHorizontalHeaderLabels(headers);

    ui->tableView->setModel(m_pTVModel);
    saveLoadMenuStatus(false) ;

    connect(ui->pushButtonSetting,&QPushButton::clicked,this,[=]{
        static QMenu   *pMenu = new QMenu(this) ;
        static QAction *pAct0 = new QAction("显示:" + headers[2],this) ;
        static QAction *pAct1 = new QAction("显示:" + headers[3],this) ;
        static QAction *pAct2 = new QAction("显示:" + headers[4],this) ;
        static QAction *pAct3 = new QAction("显示:" + headers[5],this) ;
        static bool addItem = false ;

        if(!addItem)
        {
            addItem = true ;
            pMenu->addAction(pAct0);
            pMenu->addAction(pAct1);
            pMenu->addAction(pAct2);
            pMenu->addAction(pAct3);

            QString strCfgFile = QCoreApplication::applicationFilePath() + "/TCLMenuConfig.ini" ;
            QSettings MS(strCfgFile,QSettings::IniFormat) ;

            pAct0->setCheckable(true) ;
            pAct0->setChecked(!MS.value("Item2").toBool()) ;

            pAct1->setCheckable(true) ;
            pAct1->setChecked(!MS.value("Item3").toBool()) ;

            pAct2->setCheckable(true) ;
            pAct2->setChecked(!MS.value("Item4").toBool()) ;

            pAct3->setCheckable(true) ;
            pAct3->setChecked(!MS.value("Item5").toBool()) ;

            connect(pAct0,&QAction::triggered,this,[=](bool checked ){
                ui->tableView->setColumnHidden(2,!checked) ;
                saveLoadMenuStatus(true) ;
            }) ;

            connect(pAct1,&QAction::triggered,this,[=](bool checked ){
                ui->tableView->setColumnHidden(3,!checked) ;
                saveLoadMenuStatus(true) ;
            }) ;

            connect(pAct2,&QAction::triggered,this,[=](bool checked ){
                ui->tableView->setColumnHidden(4,!checked) ;
                saveLoadMenuStatus(true) ;
            }) ;

            connect(pAct3,&QAction::triggered,this,[=](bool checked ){
                ui->tableView->setColumnHidden(5,!checked) ;
                saveLoadMenuStatus(true) ;
            }) ;
        }

        pMenu->exec(QCursor::pos());
        //pMenu->exec(ui->pushButtonSetting->geometry().bottomLeft());
    });

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(0,QHeaderView::Fixed);
    header->resizeSection(0,110) ;
    header->setSectionResizeMode(1,QHeaderView::Fixed);
    header->resizeSection(1,200) ;
    header->setSectionResizeMode(2,QHeaderView::Fixed);
    header->resizeSection(2,120) ;
    header->setSectionResizeMode(3,QHeaderView::Fixed);
    header->resizeSection(3,120) ;
    header->setSectionResizeMode(4,QHeaderView::Fixed);
    header->resizeSection(4,100) ;
    header->setSectionResizeMode(5,QHeaderView::Fixed);
    header->resizeSection(5,100) ;
    header->setSectionResizeMode(7,QHeaderView::Fixed);
    header->resizeSection(7,50) ;

    SideValueDelegate *pDele0 = new SideValueDelegate(this);
    SideValueDelegate *pDele1 = new SideValueDelegate(this);
    pDele0->setTableView(ui->tableView) ;
    pDele1->setTableView(ui->tableView) ;
    pDele0->setHexMode();
    ui->tableView->setItemDelegateForColumn(2,pDele0) ;
    ui->tableView->setItemDelegateForColumn(3,pDele1) ;

    ui->tableView->setStyleSheet("QTableView::indicator {margin-left: 12px; }");

    static CornerButtonProxy proxy(ui->tableView);

    ui->tableView->setCornerButtonEnabled(false);

    header->resizeSection(0,100) ;
    header->setDefaultAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;
    header->setAlternatingRowColors(true) ;


    for(int i=2; i<=5; i++)
    {
        QStandardItem *headerItem = m_pTVModel->horizontalHeaderItem(i);
        headerItem->setTextAlignment(Qt::AlignCenter);
    }
    m_pTVModel->horizontalHeaderItem(7)->setTextAlignment(Qt::AlignCenter);

    header->setSectionsClickable(true);
    connect(header,&QHeaderView::sectionDoubleClicked,this,[=](int logicalIndex){
        qDebug() <<"QHeaderView::sectionDoubleClicked:" << logicalIndex;
        if(logicalIndex == 7)
        {
            int nCount  = m_pTVModel->rowCount();
            if(nCount>0)
            {
                bool bCheck = (m_pTVModel->item(0,7)->checkState() == Qt::Checked);

                for(int i=0; i<nCount; i++)
                {
                    m_pTVModel->item(i,7)->setCheckState(bCheck ? Qt::Unchecked : Qt::Checked) ;
                }
                resetAddress() ;
            }
        }
    });

    connect(m_pTVModel, &QStandardItemModel::itemChanged, this, [=](QStandardItem *item) {
        if(m_bLoading)
            return ;
        int nRow = item->row() ;
        int nCol = item->column() ;
        if(nRow == 0 && nCol == 0 )
        {
            if(!m_isCustumReg)
                resetAddress() ;
        }

        if(m_isCustumReg && nCol == 0)
        {
            QString strText = m_pTVModel->item(nRow,0)->text().trimmed() ;
            quint32 nHex = strText.toUInt(nullptr,16) ;
            m_pTVModel->item(nRow,0)->setText(QString("%1").arg(nHex,4,16,QLatin1Char('0')).toUpper()) ;
        }

        if(nCol == 2)
        {
            quint32 nHex = m_pTVModel->item(nRow,2)->text().trimmed().toUInt(nullptr,16) ;
            m_pTVModel->item(nRow,3)->setText(QString::number(nHex)) ;
        }

        if(nCol == 3)
        {
            quint32 nDec = m_pTVModel->item(nRow,3)->text().trimmed().toUInt() ;
            int nLen = 2 ;
            if(m_pTVModel->item(nRow,7)->checkState() == Qt::Checked)
                nLen = 4 ;

            m_pTVModel->item(nRow,2)->setText(QString("%1").arg(nDec,nLen,16,QLatin1Char('0')).toUpper()) ;
        }
    });

    connect(ui->tableView,&QTableView::clicked,this,[=](const QModelIndex &index)
    {
        int nRow = index.row() ;
        m_nSelect = nRow;

        QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
        if(!m_isCustumReg && !selIndexs.isEmpty())
        {
            int nStart = 10000;
            int nEnd = -1;

            QList<int> sels ;
            for (auto it = selIndexs.begin(); it != selIndexs.end(); ++it)
            {
                int nRow = it->row() ;
                sels.append(nRow) ;
                if(nRow>nEnd)
                    nEnd = nRow ;
                if(nRow<nStart)
                    nStart = nRow;
            }

            for(int i=nStart; i<nEnd; i++)
            {
                if(!sels.contains(i))
                    ui->tableView->selectRow(i);
            }
            ui->tableView->update() ;
        }
    }) ;

    connect(this,&FrameRegManager::onWriteReply,this,[=](){ doSendList() ;}) ;
    connect(this,&FrameRegManager::onReadReply ,this,[=](){ doReadList() ;}) ;

    m_pCOMDlg = SerialTestDialog::getInstance() ;
    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;
        quint8 *pData   = m_pCOMDlg->GetDataBody() ;
        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE && !m_bReading)
        {
            if(pData[0] == TYPE_WRITE_SUCCESS)
            {
                emit onWriteReply() ;
            }
        }

        if( pHD->type == TYPE_REG_READ && pHD->head == HEAD_RECV )
        {
            char szLine[20] = {0};
            quint8 *pSub = (quint8 *)data.data() + 10 ;
            int nCount = m_pTVModel->rowCount() ;

            m_bLoading = true ;
            for(int j=0; j<pHD->len; j++)
            {
                quint32 nAddr1 = pHD->addr + j;
                sprintf(szLine,"%04X", nAddr1);

                for(int i=0; i<nCount; i++)
                {
                    quint32 nItemAddr = m_pTVModel->item(i,0)->text().trimmed().toInt(nullptr,16);
                    if(nAddr1 == nItemAddr /*|| nAddr1 + 1 == nItemAddr*/)
                    {
                        if( m_pTVModel->item(i,7)->checkState() == Qt::Checked)
                        {
                            sprintf(szLine,"%04X",*(quint16 *)(pSub+j));
                            j++ ;
                        }
                        else
                        {
                            sprintf(szLine,"%02X",pSub[j]);
                        }

                        m_pTVModel->item(i,4)->setText(szLine) ;

                        if(ui->checkBoxSyncRead->isChecked())
                            m_pTVModel->item(i,2)->setText(szLine) ;

                        sprintf(szLine,"%d",pSub[j]);
                        m_pTVModel->item(i,5)->setText(szLine) ;

                        break ;
                    }
                }
            }
            m_bLoading = false ;

            emit onReadReply() ;
        }
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](const QString &strModel){
        m_strModel = strModel;
        QSettings Set(m_pCOMDlg->getDataPath() + "TCLDebugToolReg.ini", QSettings::IniFormat) ;
        QStringList CommonReg = Set.value("CommonReg").toStringList();
        QStringList SpecialReg = Set.value("SpecialReg").toStringList();
        if(CommonReg.isEmpty())
        {
            CommonReg  = QStringList{"Reg0","Reg1","Reg2","Reg3","Reg4"};
            SpecialReg = QStringList{"RegEx0","RegEx1","RegEx2","RegEx3","RegEx4"};
            Set.setValue("CommonReg",CommonReg) ;
            Set.setValue("SpecialReg",SpecialReg) ;
        }

        ui->comboBoxReg->clear() ;
        ui->comboBoxRegEx->clear() ;
        ui->comboBoxReg->addItems(CommonReg);
        ui->comboBoxRegEx->addItems(SpecialReg);

        buildFileName() ;
        LoadDataFromFile() ;
    });

    on_checkBoxShowRegEx_clicked() ;

    ui->tableView->installEventFilter(this) ;
}

FrameRegManager::~FrameRegManager()
{
    delete ui;
}

void FrameRegManager::saveLoadMenuStatus(bool bSave)
{
    QString strCfgFile = QCoreApplication::applicationDirPath() + "/TCLMenuConfig.ini" ;
    QSettings MS(strCfgFile,QSettings::IniFormat) ;
    qDebug() << strCfgFile << bSave ;
    if(bSave)
    {
        MS.setValue("Item2",!ui->tableView->isColumnHidden(2)) ;
        MS.setValue("Item3",!ui->tableView->isColumnHidden(3)) ;
        MS.setValue("Item4",!ui->tableView->isColumnHidden(4)) ;
        MS.setValue("Item5",!ui->tableView->isColumnHidden(5)) ;
    }
    else
    {
        ui->tableView->setColumnHidden(2,MS.value("Item2",false).toBool());
        ui->tableView->setColumnHidden(3,MS.value("Item3",false).toBool());
        ui->tableView->setColumnHidden(4,MS.value("Item4",false).toBool());
        ui->tableView->setColumnHidden(5,MS.value("Item5",false).toBool());
    }
}

void FrameRegManager::resetAddress()
{
    if(m_isCustumReg)
        return ;

    int nCount = m_pTVModel->rowCount();
    QStandardItem *item = m_pTVModel->item(0) ;
    QString strAddr = item->text() ;
    quint32 nAddr = strAddr.toInt(nullptr,16) ;
    for(int i=0; i<nCount; i++)
    {
        m_pTVModel->item(i,0)->setText(QString("%1").arg(nAddr, 4, 16, QLatin1Char('0')).toUpper()) ;
        nAddr++;
        if(m_pTVModel->item(i,7)->checkState() == Qt::Checked)
            nAddr++ ;
    }
}

void FrameRegManager::addItem(const QStringList&values)
{
    //qDebug()<< values;
    QStandardItem *item0 = new QStandardItem("") ;
    QStandardItem *item1 = new QStandardItem("") ;
    QStandardItem *item2 = new QStandardItem("") ;
    QStandardItem *item3 = new QStandardItem("") ;
    QStandardItem *item4 = new QStandardItem("") ;
    QStandardItem *item5 = new QStandardItem("") ;
    QStandardItem *item6 = new QStandardItem("") ;
    QStandardItem *item7 = new QStandardItem("") ;
    item7->setCheckable(true) ;
    item7->setEditable(false) ;

    QList<QStandardItem *> items = {item0,item1,item2,item3,item4,item5,item6,item7};
    if(m_nSelect != -1 && m_bCtrlPress)
        m_pTVModel->insertRow(m_nSelect,items) ;
    else
        m_pTVModel->appendRow(items) ;

    ui->tableView->setRowHeight(m_pTVModel->rowCount() - 1,18) ;

    int nCount = values.count() ;

    if(nCount>7) item7->setCheckState(values[7] == "1"?Qt::Checked:Qt::Unchecked) ;

    if(nCount>0) item0->setText(values[0]) ;
    if(nCount>1) item1->setText(values[1]) ;
    if(nCount>2) item2->setText(values[2]) ;
    if(nCount>4) item4->setText(values[4]) ;
    if(nCount>3) item3->setText(values[3]) ;
    if(nCount>5) item5->setText(values[5]) ;
    if(nCount>6) item6->setText(values[6]) ;

    // item0->setBackground(QBrush(Qt::darkGray)) ;
    // item3->setBackground(QBrush(Qt::darkGray)) ;
    // item4->setBackground(QBrush(Qt::gray)) ;
    // item5->setBackground(QBrush(Qt::gray)) ;

    //item4->setData(QBrush(Qt::red), Qt::BackgroundRole);
    item7->setBackground(QBrush(Qt::lightGray)) ;

    //item1->setTextAlignment(Qt::AlignCenter) ;
    item2->setTextAlignment(Qt::AlignCenter) ;
    item3->setTextAlignment(Qt::AlignCenter) ;
    item4->setTextAlignment(Qt::AlignCenter) ;
    item5->setTextAlignment(Qt::AlignCenter) ;

    if(!m_isCustumReg)
        item0->setEditable(false);
    //item3->setEditable(false) ;
    item4->setEditable(false) ;
    item5->setEditable(false) ;
}


void FrameRegManager::addItem(const QString &strLine)
{
    addItem(strLine.split(',')) ;
}

bool FrameRegManager::LoadDataFromFile()
{
    if(!m_pTVModel || m_strCurFile.isEmpty() || m_strModel.isEmpty())
        return false;

    while(m_pTVModel->rowCount()) m_pTVModel->removeRow(0) ;

    QFile file(m_strCurFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << m_strCurFile;
        return false;
    }

    m_bLoading = true ;
    QTextStream in(&file);
    while (!in.atEnd()) addItem(in.readLine());// 逐行读取
    file.close();
    m_bLoading = false ;

    QStandardItem *item = m_pTVModel->item(0);
    if(item) item->setEditable(true);

    return true ;
}

bool FrameRegManager::SaveDataToFile()
{
    QFile file(m_strCurFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件创建失败：" << file.errorString() << m_strCurFile;
        return false;
    }
    QTextStream out(&file);

    int nCount = m_pTVModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1,%2,%3,%4,%5,%6,%7,%8\n")
                .arg(m_pTVModel->item(i,0)->text().trimmed())
                .arg(m_pTVModel->item(i,1)->text().trimmed())
                .arg(m_pTVModel->item(i,2)->text().trimmed())
                .arg(m_pTVModel->item(i,3)->text().trimmed())
                .arg(m_pTVModel->item(i,4)->text().trimmed())
                .arg(m_pTVModel->item(i,5)->text().trimmed())
                .arg(m_pTVModel->item(i,6)->text().trimmed())
                .arg(m_pTVModel->item(i,7)->checkState() == Qt::Checked ? "1" : "0")  ;
        out << strLine ;
    }

    return true ;
}

void FrameRegManager::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)  m_bCtrlPress = true;
    if(event->key() == Qt::Key_Shift)   m_bShiftPress = true;

    if(event->key() == Qt::Key_A && event->modifiers() == Qt::ControlModifier)
    {
        ui->tableView->selectAll() ;
    }

    if(event->modifiers() == (Qt::ControlModifier|Qt::ShiftModifier))
    {
        srand(time(nullptr)) ;

        if( event->key() == Qt::Key_F )
        {
            int nCount = m_pTVModel->rowCount();
            for(int i=0; i<nCount; i++)
            {
                if(m_pTVModel->item(i,7)->checkState() == Qt::Unchecked)
                    m_pTVModel->item(i,2)->setText(QString("%1").arg(rand() % 0x100,2,16,QLatin1Char('0')).toUpper());
                else
                    m_pTVModel->item(i,2)->setText(QString("%1").arg(rand() % 0x10000,4,16,QLatin1Char('0')).toUpper());
            }
        }

        if( event->key() == Qt::Key_S )
        {
            QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
            for (auto it = selIndexs.rbegin(); it != selIndexs.rend(); ++it)
            {
                m_pTVModel->item(it->row(),2)->setText(QString("%1").arg(rand() % 256,2,16,QLatin1Char('0')).toUpper());
            }
        }

        if( event->key() == Qt::Key_Z )
        {
            int nCount = m_pTVModel->rowCount();
            for(int i=0; i<nCount; i++)
            {
                m_pTVModel->item(i,2)->setText(QString("%1").arg(0,2,16,QLatin1Char('0')).toUpper());
            }
        }

        if( event->key() == Qt::Key_C )
        {
            QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
            for (auto it = selIndexs.rbegin(); it != selIndexs.rend(); ++it)
            {
                m_pTVModel->item(it->row(),2)->setText(QString("%1").arg(0,2,16,QLatin1Char('0')).toUpper());
            }
        }

        if( event->key() == Qt::Key_D )
        {
            ui->pushButtonClear->click() ;
        }
    }

    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Space)
        on_pushButtonWrite_clicked() ;

    if(m_bShiftPress)
    {
        if(event->key() == Qt::Key_R)
            on_pushButtonRead_clicked() ;
        if(event->key() == Qt::Key_S)
            on_pushButtonRead_clicked() ;
    }

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Left)
    {
        srand(time(nullptr)) ;
        QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
        int nRow = 0 ;
        if(selIndexs.count() > 0)
            nRow = selIndexs[0].row() - 1;
        if(nRow < 0)
            nRow = m_pTVModel->rowCount() - 1 ;
        ui->tableView->selectRow(nRow) ;
    }

    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_Right)
    {
        srand(time(nullptr)) ;
        QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
        int nRow = 0 ;
        if(selIndexs.count() > 0)
            nRow = selIndexs[0].row() + 1;
        if(nRow >= m_pTVModel->rowCount())
            nRow = 0 ;
        ui->tableView->selectRow(nRow) ;
    }

    QFrame::keyPressEvent(event);
}

void FrameRegManager::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)  m_bCtrlPress  = false;
    if(event->key() == Qt::Key_Shift  )  m_bShiftPress = false;

    QFrame::keyReleaseEvent(event);
}

void FrameRegManager::on_pushButtonAdd_clicked()
{
    int nAddCount = ui->lineEditAddCount->text().toInt() ;
    if( nAddCount <= 0 )
        nAddCount= 1 ;
    //m_bLoading = true ;
    srand(time(nullptr)) ;
    for(int i=0; i<nAddCount; i++)
    {
        QString strAddr="0000" ;

        int nCount = m_pTVModel->rowCount() ;
        if(nCount>0)
            strAddr = QString("%1").arg(m_pTVModel->item(nCount-1)->text().trimmed().toInt(nullptr,16) + 1,4,16,QLatin1Char('0'));

        QString strNewLine = QString(strAddr.toUpper() + ",reg_name,0,%1,...,...,For New Reg,0").arg(rand()%0x100) ;

        addItem(strNewLine) ;
    }
    //m_bLoading = false ;

    QStandardItem *item = m_pTVModel->item(0);
    if(item) item->setEditable(true);

    resetAddress() ;
}

void FrameRegManager::on_pushButtonDelete_clicked()
{
    if(m_nSelect == -1)
        return ;

    QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
    for (auto it = selIndexs.rbegin(); it != selIndexs.rend(); ++it)
    {
        m_pTVModel->removeRow(it->row() ) ;
    }

    m_nSelect = -1 ;
    resetAddress() ;
}

void FrameRegManager::on_pushButtonSave_clicked()
{
    if(SaveDataToFile())
    {
        QMessageBox::information(this,"提示","Reg数据保存成功！\n" + m_strCurFile) ;
    }
    else
    {
        QMessageBox::warning(this,"提示","文件创建失败，Reg数据未保存！") ;
    }
}

void FrameRegManager::on_pushButtonSaveAs_clicked()
{
    QString strFile = QFileDialog::getSaveFileName(this,"Reg配置文件 另存为", m_pCOMDlg->getDataPath(),
                                                   tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;
    QString strOldFile = m_strCurFile ;
    m_strCurFile = strFile ;
    on_pushButtonSave_clicked();
    m_strCurFile = strOldFile ;
}

void FrameRegManager::on_pushButtonLoad_clicked()
{
     QString strFile = QFileDialog::getOpenFileName(this,"打开Reg配置文件", m_pCOMDlg->getDataPath(),
                                 tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

     if(strFile.isEmpty())
         return ;

     int index = strFile.lastIndexOf('/') ;
     QString strItem = strFile.mid(index+1);
     strItem.replace(".csv","") ;
     qDebug() << strItem;

     QComboBox *comboBox = ui->comboBoxReg ;
     if(m_isCustumReg)
         comboBox = ui->comboBoxRegEx;

    int nFind = comboBox->findText(strItem);
    if(nFind == -1)
    {
        comboBox->addItem(strItem) ;
        nFind = comboBox->count() - 1;
    }
    comboBox->setCurrentIndex(nFind);
}

void FrameRegManager::doReadList()
{
    int nCount = m_selectRows.count();
    if(nCount <= 0)
    {
        m_bReading = false ;
        return ;
    }
    m_bReading = true ;

    int nRow = m_selectRows[0];
    quint32 nAddr = m_pTVModel->item(nRow,0)->text().trimmed().toUInt(nullptr,16) ;

    if(!m_isCustumReg)
    {
        int nGet = 0 ;
        for(int i=0; i<nCount; i++)
        {
            nGet ++ ;
            if(m_pTVModel->item(m_selectRows[i],7)->checkState() == Qt::Checked)
                nGet ++ ;
        }
        nCount = nGet ;
        m_selectRows.clear();
    }
    else
    {
        nCount = 1 ;
        if(m_pTVModel->item(nRow,7)->checkState() == Qt::Checked)
            nCount = 2 ;
        m_selectRows.removeFirst() ;
    }
    m_pCOMDlg->readRegData(nAddr,nCount,this) ;
}

void FrameRegManager::on_pushButtonRead_clicked()
{
    if(!m_pCOMDlg->isConnected())
    {
        return ;
    }

    m_bWriting = false ;
    m_bReading = false ;
    m_selectRows.clear() ;
    QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
    if(selIndexs.isEmpty())
    {
        int nCount = m_pTVModel->rowCount() ;
        for (int i = 0; i<nCount; i++)
        {
            m_selectRows.push_back(i) ;
            m_pTVModel->item(i,4)->setText("...") ;
            m_pTVModel->item(i,5)->setText("...") ;
        }
    }
    else
    {
        for (auto it = selIndexs.begin(); it != selIndexs.end(); ++it)
        {
            int nRow = it->row() ;
            m_selectRows.push_back(nRow) ;
            m_pTVModel->item(nRow,4)->setText("...") ;
            m_pTVModel->item(nRow,5)->setText("...") ;
        }
    }
    doReadList() ;
}

void FrameRegManager::doSendList()
{
    int nCount = m_selectRows.count();
    if(nCount <= 0)
    {
        m_bWriting = false ;
        return ;
    }
    m_bWriting = true ;

    int nRow = m_selectRows[0];
    quint32 nAddr = m_pTVModel->item(nRow,0)->text().trimmed().toInt(nullptr,16) ;

    QByteArray buf ;

    if(!m_isCustumReg)
    {
        for(int i=0; i<nCount; i++)
        {
            if(m_pTVModel->item(m_selectRows[i],7)->checkState() == Qt::Checked)
            {
                quint16 val = m_pTVModel->item(m_selectRows[i],2)->text().trimmed().toInt(nullptr,16) ;
                buf.append((char *)&val,2) ;
            }
            else
            {
                quint8 val = m_pTVModel->item(m_selectRows[i],2)->text().trimmed().toInt(nullptr,16) ;
                buf.append(val);
            }
        }
        m_selectRows.clear();
    }
    else
    {
        m_selectRows.removeFirst() ;

        if(m_pTVModel->item(nRow,7)->checkState() == Qt::Checked)
        {
            quint16 val = m_pTVModel->item(nRow,2)->text().trimmed().toInt(nullptr,16) ;
            buf.append((char *)&val,2) ;
        }
        else
        {
            quint8 val = m_pTVModel->item(nRow,2)->text().trimmed().toInt(nullptr,16) ;
            buf.append(val);
        }
    }
    m_pCOMDlg->writeRegData(nAddr,buf,buf.count(),this);
}

void FrameRegManager::on_pushButtonWrite_clicked()
{
    if(!m_pCOMDlg->isConnected())
    {
        return ;
    }

    m_bWriting = false ;
    m_bReading = false ;
    m_selectRows.clear() ;
    QModelIndexList selIndexs = ui->tableView->selectionModel()->selectedRows() ;
    if(selIndexs.isEmpty())
    {
        int nCount = m_pTVModel->rowCount() ;
        for (int i = 0; i<nCount; i++)
            m_selectRows.push_back(i) ;
    }
    else
    {
        for (auto it = selIndexs.begin(); it != selIndexs.end(); ++it)
            m_selectRows.push_back(it->row()) ;
    }
    doSendList() ;
}

void FrameRegManager::buildFileName()
{
    QString strFile = ui->comboBoxReg->currentText().trimmed() + ".csv";
    if(strFile.size() == 4 || m_strModel.isEmpty())
        return;
    if(m_isCustumReg)
        strFile = ui->comboBoxRegEx->currentText().trimmed() + ".csv";

    m_strCurFile = m_pCOMDlg->getDataPath() + strFile ;
}

void FrameRegManager::on_comboBoxReg_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    SaveDataToFile();

    buildFileName() ;
    LoadDataFromFile() ;
}

bool FrameRegManager::eventFilter(QObject *watched, QEvent *event)
{
    if ( watched == nullptr )
    {
        if(event->type() == QEvent::User)
        {
        }

        return true ;
    }

    if ( watched == ui->tableView )
    {
        if(event->type() == QEvent::ContextMenu)
        {
            QPoint pos = ui->tableView->mapFromGlobal(QCursor::pos());
            QSize hs = ui->tableView->horizontalHeader()->sizeHint() ;
            QSize vs = ui->tableView->verticalHeader()->sizeHint() ;
            int row = ui->tableView->rowAt(pos.y() - hs.height()) ;
            int col = ui->tableView->columnAt(pos.x() - vs.width());

            // qDebug() << hs << vs;
            // qDebug() << row << col;

            if(col == 7)
            {
                static QMenu   *pMenu = new QMenu(this) ;
                static QAction *pAct0 = new QAction("全部 √",this) ;
                static QAction *pAct1 = new QAction("全部 ×",this) ;
                static QAction *pAct2 = new QAction("全部 取反",this) ;
                static bool addItem = false ;

                if(!addItem)
                {
                    addItem = true ;
                    pMenu->addAction(pAct0);
                    pMenu->addAction(pAct1);
                    pMenu->addAction(pAct2);

                    connect(pAct0,&QAction::triggered,this,[=](bool checked ){
                        Q_UNUSED(checked)
                        int nCount = m_pTVModel->rowCount();
                        for(int i=0; i<nCount; i++)
                            m_pTVModel->item(i,7)->setCheckState(Qt::Checked);
                        resetAddress();
                    }) ;

                    connect(pAct1,&QAction::triggered,this,[=](bool checked ){
                        Q_UNUSED(checked)
                        int nCount = m_pTVModel->rowCount();
                        for(int i=0; i<nCount; i++)
                            m_pTVModel->item(i,7)->setCheckState(Qt::Unchecked);
                        resetAddress();
                    }) ;

                    connect(pAct2,&QAction::triggered,this,[=](bool checked ){
                        Q_UNUSED(checked)
                        int nCount = m_pTVModel->rowCount();
                        for(int i=0; i<nCount; i++)
                        {
                            QStandardItem *item = m_pTVModel->item(i,7) ;
                            item->setCheckState(item->checkState()==Qt::Checked ? Qt::Unchecked:Qt::Checked);
                        }
                        resetAddress();
                    }) ;
                }

                pMenu->exec(QCursor::pos());
            }
        }
    }

    return QFrame::eventFilter(watched, event);
}

void FrameRegManager::on_checkBoxShowRegEx_clicked()
{
    SaveDataToFile();
    bool bShowEx = ui->checkBoxShowRegEx->isChecked() ;
    m_isCustumReg = bShowEx ;
    ui->comboBoxReg->setVisible(!bShowEx) ;
    ui->comboBoxRegEx->setVisible(bShowEx) ;

    buildFileName() ;
    LoadDataFromFile() ;
}

void FrameRegManager::on_comboBoxRegEx_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    SaveDataToFile();

    buildFileName() ;
    LoadDataFromFile() ;
}

void FrameRegManager::on_pushButtonClear_clicked()
{
    auto nRet = QMessageBox::warning(this,"提示","确认要清空列表吗？",QMessageBox::Yes|QMessageBox::No);
    if(nRet == QMessageBox::Yes)
    {
        m_pTVModel->setRowCount(0) ;
        SaveDataToFile() ;
    }
}

