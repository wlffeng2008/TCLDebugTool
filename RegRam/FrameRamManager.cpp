
#include "DialogToast.h"
#include "ui_FrameRamManager.h"

#include "global.h"
#include "FrameRamManager.h"
#include "SerialTestDialog.h"

#include <QFileDialog>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QSettings>
#include <QProcess>
#include <QScrollBar>
#include <QMessageBox>
#include <QThread>

static FrameRamManager *g_pRamWorker = nullptr ;
FrameRamManager *FrameRamManager::getInstance()
{
    return g_pRamWorker ;
}

FrameRamManager::FrameRamManager(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameRamManager)
{
    ui->setupUi(this);

    g_pRamWorker = this ;

    QStringList headers0 = {"地址(Hex)","Byte0" ,"Byte1", "Byte2", "Byte3", "Byte4", "Byte5", "Byte6", "Byte7", "Byte8"};

    m_pDataModel = new QStandardItemModel(this) ;
    m_pDataModel->setHorizontalHeaderLabels(headers0);
    ui->tableViewData->setModel(m_pDataModel);

    QStringList headers1 = {"文件" ,"起始地址(Hex)", "大小(B)","行数","修改日期"};
    m_pFileModel= new QStandardItemModel(this) ;
    m_pFileModel->setHorizontalHeaderLabels(headers1);
    ui->tableViewFile->setModel(m_pFileModel);

    QHeaderView *header = ui->tableViewData->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(0,QHeaderView::Fixed);
    header->resizeSection(0,100) ;
    header->setDefaultAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;
    for(int i=1; i<10; i++)
    {
        QStandardItem *headerItem = m_pDataModel->horizontalHeaderItem(i);
        headerItem->setTextAlignment(Qt::AlignCenter);
    }

    connect(header,&QHeaderView::sectionClicked,this,[=](int logicalIndex) {
        if(logicalIndex == 0 ) return ;

        if (isKeyPressed('A'))        qDebug() << "A键按下";
        if (isKeyPressed(VK_CONTROL)) qDebug() << "Ctrl键按下";

        int nCount = m_pDataModel->rowCount() ;
        for(int i=0; i<nCount; i++)
        {
            QStandardItem *item = m_pDataModel->item(i,logicalIndex) ;
            if(m_bCtrlPress ) item->setText(QString("%1").arg(rand()%0x100,2,16,QLatin1Char('0')).toUpper()) ;
            if(m_bShiftPress) item->setText("00") ;
            if(m_bAltPress  ) item->setText("FF") ;
        }
    }) ;

    header = ui->tableViewFile->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(1, QHeaderView::Fixed);
    header->setSectionResizeMode(2, QHeaderView::Fixed);
    header->setSectionResizeMode(3, QHeaderView::Fixed);
    header->setSectionResizeMode(4, QHeaderView::Fixed);
    header->resizeSection(1, 90);
    header->resizeSection(2, 60);
    header->resizeSection(3, 60);
    header->resizeSection(4, 140);

    {
        static CornerButtonProxy proxy0(ui->tableViewData);
        static CornerButtonProxy proxy1(ui->tableViewFile);

        connect(ui->tableViewData,&QTableView::clicked,this,[=](const QModelIndex &index) {
            int nRow = index.row() ;
            m_nSelectData = nRow ;

            for(int i=1; i<10; i++)
            {
                QStandardItem *item = m_pDataModel->item(nRow,i);
                if(m_bCtrlPress) item->setText(QString("%1").arg(rand()%0x100,2,16,QLatin1Char('0')).toUpper()) ;
                if(m_bShiftPress) item->setText("00") ;
            }

            if(index.column() == 0 && isKeyPressed(VK_CONTROL))
            {
                 QStandardItem *item = m_pDataModel->item(nRow);
                 ui->lineEditDataAddr->setText(item->text()) ;
            }
        }) ;

        connect(ui->tableViewFile,&QTableView::clicked,this,[=](const QModelIndex &index) {
            int nRow = index.row() ;
            m_nSelectFile = nRow ;
            QStandardItem *item = m_pFileModel->item(nRow);
            m_strSelectFile = item->text() ;
            ui->lineEditFileAddr->setText(m_pFileModel->item(nRow,1)->text().trimmed()) ;
        }) ;

        connect(m_pFileModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) {
            int nCol = item->column() ;
            if(nCol == 1)
            {
                saveLoadFileList() ;
            }
        });
    }

    m_pCOMDlg = SerialTestDialog::getInstance() ;
    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;
        quint8 *pData    = m_pCOMDlg->GetDataBody() ;

        if(data.size() == 15 && pHD->type == TYPE_RAM_WRITE)
        {
            if(pData[0] == TYPE_WRITE_SUCCESS)
            {
                writeHugeRam();
            }
        }

        if((pHD->type == TYPE_RAM_READ) && pHD->head == HEAD_RECV ) // && data.size() > pHD->len
        {
            if(m_bReadFromOut)
            {
                m_writeBuf.append((char *)pData,pHD->len) ;
            }
            else
            {
                char szLine[1024] = {0};
                int nSubs = pHD->len/9 ;
                for(int i=0; i<nSubs; i++)
                {
                    quint8 *pSub = pData + i * 9 ;
                    sprintf(szLine,"%04X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X",pHD->addr + i,
                            pSub[0],pSub[1],pSub[2],pSub[3],pSub[4],pSub[5],pSub[6],pSub[7],pSub[8]);
                    addDataTolist(szLine) ;
                }

                m_TMReadEnd.stop() ;
                m_TMReadEnd.start(200);
            }

            readHugeRam() ;
        }
    });

    connect(&m_TMReadEnd,&QTimer::timeout,this,[=]{
        m_TMReadEnd.stop() ;
        toast()->active("Ram数据 读取 结束！") ;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](const QString &strModel){
        Q_UNUSED(strModel)
        QString strFile = m_pCOMDlg->getDataPath() + "defaultRam.bin" ;
        loadDataFromFile(strFile) ;
        saveLoadFileList(false) ;
    });

    connect(ui->pushButtonClearData,&QPushButton::clicked,this,[=]{
        auto nRet = QMessageBox::warning(this,"提示","确认要清空列表吗？",QMessageBox::Yes|QMessageBox::No);
        if(nRet == QMessageBox::Yes)
            m_pDataModel->setRowCount(0) ;
    });
    connect(ui->pushButtonGenData,&QPushButton::clicked,this,[=]{
        m_pDataModel->setRowCount(0) ;
        quint32 nCount = ui->spinBoxDataCount->value();
        quint32 nAddr  = ui->lineEditDataAddr->text().trimmed().toInt(nullptr,16) ;

        char szLine[1024] = {0};
        quint8 values[20] = {0} ;
        for(quint32 i=0; i<nCount; i++)
        {
            for(quint32 j=0; j<10; j++)
                values[j] = rand() % 0x100;
            sprintf(szLine,"%04X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X",nAddr + i,
                values[0],values[1],values[2],values[3],values[4],values[5],values[6],values[7],values[8]);
            addDataTolist(szLine) ;
        }
    });

    connect(ui->spinBoxD,&QSpinBox::textChanged,this,[=](const QString & value){
        Q_UNUSED(value)
        quint64 nD = ui->spinBoxD->value() ;
        int nLeft  = ui->spinBoxL->value() ;
        ui->lineEditDataAddr->setText(QString("%1").arg((nD<<nLeft),4,16,QLatin1Char('0')).toUpper());
    }) ;
    connect(ui->spinBoxL,&QSpinBox::textChanged,this,[=](const QString & value){
        Q_UNUSED(value)
        quint64 nD = ui->spinBoxD->value() ;
        int nLeft  = ui->spinBoxL->value() ;
        ui->lineEditDataAddr->setText(QString("%1").arg((nD<<nLeft),4,16,QLatin1Char('0')).toUpper());
    }) ;
}

