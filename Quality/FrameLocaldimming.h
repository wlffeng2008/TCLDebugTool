#ifndef FRAMELOCALDIMMING_H
#define FRAMELOCALDIMMING_H

#include <QFrame>

namespace Ui {
class FrameLocaldimming;
}

class FrameLocaldimming : public QFrame
{
    Q_OBJECT

public:
    explicit FrameLocaldimming(QWidget *parent = nullptr);
    ~FrameLocaldimming();

private:
    Ui::FrameLocaldimming *ui;
};

#endif // FRAMELOCALDIMMING_H
