#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>
#include <qglobal.h>
#include <QSettings>
#include <QShortcut>
#include <QProcess>
#include <QXlsx>
using namespace  QXlsx ;

static QSettings *g_pSet = nullptr ;

using FuncPtr = void (*)(int, std::string);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this) ;

    QString strBuild ;
#ifdef _MSC_VER

    QString strName = "MSVC2017";

#if _MSC_VER >= 1930
    strName = "MSVC2022";
#elif _MSC_VER >= 1920
    strName = "MSVC2019";
#else
    strName = "MSVC2017";
#endif

    strBuild = QString("使用 %1 或更高版本编译, 版本号: %2").arg(strName).arg(_MSC_VER)  ;

#else
    strBuild = "非 MSVC 编译(如 MinGW, GCC 等)";
#endif

    QString strTitle = QString("TCL Debug Tool (V2.12) -- [Build: %1] [By Qt%2] -- [%3]").arg(__TIMESTAMP__,QT_VERSION_STR,strBuild) ;
    setWindowTitle(strTitle);
    qDebug() << strTitle;
    {
        // Document xlsx;
        // xlsx.write("A1", "Hello QtXlsx!"); // current file is utf-8 character-set.
        // xlsx.write("A2", 12345);
        // xlsx.write("A3", "=44+33"); // cell value is 77.
        // xlsx.write("A4", true);
        // xlsx.write("A5", "http://qt-project.org");
        // xlsx.write("A6", QDate(2013, 12, 27));
        // xlsx.write("A7", QTime(6, 30));
        // xlsx.write("A8", QDateTime(QDate(2049, 7, 23), QTime(23, 5, 32), Qt::LocalTime));
        // xlsx.write("A9", "1234,\"123345");

        // if (!xlsx.saveAs("D:/WriteExcel1.csv")) {
        //     qDebug() << "[WriteExcel1] failed to save excel file";
        // }
    }

    {
        QString strA("1234567890ABCDEF") ;
        quint64 A = strA.toULongLong(nullptr,16) ;//;  0x1234567890ABCDEF ;
        char szBuf[20] = {0} ;
        *(quint64 *)szBuf = A ;
        *(quint32 *)(szBuf + sizeof(quint64) + 2) = 0x3412 ;

        QByteArray T((char *)&A,3) ;
        qDebug() << T.toHex(' ').toUpper() ;

        quint8 *bytes=(quint8 *)&A ;
        QByteArray data((char*)bytes,8) ;
        std::reverse(data.begin(),data.end()) ;
        qDebug() << data.toHex(' ').toUpper() ;

        quint64 B =  *(quint64 *)szBuf ;
        qDebug().noquote() << QByteArray(szBuf,20).toHex(' ').toUpper() << Qt::hex  << B << QString::asprintf("0x%08llX",B)<< Qt::dec << (qint8)sizeof(sPackHeader);

        qDebug() << QString().setNum(12345) << QString("123qwert").split(',') << Qt::hex << (0x1234) ;
        int  nInter = 1 ;
        int  at = nInter ;
        for(;;)
        {
            strA.insert(at,' ') ;
            at += nInter + 1 ;
            if(at >= strA.length())
                break;
        }
        qDebug() << strA;
    }

    g_pSet = new QSettings(QCoreApplication::applicationDirPath()+ "/TCLDebugToolCfg.ini",QSettings::IniFormat) ;

    m_pCOMDlg  = new SerialTestDialog() ;
    m_pRegRam  = new DialogRegRamManager() ;
    m_pQuality = new DialogQualityManager() ;
    m_pAging   = new DialogAgingTest() ;
    m_pPack    = new DialogPackMaker() ;
    m_pConfig  = new DialogConfigPack() ;

    connect(m_pCOMDlg,&SerialTestDialog::COMStatusChanged,this,[=](bool bOpen){
        ui->labelStatus->setText(bOpen ? "连接成功" : "连接失败") ;
        ui->labelStatus->setStyleSheet(bOpen ? "QLabel{color: green;}" : "QLabel{color: red;}") ;
    }) ;

    ui->pushButtonSerial->setCursor(Qt::PointingHandCursor);

    ui->labelLogo->setFixedSize(131,79);
    ui->labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/TCL.png")));

    int         nModel = g_pSet->value("ModelIndex",0).toInt() ;
    QStringList Models = g_pSet->value("ModelGroup").toStringList() ;
    if(Models.isEmpty())
    {
        Models = QStringList{"85QD", "98QD", "85FC", "98FC", "115FC"} ;
        g_pSet->setValue("ModelGroup", Models);
    }

    ui->comboBoxModel->addItems(Models) ;
    ui->comboBoxModel->setCurrentIndex(nModel) ;

    m_pRegRam->setMinimumSize(size()) ;
    m_pQuality->setMinimumSize(size()) ;

    ui->pushButtonScreenConfig->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonBrightness->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonPictureControl->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonTestTool->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonLightBoardFlash->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonAdjust->setFocusPolicy(Qt::NoFocus);

    ui->pushButtonScreenConfig->installEventFilter(this);
    ui->pushButtonBrightness->installEventFilter(this);
    ui->pushButtonPictureControl->installEventFilter(this);
    ui->pushButtonTestTool->installEventFilter(this);
    ui->pushButtonLightBoardFlash->installEventFilter(this);
    ui->pushButtonAdjust->installEventFilter(this);

    ui->labelStatus->installEventFilter(this);

    QString strQss = R"(
        QPushButton{
                    border-image: url(:/images/MWCentralWidgetButtonBG.png);
                    padding-left: 65px;
                    padding-top: 3px;
                    text-align: left center;
                    font: bold 14pt "微软雅黑";
                    color: white;
                    width:244px;
                    height:50px;
                    background: transparent; }
            )" ;

    ui->pushButtonScreenConfig->setStyleSheet(strQss) ;
    ui->pushButtonBrightness->setStyleSheet(strQss) ;
    ui->pushButtonPictureControl->setStyleSheet(strQss) ;
    ui->pushButtonTestTool->setStyleSheet(strQss) ;
    ui->pushButtonLightBoardFlash->setStyleSheet(strQss) ;
    ui->pushButtonAdjust->setStyleSheet(strQss) ;

    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F1), this);
    connect(shortcut, &QShortcut::activated, []() {
        qDebug() << "F1键按下";
    });

    connect(ui->actionFirmware,&QAction::triggered,this,[=]{
            m_pPack->showNormal() ;
            m_pPack->raise();
    }) ;

    connect(ui->actionConfig,&QAction::triggered,this,[=]{
            m_pConfig->showNormal() ;
            m_pConfig->raise();
    }) ;

    connect(ui->actionCalc,&QAction::triggered,this,[=]{
        QProcess::startDetached("calc.exe", QStringList{});
    }) ;

    connect(ui->actionNotepad,&QAction::triggered,this,[=]{
        QProcess::startDetached("notepad.exe", QStringList{});
    }) ;
    connect(ui->actionPainter,&QAction::triggered,this,[=]{
        QProcess::startDetached("mspaint.exe", QStringList{});
    }) ;

    connect(&m_TMSearial,&QTimer::timeout,this,[=](){
        m_TMSearial.stop() ;
        QString strModel = ui->comboBoxModel->currentText().trimmed();
        m_pCOMDlg->setModel(strModel) ;
        g_pSet->setValue("ModelIndex",ui->comboBoxModel->currentIndex());
    }) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    auto nRet = QMessageBox::question(this,"提示","确定要退出 TCLDebugTool 吗？") ;
    if(nRet != QMessageBox::Yes)
    {
        event->ignore() ;
        return ;
    }
    m_pCOMDlg->close() ;
    m_pRegRam->close() ;
    m_pQuality->close() ;
    QMainWindow::closeEvent(event) ;
    exit(0) ;
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if (msg->message == WM_DEVICECHANGE)
    {
        switch (msg->wParam)
        {
        case DBT_DEVICEARRIVAL:
            if(m_pCOMDlg->isHidden())
                m_pCOMDlg->OnUSBChanged() ;
            break;
        case DBT_DEVICEREMOVECOMPLETE:
            if(m_pCOMDlg->isHidden())
                m_pCOMDlg->OnUSBChanged() ;
            break;
        }
    }

    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::paintEvent(QPaintEvent *pEvt)
{
    static QPixmap bg(":/images/MWCentralWidgetBG.png") ;

    QPainter PT(this) ;
    QRectF rc = geometry() ;
    PT.drawPixmap(0,0,rc.width(),rc.height(),bg) ;

    QMainWindow::paintEvent(pEvt);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (   (watched == ui->pushButtonScreenConfig)
        || (watched == ui->pushButtonBrightness)
        || (watched == ui->pushButtonPictureControl)
        || (watched == ui->pushButtonTestTool)
        || (watched == ui->pushButtonLightBoardFlash)
        || (watched == ui->pushButtonAdjust)
        )
    {
        switch (event->type())
        {
        case QEvent::HoverEnter:
        //case QEvent::FocusIn:
            pushButtonFocusInOutAnimation(watched, true);
            break;

        case QEvent::HoverLeave:
        //case QEvent::FocusOut:
            pushButtonFocusInOutAnimation(watched, false);
            break;
        default:
            break;
        }
    }

    if (watched == ui->labelStatus && event->type() == QEvent::MouseButtonRelease)
    {
        on_pushButtonSerial_clicked();
    }

    return QWidget::eventFilter(watched, event);
}