FrameRamManager::~FrameRamManager()
{
    delete ui;
}

bool FrameRamManager::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == nullptr)
    {
        if(event->type() == QEvent::User)
        {
            const QByteArray&data = m_pCOMDlg->GetBuf() ;
        }
        return true ;
    }
    return QFrame::eventFilter(watched, event);
}


void FrameRamManager::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)  m_bCtrlPress  = true;
    if(event->key() == Qt::Key_Shift)    m_bShiftPress = true;
    if(event->key() == Qt::Key_Alt)      m_bAltPress   = true;

    if(event->modifiers() == (Qt::ControlModifier|Qt::ShiftModifier))
    {
        srand(time(nullptr)) ;
        if(event->key() == Qt::Key_F)
        {
            int nCount = m_pDataModel->rowCount();
            for(int i=0; i<nCount; i++)
            {
                for(int j=1; j<10; j++)
                {
                    int nValue = rand() % 256 ;
                    m_pDataModel->item(i,j)->setText(QString("%1").arg(nValue,2,16,QLatin1Char('0')).toUpper());
                }
            }
        }
    }

    QFrame::keyPressEvent(event);
}

void FrameRamManager::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)  m_bCtrlPress  = false;
    if(event->key() == Qt::Key_Shift)    m_bShiftPress = false;
    if(event->key() == Qt::Key_Alt)      m_bAltPress   = false;

    QFrame::keyReleaseEvent(event);
}

