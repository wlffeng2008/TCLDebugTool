#include "SerialTestDialog.h"
#include "ui_SerialTestDialog.h"
#include "DialogToast.h"

#include <QSerialPortInfo>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QEvent>
#include <QByteArray>
#include <QMessageBox>

static quint8 nPackIndex = 0 ;

static QByteArray makeDebugPack(qint8 nType,qint32 nAddr,qint16 nLen,const char *pData)
{
    QByteArray pack ;
    quint16 nHead= HEAD_SEND;
    pack.append((char *)&nHead,2) ;
    pack.append(nPackIndex) ;
    pack.append(nType) ;
    pack.append((char *)&nAddr,4) ;
    pack.append((char *)&nLen,2) ;

    if(nType == TYPE_REG_READ || nType == TYPE_RAM_READ)
    {
        pack.append((char)0) ;
    }
    else
    {
        if(pData && nLen)
           pack.append(pData,nLen) ;
    }

    char *ptoCheck = pack.data() ;
    int nCount = pack.size() ;
    quint32 checkSum = 0 ;
    for(int i=2; i<nCount; i++ )
        checkSum += (quint8)ptoCheck[i] ;
    pack.append((char *)&checkSum,4) ;

    nPackIndex ++;

    return pack ;
}

void SerialTestDialog::setPackIndex(quint8 nIndex)
{
    nPackIndex = nIndex ;
}

quint8 SerialTestDialog::getPackIndex()
{
    return nPackIndex ;
}

static QSettings *g_set = nullptr;

static SerialTestDialog *g_pCOMDlg = nullptr;

SerialTestDialog* SerialTestDialog::getInstance()
{
    return  g_pCOMDlg;
}

QString SerialTestDialog::getDataPath()
{
    return g_pCOMDlg->dataPath();
}

QString SerialTestDialog::getModel()
{
    return g_pCOMDlg->model();
}

sPackHeader *SerialTestDialog::GetDataHead()
{
    sPackHeader *pHeader = (sPackHeader *)m_buf.data() ;
    return pHeader ;
}

quint8 *SerialTestDialog::GetDataBody()
{
    quint8 *pData = (quint8 *)(m_buf.data()) ;
    return (pData + 10) ;
}


