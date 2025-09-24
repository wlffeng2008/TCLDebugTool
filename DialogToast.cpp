#include "DialogToast.h"
#include "ui_DialogToast.h"
#include <QScreen>

DialogToast *toast(QWidget *parent)
{
    static DialogToast *pDlg = new DialogToast() ;
    //pDlg->setParent(parent) ;
    pDlg->close();
    return pDlg ;
}

void easyToast(const QString&text,QWidget *parent,quint32 durtaion)
{
    toast(parent)->active(text,durtaion) ;
}

DialogToast::DialogToast(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogToast)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::Popup | Qt::Dialog);    // 必须设置无边框
    setAttribute(Qt::WA_TranslucentBackground); // 设置背景透明
    setStyleSheet("background-color: rgba(50, 50, 50, 150); border-radius: 10px; color:white;");

    connect(&m_TMShow,&QTimer::timeout,this,[=]{
        m_TMHide.stop() ;
        m_TMHide.start(30) ;
    });

    connect(&m_TMHide,&QTimer::timeout,this,[=]{
        m_opacity -= 0.1 ;
        setWindowOpacity(m_opacity) ;
        if(m_opacity <= 0.0)
        {
            m_TMHide.stop() ;
            this->hide() ;
        }
    });
}

DialogToast::~DialogToast()
{
    delete ui;
}

void DialogToast::active(const QString&text,int durtion)
{
    m_TMShow.stop() ;
    m_TMHide.stop() ;

    ui->label->setText(text) ;
    setWindowOpacity(1.0) ;
    m_opacity = 1.0 ;

    m_TMShow.start(durtion) ;

    // QRect screenGeometry = QApplication::primaryScreen()->availableGeometry();
    // int x = (screenGeometry.width() - width()) / 2;
    // int y = (screenGeometry.height() - height()) / 2;

    raise() ;
    if(parent())
    {
        QRect parentGeometry = ((QWidget *)parent())->geometry();
        int x = (parentGeometry.width() - width()) / 2;
        int y = (parentGeometry.height() - height()) / 2;
        move(x, y);
        show() ;
        return ;
    }

    exec() ;
}
