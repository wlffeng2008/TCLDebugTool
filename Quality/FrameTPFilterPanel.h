#ifndef FRAMETPFILTERPANEL_H
#define FRAMETPFILTERPANEL_H

#include <QFrame>

namespace Ui {
class FrameTPFilterPanel;
}

class FrameTPFilterPanel : public QFrame
{
    Q_OBJECT

public:
    explicit FrameTPFilterPanel(QWidget *parent = nullptr);
    ~FrameTPFilterPanel();

    void setBuf(int nBuf,int nIndex,int nValue) ;

protected:
    void paintEvent(QPaintEvent *pEvt) override ;

private:
    Ui::FrameTPFilterPanel *ui;

    quint16 m_bufA[5000] ;
    quint16 m_bufB[5000] ;
};

#endif // FRAMETPFILTERPANEL_H
