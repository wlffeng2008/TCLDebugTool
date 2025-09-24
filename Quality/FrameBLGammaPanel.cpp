#include "FrameBLGammaPanel.h"
#include "ui_FrameBLGammaPanel.h"
#include "smooth_algorithm.h"


#include <QPainter>
#include <QDebug>
#include <QMimeData>
#include <QToolTip>
#include <QTimer>


FrameBLGammaPanel::FrameBLGammaPanel(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameBLGammaPanel)
{
    ui->setupUi(this);

    setMouseTracking(true);  // 关键步骤

    setAcceptDrops(true) ;
}

FrameBLGammaPanel::~FrameBLGammaPanel()
{
    delete ui;
}

void FrameBLGammaPanel::setBuf(int nBuf,int nIndex,int nValue)
{
    if (nBuf == 0 )
    {
        m_bufA[nIndex] = nValue ;
        m_dataCount = nIndex + 1 ;
    }
    else
    {
        m_bufB[nIndex] = nValue ;
    }
}

int FrameBLGammaPanel::getBuf(int nBuf,int nIndex)
{
    if (nBuf == 0 )
       return m_bufA[nIndex] ;

    return m_bufB[nIndex]  ;
}

int FrameBLGammaPanel::valueFromPos(const QPoint &pos)
{
    int nValue = 0;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nH = rc.height() ;

        nValue = 4095 - (pos.y() - rc.top())*4095/nH;
        if(nValue<0)
            nValue = 0 ;

        if(nValue>4095)
            nValue = 4095 ;
    }
    return nValue ;
}

int FrameBLGammaPanel::indexFromPos(const QPoint &pos)
{
    int index = 0 ;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nW = rc.width() ;
        int nDist = pos.x()  - rc.left() ;
        index = nDist * m_dataCount / nW ;

        if(index<0)
            index = 0 ;

        if(index>m_dataCount)
            index = m_dataCount ;
    }
    return index ;
}

double *cubicSmooth5(double in[], int N)
{
    static double out[6000]={0} ;
    if(N < 5) {
        for(int i=0; i<N; i++) out[i] = in[i];
        return out;
    }

    out[0] = (69.0*in[0] + 4.0*in[1] - 6.0*in[2] + 4.0*in[3] - in[4]) / 70.0;
    out[1] = (2.0*in[0] + 27.0*in[1] + 12.0*in[2] - 8.0*in[3] + 2.0*in[4]) / 35.0;

    for(int i=2; i<=N-3; i++) {
        out[i] = (-3.0*(in[i-2]+in[i+2]) + 12.0*(in[i-1]+in[i+1]) + 17.0*in[i]) / 35.0;
    }

    out[N-2] = (2.0*in[N-5] - 8.0*in[N-4] + 12.0*in[N-3] + 27.0*in[N-2] + 2.0*in[N-1]) / 35.0;
    out[N-1] = (69.0*in[N-1] + 4.0*in[N-2] - 6.0*in[N-3] + 4.0*in[N-4] - in[N-5]) / 70.0;
    return  out ;
}

void propagateChange(double arr[], int size, int changeIndex, int changeAmount, float decayFactor) {
    // 边界检查
    if(changeIndex < 0 || changeIndex >= size) {
        printf("Invalid change index!\n");
        return;
    }

    arr[changeIndex] += changeAmount;

    // 向左右邻居传播变化
    int currentAmount = changeAmount;
    for(int distance = 1; ; distance++)
    {
        int left = changeIndex - distance;
        int right = changeIndex + distance;

        // 计算衰减后的变化量
        currentAmount = (int)(currentAmount * decayFactor);
        if(currentAmount == 0)
            break; // 变化量衰减到0时停止

        int changed = 0; // 标记本轮是否有变化

        // 处理左邻居
        if(left >= 0) {
            arr[left] += currentAmount;
            changed = 1;
        }

        // 处理右邻居
        if(right < size) {
            arr[right] += currentAmount;
            changed = 1;
        }

        if(!changed)
            break;
    }
}

