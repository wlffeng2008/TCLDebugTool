#include "FrameEPCCPanel.h"
#include "ui_FrameEPCCPanel.h"

#include <QPainter>
#include <math.h>

FrameEPCCPanel::FrameEPCCPanel(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameEPCCPanel)
{
    ui->setupUi(this);
}

FrameEPCCPanel::~FrameEPCCPanel()
{
    delete ui;
}

void FrameEPCCPanel::setBuf(int nBuf,int nIndex,int nValue)
{
    if(nBuf == 0)
        m_bufA[nIndex] = nValue ;
    else
        m_bufB[nIndex] = nValue ;
}

int FrameEPCCPanel::getBuf(int nBuf,int nIndex)
{
    if(nBuf == 0)
        return m_bufA[nIndex] ;

    return m_bufB[nIndex] ;
}

static QPointF drawArrowA(QPainter &painter, QPointF at,double w, double h, double rotate) {

    int nxp = at.x() ;
    int nyp = at.y() ;

    QPointF p0 =  QPointF(nxp + sin( rotate         ) * h, nyp - cos(rotate) * h        );
    QPointF p1 =  QPointF(nxp + sin( rotate + M_PI/2) * w, nyp - cos(rotate+ M_PI/2) * w);
    QPointF p2 =  QPointF(nxp + sin( rotate - M_PI/2) * w, nyp - cos(rotate- M_PI/2) * w);
    painter.drawPolygon(QPolygonF() << p0 << p1 << p2);

    return p0 ;
}

void FrameEPCCPanel::paintEvent(QPaintEvent *pEvt)
{
    QPainter painter(this);
    QRect rcOrg = QRect(0,0,size().width(),size().height()) ;

    QRect rc = rcOrg.adjusted(30,10,-10,-50) ;
    int nW = rc.width() ;
    int nH = rc.height() ;
    qreal fStepX = nW/4.0 ;
    qreal fStepY = nH/4.0 ;

    painter.fillRect(rcOrg,QBrush(QColor(80,80,80))) ;
    painter.fillRect(rc,QBrush(Qt::darkGray)) ;

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    painter.setPen(QPen(Qt::white,1));
    painter.setBrush(Qt::white);

    //QPointF org(400,200) ;
    //for(int i=0; i<8; i++)
    //    org = drawArrowA(painter,org,5,40,M_PI/4 * i);

    QPointF p1(rc.left(),rc.bottom() + 10);
    QPointF p2(rc.left(),rc.top());
    painter.drawLine(p1,p2) ;
    drawArrowA(painter,p2,3,15,0);

    QPointF p3(rc.left()-10,rc.bottom() );
    QPointF p4(rc.right(),rc.bottom());
    painter.drawLine(p3,p4) ;
    drawArrowA(painter,p4,3,15,M_PI/2);

    painter.setPen(QPen(Qt::white));
    QRect  rcText = rc ;
    rcText.setTop(rc.bottom());
    rcText.setHeight(30);
    rcText.setHeight(30);
    painter.drawText(rcText,Qt::AlignVCenter|Qt::AlignHCenter,"BL_APL") ;

    rcText.setLeft(rc.right()-50);
    painter.drawText(rcText,Qt::AlignVCenter|Qt::AlignHCenter,"4095") ;
    painter.drawText(rc.left()+10,rc.top()+10,"4095") ;

    painter.save();
    QTransform tx;
    tx.translate(0, 2*fStepY + 110 );
    tx.rotate(270);
    painter.setTransform(tx);

    QRectF rect(0, 0, 200, 30); // 调整高度以适应文字长度
    painter.drawText(rect, Qt::AlignCenter, "I_Val");
    painter.restore();

    painter.setRenderHint(QPainter::Antialiasing, true);

    quint16 nDataCount = 4096 ;
    qreal fDataMax = 4095 ;
    {
        painter.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
        QPoint p1(rc.left(),rc.bottom()) ;
        QPoint p2(0,0) ;
        srand(time(nullptr)) ;
        qreal fStepX = nW*1.0/(nDataCount-1) ;
        for(int i=0;i<nDataCount; i++)
        {
            float x = rc.left()+fStepX *i ;
            float y = rc.bottom() - m_bufB[i]/fDataMax * nH ;
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
        qreal fStepX = nW*1.0/(nDataCount-1) ;
        for(int i=0;i<nDataCount; i++)
        {
            float x = rc.left()+fStepX *i ;
            float y = rc.bottom() - m_bufA[i]/fDataMax * nH ;
            p2 = QPoint(x,y) ;
            painter.drawLine(p1,p2) ;
            p1 = p2 ;
        }
    }

    QFrame::paintEvent(pEvt) ;
}
