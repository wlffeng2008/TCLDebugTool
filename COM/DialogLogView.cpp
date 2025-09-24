#include "DialogLogView.h"
#include "ui_DialogLogView.h"

#include <QDateTime>
#include <QWindow>

DialogLogView::DialogLogView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogView)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint) ;

    ui->plainTextEdit->setMaximumBlockCount(1000) ;

    connect(ui->checkBoxSetTop,&QCheckBox::toggled,this,[=](bool checked){
        QWindow *pWin = windowHandle() ;
        if(checked)
            pWin->setFlags(windowFlags() | Qt::WindowStaysOnTopHint) ;
        else
            pWin->setFlags(windowFlags() & ~Qt::WindowStaysOnTopHint) ;
        show() ;
    }) ;
}

DialogLogView::~DialogLogView()
{
    delete ui;
}


void DialogLogView::pushLogText(const QString&strLog,bool isSend)
{
    QDateTime now = QDateTime::currentDateTime() ;
    QString strTime = now.toString("MM-dd hh:mm:ss.zzz") ;
    strTime += isSend ? ": ---> " :": <--- ";
    ui->plainTextEdit->appendPlainText(strTime + strLog + QString(isSend ? "" : "\n")) ;
}

void DialogLogView::on_pushButtonClear_clicked()
{
    ui->plainTextEdit->clear() ;
}
