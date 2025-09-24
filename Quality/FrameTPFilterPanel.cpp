#include "FrameTPFilterPanel.h"
#include "ui_FrameTPFilterPanel.h"

#include <QPainter>
#include <QDebug>
#include <math.h>

FrameTPFilterPanel::FrameTPFilterPanel(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameTPFilterPanel)
{
    ui->setupUi(this);
}

FrameTPFilterPanel::~FrameTPFilterPanel()
{
    delete ui;
}

void FrameTPFilterPanel::setBuf(int nBuf,int nIndex,int nValue)
{
    if(nBuf == 0)
        m_bufA[nIndex] = nValue ;
    else
        m_bufB[nIndex] = nValue ;
}

QPointF drawArrowA(QPainter &painter, QPointF at,double w, double h, double rotate) {

    int nxp = at.x() ;
    int nyp = at.y() ;

    QPointF p0 =  QPointF(nxp + sin( rotate         ) * h, nyp - cos(rotate) * h        );
    QPointF p1 =  QPointF(nxp + sin( rotate + M_PI/2) * w, nyp - cos(rotate+ M_PI/2) * w);
    QPointF p2 =  QPointF(nxp + sin( rotate - M_PI/2) * w, nyp - cos(rotate- M_PI/2) * w);
    painter.drawPolygon(QPolygonF() << p0 << p1 << p2);

    return p0 ;
}

void FrameTPFilterPanel::paintEvent(QPaintEvent *pEvt)
{
    QPainter painter(this);
    QRect rcOrg = QRect(0,0,size().width(),size().height()) ;

    QRect rc = rcOrg.adjusted(60,10,-10,-50) ;
    int nW = rc.width() ;
    int nH = rc.height() ;
    qreal fStepX = nW/4.0 ;
    qreal fStepY = nH/4.0 ;

    painter.fillRect(rcOrg,QBrush(QColor(80,80,80))) ;
    painter.fillRect(rc,QBrush(Qt::darkGray)) ;

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    painter.setPen(QPen(Qt::blue,2));
    painter.setBrush(Qt::blue);

    // QPointF org(400,200) ;
    // for(int i=0; i<8; i++)
    //     org = drawArrowA(painter,org,5,40,M_PI/4 * i);

    QPointF p1(rc.left(),rc.bottom() + 10);
    QPointF p2(rc.left(),rc.top());
    painter.drawLine(p1,p2) ;
    drawArrowA(painter,p2,2,10,0);

    QPointF p3(rc.left()-10,rc.bottom() );
    QPointF p4(rc.right(),rc.bottom());
    painter.drawLine(p3,p4) ;
    drawArrowA(painter,p4,2,10,M_PI/2);

    painter.setRenderHint(QPainter::Antialiasing, true);
    {
        painter.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
        QPoint p1(rc.left(),rc.bottom()) ;
        QPoint p2(0,0) ;
        srand(time(nullptr)) ;
        qreal fStepX = nW/255.0 ;
        for(int i=0;i<256; i++)
        {
            float x = rc.left()+fStepX *i ;
            float y = rc.bottom() - m_bufB[i]/1023.0 * nH ;
            p2 = QPoint(x,y) ;
            painter.drawLine(p1,p2) ;
            p1 = p2 ;
        }
    }
    {
        painter.setPen(QPen(QColor(0x3EA8FF), 2, Qt::SolidLine));
        QPoint p1(rc.left(),rc.bottom()) ;
        QPoint p2(0,0) ;
        srand(time(nullptr)) ;
        qreal fStepX = nW/(256.0 -1);
        for(int i=0;i<256; i++)
        {
            float x = rc.left()+fStepX *i ;
            float y = rc.bottom() - m_bufA[i]/1023.0 * nH ;
            p2 = QPoint(x,y) ;
            painter.drawLine(p1,p2) ;
            p1 = p2 ;
        }
    }

    {
        qreal fStepX = nW/4.0 ;
        qreal fStepY = nH/4.0 ;

        painter.setPen(QPen(QColor(Qt::white), 1, Qt::SolidLine));
        for(int i=0; i<=4; i++)
        {
            //painter.drawLine(QPoint(rc.left()+i*fStepX,rc.top()),QPoint(rc.left()+i*fStepX,rc.bottom()));
            int nOffset = 25 ;
            if(i==0) nOffset = 2  ;
            if(i==4) nOffset = 30 ;
            painter.drawText(rc.left()+i*fStepX - nOffset,rc.bottom()+20, QString::number(256/4 * i) );
        }

        for(int i=0; i<=4; i++)
        {
            //painter.drawLine(QPoint(rc.left(),rc.top()+i*fStepY),QPoint(rc.right(),rc.top()+i*fStepY));

            int nOffset = 42 ;
            if(i==4) nOffset = 15 ;
            painter.drawText(rc.left() - nOffset ,rc.top()+i*fStepY+8, QString::number((int)(1023/4.0 *(4-i))));
        }
    }

    QFrame::paintEvent(pEvt) ;
}
