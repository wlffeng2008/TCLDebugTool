#include "FrameGenGammaEdit.h"
#include "ui_FrameGenGammaEdit.h"

#include "DialogToast.h"

#include <QPainter>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QThread>
#include <QMessageBox>
#include <QHeaderView>
#include <cmath>

static void changevalue(qreal *buf,int nDCount,int nStage, int nIndex,int nValue)
{

    buf[nIndex] = nValue ;
    if(nStage > 0)
    {
        int nCount = nDCount / nStage ;
        int nLIndex = nIndex-nCount ;
        int nRIndex = nIndex+nCount ;
        if(nLIndex < 0)
            nLIndex = 0;
        if(nRIndex >= nDCount)
            nRIndex = nDCount - 1;
        float fStep1 = (buf[nLIndex] - nValue) / nCount;
        float fStep2 = (buf[nRIndex] - nValue) / nCount;
        for(int i=1; i<nCount; i++)
        {
            if(nIndex-i >= 0)
                buf[nIndex-i] = round(nValue + (i) * fStep1);
            if(nIndex+i <= nDCount)
                buf[nIndex+i] = round(nValue + (i) * fStep2);
        }
    }
}

FrameGenGammaEdit::FrameGenGammaEdit(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameGenGammaEdit)
{
    ui->setupUi(this);

    for(int n=0; n<32; n++)
    {
        for(int i=0; i<8192; i++)
        {
            m_nGammaBuf[n][i] = rand() % 4096 ;
        }
    }

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    m_pModel = new QStandardItemModel();
    m_pModel->setHorizontalHeaderLabels({"No.","Value"});

    ui->tableView->setModel(m_pModel) ;

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->labelCurve->installEventFilter(this) ;
    ui->labelCurve->setMouseTracking(true) ;
    ui->labelCurve->clear() ;

    connect(ui->spinBoxX, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderX, &QSlider::setValue);
    connect(ui->hSliderX, &QSlider::valueChanged, ui->spinBoxX, &QSpinBox::setValue);
    connect(ui->hSliderX, &QSlider::valueChanged, this, [=](int value){
        m_nEditX = value ;
        ui->vSliderY->setValue(m_pModel->item(m_nEditX,1)->text().toInt()) ;

        QModelIndex index = ui->tableView->model()->index(value, 1);
        ui->tableView->scrollTo(index, QAbstractItemView::EnsureVisible);
        ui->labelCurve->update() ;
    });

    connect(ui->spinBoxY, QOverload<int>::of(&QSpinBox::valueChanged), ui->vSliderY, &QSlider::setValue);
    connect(ui->vSliderY, &QSlider::valueChanged, ui->spinBoxY, &QSpinBox::setValue);

    connect(ui->vSliderY, &QSlider::valueChanged, this, [=](int value){
        m_pModel->item(m_nEditX,1)->setText(QString::number(value)) ;
    });


    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        Q_UNUSED(data)
        if(pSender != this) return;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMWriteHugeRamDone,this,[=](QWidget *pSender){
        if(pSender != this) return;

        QTimer::singleShot(100,this,[=]{
                toast(this)->active("CT Gamma数据 写入 完成！") ;
        }) ;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMReadHugeRamDone,this,[=](const QByteArray&ramData,QWidget *pSender){
        if(pSender != this) return ;

        char *pGmaData = (char *)ramData.data() ;

        QStandardItemModel *pModel = m_pModel;
        m_bLoading = true ;
        for(int i=0; i<m_nDCount; i++)
        {
            quint16 nValue = *(quint16 *)(pGmaData + i*9 ) ;
            m_nGammaBuf[m_nGammaIndex][i] = nValue;
            pModel->item(i,1)->setText(QString::number(nValue)) ;
        }
        update() ;
        m_bLoading = false ;

        QTimer::singleShot(100,this,[=]{
            toast(this)->active("CT Gamma数据 读取 完成！") ;
        }) ;

    }) ;

    connect(m_pModel,&QStandardItemModel::itemChanged,this,[=](QStandardItem *item){
        if(!m_bLoading)
        {
            m_nGammaBuf[m_nGammaIndex][item->row()] = item->text().toUInt();
            ui->labelCurve->update() ;
        }
    }) ;

    connect(ui->pushButtonRead, &QPushButton::clicked,this,[=]{ doRead(); }) ;
    connect(ui->pushButtonWrite,&QPushButton::clicked,this,[=]{ doWrite(); }) ;

    connect(ui->pushButtonLoad, &QPushButton::clicked,this,[=]{ loadFile(); }) ;
    connect(ui->pushButtonSave, &QPushButton::clicked,this,[=]{ saveFile(); }) ;
    connect(ui->pushButtonReset, &QPushButton::clicked,this,[=]{
        m_bLoading = true ;
        for(int i=0; i<m_nDCount; i++)
        {
            int value = m_nGammaOrg[m_nGammaIndex][i] ;
            m_pModel->item(i,1)->setText(QString::number(value)) ;
            m_nGammaBuf[m_nGammaIndex][i] = value ;
        }
        m_bLoading = false ;
        ui->labelCurve->update() ;
    }) ;

    setDrawColor({ Qt::red, Qt::green, Qt::blue }) ;

    QList<QPushButton *> btns= this->findChildren<QPushButton *>() ;
    for (QPushButton *btn:qAsConst(btns)) {
        btn->setCursor(Qt::PointingHandCursor) ;
        btn->setFocusPolicy(Qt::NoFocus) ;
    }
}

