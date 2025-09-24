#include "FrameLocaldimming.h"
#include "ui_FrameLocaldimming.h"

FrameLocaldimming::FrameLocaldimming(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameLocaldimming)
{
    ui->setupUi(this);
}

FrameLocaldimming::~FrameLocaldimming()
{
    delete ui;
}