SerialTestDialog::SerialTestDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SerialTestDialog)
{
    ui->setupUi(this);
    setWindowFlags((windowFlags() | Qt::MSWindowsFixedSizeDialogHint) & ~Qt::WindowContextHelpButtonHint);
    g_pCOMDlg = this ;

    g_set = new QSettings(QCoreApplication::applicationDirPath() + "/DebugToolCOM.ini",QSettings::IniFormat) ;
    ui->pushButtonLog->setIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation)) ;

    m_pLogDlg = new DialogLogView(nullptr) ;

    m_pCOM = new GenComport(this) ;

    m_model = new QStandardItemModel();
    m_model->setHorizontalHeaderLabels({"串口命令列表", "备注"});
    ui->tableView->setModel(m_model);

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(1,QHeaderView::Fixed);
    header->resizeSection(1,100) ;

    ui->tableView->setShowGrid(false);

    LoadCmdFile(g_set->value("lastFile").toString().trimmed()) ;

    connect(ui->tableView,&QAbstractItemView::clicked,this,[=](const QModelIndex&index){
        m_nCurRow = index.row() ;
        QStandardItem *item =  m_model->item(index.row());
        ui->textEditCommand->setText(item->text().trimmed()) ;
    });

    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this,[=](const QItemSelection &selected, const QItemSelection &deselected){
        Q_UNUSED(deselected)
        QModelIndexList selectedIndexes = selected.indexes();
        QModelIndex&index = selectedIndexes[0] ;
        QStandardItem *item =  m_model->item(index.row());
        ui->textEditCommand->setText(item->text().trimmed()) ;

        m_nCurRow = index.row() ;
    });

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(m_pCOM,&GenComport::onReceive,this,[=](const QByteArray &data){
        if(!m_bCOMConnected)
        {
            quint8 *pData = (quint8 *)data.data() ;
            sPackHeader *pHD = (sPackHeader *)pData ;
            if(data.size() == 15 && pHD->type == TYPE_REG_READ && pHD->head == HEAD_RECV)
            {
                m_bCOMConnected = true ;
                updateCOMStatus() ;
            }
            else
            {
                QString strInfo = "握手失败，请切换COM口后重试！" ;
                m_pLogDlg->pushLogText(strInfo) ;
                QMessageBox::warning(this,"提示",strInfo) ;
            }

            return ;
        }

        m_buf.append(data) ;
        m_ReplyTM.stop() ;

        int nSize = m_buf.size() ;

        if( nSize < 15 )
            return;

        quint32 nSum   = 0 ;
        quint32 nCheck = *(quint32 *)m_buf.right(4).data() ;
        for(int i=2; i<nSize - 4; i++)
            nSum += (quint8)m_buf[i] ;

        sPackHeader *pHD = GetDataHead() ;

        quint8 nType = pHD->type ;

        if(nType == TYPE_REG_READ || nType == TYPE_RAM_READ)
        {
            if(pHD->len + 10 + 4 == nSize)
            {
                if( nSum != nCheck )
                {
                    QMessageBox::critical(nullptr,"提示","数据读取校验失败！") ;
                }
            }
        }

        if( nSum == nCheck )
        {
            if(nSize == 15 && (nType == TYPE_REG_WRITE || nType == TYPE_RAM_WRITE))
            {
                m_bWriteOK = (0x50 == (quint8)m_buf[10]) ;

                if(ui->checkBoxWriteNotify->isChecked() && m_pSender)
                {
                    m_TMWriteNotify.stop() ;
                    m_TMWriteNotify.start(200) ;
                }
            }

            m_pLogDlg->pushLogText(m_buf.toHex(' ').toUpper(),false) ;
            emit COMDataIn(m_buf,m_pSender);

            static QEvent Notify(QEvent::User) ;
            if(m_pSender) m_pSender->eventFilter(nullptr,&Notify) ;
        }
    });

    connect(&m_TMWriteNotify,&QTimer::timeout,this,[=](){
        m_TMWriteNotify.stop() ;

        if(m_bWriteOK)
            toast(this)->active("数据写入成功！",600) ;
        else
            QMessageBox::critical(nullptr,"提示","数据写入失败！") ;
    });

    connect(&m_ReplyTM,&QTimer::timeout,this,[=](){
        m_ReplyTM.stop() ;
        m_pLogDlg->pushLogText("设备应答超时!") ;
        if(ui->checkBoxReply->isChecked())
        {
            emit COMReplyTimeout();
            static QEvent Notify((QEvent::Type)(QEvent::User+1)) ;

            if(m_pSender) m_pSender->eventFilter(nullptr,&Notify) ;
            QMessageBox::critical(nullptr,"提示","设备应答超时!") ;
        }
    });

    QString strCOM  = g_set->value("lastCOM","COM1").toString().trimmed() ;
    QString strBaud = g_set->value("lastBaud","115200").toString().trimmed() ;
    QString strData = g_set->value("lastData","8").toString().trimmed() ;
    int nStop       = g_set->value("lastStop",0).toInt() ;
    int nParity     = g_set->value("lastParity",0).toInt()  ;
    int nFlow       = g_set->value("lastFlow",0).toInt()  ;

    int nCount = ui->comboBoxCOM->count() ;
    for(int i=0; i<nCount; i++)
    {
        if(ui->comboBoxCOM->itemText(i).startsWith(strCOM))
        {
            ui->comboBoxCOM->setCurrentIndex(i);
            break;
        }
    }

    ui->comboBoxBaud->setCurrentText(strBaud);
    ui->comboBoxData->setCurrentText(strData);

    ui->comboBoxStop->setCurrentIndex(nStop);
    ui->comboBoxParity->setCurrentIndex(nParity);
    ui->comboBoxFlow->setCurrentIndex(nFlow);
    ui->checkBoxHexCmd->setChecked(true);
    ui->checkBoxAutoCnnt->setChecked(g_set->value("autoConnect",false).toBool());
    ui->checkBoxHexData->setChecked(true);
    ui->radioButtonRegRead->setChecked(true);

    ui->checkBoxReply->setChecked(g_set->value("replyNotify",true).toBool());
    ui->lineEditReply->setText(g_set->value("replyTimeout",1500).toString());
    ui->checkBoxWriteNotify->setChecked(g_set->value("writeNotify",true).toBool());
    ui->checkBoxHandShake->setChecked(g_set->value("handShake",false).toBool());

    QTimer::singleShot(500,this,[=]{ m_pRamReader = FrameRamManager::getInstance(); });

    on_pushButtonScan_clicked();
    on_radioButtonRegRead_clicked();
    updateCOMStatus() ;

    connect(ui->checkBoxReply,&QCheckBox::clicked,this,[=]{ saveSetting(); });
    connect(ui->checkBoxWriteNotify,&QCheckBox::clicked,this,[=]{ saveSetting(); });
    connect(ui->checkBoxHandShake,&QCheckBox::clicked,this,[=]{ saveSetting(); });
    connect(ui->checkBoxAutoCnnt,&QCheckBox::clicked,this,[=]{ saveSetting(); });
}

