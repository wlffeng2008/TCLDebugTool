#ifndef FRAMEDEMO_H
#define FRAMEDEMO_H

#include <QFrame>
#include <QSettings>

#include <SerialTestDialog.h>

namespace Ui {
class FrameDemo;
}

class FrameDemo : public QFrame
{
    Q_OBJECT

public:
    explicit FrameDemo(QWidget *parent = nullptr);
    ~FrameDemo();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:

private:
    Ui::FrameDemo *ui;

    QPointF m_p1 ;
    QPointF m_p2 ;
    bool m_bDraging = false ;

    int getMapX(int nOrgX) ;
    int getMapY(int nOrgY) ;
    void calcRect() ;
    QSettings *m_pSet = nullptr ;
    void SaveLoadDemoConfig(bool bToSave=true) ;

    SerialTestDialog *m_pCOMDlg = nullptr ;
};

#endif // FRAMEDEMO_H
