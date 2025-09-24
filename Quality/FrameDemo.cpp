#include "FrameDemo.h"
#include "ui_FrameDemo.h"

#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QSettings>

FrameDemo::FrameDemo(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameDemo)
{
    ui->setupUi(this);
    m_pCOMDlg = SerialTestDialog::getInstance() ;
    connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](const QString&strModel){
        Q_UNUSED(strModel)
        if(m_pSet)
            delete m_pSet ;
        m_pSet = new QSettings(m_pCOMDlg->getDataPath() + "DemoConfig.ini",QSettings::IniFormat) ;
        SaveLoadDemoConfig(false) ;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        unsigned char *pData = (unsigned char *)data.data() ;
        sPackHeader *pHD = (sPackHeader *)pData ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }
    });

    ui->frame->installEventFilter(this);
    ui->frame->setMouseTracking(true) ;

    ui->radioButton_1->setChecked(true) ;
    ui->radioButton_4->setChecked(true) ;

    connect(ui->checkBoxSelectArea,&QCheckBox::clicked,this,[=]{
        m_pCOMDlg->sendSwitch(0x105B,ui->checkBoxSelectArea->isChecked(),this);
        SaveLoadDemoConfig() ;
    });

    connect(ui->checkBoxFullSrceen,&QCheckBox::clicked,this,[=]{
        if(ui->checkBoxFullSrceen->isChecked())
        {
            ui->frame->setDisabled(true);
            ui->lineEdit_X1->setText("0") ;
            ui->lineEdit_Y1->setText("0") ;
            ui->lineEdit_X2->setText(ui->lineEditSrcW->text()) ;
            ui->lineEdit_Y2->setText(ui->lineEditSrcH->text()) ;
            calcRect();
        }
        else
        {
            ui->frame->setDisabled(false);
        }
    });

    connect(ui->buttonGroup1, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::idClicked), this,[=](int nIndex){
        m_pCOMDlg->sendInt8(0x1052,abs(nIndex) - 2,this);
        m_pCOMDlg->sendInt8(0x1252,abs(nIndex) - 2,this);
    });

    connect(ui->buttonGroup2, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::idClicked), this,[=](int nIndex){
        m_pCOMDlg->sendInt8(0x160E,abs(nIndex) - 2,this);
    });

    connect(ui->lineEditSrcW,&QLineEdit::editingFinished,this,[=](){ calcRect(); });
    connect(ui->lineEditSrcH,&QLineEdit::editingFinished,this,[=](){ calcRect(); });
    connect(ui->lineEdit_X1, &QLineEdit::editingFinished,this,[=](){ calcRect(); });
    connect(ui->lineEdit_Y1, &QLineEdit::editingFinished,this,[=](){ calcRect(); });
    connect(ui->lineEdit_X2, &QLineEdit::editingFinished,this,[=](){ calcRect(); });
    connect(ui->lineEdit_Y2, &QLineEdit::editingFinished,this,[=](){ calcRect(); });

    connect(ui->pushButtonSetEara,&QPushButton::clicked,this,[=](){
        int nX1 = ui->lineEdit_X1->text().trimmed().toInt() ;
        int nY1 = ui->lineEdit_Y1->text().trimmed().toInt() ;
        int nX2 = ui->lineEdit_X2->text().trimmed().toInt() ;
        int nY2 = ui->lineEdit_Y2->text().trimmed().toInt() ;

        m_pCOMDlg->sendInt16(0x105C,nX1,this);
        m_pCOMDlg->sendInt16(0x105E,nY1,this);
        m_pCOMDlg->sendInt16(0x1060,nX2,this);
        m_pCOMDlg->sendInt16(0x1062,nY2,this);
    }) ;

}

FrameDemo::~FrameDemo()
{
    delete ui;
}

void FrameDemo::SaveLoadDemoConfig(bool bToSave)
{
    if(!m_pSet)
        return ;

    if(bToSave)
    {
        m_pSet->setValue("ScreenWidth",ui->lineEditSrcW->text());
        m_pSet->setValue("ScreenHeight",ui->lineEditSrcH->text());
        m_pSet->setValue("MapX1",ui->lineEdit_X1->text());
        m_pSet->setValue("MapY1",ui->lineEdit_Y1->text()) ;
        m_pSet->setValue("MapX2",ui->lineEdit_X2->text()) ;
        m_pSet->setValue("MapY2",ui->lineEdit_Y2->text()) ;
        m_pSet->setValue("fullsrceen",ui->checkBoxFullSrceen->isChecked()) ;

        m_pSet->setValue("X1",m_p1.x());
        m_pSet->setValue("Y1",m_p1.y()) ;
        m_pSet->setValue("X2",m_p2.x()) ;
        m_pSet->setValue("Y2",m_p2.y()) ;
    }
    else
    {
        ui->lineEditSrcW->setText(m_pSet->value("ScreenWidth",3840).toString()) ;
        ui->lineEditSrcH->setText(m_pSet->value("ScreenHeight",2160).toString());
        ui->lineEdit_X1->setText(m_pSet->value("MapX1",0).toString());
        ui->lineEdit_Y1->setText(m_pSet->value("MapY1",0).toString()) ;
        ui->lineEdit_X2->setText(m_pSet->value("MapX2",600).toString()) ;
        ui->lineEdit_Y2->setText(m_pSet->value("MapY2",480).toString()) ;

        m_p1 = QPoint(m_pSet->value("X1",0).toInt(),m_pSet->value("Y1",600).toInt()) ;
        m_p2 = QPoint(m_pSet->value("X2",0).toInt(),m_pSet->value("Y2",480).toInt()) ;

        ui->checkBoxFullSrceen->setChecked(!m_pSet->value("fullsrceen",false).toBool()) ;
        ui->checkBoxFullSrceen->click() ;
    }
}

