#include "DialogPackMaker.h"
#include "ui_DialogPackMaker.h"

#include "norflash.h"
#include "DialogToast.h"

#include <QDebug>
#include <QMimeData>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

static DialogPackMaker *g_instance = nullptr ;

DialogPackMaker *DialogPackMaker::getInstance()
{
    return g_instance ;
}

DialogPackMaker::DialogPackMaker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPackMaker)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::MSWindowsFixedSizeDialogHint ;
    flags &= ~Qt::WindowContextHelpButtonHint ;
    setWindowFlags(flags);
    setWindowTitle("固件打包工具") ;

    g_instance = this ;

    setAcceptDrops(true) ;

    ui->pushButtonGo->setEnabled(false) ;

    connect(ui->lineEditFile1,&QLineEdit::textChanged,this,[=](const QString & text){
        QFile InFile(text.trimmed()) ;
        QString strInfo("文件大小: 未知   日期: 未知");

        ui->pushButtonGo->setEnabled(false) ;
        if(InFile.exists())
        {
            quint64 fileSize = InFile.size() ;
            QFileInfo info(InFile) ;
            QString createdTime = info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
            strInfo = QString("文件大小: %1   日期: %2").arg(fileSize).arg(createdTime);

            QString strName = info.fileName() ;
            QString strPath = info.path() + "/output/";
            QDir OD(strPath) ;
            if(!OD.exists()) OD.mkpath(strPath) ;

            ui->lineEditFile2->setText(strPath + strName) ;
            ui->pushButtonGo->setEnabled(true) ;
        }

        ui->labelFileInfo->setText(strInfo) ;
    });

    connect(ui->pushButtonClear,&QPushButton::clicked,this,[=]{ ui->plainTextEdit->clear(); });

    connect(ui->pushButtonHide,&QPushButton::clicked,this,[=]{ this->hide(); });
    connect(ui->pushButtonGo,&QPushButton::clicked,this,[=]{
        this->makeUpdatePack(ui->lineEditFile1->text().trimmed(),ui->lineEditFile2->text().trimmed());
        toast(this)->active("升级包打包已完成！");
    });

    connect(ui->pushButtonLoad,&QPushButton::clicked,this,[=]{
        QString strFile = QFileDialog::getOpenFileName(this,"选择固件文件", nullptr,
                                                       tr("BIN文件(*.BIN);;所有文件 (*.*)"));
        if(strFile.isEmpty())
            return ;
        ui->lineEditFile1->setText(strFile);
    }) ;

    ui->labelSwitch->installEventFilter(this) ;

    connect(&m_TMSwitch,&QTimer::timeout,this,[=]{
        m_TMSwitch.stop() ;
        m_nCount = 0 ;
    });

    const QList<QPushButton *> btns = findChildren<QPushButton *>() ;
    for (QPushButton *btn : std::as_const(btns)) {
        btn->setCursor(Qt::PointingHandCursor) ;
        btn->setFocusPolicy(Qt::NoFocus) ;
    }
}

DialogPackMaker::~DialogPackMaker()
{
    delete ui;
}

bool DialogPackMaker::eventFilter(QObject*watched,QEvent *event)
{
    if(watched == ui->labelSwitch)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            m_nCount ++ ;
            if(m_nCount >= 3)
            {
                ui->lineEditVersi->setReadOnly(false) ;
                toast(this)->active("Magic Number 可以修改了！");
            }
            m_TMSwitch.stop() ;
            m_TMSwitch.start(2000) ;

        }
    }
    return QDialog::eventFilter(watched,event);
}