void FrameRamManager::addDataTolist(const QString&strLine)
{
    addDataTolist(strLine.trimmed().split(',')) ;
}

void FrameRamManager::addDataTolist(const QStringList&dataGroup)
{
    QStandardItem *item0 = new QStandardItem("0000");
    QStandardItem *item1 = new QStandardItem();
    QStandardItem *item2 = new QStandardItem();
    QStandardItem *item3 = new QStandardItem();
    QStandardItem *item4 = new QStandardItem();
    QStandardItem *item5 = new QStandardItem();
    QStandardItem *item6 = new QStandardItem();
    QStandardItem *item7 = new QStandardItem();
    QStandardItem *item8 = new QStandardItem();
    QStandardItem *item9 = new QStandardItem();

    int nCount = dataGroup.count();
    if(nCount>0)
        item0->setText(dataGroup[0]) ;
    if(nCount>1)
        item1->setText(dataGroup[1]) ;
    if(nCount>2)
        item2->setText(dataGroup[2]) ;
    if(nCount>3)
        item3->setText(dataGroup[3]) ;
    if(nCount>4)
        item4->setText(dataGroup[4]) ;
    if(nCount>5)
        item5->setText(dataGroup[5]) ;
    if(nCount>6)
        item6->setText(dataGroup[6]) ;
    if(nCount>7)
        item7->setText(dataGroup[7]) ;
    if(nCount>8)
        item8->setText(dataGroup[8]) ;
    if(nCount>9)
        item9->setText(dataGroup[9]) ;

    item1->setTextAlignment(Qt::AlignCenter) ;
    item2->setTextAlignment(Qt::AlignCenter) ;
    item3->setTextAlignment(Qt::AlignCenter) ;
    item4->setTextAlignment(Qt::AlignCenter) ;
    item5->setTextAlignment(Qt::AlignCenter) ;
    item6->setTextAlignment(Qt::AlignCenter) ;
    item7->setTextAlignment(Qt::AlignCenter) ;
    item8->setTextAlignment(Qt::AlignCenter) ;
    item9->setTextAlignment(Qt::AlignCenter) ;

    QList<QStandardItem *> items={item0,item1,item2,item3,item4,item5,item6,item7,item8,item9};
    m_pDataModel->appendRow(items) ;
    ui->tableViewData->setRowHeight(m_pDataModel->rowCount() - 1,18) ;
}

void FrameRamManager::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开Ram数据文件", QDir::homePath(),
                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;

    loadDataFromFile(strFile) ;
}

void FrameRamManager::loadDataFromFile(const QString&strFile)
{
    ui->lineEditFileName->setText(strFile) ;
    m_pDataModel->setRowCount(0);

    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << strFile << __FILE__ << __LINE__;
        return ;
    }

    uint nLine = 0 ;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString strLine = in.readLine();
        addDataTolist(QString("%1,").arg(nLine++,4,16,QLatin1Char('0')).toUpper() + strLine.trimmed());
    }

    file.close();
}

void FrameRamManager::on_pushButtonSave_clicked()
{
    QString strFile = ui->lineEditFileName->text() ;
    if(strFile.isEmpty())
        return ;

    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件创建失败：" << file.errorString() << strFile << __FILE__ << __LINE__;
        return ;
    }
    QTextStream out(&file);

    int nCount = m_pDataModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9\n")  //.arg(m_pDataModel->item(i,0)->text().trimmed())
                .arg(m_pDataModel->item(i,1)->text().trimmed())
                .arg(m_pDataModel->item(i,2)->text().trimmed())
                .arg(m_pDataModel->item(i,3)->text().trimmed())
                .arg(m_pDataModel->item(i,4)->text().trimmed())
                .arg(m_pDataModel->item(i,5)->text().trimmed())
                .arg(m_pDataModel->item(i,6)->text().trimmed())
                .arg(m_pDataModel->item(i,7)->text().trimmed())
                .arg(m_pDataModel->item(i,8)->text().trimmed())
                .arg(m_pDataModel->item(i,9)->text().trimmed()) ;
        out << strLine ;
    }
    file.close() ;

    QMessageBox::information(this,"提示","数据保存完毕！");
}

