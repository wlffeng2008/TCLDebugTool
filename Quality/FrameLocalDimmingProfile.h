#ifndef FRAMELOCALDIMMINGPROFILE_H
#define FRAMELOCALDIMMINGPROFILE_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QImage>

#include<QGraphicsScene>

namespace Ui {
class FrameLocalDimmingProfile;
}

class FrameLocalDimmingProfile : public QFrame
{
    Q_OBJECT

public:
    explicit FrameLocalDimmingProfile(QWidget *parent = nullptr);
    ~FrameLocalDimmingProfile();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::FrameLocalDimmingProfile *ui;

    SerialTestDialog *m_pCOMDlg = nullptr ;

    QGraphicsScene *m_sence = nullptr ;

    qreal m_factor=1.0 ;
    bool m_bCtrlPress = false ;
    bool m_bShiftlPress = false ;
    bool m_bAltPress = false ;
    QRect m_rcOrg ;
    QImage m_img ;
    void pickup(const QPointF & pt) ;
};

#endif // FRAMELOCALDIMMINGPROFILE_H