SerialTestDialog::~SerialTestDialog()
{
    delete ui;
}

void SerialTestDialog::setModel(const QString &strModel)
{
    m_strCurModel = strModel ;
    QString strPath = QCoreApplication::applicationDirPath() + "/data/" ;
    QDir a(strPath);
    if(!a.exists()) a.mkdir(strPath) ;

    strPath += strModel ;
    QDir b(strPath);
    if(!b.exists()) b.mkdir(strPath) ;

    strPath += '/' ;
    m_strDataPath = strPath ;

    emit COMModelChanged(strModel);
}

bool SerialTestDialog::readRegData(quint32 nAddr, int nLen,QWidget *pSender)
{
    m_pSender = pSender ;
    QString strData = makeDebugPack(TYPE_REG_READ,nAddr,nLen,nullptr).toHex(' ').toUpper() ;
    return sendCommand(strData) ;
}

bool SerialTestDialog::writeRegData(quint32 nAddr, const char *data, int nLen,QWidget *pSender)
{
    m_pSender = pSender ;
    QString strData = makeDebugPack(TYPE_REG_WRITE,nAddr,nLen,data).toHex(' ').toUpper() ;
    return sendCommand(strData) ;
}

bool SerialTestDialog::readRamData(quint32 nAddr, int nLen,QWidget *pSender)
{
    m_pSender = pSender ;
    QString strData = makeDebugPack(TYPE_RAM_READ,nAddr,nLen,nullptr).toHex(' ').toUpper() ;
    return sendCommand(strData) ;
}

bool SerialTestDialog::writeRamData(quint32 nAddr, const char *data, int nLen,QWidget *pSender)
{
    m_pSender = pSender ;
    QString strData = makeDebugPack(TYPE_RAM_WRITE,nAddr,nLen,data).toHex(' ').toUpper() ;
    return sendCommand(strData) ;
}

void SerialTestDialog::sendInt8(quint32 addr, quint8 Byte, QWidget *pSender)
{
    m_pSender = pSender;
    char buf[8] = {0} ;
    buf[0] = Byte ;
    writeRegData(addr,buf,1,pSender) ;
}

void SerialTestDialog::sendSwitch(quint32 addr, bool bOn, QWidget *pSender)
{
    sendInt8(addr,bOn?1:0,pSender) ;
}

