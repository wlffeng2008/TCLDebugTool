#include "DialogQualityManager.h"
#include "ui_DialogQualityManager.h"

#include <QDebug>
#include <QWindow>

DialogQualityManager::DialogQualityManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogQualityManager)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowMinMaxButtonsHint|Qt::Window;
    setWindowFlags(flags);
    connect(ui->checkBoxOntop,&QCheckBox::toggled,this,[=](bool checked){
        QWindow *pWin = windowHandle() ;
        if(checked)
            pWin->setFlags(windowFlags() | Qt::WindowStaysOnTopHint) ;
        else
            pWin->setFlags(windowFlags() & ~Qt::WindowStaysOnTopHint) ;
        show() ;
    }) ;


    showFrame(0);

    connect(ui->buttonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::idClicked), this,[=](int nIndex){
        if(nIndex <= -2)
            showFrame(abs(nIndex) - 2);
        else
            showFrame(nIndex);
    });

    setStyleSheet("font: bold 14px 微软雅黑; background-color: !important;") ;
}

DialogQualityManager::~DialogQualityManager()
{
    delete ui;
}

void DialogQualityManager::showFrame(int nIndex)
{
    static QFrame *pFrames[]=
    {
        ui->frame0,
        ui->frame1,
        ui->frame2,
        ui->frame3,
        ui->frame4,
        ui->frame5,
        ui->frame6,
        ui->frame7,
        ui->frame8,
        ui->frame9
    } ;

    for(quint64 i=0; i<sizeof(pFrames)/sizeof(QFrame *); i++)
        pFrames[i]->hide();
    pFrames[nIndex]->show() ;
}