FrameGenGammaEdit::~FrameGenGammaEdit()
{
    delete ui;
}



void FrameGenGammaEdit::doRead()
{
    quint32 nAddr = m_nCammaAddr[m_nGammaIndex] ;
    m_pCOMDlg->readHugeRam(nAddr,m_nDCount*9,this) ;
}

void FrameGenGammaEdit::doWrite()
{
    QStandardItemModel *pModel = m_pModel ;
    QByteArray buf ;
    char szSub[20] = {0} ;
    for(int i=0; i<m_nDCount; i++)
    {
        quint16 nValue = pModel->item(i,1)->text().trimmed().toInt() ;
        *(quint16 *)szSub = nValue ;
        buf.append(szSub,9) ;
    }

    quint32 nAddr = m_nCammaAddr[m_nGammaIndex]  ;
    m_pCOMDlg->writeHugeRam(nAddr,buf,this) ;
}


void FrameGenGammaEdit::loadFile()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开 PQ-Gamma 配置文件", m_pCOMDlg->getDataPath(),
                                                   tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));
    if(strFile.isEmpty())
        return ;

    m_strFiles[m_nGammaIndex] = strFile ;

    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败：" << file.errorString()  << strFile << __FILE__ << __LINE__;
        return ;
    }
    m_bLoading = true ;
    int nLine = 0 ;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QStringList values = in.readLine().trimmed().split(',');
        m_pModel->item(nLine,1)->setText(values[0]) ;
        m_nGammaBuf[m_nGammaIndex][nLine] = values[0].toUInt() ;
        m_nGammaOrg[m_nGammaIndex][nLine] = values[0].toUInt() ;

        nLine++ ;
        if(nLine >= m_nDCount)
            break;
    }
    m_bLoading = false ;
    file.close();

    ui->labelCurve->update() ;
}

void FrameGenGammaEdit::saveFile()
{
    QString strFile = m_strFiles[m_nGammaIndex];
    if(strFile.isEmpty())
    {
        strFile = QFileDialog::getSaveFileName(this,"保存 PQ-Gamma 配置文件", m_pCOMDlg->getDataPath(),
                                               tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));
        if(strFile.isEmpty())
            return ;
        m_strFiles[m_nGammaIndex] = strFile ;
    }

    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        toast()->active( "文件创建失败：" + strFile);
        return ;
    }

    QTextStream out(&file);
    QStandardItemModel *pModel = m_pModel ;
    int nCount = pModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1").arg(
            pModel->item(i,1)->text().trimmed()) ;
        m_nGammaOrg[m_nGammaIndex][i] = strLine.toUInt() ;
        out << strLine << "\n";
    }
    file.close() ;
}

void FrameGenGammaEdit::setDataRange(int nCount,int nMax)
{
    m_bLoading = true ;
    m_nDMaxVal = nMax ;

    ui->vSliderY->setRange(0,nMax-1) ;
    ui->spinBoxY->setRange(0,nMax-1) ;
    m_nDCount = nCount;
    m_pModel->setRowCount(0) ;

    ui->hSliderX->setRange(0,nCount-1) ;
    ui->spinBoxX->setRange(0,nCount-1) ;
    for(int i=0; i<nCount; i++)
    {
        QStandardItem *item0 = new QStandardItem(QString::number(i)) ;
        QStandardItem *item1 = new QStandardItem("0") ;
        item0->setEditable(false) ;
        item1->setForeground(QBrush(Qt::blue));
        m_pModel->appendRow({item0,item1}) ;
    }
    m_bLoading = false ;
}