void SerialTestDialog::sendInt16(quint32 addr, quint16 value, QWidget *pSender)
{
    m_pSender = pSender;
    char buf[8] = {0} ;
    *(quint16 *)buf = value ;
    writeRegData(addr,buf,2,pSender) ;
}

void SerialTestDialog::sendInt32(quint32 addr, quint32 value, QWidget *pSender)
{
    m_pSender = pSender;
    char buf[8] = {0} ;
    *(quint32 *)buf = value ;
    writeRegData(addr,buf,4,pSender) ;
}

void SerialTestDialog::sendInt64(quint32 addr, quint64 value, QWidget *pSender)
{
    m_pSender = pSender;
    char buf[12] = {0} ;
    *(quint64 *)buf = value ;
    writeRegData(addr,buf,8,pSender) ;
}

void SerialTestDialog::readHugeRam(quint32 nAddr,quint32 nLen, QWidget *pSender)
{
    m_pHugeRamReader = pSender;
    m_pRamReader->readHugeRamOutside(nAddr,nLen) ;
}

void SerialTestDialog::writeHugeRam(quint32 nAddr,const QByteArray&ramData, QWidget *pSender)
{
    m_pHugeRamReader = pSender;
    m_pRamReader->writeHugeRamOutside(nAddr,ramData) ;
}

void SerialTestDialog::notifyReadHugeRamDone(const QByteArray&ramData)
{
    emit COMReadHugeRamDone(ramData,m_pHugeRamReader) ;
}

void SerialTestDialog::notifyWriteHugeRamDone()
{
    emit COMWriteHugeRamDone(m_pHugeRamReader) ;
}


bool SerialTestDialog::isConnected(bool showBox)
{
    if(!m_bCOMConnected)
    {
        if(showBox)
            QMessageBox::warning(this,"提示","串口尚未打开（连接）！") ;
        else
            toast()->active("串口尚未打开（连接）！");
        return false ;
    }

    return m_bCOMConnected ;
}


void SerialTestDialog::LoadCmdFile(const QString&strFile)
{
    while(m_model->rowCount())
        m_model->removeRow(0);

    QStringList cmdList ;
    QStringList memoList ;

    {
        QFile fileCmd(strFile);
        if (fileCmd.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            m_strCurFile = strFile ;
            setWindowTitle("串口测试 [命令文件: "  + strFile + "]");
            g_set->setValue("lastFile",strFile) ;
            QTextStream in(&fileCmd);

            while (!in.atEnd()) cmdList << in.readLine().trimmed();
            fileCmd.close();
        }
    }
    {
        QFile fileMemo(strFile + ".memo.txt");
        if (fileMemo.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&fileMemo);

            while (!in.atEnd()) memoList << in.readLine().trimmed();
            fileMemo.close();
        }
    }

    if(cmdList.isEmpty())
    {
        cmdList << "55 D5 28 11 01 00 00 00 1B 00 00 55 00 00 00";
        cmdList << "start_set_factory_info";
        cmdList << "factory_set_wifi Redmi_7325 qqqqqqqq";
        cmdList << "factory_set_server 47.106.117.102 3736";
        cmdList << "factory_set_mqtt tanshi tanshi987123";
        cmdList << "factory_set_work_pos_id 6688";
        cmdList << "stop_set_factory_info";
    }

    int i = 0 ;
    foreach (const QString &strCmd, cmdList)
    {
        QStandardItem *item0 = new QStandardItem(strCmd);
        item0->setCheckable(true) ;
        item0->setCheckState(Qt::Checked) ;

        QStandardItem *item1 = new QStandardItem("备注");

        QList<QStandardItem *> items={item0,item1};
        m_model->appendRow(items) ;
    }

    i = 0;
    foreach (const QString &strMomo, memoList)
    {
        QStandardItem *item = m_model->item(i++,1);
        if(item)
            item->setText(strMomo) ;
    }
}

