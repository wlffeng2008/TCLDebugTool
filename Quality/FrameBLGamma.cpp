#include "FrameBLGamma.h"
#include "ui_FrameBLGamma.h"
#include "global.h"
#include "frameblgammapanel.h"
#include "DialogToast.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>


FrameBLGamma::FrameBLGamma(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameBLGamma)
{
    ui->setupUi(this);
    m_pCOMDlg = SerialTestDialog::getInstance() ;

    QStringList header = {"No.","Value"};
    m_pDModel = new QStandardItemModel(this) ;
    m_pDModel->setHorizontalHeaderLabels(header);
    ui->tableView->setModel(m_pDModel) ;

    ui->tableView->setAutoFillBackground(true);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch) ;

    ui->tableView->setColumnWidth(0,70);
    ui->tableView->setColumnWidth(1,59);
    ui->tableView->setFocusPolicy(Qt::NoFocus) ;

    ui->horizontalSliderPos->setValue(0) ;
    ui->verticalSliderValue->setValue(0) ;

    connect(ui->horizontalSliderPoints,&QSlider::valueChanged,this,[=](int value){
        ui->labelPoints->setText(QString::number(value)) ;
    }) ;

    connect(ui->horizontalSliderPoints,&QSlider::sliderReleased,this,[=](){
        int value = ui->horizontalSliderPoints->value() ;
        ui->framePanel->setGammaStage(value) ;
    }) ;

    connect(ui->spinBoxX,&QSpinBox::textChanged,this,[=](const QString&text){
        ui->horizontalSliderPos->setValue(text.toInt()) ;
    }) ;

    connect(ui->checkBoxShowGammaIn,&QCheckBox::clicked,this,[=](bool checked){
        ui->framePanel->setShowGamin(checked) ;
    }) ;
    connect(ui->checkBoxShowRemap,&QCheckBox::clicked,this,[=](bool checked){
        ui->framePanel->setShowRemap(checked) ;
    }) ;

    connect(ui->horizontalSliderPos,&QSlider::valueChanged,this,[=](int value){
        ui->spinBoxX->setValue(value) ;
    }) ;

    connect(ui->spinBoxY,&QSpinBox::textChanged,this,[=](const QString&text){
        ui->verticalSliderValue->setValue(text.toInt()) ;
    }) ;

    connect(ui->verticalSliderValue,&QSlider::valueChanged,this,[=](int value){
        ui->spinBoxY->setValue(value) ;
    }) ;

    connect(m_pDModel, &QStandardItemModel::itemChanged,this, [=](QStandardItem *item) {
        int nRow = item->row() ;
        int nCol = item->column() ;
        if( nCol == 1 )
        {
            if(!m_bLoading)
                ui->framePanel->changeValue(nRow,item->text().toInt());
        }
    });

    LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "1_bl_gamma_table_12bit_low.csv") ;
    LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "3_bl_gamma_table_12bit_liner.csv",true) ;
    //LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "BL_Gamma_WZ_85QD_HDR_H.csv") ;
    //LoadBuf(QCoreApplication::applicationDirPath() + QString("/data/") + "BL_Gamma_WZ_85QD_HDR_M.csv",true) ;

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this) return;

        quint8 *pData = m_pCOMDlg->GetDataBody() ;
        sPackHeader *pHD = m_pCOMDlg->GetDataHead() ;
    });

    //setStyleSheet("font: bold 12px 微软雅黑;") ;

    connect(m_pCOMDlg,&SerialTestDialog::COMReadHugeRamDone,this,[=](const QByteArray&ramData,QWidget *pSender){
        if(pSender != this) return ;
        m_bLoading = true ;
        char *pGmaData = (char *)ramData.data() ;
        int nCount = ramData.size() / 9 ;
        m_pDModel->setRowCount(0) ;
        for(int i=0; i<nCount; i++)
        {
            quint16 nValue = *(quint16 *)(pGmaData + i*9) ;
            QStandardItem *item0 = new QStandardItem(QString::number(i)) ;
            QStandardItem *item1 = new QStandardItem(QString::number(nValue)) ;

            item0->setEditable(false) ;
            item1->setForeground(QBrush(QColor(Qt::blue)));
            m_pDModel->appendRow({item0,item1}) ;
            ui->tableView->setRowHeight(i,16) ;
            ui->framePanel->setBuf(0,i,nValue) ;
        }

        ui->spinBoxX->setRange(0,nCount-1) ;
        ui->horizontalSliderPos->setRange(0,nCount-1) ;
        ui->framePanel->update() ;
        ui->tableView->repaint() ;
        toast(this)->active("Gamma数据读取成功！");
        m_bLoading = false ;
    }) ;

    connect(ui->framePanel,&FrameBLGammaPanel::onBufChanged,this,[=](double *pBuf,int nCount){
        m_bLoading = true ;
        for(int i=0; i<nCount; i++)
        {
            quint16 nValue = pBuf[i] ;
            m_pDModel->item(i,1)->setText(QString::number(nValue)) ;
        }
        m_bLoading = false ;
    }) ;

    connect(ui->framePanel,&FrameBLGammaPanel::onValueChanged,this,[=](int index,int value){
        ui->horizontalSliderPos->setValue(index) ;
        ui->verticalSliderValue->setValue(value) ;
    }) ;
    connect(ui->framePanel,&FrameBLGammaPanel::onClickIndex,this,[=](int index,int value){
        ui->horizontalSliderPos->setValue(index) ;

        int nRow = ui->horizontalSliderPos->value() ;
        int nVal = m_pDModel->item(nRow,1)->text().toInt();
        ui->verticalSliderValue->setValue(nVal) ;
    }) ;

    connect(ui->horizontalSliderPos,&QSlider::valueChanged,this,[=](int value){
        int nRow = ui->horizontalSliderPos->value() ;
        int nVal = m_pDModel->item(nRow,1)->text().toInt();
        ui->verticalSliderValue->setValue(nVal) ;

        ui->framePanel->changeValue(nRow,-1);

        QModelIndex index = ui->tableView->model()->index(nRow, 1);
        ui->tableView->scrollTo(index, QAbstractItemView::EnsureVisible);
    }) ;

    connect(ui->verticalSliderValue,&QSlider::valueChanged,this,[=](int value){
        int nRow = ui->horizontalSliderPos->value() ;
        int nVal = ui->verticalSliderValue->value() ;
        m_pDModel->item(nRow,1)->setText(QString::number(nVal));
    }) ;

    connect(ui->checkBox109D,&QCheckBox::clicked,this,[=]{
        m_pCOMDlg->sendSwitch(0x109D,ui->checkBox109D->isChecked(),this);
    });

    ui->horizontalSliderPoints->setValue(48) ;
}

