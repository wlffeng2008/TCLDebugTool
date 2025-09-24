#include "FrameTPFilter.h"
#include "ui_FrameTPFilter.h"

#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

FrameTPFilter::FrameTPFilter(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameTPFilter)
{
    ui->setupUi(this);
    m_pCOMDlg = SerialTestDialog::getInstance() ;

    QStringList header = {"Index","Alpha up/down"};
    m_pDModel = new QStandardItemModel(256,2,this) ;
    m_pDModel->setHorizontalHeaderLabels(header);
    ui->tableView->setModel(m_pDModel) ;

    ui->tableView->setAutoFillBackground(true);
    m_bLoading = true ;
    for(int i=0; i<256; i++)
    {
        for(int j=0; j<2; j++)
        {
            QStandardItem *pItem = new QStandardItem() ;
            pItem->setText(QString::number(i)) ;

            m_pDModel->setItem(i,j,pItem);
            if(j == 0)
                pItem->setEditable(false) ;
            if(j == 1)
                pItem->setForeground(QBrush(QColor(Qt::blue)));
        }
        ui->tableView->setRowHeight(i,16) ;
    }
    m_bLoading = false ;
    ui->tableView->setColumnWidth(0,70);
    ui->tableView->setColumnWidth(1,119);
    ui->tableView->setFocusPolicy(Qt::NoFocus) ;

    ui->radioButton1->setChecked(true) ;

    LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "Aplha_up_lut.csv") ;
    LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "Aplha_down_lut.csv",true) ;

    connect(ui->radioButton1,&QRadioButton::clicked,this,[=](){ m_addr = (4<<13); });
    connect(ui->radioButton2,&QRadioButton::clicked,this,[=](){ m_addr = (5<<13); });
    connect(ui->checkBox109D,&QCheckBox::clicked,this,[=]{
        m_pCOMDlg->sendSwitch(0x109D,ui->checkBox109D->isChecked(),this);
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        quint8 *pData = (quint8 *)data.data() ;
        sPackHeader *pHD = (sPackHeader *)pData ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMReadHugeRamDone,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        quint8 *pData = (quint8 *)data.data() ;
        for(int i=0; i<256; i++)
        {
            quint16 nValue = *(quint16*)(pData + i* 9);
            ui->framePanel->setBuf(0,i,nValue) ;
            m_pDModel->item(i,1)->setText(QString::number(nValue)) ;
        }
        ui->framePanel->update() ;
    });
}

FrameTPFilter::~FrameTPFilter()
{
    delete ui;
}


void FrameTPFilter::LoadBuf(const QString&strFile,bool bForLinar)
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
            if(m_pDModel->item(i,1))
                m_pDModel->item(i,1)->setText(strItem) ;

        }
    }
    file.close() ;
    m_bLoading = false ;

    if(!bForLinar)
        ui->lineEditFilename->setText(strFile) ;

    ui->framePanel->update() ;
}

void FrameTPFilter::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开Gamma数据文件",QCoreApplication::applicationDirPath() + QString("/data/"),
                                                   tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;

    LoadBuf(strFile) ;
}


void FrameTPFilter::on_pushButtonSave_clicked()
{
    QString strFile = ui->lineEditFilename->text().trimmed() ;
    if(strFile.isEmpty())
    {
        strFile = QFileDialog::getSaveFileName(this,"保存Gamma数据到文件",QCoreApplication::applicationDirPath() + QString("/data/"),
                                               tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

        if(strFile.isEmpty())
            return ;
        ui->lineEditFilename->setText(strFile) ;
    }

    QFile file(strFile);

    if(file.exists())
    {
        auto nRet = QMessageBox::question(this,"提示","当前文件即将被覆盖，确定要保存吗？",QMessageBox::Yes|QMessageBox::No) ;
        if(nRet != QMessageBox::Yes)
            return ;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "文件创建失败：" << file.errorString() << strFile;

        QMessageBox::critical(this,"提示","文件创建失败：Gamma数据保存失败！") ;
        return ;
    }
    QTextStream out(&file);

    int nCount = m_pDModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1\n").arg(m_pDModel->item(i,1)->text().trimmed());
        out << strLine ;
    }
    file.close() ;

    QMessageBox::information(this,"提示","Gamma数据保存完毕！") ;
}


void FrameTPFilter::on_pushButtonRead_clicked()
{
    if(!ui->checkBox109D->isChecked())
    {
        QMessageBox::warning(this,"提示","请打开： 0x109D");
        return ;
    }
    m_pCOMDlg->readHugeRam(m_addr, 256*9, this);
}


void FrameTPFilter::on_pushButtonWrite_clicked()
{
    if(!ui->checkBox109D->isChecked())
    {
        QMessageBox::warning(this,"提示","请打开： 0x109D");
        return ;
    }

    QByteArray buf ;
    char szBuf[20]={0} ;
    int nCount = m_pDModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        quint16 nValue = m_pDModel->item(i,1)->text().trimmed().toInt();
        *(quint16 *)szBuf = nValue ;
        buf.append(szBuf,9) ;
    }

    m_pCOMDlg->writeHugeRam(m_addr,buf,this) ;
}


void FrameTPFilter::on_pushButtonReset_clicked()
{
    //static char szBuf[512]={0} ;
    //static QByteArray buf(szBuf,512) ;
    //m_pCOMDlg->writeHugeRam(m_addr,buf,this) ;
}