void SerialTestDialog::on_pushButtonScan_clicked()
{
    m_bScanCOM = true ;

    ui->comboBoxCOM->clear() ;
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &SPI, serialPortInfos)
    {
        QString strCOM = QString("%1 - %2(%3)").arg(SPI.portName(),SPI.description(),SPI.manufacturer()) ;
        ui->comboBoxCOM->addItem(strCOM) ;
    }

    if(serialPortInfos.count()>0)
    {
        QString strCOM = g_set->value("lastCOM").toString().trimmed() ;
        if(!strCOM.isEmpty())
        {
            int nCount = ui->comboBoxCOM->count();
            for(int i=0; i<nCount; i++)
            {
                if(ui->comboBoxCOM->itemText(i).startsWith(strCOM))
                {
                    ui->comboBoxCOM->setCurrentIndex(i) ;
                    break;
                }
            }
        }
    }

    m_bScanCOM = false ;

    ui->checkBoxOpen->setChecked(ui->checkBoxAutoCnnt->isChecked()) ;

    QTimer::singleShot(200,this,[=]{ on_checkBoxOpen_clicked() ; });
}

void SerialTestDialog::on_checkBoxOpen_clicked()
{
    m_pCOM->closePort() ;
    m_bCOMConnected = false ;

    bool bToOpen = ui->checkBoxOpen->isChecked() ;
    if(bToOpen && ui->comboBoxCOM->count()>0)
    {
        QString strCOM = ui->comboBoxCOM->currentText().trimmed() ;

        int nIndex = strCOM.indexOf('-') ;
        if(nIndex > 2)
        {
            strCOM = strCOM.left(nIndex).trimmed() ;

            int nBaud = ui->comboBoxBaud->currentText().toInt() ;
            int nData = ui->comboBoxData->currentText().toInt() ;
            int nStop = ui->comboBoxStop->currentIndex();
            int nParity = ui->comboBoxParity->currentIndex() ;
            int nFlow = ui->comboBoxFlow->currentIndex();

            g_set->setValue("lastCOM",strCOM) ;

            m_pCOM->setPortParam(nBaud,nData,nStop,nParity,nFlow) ;
            m_pCOM->setPortName(strCOM) ;

            saveSetting() ;
        }
    }
    updateCOMStatus() ;
}

void SerialTestDialog::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(
        nullptr,
        "请选择串口命令文件",
        "",
        "文本文件 (*.txt);;All Files (*.*)"
        );
    if( strFile.isEmpty() )
        return ;

    m_strCurFile = strFile;
}


void SerialTestDialog::on_pushButtonSave_clicked()
{
    if(m_strCurFile.isEmpty())
    {
        on_pushButtonSaveAs_clicked() ;
        return  ;
    }

    QFile fileCmd( m_strCurFile );
    if( fileCmd.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        QFile fileMemo( m_strCurFile + ".memo.txt" );
        fileMemo.open( QIODevice::WriteOnly| QIODevice::Text) ;

        QTextStream out0(&fileCmd);
        QTextStream out1(&fileMemo);

        int nCount = m_model->rowCount();
        for(int i=0; i<nCount; i++)
        {
            QStandardItem *item0=  m_model->item(i);
            QString strLine = item0->text().trimmed() + "\n" ;
            out0 << strLine;

            QStandardItem *item1 =  m_model->item(i,1);
            strLine = item1->text().trimmed() + "\n" ;
            out1 << strLine ;
        }

        fileCmd.close() ;
        fileMemo.close() ;

        QMessageBox::information(this,"提示","串口命令文件保存 成功！\n" + m_strCurFile) ;
    }
}


