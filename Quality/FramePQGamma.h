#ifndef FRAMEPQGAMMA_H
#define FRAMEPQGAMMA_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class FramePQGamma;
}

class FramePQGamma : public QFrame
{
    Q_OBJECT

public:
    explicit FramePQGamma(QWidget *parent = nullptr);
    ~FramePQGamma();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override ;
private:
    Ui::FramePQGamma *ui;

    QStandardItemModel *m_pModel = nullptr;

    QString m_strFile ;

    int m_nCurType = 0 ;
    int m_nEditX = 0 ;
    int getCol() ;

    quint32 m_addrR = (45<<13) ;
    quint32 m_addrG = (46<<13) ;
    quint32 m_addrB = (47<<13) ;

    quint32 getAddr(int nType) ;

    void doRead(int nType) ;
    void doWrite(int nType) ;
    void loadFile() ;
    void saveFile() ;
    bool m_bLoading = false ;

    bool m_bDraging = false ;
    int m_nEditIndex = -1 ;
    int m_nHitIndex = -1 ;
    QPointF m_clkPoint=QPointF(0,0);

    QRect  m_drawRect ;
    int m_stage = 32 ;
    QList<QRect> m_hotRects ;
    QList<int> m_hotIndexs ;

    int valueFromPos(const QPoint &pos) ;
    int indexFromPos(const QPoint &pos) ;

    SerialTestDialog *m_pCOMDlg = nullptr ;
};

#endif // FRAMEPQGAMMA_H
