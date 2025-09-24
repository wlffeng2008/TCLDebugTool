#include "FrameEPCCBOOST.h"
#include "ui_FrameEPCCBOOST.h"

#include <QFile>
#include <QPainter>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <cmath>

FrameEPCCBOOST::FrameEPCCBOOST(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameEPCCBOOST)
{
    ui->setupUi(this);
    m_pCOMDlg = SerialTestDialog::getInstance() ;

    connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](const QString&strModel){
        Q_UNUSED(strModel)
        SaveLoadTable(false) ;

        //LoadBuf(m_pCOMDlg->getDataPath() + "/APL20250626_85QD_epcc_mode0_12b_to_12b_ok.csv",false) ;
        //LoadBuf(m_pCOMDlg->getDataPath() + "/APL20250626_85QD_epcc_mode1_12b_to_12b_ok.csv",true) ;
    });

    m_pModel4 = new QStandardItemModel(this) ;
    m_pModel4->setHorizontalHeaderLabels({"","全白","L32","过驱","拐点","上限"});
    ui->tableView4->setModel(m_pModel4) ;

    m_pModel4->appendRow({  new QStandardItem("W"),
                            new QStandardItem("1.780"),
                            new QStandardItem("7.200"),
                            new QStandardItem("11.100"),
                            new QStandardItem("4.500"),
                            new QStandardItem("4.500")}) ;

    m_pModel4->appendRow({  new QStandardItem("R"),
                          new QStandardItem("5.200"),
                          new QStandardItem("21.300"),
                          new QStandardItem("32.500"),
                          new QStandardItem("9.690"),
                          new QStandardItem("9.690")}) ;

    m_pModel4->appendRow({  new QStandardItem("G"),
                          new QStandardItem("2.280"),
                          new QStandardItem("9.300"),
                          new QStandardItem("14.200"),
                          new QStandardItem("13.500"),
                          new QStandardItem("13.500")}) ;

    m_pModel4->appendRow({  new QStandardItem("B"),
                          new QStandardItem("1.780"),
                          new QStandardItem("7.200"),
                          new QStandardItem("11.100"),
                          new QStandardItem("4.500"),
                          new QStandardItem("4.500")}) ;


    m_pModel5 = new QStandardItemModel(this) ;
    m_pModel5->setHorizontalHeaderLabels({"","","","","",""});
    ui->tableView5->setModel(m_pModel5) ;

    m_pModel5->appendRow({new QStandardItem("R/B"),new QStandardItem("1.00"),new QStandardItem("1.00"),new QStandardItem("1.00")});
    m_pModel5->appendRow({new QStandardItem("G/B"),new QStandardItem("1.00"),new QStandardItem("1.00"),new QStandardItem("1.00")});
    m_pModel5->appendRow({new QStandardItem("B/B"),new QStandardItem("1.00"),new QStandardItem("1.00"),new QStandardItem("1.00")});

    m_pModel6 = new QStandardItemModel(this) ;
    m_pModel6->setHorizontalHeaderLabels({"","I_low","I_max","I_boost","I_拐点","I_limit"});
    ui->tableView6->setModel(m_pModel6) ;

    ui->tableView4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView4->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView5->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView6->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    m_pModel6->appendRow({new QStandardItem("W"),
                          new QStandardItem("137"),
                          new QStandardItem("704"),
                          new QStandardItem("1408"),
                          new QStandardItem("448"),
                          new QStandardItem("1408")}) ;

    m_pModel6->appendRow({new QStandardItem("R"),
                          new QStandardItem("328"),
                          new QStandardItem("1687"),
                          new QStandardItem("3370"),
                          new QStandardItem("896"),
                          new QStandardItem("3370")}) ;

    m_pModel6->appendRow({new QStandardItem("G"),
                          new QStandardItem("177"),
                          new QStandardItem("914"),
                          new QStandardItem("1826"),
                          new QStandardItem("576"),
                          new QStandardItem("1826")}) ;

    m_pModel6->appendRow({new QStandardItem("B"),
                          new QStandardItem("137"),
                          new QStandardItem("704"),
                          new QStandardItem("1408"),
                          new QStandardItem("448"),
                          new QStandardItem("1408")}) ;

    m_pModel4->item(0,0)->setEditable(false);
    m_pModel4->item(1,0)->setEditable(false);
    m_pModel4->item(2,0)->setEditable(false);
    m_pModel4->item(3,0)->setEditable(false);
    m_pModel6->item(0,0)->setEditable(false);
    m_pModel6->item(1,0)->setEditable(false);
    m_pModel6->item(2,0)->setEditable(false);
    m_pModel6->item(3,0)->setEditable(false);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            QStandardItem *item0 = m_pModel5->item(i,j);
            item0->setEditable(false) ;
        }
    }

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        quint8 *pData = (quint8 *)data.data() ;
        sPackHeader *pHD = (sPackHeader *)pData ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            SaveLoadTable() ;
            return ;
        }

        char szLine[20] = {0};
        quint8 *pSub = pData + 10 ;

        SaveLoadTable() ;
    });


    connect(ui->pushButtonLoad,&QPushButton::clicked,this,[=](){
    });

    connect(ui->pushButtonSave,&QPushButton::clicked,this,[=](){
    });

    connect(ui->radioButton1,&QRadioButton::clicked,this,[=](){ m_addr = ( 9<<13); doCalc(); });
    connect(ui->radioButton2,&QRadioButton::clicked,this,[=](){ m_addr = (10<<13); doCalc(); });

    connect(ui->radioButtonMode1,&QRadioButton::clicked,this,[=](){ doCalc(); });
    connect(ui->radioButtonMode2,&QRadioButton::clicked,this,[=](){ doCalc(); });

    connect(m_pModel4,&QStandardItemModel::itemChanged,this,[=](QStandardItem *item){ doCalc();}) ;
    connect(ui->lineEditMaxI,&QLineEdit::textChanged,this,[=](const QString&text){doCalc();}) ;
    connect(ui->lineEditMinI,&QLineEdit::textChanged,this,[=](const QString&text){doCalc();}) ;
    connect(ui->comboBoxBits,&QComboBox::currentTextChanged,this,[=](const QString &){doCalc();});

    connect(ui->pushButtonRead,&QPushButton::clicked,this,[=]{
        // if(!ui->checkBox109D->isChecked())
        // {
        //     QMessageBox::warning(this,"提示","请打开： 0x109D");
        //     return ;
        // }
        m_pCOMDlg->readHugeRam(m_addr, 4096*9, this);
    });
    connect(ui->pushButtonWrite,&QPushButton::clicked,this,[=]{
        // if(!ui->checkBox109D->isChecked())
        // {
        //     QMessageBox::warning(this,"提示","请打开： 0x109D");
        //     return ;
        // }

        QByteArray buf ;
        char szBuf[20]={0} ;
        int nCount = 4096;//m_pDModel->rowCount();
        for(int i=0; i<nCount; i++)
        {
            quint16 nValue = 0;//m_pDModel->item(i,1)->text().trimmed().toInt();
            *(quint16 *)szBuf = nValue ;
            buf.append(szBuf,9) ;
        }

        m_pCOMDlg->writeHugeRam(m_addr,buf,this) ;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMReadHugeRamDone,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        quint8 *pData = (quint8 *)data.data() ;
        for(int i=0; i<4096; i++)
        {
            quint16 nValue = *(quint16*)(pData + i * 9);
            ui->framePanel->setBuf(0,i,nValue) ;
        }
        ui->framePanel->update() ;
    });

    doCalc() ;
}

