#include "FramePixelCompensation.h"
#include "ui_FramePixelCompensation.h"

#include <QMessageBox>
#include <QTimer>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QDebug>

FramePixelCompensation::FramePixelCompensation(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FramePixelCompensation)
{
    ui->setupUi(this);

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        quint8 *pData = m_pCOMDlg->GetDataBody() ;
        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;
        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }

        m_bLoading = true ;
        if(pHD->len == 36)
        {
            for(int i=0; i<36; i++)
                m_pDModel->item(i,1)->setText(QString::number(pData[i])) ;

            fillGrid(false) ;
        }
        quint16 value = *(quint16 *)pData;
        switch(pHD->addr)
        {
        case 0x1064: ui->horizontalSlider1->setValue(value); break;
        case 0x1066: ui->horizontalSlider2->setValue((quint8)value); break;
        case 0x1068: ui->horizontalSlider3->setValue(value); break;
        }
        QTimer::singleShot(500,this,[=]{ m_bLoading = false; });
    });

    {
        //ui->tableViewGrid->setProperty("PanelStyle",true);
        ui->tableViewGrid->setStyleSheet("");
        ui->tableViewGrid->setFixedSize(442,442);
        m_pGModel = new QStandardItemModel(11,11,this) ;
        ui->tableViewGrid->setModel(m_pGModel) ;

        ui->tableViewGrid->horizontalHeader()->hide();
        ui->tableViewGrid->verticalHeader()->hide();

        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                QStandardItem *item = new QStandardItem() ;
                item->setText("0" ) ;
                item->setEditable(i<=5 && j<=5) ;
                item->setTextAlignment(Qt::AlignCenter);
                item->setBackground(QBrush(Qt::white));
                m_pGModel->setItem(i,j,item);

                if(j<=5 && i <= 5)
                {
                    if(i == 0 || j == 0)
                        item->setForeground(QBrush(QColor(Qt::darkCyan)));

                    else if(i == 1 || j == 1)
                        item->setForeground(QBrush(QColor(Qt::blue)));

                    else if(i == 2 || j == 2)
                        item->setForeground(QBrush(QColor(Qt::green)));

                    else if(i == 3 || j == 3)
                        item->setForeground(QBrush(QColor(Qt::red)));

                    else if(i == 4 || j == 4)
                        item->setForeground(QBrush(QColor(Qt::darkYellow)));

                    else if(i == 5 || j == 5)
                        item->setForeground(QBrush(QColor(Qt::magenta)));
                }
                else
                {
                    item->setEditable(false);
                    item->setEnabled(false) ;
                    item->setForeground(QBrush(QColor(Qt::gray)));
                }
            }

            ui->tableViewGrid->setColumnWidth(i,40);
            ui->tableViewGrid->setRowHeight(i,40) ;
        }
    }

    {
        m_pDModel = new QStandardItemModel(36,2,this) ;
        ui->tableView->setModel(m_pDModel) ;
        QHeaderView *header = ui->tableView->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
        header->setSectionResizeMode(1,QHeaderView::Fixed);
        header->resizeSection(1,50) ;

        ui->tableView->horizontalHeader()->hide();
        ui->tableView->verticalHeader()->hide();
        for(int i=0; i<36; i++)
        {
            QStandardItem *pItem0= new QStandardItem() ;
            pItem0->setText("expand_weight" + QString::number(i+1)) ;
            pItem0->setEditable(false) ;
            m_pDModel->setItem(i,0,pItem0);

            QStandardItem *pItem1= new QStandardItem() ;
            pItem1->setText("0") ;
            m_pDModel->setItem(i,1,pItem1);
            ui->tableView->setRowHeight(i,20) ;
            if(i>=30)
                pItem1->setForeground(QBrush(QColor(Qt::magenta)));
            else if(i>=24)
                pItem1->setForeground(QBrush(QColor(Qt::darkYellow)));
            else if(i>=18)
                pItem1->setForeground(QBrush(QColor(Qt::red)));
            else if(i>=12)
                pItem1->setForeground(QBrush(QColor(Qt::green)));
            else if(i>=6)
                pItem1->setForeground(QBrush(QColor(Qt::blue)));
            else
                pItem1->setForeground(QBrush(QColor(Qt::darkCyan)));
        }

        ui->tableView->setColumnWidth(0,160);
        ui->tableView->setColumnWidth(1,60);

        connect(m_pCOMDlg,&SerialTestDialog::COMModelChanged,this,[=](){
            if(m_pSet)
                delete m_pSet ;
            m_pSet = new QSettings(m_pCOMDlg->getDataPath() + "expand_weight36.ini",QSettings::IniFormat);
            QStringList EWs = m_pSet->value("expand_weights").toStringList() ;
            if(EWs.isEmpty())
                EWs = QString("1, 2, 3, 5, 6, 7, 2, 3, 6, 9, 12, 14, 3, 5, 10, 17, 26, 31, 3, 7, 15, 31, 58, 76, 4, 9, 20, 50, 128, 228, 5, 11, 24, 64, 195, 255").split(',') ;
            for(int i=0; i<36; i++)
                m_pDModel->item(i,1)->setText(EWs[i]) ;
            fillGrid() ;
        });
    }

    ui->tableView->setFocusPolicy(Qt::NoFocus) ;
    ui->tableViewGrid->setFocusPolicy(Qt::NoFocus) ;

    connect(m_pDModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) { Q_UNUSED(item)  fillGrid(false) ; });
    connect(m_pGModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) { Q_UNUSED(item)  fillGrid(true)  ; });

    connect(ui->horizontalSlider1,&QSlider::valueChanged,this,[=](int value){
        ui->lineEdit1->setText( QString("%1").arg(value)) ;
    }) ;
    connect(ui->horizontalSlider2,&QSlider::valueChanged,this,[=](int value){
        ui->lineEdit2->setText( QString("%1").arg(value)) ;
    }) ;
    connect(ui->horizontalSlider3,&QSlider::valueChanged,this,[=](int value){
        ui->lineEdit3->setText( QString("%1").arg(value)) ;
    }) ;

    connect(ui->horizontalSlider1,&QSlider::sliderReleased,this,[=](){ sendValue(1) ; }) ;
    connect(ui->horizontalSlider2,&QSlider::sliderReleased,this,[=](){ sendValue(2) ; }) ;
    connect(ui->horizontalSlider3,&QSlider::sliderReleased,this,[=](){ sendValue(3) ; }) ;

    connect(ui->lineEdit1,&QLineEdit::editingFinished,this,[=](){
        ui->horizontalSlider1->setValue(ui->lineEdit1->text().toInt()) ;
        sendValue(1) ;
    }) ;
    connect(ui->lineEdit2,&QLineEdit::editingFinished,this,[=](){
        ui->horizontalSlider2->setValue(ui->lineEdit2->text().toInt()) ;
        sendValue(2) ;
    }) ;
    connect(ui->lineEdit3,&QLineEdit::editingFinished,this,[=](){
        ui->horizontalSlider3->setValue(ui->lineEdit3->text().toInt()) ;
        sendValue(3) ;
    }) ;
    connect(ui->pushButtonRead,&QPushButton::clicked,this,[=]{
        if(!m_pCOMDlg->isConnected(false))
        {
            return ;
        }
        m_pCOMDlg->readRegData(0x1064,2,this);
        m_pCOMDlg->readRegData(0x1066,1,this);
        m_pCOMDlg->readRegData(0x1068,2,this);
    }) ;

    ui->horizontalSlider1->setValue(0xFFF) ;
    ui->horizontalSlider2->setValue(0x01) ;
    ui->horizontalSlider3->setValue(0xFFF) ;

    QTimer::singleShot(500,this,[=](){ m_bAutoSEnd = true ;}) ;

    connect(ui->buttonGroup1, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::idClicked), this,[=](int nIndex){
        Q_UNUSED(nIndex)
        on_pushButtonWriteM_clicked() ;
    });
}

