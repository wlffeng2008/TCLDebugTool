#ifndef FRAMECONTROL_H
#define FRAMECONTROL_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QTimer>
#include <QStandardItemModel>

namespace Ui {
class FrameControl;
}

class FrameControl : public QFrame
{
    Q_OBJECT

public:
    explicit FrameControl(QWidget *parent = nullptr);
    ~FrameControl();

private:
    Ui::FrameControl *ui;
    SerialTestDialog *m_pCOMDlg = nullptr;

    QTimer m_TMSendSliderValue;
    int m_sendIndex = -1 ;
    void sendData(int nIndex) ;

    QStandardItemModel *m_pModel = nullptr ;

    int m_nSelect = -1 ;
    int m_nCol = -1 ;
    int m_nAddr   = -1 ;

    bool m_bReading = false ;
    void  doReadReg() ;
};

#endif // FRAMECONTROL_H
