#ifndef FRAMEBLGAMMAPANEL_H
#define FRAMEBLGAMMAPANEL_H

#include <QFrame>
#include <QList>
#include <QPointF>
#include <QMouseEvent>
#include <QPainterPath>

namespace Ui {
class FrameBLGammaPanel;
}

class FrameBLGammaPanel : public QFrame
{
    Q_OBJECT
public:
    explicit FrameBLGammaPanel(QWidget *parent = nullptr);
    ~FrameBLGammaPanel();

    void setBuf(int nBuf,int nIndex,int nValue) ;
    int  getBuf(int nBuf,int nIndex) ;
    void setShowGamin(bool bShow=true) ;
    void setShowRemap(bool bShow=true) ;
    void setGammaStage(int nStage=20) ;

    void changeValue(int nIndex,int nValue) ;

signals:
    void onBufChanged(double *pBuf,int nCount=4096) ;
    void onValueChanged(int index,int value) ;
    void onClickIndex(int index,int value) ;

protected:
    void paintEvent(QPaintEvent *event) override ;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    Ui::FrameBLGammaPanel *ui;

    double m_bufA[5000] ;
    double m_bufB[5000] ;
    QRect  m_drawRect ;
    QPointF m_clkPoint=QPointF(0,0);

    bool m_bDraging = false ;
    int m_nEditIndex = -1 ;
    int m_nHitIndex = -1 ;

    quint16  m_dataCount = 4096;

    int m_stage = 32 ;
    QList<QRect> m_hotRects ;
    QList<int> m_hotIndexs ;

    bool m_bshowGamIn = true ;
    bool m_bshowRemap = true ;

    int valueFromPos(const QPoint &pos) ;
    int indexFromPos(const QPoint &pos) ;
};

#endif // FRAMEBLGAMMAPANEL_H