FramePixelCompensation::~FramePixelCompensation()
{
    delete ui;
}

void FramePixelCompensation::sendValue(int nIndex)
{
    if(m_bLoading)
        return ;
    quint16 value1 = ui->horizontalSlider1->value();
    qint8   value2 = ui->horizontalSlider2->value();
    quint16 value3 = ui->horizontalSlider3->value();
    switch(nIndex)
    {
    case 1: m_pCOMDlg->sendInt16(0x1064,value1,this); break ;
    case 2: m_pCOMDlg->sendInt8 (0x1066,value2,this); break ;
    case 3: m_pCOMDlg->sendInt16(0x1068,value3,this); break ;
    }
}

void FramePixelCompensation::fillGrid(bool bSelf)
{
    int i=0;
    int j=0;
    QStringList  EWs;

    if(!bSelf)
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                QString strText = m_pDModel->item(i*6 + j,1)->text() ;
                m_pGModel->item(i, j)->setText(strText);
                m_pGModel->item(i, 10-j)->setText(strText);

                EWs.push_back(strText) ;
            }
        }
    }
    else
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                QString strText = m_pGModel->item(i,j)->text() ;
                m_pGModel->item(i, 10-j)->setText(strText);
            }
        }

        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                EWs.push_back(m_pGModel->item(i,j)->text()) ;
            }
        }

        for(i=0; i<36; i++)
            m_pDModel->item(i,1)->setText(EWs[i]) ;
    }

    for(i=0; i<5; i++)
    {
        for(j=0; j<11; j++)
        {
            QString strText = m_pGModel->item(i, j)->text() ;
            m_pGModel->item(10-i, j)->setText(strText);
        }
    }

    EWs.clear() ;
    for(i=0; i<36; i++)
    {
        EWs.push_back(m_pDModel->item(i,1)->text()) ;
    }
    m_pSet->setValue("expand_weights",EWs);
}