void SerialTestDialog::on_pushButtonSaveAs_clicked()
{
    QString strFile = QFileDialog::getSaveFileName(
        nullptr,
        "请选择串口命令文件",
        "",
        "文本文件 (*.txt);;All Files (*.*)"
        );
    if( strFile.isEmpty() )
        return ;

    m_strCurFile = strFile;    
    setWindowTitle("串口测试 [命令文件: "  + strFile + "]");

    g_set->setValue("lastFile",strFile) ;
    on_pushButtonSave_clicked() ;
}

void SerialTestDialog::on_pushButtonHide_clicked()
{
    this->hide() ;
}

void SerialTestDialog::updateCOMStatus()
{
    if(m_pCOM && m_pCOM->isOpen())
    {
        nPackIndex = 0 ;
        if(ui->checkBoxHandShake->isChecked())
        {
            if(!m_bCOMConnected)
            {
                qDebug() << "send HandShak";
                m_pCOM->send("55 D5 00 01 00 00 00 00 01 00 00 02 00 00 00",false); // 握手
                return ;
            }
        }

        m_bCOMConnected = true ;
        QString strInfo = m_pCOM->getPortName() + " 已打开";
        ui->labelStatus->setText(strInfo) ;
        ui->labelStatus->setStyleSheet("QLabel{color: green;}") ;
        m_pLogDlg->pushLogText(strInfo);
        emit COMStatusChanged(true) ;
        return;
    }

    ui->labelStatus->setText("串口未打开") ;
    ui->labelStatus->setStyleSheet("QLabel{color: red;}") ;

    emit COMStatusChanged(m_bCOMConnected) ;
}

void SerialTestDialog::on_comboBoxCOM_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    if(ui->checkBoxOpen->isChecked() && !m_bScanCOM)
        on_checkBoxOpen_clicked() ;
}

bool SerialTestDialog::sendCommand(const QString&strCmd)
{
    if(strCmd.isEmpty())
    {
        return false ;
    }

    if(!isConnected(false))
    {
        qCritical() <<"COM not open!" << time(nullptr) ;
        return false;
    }

    m_buf.clear() ;
    if(m_pCOM && m_pCOM->isOpen())
    {
        m_strLastCmd = strCmd ;
        m_ReplyTM.start(ui->lineEditReply->text().trimmed().toInt()) ;
        m_pLogDlg->pushLogText(strCmd) ;
        m_pCOM->send(strCmd, !ui->checkBoxHexCmd->isChecked()) ;
        return true ;
    }
    return false ;
}


void SerialTestDialog::on_pushButtonSend_clicked()
{
    m_pSender = nullptr ;
    QString strCmd = ui->textEditCommand->toPlainText().trimmed() ;
    sendCommand(strCmd);
}


void SerialTestDialog::on_pushButtonNew_clicked()
{
    QString strCmd = ui->textEditCommand->toPlainText().trimmed() ;
    QList<QStandardItem *> items;
    QStandardItem *item1 = new QStandardItem(strCmd);
    item1->setCheckable(true) ;
    item1->setCheckState(Qt::Checked) ;
    items.append(item1);

    QStandardItem *item2 = new QStandardItem("");
    items.append(item2);

    m_model->appendRow(items) ;
}


void SerialTestDialog::on_pushButtonDel_clicked()
{
    if(m_nCurRow != -1)
    {
        m_model->removeRow(m_nCurRow);
        m_nCurRow = -1 ;
    }
}

void SerialTestDialog::makePack()
{
    int nLen  = ui->lineEditLen->text().toInt() ;
    int nAddr = ui->lineEditAddr->text().toInt(nullptr,16) ;

    QByteArray buf ;
    if(m_nMakeType == TYPE_REG_WRITE || m_nMakeType == TYPE_RAM_WRITE)
    {
        QString strBuf = ui->lineEditWrite->text() ;
        if(ui->checkBoxHexData->isChecked())
        {
            strBuf.replace("0x","") ;
            strBuf.replace("0X","") ;
            buf.append(QByteArray::fromHex(strBuf.toLatin1())) ;
        }
        else
        {
            buf.append(strBuf.toUtf8()) ;
        }

        nLen = buf.size();
        ui->lineEditLen->setText(QString::number(nLen)) ;
    }

    m_bCanMakePack = false ;
    ui->spinBoxPackIndex->setValue(nPackIndex) ;
    QTimer::singleShot(200,this,[=]{m_bCanMakePack = true ;}) ;
    QString strCmd = makeDebugPack(m_nMakeType,nAddr,nLen,buf.data()).toHex(' ').toUpper() ;
    ui->textEditCommand->setText(strCmd) ;
}