void FrameRamManager::on_pushButtonWrite_clicked()
{
    if(!m_pCOMDlg->isConnected())
    {
        return ;
    }

    QByteArray buf ;
    int nCount = ui->spinBoxDataCount->value() ;
    for(int j=0; j<nCount; j++)
    {
        char szBuf[20] = {0} ;
        for(int i=0; i<9; i++)
            szBuf[i] = m_pDataModel->item(j,i+1)->text().trimmed().toUInt(nullptr,16) ;
        buf.append(szBuf,9);
    }

    quint32 nAddr = ui->lineEditDataAddr->text().trimmed().toInt(nullptr,16) ;
    m_writeAddr = nAddr ;
    m_writeBuf = buf;
    writeHugeRam() ;
}

void FrameRamManager::on_pushButtonRead_clicked()
{
    if(!m_pCOMDlg->isConnected())
    {
        return ;
    }

    m_pDataModel->setRowCount(0) ;

    quint32 nAddr  = ui->lineEditDataAddr->text().trimmed().toUInt(nullptr,16) ;
    int nReadCount = ui->spinBoxDataCount->value();
    m_readAddr = nAddr;
    m_readCount = nReadCount ;
    readHugeRam() ;
}


void FrameRamManager::on_pushButtonAddFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"打开Ram数据文件", m_pCOMDlg->getDataPath(),
                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(file.isEmpty())
        return ;

    addFileTolist(file,"0000") ;
    saveLoadFileList();
}

void FrameRamManager::addFileTolist(const QString&strFile,const QString&strAddr)
{
    int nLines =  0 ;
    QFile FL(strFile) ;
    if(FL.open(QIODevice::ReadOnly))
    {
        QTextStream  in(&FL) ;
        while(!in.atEnd())
        {
            in.readLine() ;
            nLines ++ ;
        }
    }

    QFileInfo file (strFile) ;
    QStandardItem *item0 = new QStandardItem(strFile);
    QStandardItem *item1 = new QStandardItem(strAddr);
    QStandardItem *item2 = new QStandardItem(QString::number(file.size()));
    QStandardItem *item3 = new QStandardItem(QString::number(nLines));
    QStandardItem *item4 = new QStandardItem(file.lastModified().toString("yyyy-MM-dd hh:mm:ss"));

    item0->setEditable(false);
    item2->setEditable(false);
    item3->setEditable(false);
    item4->setEditable(false);
    item1->setTextAlignment(Qt::AlignCenter) ;
    item2->setTextAlignment(Qt::AlignCenter) ;
    item3->setTextAlignment(Qt::AlignCenter) ;
    item4->setTextAlignment(Qt::AlignCenter) ;

    m_pFileModel->appendRow({item0,item1,item2,item3,item4}) ;
    //ui->tableViewFile->setRowHeight(m_pFileModel->rowCount()-1,25) ;
}

void FrameRamManager::saveLoadFileList(bool bToSave)
{
    QString strFile = m_pCOMDlg->getDataPath() + "filelist.ini" ;
    QSettings FL(strFile,QSettings::IniFormat) ;

    QStringList Files;
    QStringList Addrs;

    if(bToSave)
    {
        int nCount = m_pFileModel->rowCount() ;
        for(int i=0; i<nCount; i++)
        {
            Files.push_back(m_pFileModel->item(i,0)->text());
            Addrs.push_back(m_pFileModel->item(i,1)->text());
        }

        FL.setValue("Files",Files);
        FL.setValue("Addrs",Addrs);
    }
    else
    {
        Files = FL.value("Files").toStringList() ;
        Addrs = FL.value("Addrs").toStringList() ;

        int nCount = Files.count() ;
        for(int i=0; i<nCount; i++)
        {
            addFileTolist(Files[i],Addrs[i]) ;
        }
    }
}

void FrameRamManager::on_pushButtonRemoveFile_clicked()
{
    if(m_nSelectFile == -1)
        return ;

    m_pFileModel->removeRow(m_nSelectFile) ;
    saveLoadFileList();
    m_nSelectFile = -1 ;
}