FrameEPCCBOOST::~FrameEPCCBOOST()
{
    delete ui;
}

void FrameEPCCBOOST::doCalc()
{
    if(ui->radioButton2->isChecked())
    {
        char szValue[20]={0} ;
        for(int i=1; i<4; i++)
        {
            qreal RVal = m_pModel4->item(1,i)->text().toFloat() ;
            qreal GVal = m_pModel4->item(2,i)->text().toFloat() ;
            qreal BVal = m_pModel4->item(3,i)->text().toFloat() ;

            sprintf(szValue,"%.2f",RVal/BVal);
            m_pModel5->item(0,i)->setText(szValue) ;

            sprintf(szValue,"%.2f",GVal/BVal);
            m_pModel5->item(1,i)->setText(szValue) ;
        }
    }
    else
    {
        for(int i=0; i<2; i++)
        {
            for(int j=1; j<4; j++)
            {
                m_pModel5->item(i,j)->setText("1.00") ;
            }
        }
    }

    bool bEnable = ui->radioButton2->isChecked();
    for(int i=1; i<4; i++)
    {
        for(int j=0; j<6; j++)
        {
            QStandardItem *item0 = m_pModel4->item(i,j);
            QStandardItem *item1 = m_pModel6->item(i,j);

            item0->setSelectable(bEnable) ;
            item1->setSelectable(bEnable) ;

            item0->setEnabled(bEnable);
            item1->setEnabled(bEnable);

            item0->setForeground(QBrush(bEnable?Qt::black:Qt::lightGray));
            item1->setForeground(QBrush(bEnable?Qt::black:Qt::lightGray));
        }
    }


    int nCount = 64 ;
    if(ui->comboBoxBits->currentIndex() == 0)
        nCount = 16 ;
    if(ui->comboBoxBits->currentIndex() == 2)
        nCount = 256 ;

    qreal Imin = ui->lineEditMinI->text().trimmed().toDouble() ;
    qreal Imax = ui->lineEditMaxI->text().trimmed().toDouble() ;
    qreal IStep = (Imax - Imin) / nCount;

    for(int i=0; i<4; i++)
    {
        qreal I_whI = m_pModel4->item(i,1)->text().toDouble() ;
        qreal I_l32I= m_pModel4->item(i,2)->text().toDouble() ;
        qreal I_gqI = m_pModel4->item(i,3)->text().toDouble() ;
        qreal I_infI= m_pModel4->item(i,4)->text().toDouble() ;

        qreal I_inf   = floor(I_infI)    / IStep * 64;
        qreal I_low   = (I_whI / I_infI) * I_inf     ;
        qreal I_max   = (I_l32I - Imin)  / IStep * 64;
        qreal I_boost = (I_gqI - Imin)   / IStep * 64;

        if(ui->radioButtonMode2->isChecked())
        {
            I_inf = (I_infI/ Imax) * 4095;
            I_low = (I_whI / Imax) * 4095 ;
            I_max = (I_l32I/ Imax) * 4095;
            I_boost=(I_gqI / Imax) * 4095;
        }

        m_pModel6->item(i,1)->setText(QString::number((int)I_low)) ;
        m_pModel6->item(i,2)->setText(QString::number((int)I_max)) ;
        m_pModel6->item(i,3)->setText(QString::number((int)I_boost)) ;
        m_pModel6->item(i,4)->setText(QString::number((int)I_inf)) ;
        m_pModel6->item(i,5)->setText(QString::number((int)I_boost)) ;
    }

    {
        int bl_apl_i_low_value = 4095 ;
        qreal I_low = m_pModel6->item(3,1)->text().toFloat() ;
        qreal I_boost = m_pModel6->item(3,3)->text().toFloat() ;

        for(int apl=0; apl <= bl_apl_i_low_value; apl++)
        {
            qreal value = 0 ;
            if(apl <= 10)
            {
                value = I_boost;
            }
            else
            {
                value = I_low * bl_apl_i_low_value / apl ;
            }
            if(value>I_boost)
                value = I_boost;

            if(value>4095)
                value = 4095;
            ui->framePanel->setBuf(1,apl,value) ;
        }
        ui->framePanel->update() ;
    }
}