int FrameDemo::getMapX(int nOrgX)
{
    QSize fs = ui->frame->size() ;

    int nSrcW = ui->lineEditSrcW->text().trimmed().toInt() ;

    int nMap = nSrcW * nOrgX / fs.width() ;
    if(nMap>nSrcW)
        nMap = nSrcW;

    return nMap ;
}

int FrameDemo::getMapY(int nOrgY)
{
    QSize fs = ui->frame->size() ;

    int nSrcH = ui->lineEditSrcH->text().trimmed().toInt() ;

    int nMap = nSrcH * nOrgY / fs.height() ;
    if(nMap>nSrcH)
        nMap = nSrcH;

    return nMap ;
}

void FrameDemo::calcRect()
{
    QSize fs = ui->frame->size() ;
    int nSrcW = ui->lineEditSrcW->text().trimmed().toInt() ;
    int nSrcH = ui->lineEditSrcH->text().trimmed().toInt() ;
    int nX1 = ui->lineEdit_X1->text().trimmed().toInt() ;
    int nY1 = ui->lineEdit_Y1->text().trimmed().toInt() ;
    int nX2 = ui->lineEdit_X2->text().trimmed().toInt() ;
    int nY2 = ui->lineEdit_Y2->text().trimmed().toInt() ;

    nX1 = fs.width() * nX1 / nSrcW ;
    nX2 = fs.width() * nX2 / nSrcW ;
    nY1 = fs.height() * nY1 / nSrcH ;
    nY2 = fs.height() * nY2 / nSrcH ;

    if(nX1>fs.width())  nX1=fs.width() ;
    if(nX2>fs.width())  nX2=fs.width() ;
    if(nY1>fs.height())  nY1=fs.height() ;
    if(nY2>fs.height())  nY2=fs.height() ;

    m_p1 = QPointF(nX1,nY1);
    m_p2 = QPointF(nX2,nY2);

    ui->frame->update() ;

    SaveLoadDemoConfig() ;
}

bool FrameDemo::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->frame)
    {
        QMouseEvent *mEvent = static_cast<QMouseEvent *>(event) ;
        int nType = event->type() ;
        switch(nType)
        {
        case QEvent::Enter:
            if(!ui->frame->isEnabled())
                break;
            setCursor(Qt::CrossCursor);
            break;
        case QEvent::Leave:
            setCursor(Qt::ArrowCursor);
            break;

        case QEvent::MouseButtonPress:
            if(!ui->frame->isEnabled())
                break;
            m_bDraging = true ;
            m_p1 = mEvent->localPos() ;
            ui->lineEdit_X1->setText(QString::number(getMapX(m_p1.x()))) ;
            ui->lineEdit_Y1->setText(QString::number(getMapY(m_p1.y()))) ;
            break;

        case QEvent::MouseButtonRelease:
            m_bDraging = false ;
            SaveLoadDemoConfig() ;
            break;

        case QEvent::MouseMove:
            if(!ui->frame->isEnabled())
                break;
            if(m_bDraging)
            {
                m_p2 = mEvent->localPos() ;
                ui->lineEdit_X2->setText(QString::number(getMapX(m_p2.x()))) ;
                ui->lineEdit_Y2->setText(QString::number(getMapY(m_p2.y()))) ;
                ui->frame->update() ;
            }
            else
            {
                //ui->frame->setToolTip("123456") ;
            }
            break;

        case QEvent::Paint:
        {
            QPainter painter(ui->frame) ;
            QRect rcTmp = ui->frame->rect() ;
            painter.fillRect(rcTmp,QBrush(QColor(80,80,80))) ;
            painter.fillRect(QRectF(m_p1,m_p2),QBrush(QColor(85, 170, 255))) ;

            return true ;
        }
            break;
        }
    }

    return QFrame::eventFilter(watched, event);
}

