#include "DialogSpeacialRead.h"
#include "ui_DialogSpeacialRead.h"

DialogSpeacialRead::DialogSpeacialRead(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSpeacialRead)
{
    ui->setupUi(this);
}

DialogSpeacialRead::~DialogSpeacialRead()
{
    delete ui;
}