void FrameRamManager::on_pushButtonWriteFile_clicked()
{
    if(!m_pCOMDlg->isConnected())
    {
        return ;
    }

    QFile file(m_strSelectFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << m_strSelectFile  << __FILE__ << __LINE__;
        return ;
    }

    quint64 nLimits = ui->spinBoxLineCount->value() ;
    if(nLimits == 0) nLimits = 0xFFFFFFFF ;

    char szTmp[20] = {0} ;
    QByteArray buf ;
    QTextStream in(&file);
    quint64 nLines = 0 ;
    while (!in.atEnd())
    {
        QString strLine = in.readLine().trimmed();
        QStringList data = strLine.split(',') ;

        if(data.count()>1)
        {
            for(const QString&val:data)
            {
                unsigned char C = val.toUInt() ;
                if(ui->checkBoxHexFile->isChecked())
                    C = val.toUInt(nullptr,16) ;
                buf.append(C) ;
            }
        }
        else
        {
            if(strLine.length() >= 18)
            {
                buf.append(QByteArray::fromHex(strLine.toLatin1()));
            }
            else
            {
                quint64 value =  strLine.toULongLong() ;
                if(ui->checkBoxHexFile->isChecked())
                    value = strLine.toULongLong(nullptr,16) ;
                *(quint64 *)szTmp = value ;
                buf.append(szTmp,9) ;
            }
        }

        nLines++ ;
        if(nLines > nLimits)
            break ;
    }
    file.close() ;

    m_writeBuf  = buf ;
    m_writeAddr = ui->lineEditFileAddr->text().trimmed().toInt(nullptr,16) ;
    writeHugeRam() ;
}

void FrameRamManager::on_pushButtonOpenFile_clicked()
{
    QProcess::startDetached("notepad.exe", QStringList{ m_strSelectFile});
}

void FrameRamManager::writeHugeRam()
{
    int nSize = m_writeBuf.size() ;
    if(nSize <= 0)
    {
        if(m_bWriteFromOut)
            m_pCOMDlg->notifyWriteHugeRamDone() ;

        m_bWriteFromOut = false ;
        return ;
    }

    int nLen = m_RdWrUnit * 9 ;
    if(nLen > nSize)
        nLen = nSize ;

    QByteArray buf = m_writeBuf.left(nLen) ;
    m_writeBuf.remove(0,nLen) ;

    quint32 nAddr = m_writeAddr ;
    m_writeAddr += m_RdWrUnit ;
    m_pCOMDlg->writeRamData(nAddr,buf.data(),nLen,this) ;
}

void FrameRamManager::readHugeRam()
{
    int nSize = m_readCount ;
    if(nSize <= 0)
    {
        if(m_bReadFromOut)
            m_pCOMDlg->notifyReadHugeRamDone(m_writeBuf) ;
        m_bReadFromOut = false ;
        return ;
    }

    quint32 nAddr = m_readAddr ;
    int nLen = m_RdWrUnit  ;
    if(nLen > nSize)
        nLen = nSize ;
    m_readCount -= m_RdWrUnit;
    m_readAddr  += m_RdWrUnit;

    m_pCOMDlg->readRamData(nAddr,nLen * 9,this) ;
}

void FrameRamManager::on_pushButtonReLoad_clicked()
{
    QString strFile = ui->lineEditFileName->text() ;
    loadDataFromFile(strFile) ;
}

void FrameRamManager::readHugeRamOutside(quint32 nAddr,quint32 nLen)
{
    if(m_bWriteFromOut)
        return ;

    m_writeBuf.clear() ;
    m_bReadFromOut = true ;
    int nCount = nLen/9 ;
    if(nLen%9)
        nCount ++ ;
    m_readAddr  = nAddr;
    m_readCount = nCount ;
    readHugeRam() ;
}

void FrameRamManager::writeHugeRamOutside(quint32 nAddr,const QByteArray&ramData)
{
    if(m_bReadFromOut)
        return ;

    m_bWriteFromOut = true ;
    m_writeAddr = nAddr ;
    m_writeBuf = ramData;
    int nLen = ramData.size() ;
    int nTail = nLen%9 ;
    if(nTail)
    {
        char szTail[20]={0} ;
        m_writeBuf.append(szTail,9-nTail);
    }

    writeHugeRam() ;
}