FrameBLGamma::~FrameBLGamma()
{
    delete ui;
}

void FrameBLGamma::LoadBuf(const QString&strFile,bool bForLinar)
{
    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << strFile  << __FILE__ << __LINE__;
        return ;
    }

    m_bLoading = true ;
    int i = 0 ;
    QTextStream in(&file);

    if(!bForLinar)
        m_pDModel->setRowCount(0) ;

    while (!in.atEnd())
    {
        QString strItem = in.readLine().trimmed();
        if(strItem.isEmpty()) break;
        int nValue = strItem.toInt();
        if(bForLinar)
        {
            ui->framePanel->setBuf(1,i,nValue) ;
        }
        else
        {
            QStandardItem *item0 = new QStandardItem(QString::number(i)) ;
            QStandardItem *item1 = new QStandardItem(strItem) ;

            item0->setEditable(false) ;
            item1->setForeground(QBrush(QColor(Qt::blue)));
            m_pDModel->appendRow({item0,item1}) ;
            ui->tableView->setRowHeight(i,16) ;

            ui->framePanel->setBuf(0,i,nValue) ;
            m_calData[i] = nValue;
            m_orgData[i] = nValue;
        }
        i++ ;
        if(i >= 4096)
            break;
    }
    file.close() ;
    m_bLoading = false ;

    if(!bForLinar)
    {
        ui->lineEditFilename->setText(strFile) ;
        ui->spinBoxX->setRange(0,i) ;
        ui->horizontalSliderPos->setRange(0,i) ;
    }

    ui->framePanel->update() ;
}

void FrameBLGamma::on_pushButtonLoad_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开Gamma数据文件",QCoreApplication::applicationDirPath() + QString("/data/"),
                                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

    if(strFile.isEmpty())
        return ;

    LoadBuf(strFile) ;
}

void FrameBLGamma::on_pushButtonSave_clicked()
{
    QString strFile = ui->lineEditFilename->text().trimmed() ;
    if(strFile.isEmpty())
    {
         strFile = QFileDialog::getSaveFileName(this,"保存Gamma数据到文件",QCoreApplication::applicationDirPath() + QString("/data/"),
                                                    tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));

        if(strFile.isEmpty())
            return ;
        ui->lineEditFilename->setText(strFile) ;
    }

    QFile file(strFile);

    if(file.exists())
    {
        auto nRet = QMessageBox::question(this,"提示","当前文件即将被覆盖，确定要保存吗？",QMessageBox::Yes|QMessageBox::No) ;
        if(nRet != QMessageBox::Yes)
            return ;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "文件创建失败：" << file.errorString() << strFile;

        QMessageBox::critical(this,"提示","文件创建失败：Gamma数据保存失败！") ;
        return ;
    }
    QTextStream out(&file);

    int nCount = m_pDModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1\n").arg(m_pDModel->item(i,1)->text().trimmed());
        out << strLine ;
    }
    file.close() ;

    toast(this)->active("Gamma数据保存完毕！") ;
    //QMessageBox::information(this,"提示","Gamma数据保存完毕！") ;
}