void FrameBLGammaPanel::changeValue(int nIndex,int nValue)
{
    m_nEditIndex = nIndex ;
    if(nValue<0)
    {
        update() ;
        return;
    }

    m_bufA[nIndex] = nValue ;
    if(m_stage > 0)
    {
        int nCount = m_dataCount / m_stage ;
        int nLIndex = nIndex-nCount ;
        int nRIndex = nIndex+nCount ;
        if(nLIndex < 0)
            nLIndex = 0;
        if(nRIndex > m_dataCount)
            nRIndex = m_dataCount;
        float fStep1 = (m_bufA[nLIndex] - nValue) / nCount;
        float fStep2 = (m_bufA[nRIndex] - nValue) / nCount;
        for(int i=1; i<nCount; i++)
        {
            if(nIndex-i >= 0)
                m_bufA[nIndex-i] = round(nValue + (i) * fStep1);
            if(nIndex+i <= m_dataCount)
                m_bufA[nIndex+i] = round(nValue + (i) * fStep2);
        }
    }
    update() ;

    static QTimer TMReport(this) ;
    TMReport.stop() ;
    TMReport.start(50) ;
    connect(&TMReport,&QTimer::timeout,this,[=]{
        TMReport.stop() ;
        emit onBufChanged(m_bufA,m_dataCount) ;
    });
}

void FrameBLGammaPanel::mousePressEvent(QMouseEvent *event)
{
    m_clkPoint = event->pos() ;

    int index = -1 ;
    QRect rc = m_drawRect ;
    if(rc.contains(event->pos()))
    {
        index = indexFromPos(event->pos());
        update() ;
    }

    if( m_nHitIndex >= 0 )
    {
        index = m_nHitIndex ;
        m_bDraging = true ;
    }

    if(index != -1)
    {
        m_nEditIndex = index ;
        emit onClickIndex(index,0) ;
    }

    QFrame::mousePressEvent(event);
}


void FrameBLGammaPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_bDraging && m_nHitIndex > 0)
    {
        if(m_clkPoint != event->pos())
            changeValue(m_nHitIndex,valueFromPos(event->pos())) ;

        QApplication::restoreOverrideCursor() ;
    }

    m_nHitIndex = -1 ;
    m_bDraging = false ;

    QFrame::mouseReleaseEvent(event);
}

void FrameBLGammaPanel::mouseDoubleClickEvent(QMouseEvent *event)
{
    QFrame::mouseDoubleClickEvent(event);
}

void FrameBLGammaPanel::mouseMoveEvent(QMouseEvent *event)
{
    QRect rc = m_drawRect ;
    if(rc.contains(event->pos()))
    {
        if(m_bDraging)
        {
            int nValue = valueFromPos(event->pos());
            emit onValueChanged(m_nHitIndex, nValue) ;
        }
        else
        {
            int nCount = m_hotRects.count() ;
            for(int i=0; i<nCount; i++)
            {
                if(m_hotRects[i].contains(event->pos()))
                {
                    m_nHitIndex = m_hotIndexs[i] ;
                    QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
                    return ;
                }
            }
        }
    }

    if(!m_bDraging)
    {
        m_nHitIndex = -1 ;
        QApplication::restoreOverrideCursor() ;
    }

    QFrame::mouseMoveEvent(event);
}

void FrameBLGammaPanel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
    // QFrame::dragEnterEvent(event);
}

void FrameBLGammaPanel::dropEvent(QDropEvent *event) {

    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        for (const QUrl &url : qAsConst(urlList)) {
            QString filePath = url.toLocalFile();
            qDebug() << "拖入文件:" << filePath;
        }
    }
    //QFrame::dropEvent(event);
}

void FrameBLGammaPanel::setShowGamin(bool bShow){m_bshowGamIn = bShow; update();}
void FrameBLGammaPanel::setShowRemap(bool bShow){m_bshowRemap = bShow; update();}
void FrameBLGammaPanel::setGammaStage(int nStage){m_stage     = nStage; update();}

