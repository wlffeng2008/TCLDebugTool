#include "FrameLocalDimmingProfile.h"
#include "ui_FrameLocalDimmingProfile.h"
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

FrameLocalDimmingProfile::FrameLocalDimmingProfile(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameLocalDimmingProfile)
{
    ui->setupUi(this);

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        unsigned char *pData = (unsigned char *)data.data() ;
        sPackHeader *pHD = (sPackHeader *)pData ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }
    });

    m_sence = new QGraphicsScene(this) ;

    ui->graphicsView->setScene(m_sence) ;

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);  // 支持拖拽平移
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // 缩放以鼠标为中心
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setMouseTracking(true) ;
    ui->graphicsView->installEventFilter(this) ;
    ui->graphicsView->viewport()->setMouseTracking(true);

    m_img = QImage(":images/bg.png") ;
    ui->lineEditW->setText(QString::number(m_img.width())) ;
    ui->lineEditH->setText(QString::number(m_img.height())) ;

    pickup(QPointF(20,60)) ;

    QPixmap pixmap=QPixmap::fromImage(m_img);
    if (!pixmap.isNull())
    {
        m_sence->addPixmap(pixmap);
        m_rcOrg = pixmap.rect();
        m_sence->setSceneRect(m_rcOrg);  // 设置场景范围以匹配图片尺寸
    }

    connect(ui->pushButtonFit,&QPushButton::clicked,this,[=](){
        QRect rc = ui->graphicsView->rect() ;
        qreal factor = rc.width()*1.0/m_rcOrg.width() ;
        m_factor *= factor ;
        ui->graphicsView->scale(factor*0.99,factor);
    }) ;
    connect(ui->pushButtonAutoImg,&QPushButton::clicked,this,[=](){
        ui->graphicsView->scale(1.0/m_factor,1.0/m_factor);
        m_sence->setSceneRect(m_rcOrg);
        ui->graphicsView->update() ;
        m_factor = 1 ;
    }) ;

    ui->pushButtonPos->setCheckable(true) ;

    connect(ui->pushButtonPos,&QPushButton::clicked,this,[=]{
        if(ui->pushButtonPos->isChecked())
            ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        else
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    }) ;
}

FrameLocalDimmingProfile::~FrameLocalDimmingProfile()
{
    delete ui;
}

void FrameLocalDimmingProfile::pickup(const QPointF & pt)
{
    QPointF MP = pt ;
    ui->lineEditX->setText(QString::number(MP.x())) ;
    ui->lineEditY->setText(QString::number(MP.y())) ;
    QRgb P = m_img.pixel(MP.toPoint()) ;
    ui->labelR->setText(QString::number(qRed(P))) ;
    ui->labelG->setText(QString::number(qGreen(P))) ;
    ui->labelB->setText(QString::number(qBlue(P))) ;
}


bool FrameLocalDimmingProfile::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *pKE = static_cast<QKeyEvent *>(event) ;
        if(pKE->key() == Qt::Key_Control)
        {
            qDebug() << "Key_Control presss" ;
            m_bCtrlPress = true ;
        }
    }


    if(event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *pKE = static_cast<QKeyEvent *>(event) ;
        if(pKE->key() == Qt::Key_Control)
        {
            qDebug() << "Key_Control release" ;
            m_bCtrlPress = false ;
        }
    }

    if(watched == ui->graphicsView)
    {
        int nType = event->type() ;
        //qDebug() << event->type() ;
        if(nType == QEvent::MouseMove)
        {
            //QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
            //qDebug() << pME->localPos() ;
        }

        if(nType == QEvent::MouseButtonDblClick || nType == QEvent::MouseButtonPress)
        {
            QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
            QPointF MP = ui->graphicsView->mapToScene(pME->localPos().toPoint()).toPoint() ;
            pickup(MP) ;
            //qDebug() << pME->localPos() << MP;

        }
        if(nType == QEvent::Wheel)
        {
            if(m_bCtrlPress)
            {
                QWheelEvent *pME = static_cast<QWheelEvent *>(event) ;
                qreal factor = (pME->angleDelta().y() > 0) ? 1.1 : 0.9;
                ui->graphicsView->scale(factor, factor);
                m_factor = factor;
                return true ;
            }
        }
    }

    if(watched == m_sence)
    {
        int nType = event->type() ;
        if(nType == QEvent::MouseMove)
        {
            QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
            qDebug() << pME->localPos() ;
        }
    }

    return QFrame::eventFilter(watched, event);

}