void FrameEPCCBOOST::LoadBuf(const QString&strFile,bool bForLinar)
{
    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << strFile  << __FILE__ << __LINE__;
        return ;
    }
    m_bLoading = true ;
    int i = 0 ;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString strItem = in.readLine().trimmed();
        if(strItem.isEmpty())
            break;
        int nValue = strItem.toInt();
        if(bForLinar)
        {
            ui->framePanel->setBuf(1,i++,nValue) ;
        }
        else
        {
            ui->framePanel->setBuf(0,i++,nValue) ;
        }
    }
    file.close() ;
    m_bLoading = false ;

    if(!bForLinar)
        ui->lineEditFilename->setText(strFile) ;

    ui->framePanel->update() ;
}

void FrameEPCCBOOST::SaveLoadTable(bool bToSave)
{
    int nCount = 0;
    QStringList Addrs ;
    QStringList Reads ;
    QStringList Writes ;
    QSettings Set(m_pCOMDlg->getDataPath() + "EPCCBOOSTSetting.ini",QSettings::IniFormat) ;

    if(bToSave)
    {
    }
    else
    {
    }
}

void FrameEPCCBOOST::paintEvent(QPaintEvent *pEvt)
{
    //QPainter painter(ui->framePannel) ;
    //painter.drawText(20,200,"1234567890") ;

    QFrame::paintEvent(pEvt) ;
}

void FrameEPCCBOOST::resizeEvent(QResizeEvent *pEvt)
{
    QFrame::resizeEvent(pEvt) ;
}
