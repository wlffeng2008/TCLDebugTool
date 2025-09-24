#include "DialogRegRamManager.h"
#include "ui_DialogRegRamManager.h"

#include<QWindow>

DialogRegRamManager::DialogRegRamManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegRamManager)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowMinMaxButtonsHint;
    setWindowFlags(flags);

    connect(ui->checkBoxOntop,&QCheckBox::toggled,this,[=](bool checked){
        QWindow *pWin = windowHandle() ;
        if(checked)
            pWin->setFlags(windowFlags() | Qt::WindowStaysOnTopHint) ;
        else
            pWin->setFlags(windowFlags() & ~Qt::WindowStaysOnTopHint) ;
        show() ;
    }) ;

    ui->radioButtonReg->setChecked(true) ;
    on_radioButtonReg_clicked() ;

    setStyleSheet("font: bold 12px 微软雅黑;") ;
}

DialogRegRamManager::~DialogRegRamManager()
{
    delete ui;
}

void DialogRegRamManager::on_radioButtonReg_clicked()
{
    ui->frameRight->hide() ;
    ui->frameLeft->show() ;
}

void DialogRegRamManager::on_radioButtonRam_clicked()
{
    ui->frameLeft->hide() ;
    ui->frameRight->show() ;
}