void SerialTestDialog::on_radioButtonRegRead_clicked()
{
    ui->lineEditLen->setDisabled(false) ;
    m_nMakeType = TYPE_REG_READ ;
    makePack() ;
}

void SerialTestDialog::on_radioButtonRegWrite_clicked()
{
    ui->lineEditLen->setDisabled(true) ;
    m_nMakeType = TYPE_REG_WRITE ;
    makePack() ;
}

void SerialTestDialog::on_radioButtonRamRead_clicked()
{
    ui->lineEditLen->setDisabled(false) ;
    m_nMakeType = TYPE_RAM_READ ;
    makePack() ;
}

void SerialTestDialog::on_radioButtonRamWrite_clicked()
{
    ui->lineEditLen->setDisabled(true) ;
    m_nMakeType = TYPE_RAM_WRITE ;
    makePack() ;
}

void SerialTestDialog::on_lineEditAddr_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    makePack() ;
}

void SerialTestDialog::on_lineEditLen_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    makePack() ;
}

void SerialTestDialog::on_pushButtonLog_clicked()
{
    m_pLogDlg->showNormal() ;
}

void SerialTestDialog::saveSetting()
{
    g_set->setValue("replyNotify",ui->checkBoxReply->isChecked())  ;
    g_set->setValue("replyTimeout",ui->lineEditReply->text().toInt())  ;
    g_set->setValue("writeNotify",ui->checkBoxWriteNotify->isChecked())  ;
    g_set->setValue("handShake",ui->checkBoxHandShake->isChecked())  ;
    int nBaud = ui->comboBoxBaud->currentText().toInt() ;
    int nData = ui->comboBoxData->currentText().toInt() ;
    int nStop = ui->comboBoxStop->currentIndex();
    int nParity = ui->comboBoxParity->currentIndex() ;
    int nFlow = ui->comboBoxFlow->currentIndex();

    //g_set->setValue("lastCOM",strCOM) ;
    g_set->setValue("lastBaud",nBaud) ;
    g_set->setValue("lastData",nData) ;
    g_set->setValue("lastStop",nStop) ;
    g_set->setValue("lastParity",nParity) ;
    g_set->setValue("lastFlow",nFlow) ;
    g_set->setValue("autoConnect",ui->checkBoxAutoCnnt->isChecked()) ;
}

void SerialTestDialog::on_lineEditReply_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    saveSetting();
}

void SerialTestDialog::on_lineEditWrite_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    makePack() ;
}

void SerialTestDialog::on_checkBoxHexData_clicked()
{
    makePack() ;
    saveSetting();
}


bool SerialTestDialog::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if (msg->message == WM_DEVICECHANGE)
    {
        switch (msg->wParam)
        {
        case DBT_DEVICEARRIVAL:
            qDebug() << "USB设备已插入";
            OnUSBChanged() ;
            break;

        case DBT_DEVICEREMOVECOMPLETE:
            qDebug() << "USB设备已拔出";
            OnUSBChanged();
            break;
        }
    }
    return QDialog::nativeEvent(eventType, message, result);
}

void SerialTestDialog::OnUSBChanged()
{
    ui->pushButtonScan->click() ;
}


void SerialTestDialog::on_spinBoxPackIndex_valueChanged(int arg1)
{
    nPackIndex = arg1 ;
    if(!m_bCanMakePack)
        return ;
    makePack() ;
}

