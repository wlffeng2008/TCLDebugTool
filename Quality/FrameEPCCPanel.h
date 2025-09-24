#ifndef FRAMEEPCCPANEL_H
#define FRAMEEPCCPANEL_H

#include <QFrame>

namespace Ui {
class FrameEPCCPanel;
}

class FrameEPCCPanel : public QFrame
{
    Q_OBJECT

public:
    explicit FrameEPCCPanel(QWidget *parent = nullptr);
    ~FrameEPCCPanel();

    void setBuf(int nBuf,int nIndex,int nValue) ;
    int getBuf(int nBuf,int nIndex) ;

protected:
    void paintEvent(QPaintEvent *pEvt) override ;

private:
    Ui::FrameEPCCPanel *ui;

    quint16 m_bufA[5000]={0} ;
    quint16 m_bufB[5000]={0};
};

#endif // FRAMEEPCCPANEL_H
