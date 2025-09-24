#ifndef FRAMECTGAMMA_H
#define FRAMECTGAMMA_H

#include <QFrame>
#include <FrameGenGammaEdit.h>

namespace Ui {
class FrameCTGamma;
}

class FrameCTGamma : public QFrame
{
    Q_OBJECT

public:
    explicit FrameCTGamma(QWidget *parent = nullptr);
    ~FrameCTGamma();

private:
    Ui::FrameCTGamma *ui;

    FrameGenGammaEdit *m_pSCT = nullptr;
    FrameGenGammaEdit *m_pDCT = nullptr;
};

#endif // FRAMECTGAMMA_H
