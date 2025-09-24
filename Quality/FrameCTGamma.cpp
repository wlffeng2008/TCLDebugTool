#include "FrameCTGamma.h"
#include "ui_FrameCTGamma.h"

FrameCTGamma::FrameCTGamma(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameCTGamma)
{
    ui->setupUi(this);

    m_pSCT = new  FrameGenGammaEdit(this) ;
    m_pDCT = new  FrameGenGammaEdit(this) ;

    m_pSCT->setDataRange(4096,4095) ;
    m_pDCT->setDataRange(2048,4095) ;

    m_pSCT->setGammaCount(1, {11<<13}) ;
    m_pDCT->setGammaCount(1, {12<<13}) ;

    m_pDCT->setDivCol(16) ;

    ui->pushButton1->setChecked(true) ;

    this->layout()->addWidget(m_pSCT) ;
    this->layout()->addWidget(m_pDCT) ;

    m_pDCT->hide() ;

    connect(ui->pushButton1,&QPushButton::clicked,this,[=]{
        m_pSCT->show() ;
        m_pDCT->hide() ;
        ui->pushButton1->setChecked(true) ;
        ui->pushButton2->setChecked(false) ;
    });

    connect(ui->pushButton2,&QPushButton::clicked,this,[=]{
        m_pSCT->hide() ;
        m_pDCT->show() ;
        ui->pushButton1->setChecked(false) ;
        ui->pushButton2->setChecked(true) ;
    });
}

FrameCTGamma::~FrameCTGamma()
{
    delete ui;
}
