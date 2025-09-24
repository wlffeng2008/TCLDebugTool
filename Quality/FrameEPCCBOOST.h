#ifndef FRAMEEPCCBOOST_H
#define FRAMEEPCCBOOST_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QStandardItemModel>


namespace Ui {
class FrameEPCCBOOST;
}

class FrameEPCCBOOST : public QFrame
{
    Q_OBJECT

public:
    explicit FrameEPCCBOOST(QWidget *parent = nullptr);
    ~FrameEPCCBOOST();
protected:
    void paintEvent(QPaintEvent *pEvt) override ;
    void resizeEvent(QResizeEvent *pEvt) override ;

private:
    Ui::FrameEPCCBOOST *ui;

    QStandardItemModel *m_pModel4 = nullptr ;
    QStandardItemModel *m_pModel5 = nullptr ;
    QStandardItemModel *m_pModel6 = nullptr ;

    int m_nOpType = 0 ;
    int m_nSelect1 = -1 ;
    int m_nSelect2 = -1 ;
    int m_nSelect3 = -1 ;
    SerialTestDialog *m_pCOMDlg = nullptr ;

    quint32 m_addr = (9<<13) ;

    bool m_bLoading = false ;
    void LoadBuf(const QString&strFile,bool bForLinar);
    void SaveLoadTable(bool bToSave=true) ;

    void doCalc() ;
};

#endif // FRAMEEPCCBOOST_H