void DialogPackMaker::makeUpdatePack(const QString &strInFile,const QString &strOutFile)
{
    ui->plainTextEdit->clear() ;

    QString strLog ;
    char szInfile[256]={0};
    strcpy_s(szInfile,strInFile.toStdString().c_str()) ;
    strLog += QString("输入文件: %1\n").arg(szInfile) ;

    char szOutfile[256] = {0};
    strcpy_s(szOutfile,strOutFile.toStdString().c_str()) ;
    if(strlen(szOutfile)<=2)
        strcpy_s(szOutfile,szInfile);
    strLog += QString("输出文件: %1\n").arg(szOutfile);

    FILE *file_in = nullptr;
    fopen_s(&file_in,szInfile, "rb");
    if(!file_in)
    {
        QMessageBox::critical(nullptr,"错误","无法打开源文件，请重试！") ;
        return ;
    }

    fseek(file_in, 0, SEEK_END);
    long sizeA = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);
    uint8_t *bufferIn = (uint8_t *)malloc(sizeA);
    fread(bufferIn, 1, sizeA, file_in);
    fclose(file_in);

    UPDATE_PACKAGE_HEADER_INFO* headerinfo = (UPDATE_PACKAGE_HEADER_INFO*)malloc(sizeof(UPDATE_PACKAGE_HEADER_INFO));
    memset(headerinfo,0,sizeof(UPDATE_PACKAGE_HEADER_INFO));
    quint64 MNumber = ui->lineEditVersi->text().trimmed().toULongLong(nullptr,16) ;
    headerinfo->magicnumber = MNumber; // 0x41475046534E4C4B;
    headerinfo->size = sizeof(UPDATE_PACKAGE_HEADER_INFO);
    headerinfo->version = 0x01;
    headerinfo->sectionNum = 1;

    headerinfo->section_header[0].mainType = 0x01;
    headerinfo->section_header[0].offset = sizeof(UPDATE_PACKAGE_HEADER_INFO);
    headerinfo->section_header[0].size = sizeA;

    calculate_file_md5((uint8_t*)szInfile,sizeA,&(headerinfo->section_header[0]));

    headerinfo->CRC = calculate_crc_update_header(headerinfo);

    strLog += (QString("headerinfo CRC: %1\n").arg(headerinfo->CRC,4,16,QLatin1Char('0'))) ;
    strLog += (QString("headerinfo magicnumber: %1\n").arg(headerinfo->magicnumber,16,16,QLatin1Char('0'))) ;
    strLog += (QString("headerinfo size: %1\n").arg(headerinfo->size,4,16,QLatin1Char('0'))) ;
    strLog += (QString("headerinfo version: %1\n").arg(headerinfo->version,4,16,QLatin1Char('0'))) ;
    strLog += (QString("headerinfo sectionNum: %1\n").arg(headerinfo->sectionNum,4,16,QLatin1Char('0'))) ;

    uint32_t i = 0;
    char szBuf[1024]={0} ;
    for(i=0; i<headerinfo->sectionNum; i++)
    {
        sprintf_s(szBuf,"[%x]:file size=(%08x), start=(%08x), end=(%08x), MD5(%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x)\n",
               headerinfo->section_header[i].mainType,
               headerinfo->section_header[i].size,
               headerinfo->section_header[i].offset,
               headerinfo->section_header[i].offset+headerinfo->section_header[i].size,
               headerinfo->section_header[i].MD5[0],headerinfo->section_header[i].MD5[1],
               headerinfo->section_header[i].MD5[2],headerinfo->section_header[i].MD5[3],
               headerinfo->section_header[i].MD5[4],headerinfo->section_header[i].MD5[5],
               headerinfo->section_header[i].MD5[6],headerinfo->section_header[i].MD5[7],
               headerinfo->section_header[i].MD5[8],headerinfo->section_header[i].MD5[9],
               headerinfo->section_header[i].MD5[10],headerinfo->section_header[i].MD5[11],
               headerinfo->section_header[i].MD5[12],headerinfo->section_header[i].MD5[13],
               headerinfo->section_header[i].MD5[14],headerinfo->section_header[i].MD5[15]);

        strLog += szBuf ;
    }

    FILE *file_out = nullptr;
    fopen_s(&file_out,szOutfile, "wb");
    if(file_out)
    {
        fwrite(headerinfo, sizeof(UPDATE_PACKAGE_HEADER_INFO),1,file_out);
        fwrite(bufferIn, sizeA,1,file_out);
        fclose(file_out);
        strLog += "输出文件写入数据结束，打包成功！";
    }
    else
    {
        strLog += "无法创建输出文件，打包失败！";
        QMessageBox::critical(nullptr,"错误","无法创建输出文件，打包失败！") ;

    }
    free(bufferIn);

    ui->plainTextEdit->appendPlainText(strLog) ;
}

void DialogPackMaker::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
    // QFrame::dragEnterEvent(event);
}

void DialogPackMaker::dropEvent(QDropEvent *event) {

    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        for (const QUrl &url : std::as_const(urlList))
        {
            QString filePath = url.toLocalFile();
            ui->lineEditFile1->setText(filePath) ;
            qDebug() << "拖入文件:" << filePath;
            break ;
        }
    }
    //QFrame::dropEvent(event);
}