int FrameGenGammaEdit::valueFromPos(const QPoint &pos)
{
    int nValue = 0;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nH = rc.height() ;

        nValue = m_nDMaxVal - (pos.y() - rc.top())*m_nDMaxVal/nH;
        if(nValue<0)
            nValue = 0 ;

        if(nValue>m_nDMaxVal)
            nValue = m_nDMaxVal ;
    }
    return nValue ;
}

int FrameGenGammaEdit::indexFromPos(const QPoint &pos)
{
    int index = 0 ;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nW = rc.width() ;
        int nDist = pos.x()  - rc.left() ;
        index = nDist * (m_nDCount-1) / nW ;

        if(index<0)
            index = 0 ;

        if(index>m_nDCount-1)
            index = m_nDCount-1 ;
    }
    return index ;
}

void FrameGenGammaEdit::setDrawMargin(int nLeft,int nTop,int nRight,int nBottom)
{
    m_nMarginL = nLeft ;
    m_nMarginT = nTop ;
    m_nMarginR = nRight ;
    m_nMarginB = nBottom ;
}

void FrameGenGammaEdit::setGammaCount(int nCount,const QList<quint32>&addrs)
{
    m_nGammaCount = nCount;
    setGammaAddr(addrs);
}

void FrameGenGammaEdit::setGammaAddr(const QList<quint32>&addrs)
{
    ui->comboBoxAddr->clear() ;
    ui->comboBoxIndex->clear() ;
    for(int i=0; i<addrs.count(); i++)
    {
        m_nCammaAddr[i] = addrs[i] ;
        ui->comboBoxAddr->addItem(QString("%1").arg(addrs[i],4,16,QLatin1Char('0')) );
        ui->comboBoxIndex->addItem(QString("%1").arg(i));
    }
}

void FrameGenGammaEdit::setGammaAddr(int nIndex,quint32 addr)
{
    m_nCammaAddr[nIndex] = addr ;
    ui->comboBoxAddr->setItemText(nIndex,QString("%1").arg(addr,4,16,QLatin1Char('0')));
}

void FrameGenGammaEdit::setDrawColor(const QList<QColor>&colors)
{
    for(int i=0; i<colors.count(); i++)
        m_colors[i] = colors[i] ;
}

void FrameGenGammaEdit::setDrawColor(int nIndex,const QColor&color)
{
    m_colors[nIndex] = color;
}

void FrameGenGammaEdit::setDivCol(int nHDivCol,int nVDivCol)
{
    if(nHDivCol>0)
        m_nHDivCol = nHDivCol;
    if(nVDivCol)
        m_nVDivCol = nVDivCol;
}


