#ifndef FRAMEGENGAMMAEDIT_H
#define FRAMEGENGAMMAEDIT_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QStandardItemModel>

namespace Ui {
class FrameGenGammaEdit;
}

class FrameGenGammaEdit : public QFrame
{
    Q_OBJECT

public:
    explicit FrameGenGammaEdit(QWidget *parent = nullptr);
    ~FrameGenGammaEdit();

    void setDataRange(int nCount,int nMax);
    void setGammaCount(int nCount,const QList<quint32>&addrs) ;

    void setGammaAddr(const QList<quint32>&addrs) ;
    void setGammaAddr(int nIndex,quint32 addr) ;

    void setDrawMargin(int nLeft,int nTop,int nRight,int nBottom) ;

    void setDrawColor(const QList<QColor>&colors) ;
    void setDrawColor(int nIndex,const QColor&color) ;

    void setDivCol(int nHDivCol=4,int nVDivCol=4);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override ;

private:
    Ui::FrameGenGammaEdit *ui;
    QStandardItemModel *m_pModel = nullptr;
    bool m_bLoading = false ;

    bool m_bDraging = false ;
    int m_nEditIndex = -1 ;
    int m_nHitIndex = -1 ;
    QPointF m_clkPoint = QPointF(0,0);

    int m_nHDivCol = 4 ;
    int m_nVDivCol = 4 ;
    int m_nDCount  = 4096 ;
    int m_nDMaxVal = 4095 ;
    int m_nEditX = -1 ;
    QRect m_drawRect ;
    int m_stage = 32 ;
    QList<QRect> m_hotRects ;
    QList<int> m_hotIndexs ;

    void doRead() ;
    void doWrite() ;
    void loadFile() ;
    void saveFile() ;

    quint32 m_nCammaAddr[32]={0} ;
    int m_nGammaCount = 1 ;
    int m_nGammaIndex = 0 ;
    qreal m_nGammaBuf[32][8192]={{0}} ;
    qreal m_nGammaOrg[32][8192]={{0}} ;
    QColor m_colors[32]={Qt::white} ;
    QString m_strFiles[32] ;

    int valueFromPos(const QPoint &pos) ;
    int indexFromPos(const QPoint &pos) ;

    int m_nMarginL = 60 ;
    int m_nMarginT = 10 ;
    int m_nMarginR = 10 ;
    int m_nMarginB = 30 ;

    SerialTestDialog *m_pCOMDlg = nullptr ;
};

#endif // FRAMEGENGAMMAEDIT_H