//0--Scale; 1--Pos;
void MainWindow::pushButtonFocusInOutAnimation(QObject *watched, bool bFocusIn)
{
    QPoint posStart(((QWidget *)watched)->pos());
    QPoint posEnd(-30 , posStart.y());
    if (!bFocusIn)
         posEnd = QPoint(0 , posStart.y());

    QPropertyAnimation *pPosAnimation = new QPropertyAnimation(watched, "pos", this);
    pPosAnimation->setDuration(100);
    pPosAnimation->setStartValue(posStart);
    pPosAnimation->setEndValue(posEnd);

    pPosAnimation->start();
}


void MainWindow::on_pushButtonSerial_clicked()
{
    m_pCOMDlg->showNormal() ;
    m_pCOMDlg->raise() ;
}

void MainWindow::on_pushButtonScreenConfig_clicked()
{
    m_pRegRam->showNormal() ;
    m_pRegRam->raise() ;
}

void MainWindow::on_pushButtonTestTool_clicked()
{
    m_pQuality->showNormal() ;
    m_pQuality->raise() ;
}

void MainWindow::on_comboBoxModel_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    m_TMSearial.stop() ;
    m_TMSearial.start(300) ;
}

void MainWindow::on_pushButtonBrightness_clicked()
{
    m_pAging->showNormal() ;
    m_pAging->raise() ;
}


void MainWindow::on_pushButtonPictureControl_clicked()
{
    //m_pPack->showNormal() ;
    //m_pPack->raise() ;
}