bool FrameGenGammaEdit::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
        QPoint pos = pME->pos() ;

        if(m_nHitIndex == -1)
        {
            int index = indexFromPos(pos) ;
            ui->hSliderX->setValue(index) ;
        }
        m_bDraging = false ;
    }

    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
        QPoint pos = pME->pos() ;
        m_clkPoint = pos ;
        if(m_nHitIndex >= 0)
        {
            m_bDraging = true ;
            ui->hSliderX->setValue(m_nHitIndex) ;
        }
    }

    if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent *pME = static_cast<QMouseEvent *>(event) ;
        QPoint pos = pME->pos() ;
        QRect rc = m_drawRect ;
        if(rc.contains(pos))
        {
            if(m_bDraging)
            {
                int value = valueFromPos(pos);
                ui->vSliderY->setValue(value) ;

                m_bLoading = true ;
                changevalue(m_nGammaBuf[m_nGammaIndex],m_nDCount,m_stage,m_nEditX,value) ;
                for(int i=0; i<m_nDCount; i++)
                    m_pModel->item(i,1)->setText(QString::number((int)m_nGammaBuf[m_nGammaIndex][i])) ;
                m_bLoading = false ;

                ui->labelCurve->update() ;
                update() ;
            }
            else
            {
                int nCount = m_hotRects.count() ;
                for(int i=0; i<nCount; i++)
                {
                    if(m_hotRects[i].contains(pos))
                    {
                        m_nHitIndex = m_hotIndexs[i] ;
                        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
                        return  true;
                    }
                }
            }
        }

        if(!m_bDraging)
        {
            m_nHitIndex = -1 ;
            QApplication::restoreOverrideCursor() ;
        }
    }

    if (event->type() == QEvent::Paint && ui->labelCurve == watched)
    {
        QLabel *pLabel = ui->labelCurve ;
        //pLabel->clear() ;
        QRect rc (0,0,pLabel->size().width(),pLabel->size().height());

        QPainter painter(pLabel) ;
        painter.fillRect(rc,QColor(80,80,80)) ;
        QPen pen(Qt::black,2) ;
        painter.drawRect(rc) ;

        rc.adjust(m_nMarginL, m_nMarginT, -m_nMarginR, -m_nMarginB) ;
        m_drawRect = rc ;

        painter.fillRect(rc,QBrush(Qt::darkGray)) ;

        pen.setColor(Qt::yellow) ;
        pen.setWidthF(1.5) ;
        painter.setPen(pen);
        painter.drawLine(rc.bottomLeft(),rc.topRight()) ;

        m_hotRects.clear() ;
        m_hotIndexs.clear() ;

        int nW = rc.width() ;
        int nH = rc.height() ;
        qreal fStepX = nW*1.0/m_nHDivCol ;
        qreal fStepY = nH*1.0/m_nVDivCol ;

        int nStage = m_stage ;
        int nSPCount = m_nDCount / (nStage-1);
        int nEditX = 0 ;
        for(int nType=0; nType<m_nGammaCount; nType ++)
        {
            pen.setColor(m_colors[nType]) ;
            pen.setWidthF(0.8) ;
            painter.setPen(pen) ;

            QPoint p1(rc.left(),rc.bottom()) ;
            qreal fStepX = nW*1.0/(m_nDCount-1) ;
            for(int i=0; i<m_nDCount; i++)
            {
                int nVal = m_nGammaBuf[nType][i];
                float x = rc.left()   + fStepX * i ;
                float y = rc.bottom() - nVal * nH * 1.0 / m_nDMaxVal ;
                if(y < rc.top())  y = rc.top() ;
                QPoint p2 = QPoint(x, y) ;
                painter.drawLine(p1, p2) ;
                p1 = p2 ;
                if(i == m_nEditX)
                    nEditX = x ;

                if(nType == m_nGammaIndex)
                {
                    if(nSPCount > 0 && (i == (m_nDCount-1) || i % nSPCount == 0))
                    {
                        painter.drawEllipse(p2,4,4) ;
                        m_hotRects.append(QRect(x-2,y-2,8,8)) ;
                        m_hotIndexs.append(i) ;
                    }
                }
            }
        }

        if(m_nEditX >= 0)
        {
            painter.setPen(QPen(Qt::green, 1, Qt::SolidLine));
            painter.drawLine(QPoint(nEditX,rc.top()),QPoint(nEditX,rc.bottom())) ;
        }

        {
            pen.setColor(Qt::white) ;
            pen.setWidthF(1.5) ;
            painter.setPen(pen) ;

            QPoint p1(rc.left() -5, rc.bottom()+5);
            QPoint p2(rc.right()+2, rc.bottom()+5);
            QPoint p3(rc.left() -5, rc.top()   -2);
            painter.drawLine(p1, p2) ;
            painter.drawLine(p1, p3) ;
            QFont font("微软雅黑", 12) ;
            painter.setFont(font) ;

            pen.setWidthF(0.5) ;
            painter.setPen(pen) ;


            float HFlagStep = m_nDCount*1.0/m_nHDivCol ;
            for(int i=0; i<=m_nHDivCol; i++)
            {
                painter.drawLine(QPoint(rc.left()+i*fStepX,rc.top()),QPoint(rc.left()+i*fStepX,rc.bottom()));
                int nOffset = 10 ;
                if(i==0) nOffset = 10 ;
                if(i==m_nHDivCol) nOffset = 30 ;
                painter.drawText(rc.left()+i*fStepX - nOffset,rc.bottom()+24, QString::number((int)(HFlagStep*(i))));
            }
            // painter.drawText(rc.center().rx() - 30 ,rc.bottom() + 40, "Gamma");

            float VFlagStep = m_nDMaxVal*1.0/m_nVDivCol ;
            for(int i=0; i<=m_nVDivCol; i++)
            {
                painter.drawLine(QPoint(rc.left(),rc.top()+i*fStepY),QPoint(rc.right(),rc.top()+i*fStepY));

                int nOffset = 50 ;
                if(i == m_nVDivCol) nOffset = 20 ;
                painter.drawText(rc.left() - nOffset, rc.top()+i*fStepY+8, QString::number((int)(VFlagStep*(4-i))) );
            }
        }
        return true;
    }

    return QFrame::eventFilter(watched, event);
}