void FrameBLGamma::on_pushButtonRead_clicked()
{
    if(!m_pCOMDlg->isConnected(false))
    {
        return ;
    }
    if(!ui->checkBox109D->isChecked())
    {
        QMessageBox::warning(this,"提示","请打开： 0x109D");
        return ;
    }
    int nIndex = ui->comboBoxIndex->currentIndex() ;
    m_pCOMDlg->readHugeRam(m_nAddr + nIndex * 4096,4096 * 9,this) ;
}

void linear_interpolation(double *input, int input_len, double *output, int output_len) {
    double step = (double)(input_len - 1) / (output_len - 1);  // 计算插值步长
    for (int i = 0; i < output_len; i++) {
        double pos = i * step;  // 目标位置在原始数组中的浮点索引
        int idx = (int)pos;     // 取整得到左侧索引
        double frac = pos - idx; // 小数部分用于插值

        if (idx < input_len - 1) {
            // 线性插值：output[i] = input[idx] + (input[idx+1] - input[idx]) * frac
            output[i] = input[idx] + (input[idx + 1] - input[idx]) * frac;
        } else {
            // 处理最后一个元素，避免越界
            output[i] = input[input_len - 1];
        }
    }
}

void FrameBLGamma::on_pushButtonWrite_clicked()
{
    if(!m_pCOMDlg->isConnected(false))
    {
        return ;
    }
    if(!ui->checkBox109D->isChecked())
    {
        QMessageBox::warning(this,"提示","请打开： 0x109D");
        return ;
    }

    QByteArray buf ;
    char szBuf[20] = {0} ;
    int nCount = m_pDModel->rowCount();
    if(nCount == 256)
    {
        double input[256];   // 原始数组（假设已填充数据）
        double output[4096];
        int nStep = 4096/256 - 1 ;
        QList<quint16>newData ;
        for(int i=0; i<nCount; i++)
        {
            input[i] = m_pDModel->item(i,1)->text().trimmed().toInt() ;
            /*quint16 nValue1 = m_pDModel->item(i,1)->text().trimmed().toInt();
            quint16 nValue2 = m_pDModel->item(i+1,1)->text().trimmed().toInt();
            qDebug() <<i << nValue1<< nValue2;

            newData.push_back(nValue1) ;
            float fStep = (nValue2 - nValue1) * 1.0 / (nStep+1);
            for(int j=1; j<=nStep; j++)
            {
                newData.push_back(nValue1 + j*fStep) ;
            }*/
        }
        linear_interpolation(input,256,output,4096) ;

        for(int i=0; i<4096; i++)
        {
            *(quint16 *)szBuf = (quint16) output[i] ;
            buf.append(szBuf,9) ;
        }
        //qDebug()<< nStep << newData.count() << newData[0] << newData[newData.count()-2] << newData[newData.count()-1] ;
        //return  ;
    }
    else
    {
        for(int i=0; i<nCount; i++)
        {
            quint16 nValue = m_pDModel->item(i,1)->text().trimmed().toInt();
            *(quint16 *)szBuf = nValue ;
            buf.append(szBuf,9) ;
        }
    }

    int nIndex = ui->comboBoxIndex->currentIndex() ;
    m_pCOMDlg->writeHugeRam(m_nAddr + nIndex * 4096,buf,this) ;
}

void FrameBLGamma::on_pushButtonReset_clicked()
{
    for(int i=0; i<m_pDModel->rowCount(); i++)
    {
        m_calData[i] = m_orgData[i] ;
        ui->framePanel->setBuf(0,i,m_calData[i]) ;
        m_pDModel->item(i,1)->setText(QString::number(m_calData[i])) ;
    }

    ui->framePanel->update() ;
}

void FrameBLGamma::doCal()
{
    QVector<double> part ;

    int nOffset = ui->horizontalSliderPos->value() ;
    int nValue = ui->verticalSliderValue->value();

    int nCount = 100 ;
    int nPoints = ui->horizontalSliderPoints->value() ;
    for(int i=0; i<nCount + nPoints; i++)
    {
        part.append(m_calData[i+nOffset]) ;
    }
    part[nCount/2] = nValue ;

    QVector<double> cal = movingAverage(part,nPoints) ;

    for(int i=0; i<nCount; i++)
    {
        m_calData[i+nOffset] = cal[i] ;
        ui->framePanel->setBuf(0,i+nOffset,cal[i]) ;
        m_pDModel->item(i+nOffset,1)->setText(QString::number((int)cal[i])) ;
    }

    ui->framePanel->update() ;
}