void FrameBLGammaPanel::paintEvent(QPaintEvent *event)
{
    QPainter P(this) ;
    QRect rcOrg = QRect(0,0,size().width(),size().height()) ;

    QRect rc = rcOrg.adjusted(65,10,-10,-50) ;
    m_drawRect = rc ;
    int nW = rc.width() ;
    int nH = rc.height() ;

    P.fillRect(rcOrg,QBrush(QColor(80,80,80))) ;
    P.fillRect(rc,QBrush(Qt::darkGray)) ;

    QPen pen(Qt::white) ;
    P.setPen(pen) ;
    QFont font("微软雅黑",12) ;

    //font.setBold(true) ;
    P.setFont(font) ;

    //pen.setWidth(3) ;

    //P.setPen(QPen(Qt::white, 2, Qt::SolidLine));
    //P.drawLine(QPoint(rc.left(),rc.bottom()),QPoint(rc.right(),rc.top()));

    int nDCount = m_dataCount ;
    int nDMaxVal = 4095 ;

    P.setPen(QPen(Qt::white, 1, Qt::SolidLine));
    P.drawRect(rcOrg) ;
    P.drawRect(rc) ;

    qreal fStepX = nW/4.0 ;
    qreal fStepY = nH/4.0 ;
    for(int i=0; i<=4; i++)
    {
        P.drawLine(QPoint(rc.left()+i*fStepX,rc.top()),QPoint(rc.left()+i*fStepX,rc.bottom()));
        int nOffset = 25 ;
        if(i==0) nOffset =2 ;
        if(i==4) nOffset =30 ;
        P.drawText(rc.left()+i*fStepX - nOffset,rc.bottom()+20, QString::number(nDCount/4 * i) );
    }
    P.drawText(rc.center().rx() - 30 ,rc.bottom() + 40, "Gamma");

    for(int i=0; i<=4; i++)
    {
        P.drawLine(QPoint(rc.left(),rc.top()+i*fStepY),QPoint(rc.right(),rc.top()+i*fStepY));

        int nOffset = 42 ;
        if(i==4) nOffset = 15 ;
        P.drawText(rc.left() - nOffset ,rc.top()+i*fStepY+8, QString::number((int)(nDMaxVal/4.0 *(4-i))));
    }

    P.save();
    QTransform tx;
    tx.translate(0, 2*fStepY + 108);
    tx.rotate(270);
    P.setTransform(tx);

    QRectF rect(0, 0, 200, 20); // 调整高度以适应文字长度
    P.drawText(rect, Qt::AlignCenter, "Value");
    P.restore();

    //P.setRenderHint(QPainter::Antialiasing, true);
    int nEditX = 0 ;
    fStepX = nW*1.0/(nDCount - 1) ;
    nEditX = rc.left() + fStepX * m_nEditIndex ;
    if(m_bshowGamIn)
    {
        P.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
        /*QPoint p1(rc.left(),rc.bottom()) ;
        for(int i=0; i<nDCount; i++)
        {
            float x = rc.left()+fStepX *i ;
            float y = rc.bottom() - m_bufB[i]*1.0/nDMaxVal * nH ;
            if(y < rc.top()) y = rc.top() ;
            QPoint p2 = QPoint(x,y) ;
            //P.drawLine(p1,p2) ;
            p1 = p2 ;
        }*/

        P.drawLine(rc.left(),rc.bottom(),rc.right(),rc.top()) ;
    }
    if(m_nEditIndex>=0)
    {
        P.setPen(QPen(Qt::green, 1, Qt::SolidLine));
        P.drawLine(QPoint(nEditX,rc.top()),QPoint(nEditX,rc.bottom())) ;
    }

    m_hotRects.clear() ;
    m_hotIndexs.clear() ;
    if(m_bshowRemap)
    {
        int nStage = m_stage ;
        int nSPCount = 0 ;
        if(nStage>0)
            nSPCount = nDCount/ nStage ;

        P.setPen(QPen(QColor(0x3EA8FF), 1, Qt::SolidLine));
        QPoint p1(rc.left(),rc.bottom()) ;
        QPoint p2(0,0) ;
        qreal fStepX = nW*1.0/(nDCount -1);
        for(int i=0; i<nDCount; i++)
        {
            float x = rc.left() + fStepX * i ;
            float y = rc.bottom() - m_bufA[i]*1.0/nDMaxVal * nH ;
            p2 = QPoint(x,y) ;
            P.drawLine(p1,p2) ;
            p1 = p2 ;

            if(nSPCount>0 && (i == nDCount-1 || i % nSPCount == 0))
            {
                P.drawEllipse(p2,4,4) ;
                m_hotRects.append(QRect(x-2,y-2,8,8)) ;
                m_hotIndexs.append(i) ;
            }
        }
    }

    QPointF click = m_clkPoint ;
    if(!click.isNull())
    {
        P.setRenderHint(QPainter::Antialiasing, false);
        P.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
        // P.drawLine(QPointF(rc.left(),click.y()),QPointF(rc.right(),click.y())) ;
        // P.drawLine(QPointF(click.x(),rc.top()),QPointF(click.x(),rc.bottom())) ;
    }

    QFrame::paintEvent(event) ;
}