void FramePixelCompensation::on_pushButtonWriteM_clicked()
{
    if(!m_pCOMDlg->isConnected(false))
    {
        return ;
    }
    char empty[64] = {0} ;
    QByteArray buf ;
    for(int i=0; i<36; i++)
    {
        quint8 val = m_pDModel->item(i,1)->text().toInt() ;
        buf.append(val) ;
    }

    if(ui->radioButtonM1->isChecked())
    {
        m_pCOMDlg->writeRegData(0x1067,buf.data(),36,this) ;
        m_pCOMDlg->writeRegData(0x1267,buf.data(),36,this) ;
    }

    if(ui->radioButtonM2->isChecked())
    {
        m_pCOMDlg->writeRegData(0x1067,buf.data(),36,this) ;
        m_pCOMDlg->writeRegData(0x1267,empty,36,this) ;
    }

    if(ui->radioButtonM3->isChecked())
    {
        m_pCOMDlg->writeRegData(0x1067,empty,36,this) ;
        m_pCOMDlg->writeRegData(0x1267,buf.data(),36,this) ;
    }

    if(ui->radioButtonM4->isChecked())
    {
        m_pCOMDlg->writeRegData(0x1067,empty,36,this) ;
        m_pCOMDlg->writeRegData(0x1267,empty,36,this) ;
    }
}


void FramePixelCompensation::on_pushButtonReadM_clicked()
{
    m_pCOMDlg->readRegData(0x1067,36,this) ;
}


void FramePixelCompensation::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开expand_weights文件", m_pCOMDlg->getDataPath(),
                                                   tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;
    m_strCurFile = strFile ;

    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,"提示","文件打开失败，请重试！");
        return ;
    }

    int j = 0 ;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QStringList items = in.readLine().trimmed().split(',');
        if(items.count() != 11)
        {
            QMessageBox::critical(this,"提示","文件格式错误，请重试！");
            break;
        }
        for(int i=0; i<11; i++)
            m_pGModel->item(j,i)->setText(items[i]) ;
        j++ ;
        if(j >= 11)
            break;
    }
    fillGrid(true) ;
    file.close();
}


void FramePixelCompensation::on_pushButtonSave_clicked()
{
    QString strFile = QFileDialog::getSaveFileName(this,"保存expand_weights文件", m_pCOMDlg->getDataPath(),
                                                   tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;
    m_strCurFile = strFile ;


    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件创建失败：" << file.errorString() << strFile;
        return ;
    }
    QTextStream out(&file);

    int nCount = m_pGModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11\n")
        .arg(m_pGModel->item(i,0)->text().trimmed(),
             m_pGModel->item(i,1)->text().trimmed(),
             m_pGModel->item(i,2)->text().trimmed(),
             m_pGModel->item(i,3)->text().trimmed(),
             m_pGModel->item(i,4)->text().trimmed(),
             m_pGModel->item(i,5)->text().trimmed(),
             m_pGModel->item(i,6)->text().trimmed(),
             m_pGModel->item(i,7)->text().trimmed(),
             m_pGModel->item(i,8)->text().trimmed(),
             m_pGModel->item(i,9)->text().trimmed(),
             m_pGModel->item(i,10)->text().trimmed());
        out << strLine ;
    }
    file.close() ;

    QMessageBox::information(this,"提示","数据保存完毕！");
}

