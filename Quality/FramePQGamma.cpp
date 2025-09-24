#include "FramePQGamma.h"
#include "ui_FramePQGamma.h"

#include "DialogToast.h"

#include <QPainter>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QThread>
#include <QMessageBox>

FramePQGamma::FramePQGamma(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FramePQGamma)
{
    ui->setupUi(this);

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    m_pModel = new QStandardItemModel(256,4);

    ui->tableView->setModel(m_pModel) ;

    m_pModel->setHorizontalHeaderLabels({"No.","R","G","B"});
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setVisible(true) ;
    srand(time(nullptr)) ;
    for(int i=0; i<256; i++)
    {
        QStandardItem *item0 = new  QStandardItem( QString::number(i) );
        QStandardItem *item1 = new  QStandardItem( QString::number(0) );//rand() %256)
        QStandardItem *item2 = new  QStandardItem( QString::number(0) );
        QStandardItem *item3 = new  QStandardItem( QString::number(0) );
        item0->setEditable(false) ;
        m_pModel->setItem(i,0,item0);
        m_pModel->setItem(i,1,item1);
        m_pModel->setItem(i,2,item2);
        m_pModel->setItem(i,3,item3);

        item1->setForeground(QBrush(QColor(Qt::red)));
        item2->setForeground(QBrush(QColor(Qt::green)));
        item3->setForeground(QBrush(QColor(Qt::blue)));
    }

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        Q_UNUSED(data)
        if(pSender != this) return;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMWriteHugeRamDone,this,[=](QWidget *pSender){
        if(pSender != this) return;

        QTimer::singleShot(100,this,[=]{
        if(m_nCurType == 0)
            doWrite(1) ;
        else if(m_nCurType == 1)
            doWrite(2) ;

        if(m_nCurType == 2)
            toast(this)->active("PQ Gamma数据 写入 完成！") ;
        }) ;
    });

    connect(m_pCOMDlg,&SerialTestDialog::COMReadHugeRamDone,this,[=](const QByteArray&ramData,QWidget *pSender){
        if(pSender != this) return ;
        qDebug() << "Show Read Gamma: " << m_nCurType;

        char *pGmaData = (char *)ramData.data() ;

        QStandardItemModel *pModel = m_pModel;
        m_bLoading = true ;
        for(int i=0; i<256; i++)
        {
            quint16 nValue = *(quint16 *)(pGmaData + i*9 ) ;
            pModel->item(i,1+m_nCurType)->setText(QString::number(nValue)) ;
        }
        update() ;
        m_bLoading = false ;

        QTimer::singleShot(100,this,[=]{
            if(m_nCurType == 0)
                doRead(1) ;
            else if(m_nCurType == 1)
                doRead(2) ;

            if(m_nCurType == 2)
                toast(this)->active("PQ Gamma数据 读取 完成！") ;
        }) ;

    }) ;

    ui->labelCurve->clear() ;

    connect(m_pModel,&QStandardItemModel::itemChanged,this,[=](QStandardItem *item){
        Q_UNUSED(item)
        if(!m_bLoading)
            ui->labelCurve->update() ;
    }) ;

    connect(ui->pushButtonRead, &QPushButton::clicked,this,[=]{
        if(!m_pCOMDlg->isConnected(false))
        {
            return ;
        }
        doRead(0);
    }) ;
    connect(ui->pushButtonWrite,&QPushButton::clicked,this,[=]{
        if(!m_pCOMDlg->isConnected(false))
        {
            return ;
        }
        doWrite(0);
    }) ;

    connect(ui->pushButtonLoad, &QPushButton::clicked,this,[=]{ loadFile(); }) ;
    connect(ui->pushButtonSave, &QPushButton::clicked,this,[=]{ saveFile(); }) ;

    connect(ui->checkBoxR,&QCheckBox::clicked,this,[=]{ ui->labelCurve->update(); }) ;
    connect(ui->checkBoxG,&QCheckBox::clicked,this,[=]{ ui->labelCurve->update(); }) ;
    connect(ui->checkBoxB,&QCheckBox::clicked,this,[=]{ ui->labelCurve->update(); }) ;

    connect(ui->checkBoxGamma,&QCheckBox::clicked,this,[=]{
        m_pCOMDlg->sendSwitch(0x001F,ui->checkBoxGamma->isChecked(),this);
    }) ;

    connect(ui->spinBoxX, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderX, &QSlider::setValue);
    connect(ui->hSliderX, &QSlider::valueChanged, ui->spinBoxX, &QSpinBox::setValue);
    connect(ui->hSliderX, &QSlider::valueChanged, this, [=](int value){
        m_nEditX = value ;
        ui->vSliderY->setValue(m_pModel->item(m_nEditX,getCol())->text().toInt()) ;

        QModelIndex index = ui->tableView->model()->index(value, 1);
        ui->tableView->scrollTo(index, QAbstractItemView::EnsureVisible);
    });

    connect(ui->spinBoxY, QOverload<int>::of(&QSpinBox::valueChanged), ui->vSliderY, &QSlider::setValue);
    connect(ui->vSliderY, &QSlider::valueChanged, ui->spinBoxY, &QSpinBox::setValue);

    connect(ui->vSliderY, &QSlider::valueChanged, this, [=](int value){
        m_pModel->item(m_nEditX,getCol())->setText(QString::number(value)) ;
    });

    connect(ui->buttonGroup, &QButtonGroup::idClicked, this,[=](int nIndex){
        Q_UNUSED(nIndex)
        ui->vSliderY->setValue(m_pModel->item(m_nEditX,getCol())->text().toInt()) ;
        update() ;
    });

    connect(ui->tableView,&QTableView::clicked,this,[=](const QModelIndex &index)
    {
        int nRow = index.row() ;
        int nCol = index.column() ;
        if(nCol==0) return ;

        if(nCol == 1) ui->radioButton1->setChecked(true);
        if(nCol == 2) ui->radioButton2->setChecked(true);
        if(nCol == 3) ui->radioButton3->setChecked(true);

        ui->hSliderX->setValue(nRow) ;
        ui->vSliderY->setValue(m_pModel->item(m_nEditX,getCol())->text().toInt()) ;
    });

    ui->labelCurve->installEventFilter(this) ;

    const QList<QPushButton *> btns = this->findChildren<QPushButton *>() ;
    for (QPushButton *btn : std::as_const(btns)) {
        btn->setCursor(Qt::PointingHandCursor) ;
        btn->setFocusPolicy(Qt::NoFocus) ;
    }
}

FramePQGamma::~FramePQGamma()
{
    delete ui;
}

int FramePQGamma::getCol()
{
    int nCol = 1 ;
    if(ui->radioButton2->isChecked()) nCol = 2 ;
    if(ui->radioButton3->isChecked()) nCol = 3 ;
    return nCol ;
}

quint32 FramePQGamma::getAddr(int nType)
{
    if(nType == 0) return m_addrR ;
    if(nType == 1) return m_addrG ;
    if(nType == 2) return m_addrB ;
    return 0 ;
}

void FramePQGamma::doRead(int nType)
{
    if(!ui->checkBoxGamma->isChecked())
    {
        QMessageBox::warning(this,"提示","请 打开： 0x001F");
        return ;
    }
    m_nCurType = nType ;

    quint32 nAddr = getAddr(nType) ;
    m_pCOMDlg->readHugeRam(nAddr,256*9,this) ;
}

void FramePQGamma::doWrite(int nType)
{
    if(ui->checkBoxGamma->isChecked())
    {
        QMessageBox::warning(this,"提示","请 关闭： 0x001F");
        return ;
    }
    QStandardItemModel *pModel = m_pModel ;
    QByteArray buf ;
    char szSub[20] = {0} ;
    for(int i=0; i<256; i++)
    {
        quint16 nValue = pModel->item(i,1+nType)->text().trimmed().toInt() ;
        *(quint16 *)szSub = nValue ;
        buf.append(szSub,9) ;
    }

    m_nCurType = nType ;
    quint32 nAddr = getAddr(nType) ;
    m_pCOMDlg->writeHugeRam(nAddr,buf,this) ;
}


void FramePQGamma::loadFile()
{
    QString strFile = QFileDialog::getOpenFileName(this,"打开 PQ-Gamma 配置文件", m_pCOMDlg->getDataPath(),
                                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));
    if(strFile.isEmpty())
        return ;

   m_strFile = strFile ;

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
        m_pModel->item(nLine,2)->setText(values[1]) ;
        m_pModel->item(nLine,3)->setText(values[2]) ;
        nLine++ ;
        if(nLine >= 256) break;
    }
    m_bLoading = false ;
    file.close();
    ui->labelCurve->update() ;
}

void FramePQGamma::saveFile()
{
    QString strFile = m_strFile;
    if(strFile.isEmpty())
    {
        strFile = QFileDialog::getSaveFileName(this,"保存 PQ-Gamma 配置文件", m_pCOMDlg->getDataPath(),
                                tr("CSV文件 (*.csv);;文本文件 (*.txt);;BIN文件 (*.BIN);;所有文件 (*.*)"));
        if(strFile.isEmpty())
            return ;
        m_strFile = strFile ;
    }

    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件创建失败：" << strFile;
    }
    QTextStream out(&file);
    QStandardItemModel *pModel = m_pModel ;
    int nCount = pModel->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QString strLine = QString("%1,%2,%3\n").arg(
            pModel->item(i,1)->text().trimmed(),
            pModel->item(i,2)->text().trimmed(),
            pModel->item(i,3)->text().trimmed() ) ;
        out << strLine ;
    }
    file.close() ;
}


int FramePQGamma::valueFromPos(const QPoint &pos)
{
    int nValue = 0;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nH = rc.height() ;

        nValue = 4095 - (pos.y() - rc.top())*4095/nH;
        if(nValue<0)
            nValue = 0 ;

        if(nValue>4095)
            nValue = 4095 ;
    }
    return nValue ;
}

int FramePQGamma::indexFromPos(const QPoint &pos)
{
    int index = 0 ;
    QRect rc = m_drawRect ;
    if(rc.contains(pos))
    {
        int nW = rc.width() ;
        int nDist = pos.x()  - rc.left() ;
        index = nDist * 255 / nW ;

        if(index<0)
            index = 0 ;

        if(index>255)
            index = 255 ;
    }
    return index ;
}


bool FramePQGamma::eventFilter(QObject *watched, QEvent *event)
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
                int nValue = valueFromPos(pos);
                ui->vSliderY->setValue(nValue) ;
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

        QRect rc (0,0,pLabel->size().width(),pLabel->size().height());

        QPainter painter(pLabel) ;
        painter.fillRect(rc,QColor(80,80,80)) ;
        QPen pen(Qt::black,2) ;
        painter.drawRect(rc) ;

        rc.adjust(60,10,-10,-30) ;
        m_drawRect = rc ;

        painter.fillRect(rc,QBrush(Qt::darkGray)) ;

        int nW = rc.width() ;
        int nH = rc.height() ;
        qreal fStepX = nW/4.0 ;
        qreal fStepY = nH/4.0 ;

        pen.setColor(Qt::yellow) ;
        pen.setWidthF(1.5) ;
        painter.setPen(pen);
        painter.drawLine(rc.bottomLeft(),rc.topRight()) ;

        m_hotRects.clear() ;
        m_hotIndexs.clear() ;

        int nStage = m_stage ;
        int nSPCount = 256 / (nStage-1);
        int nEditX = 0 ;
        static QList<QColor> colors = { Qt::red, Qt::green, Qt::blue } ;
        for(int nType=0; nType<3; nType ++)
        {
            if(nType == 0 && !ui->checkBoxR->isChecked())
                continue;

            if(nType == 1 && !ui->checkBoxG->isChecked())
                continue;

            if(nType == 2 && !ui->checkBoxB->isChecked())
                continue;

            pen.setColor(colors[nType]) ;
            pen.setWidthF(0.8) ;
            painter.setPen(pen) ;

            QPoint p1(rc.left(),rc.bottom()) ;
            qreal fStepX = nW/255.0 ;
            for(int i=0; i<256; i++)
            {
                int nVal = m_pModel->item(i,1+nType)->text().toInt() ;
                float x = rc.left()   + fStepX * i ;
                float y = rc.bottom() - nVal * nH / 4095.0 ;
                if(y < rc.top())  y = rc.top() ;
                QPoint p2 = QPoint(x, y) ;
                painter.drawLine(p1, p2) ;
                p1 = p2 ;
                if(i == m_nEditX)
                    nEditX = x ;

                if(nType == getCol() - 1 )
                {
                    if(nSPCount > 0 && (i == 255 || i % nSPCount == 0))
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

            static QStringList HFlags=QString("0,64,128,192,255").split(',') ;
            static QStringList VFlags=QString("0,1024,2048,3076,4095").split(',') ;
            for(int i=0; i<=4; i++)
            {
                painter.drawLine(QPoint(rc.left()+i*fStepX,rc.top()),QPoint(rc.left()+i*fStepX,rc.bottom()));
                int nOffset = 10 ;
                if(i==0) nOffset = 10 ;
                if(i==4) nOffset = 30 ;
                painter.drawText(rc.left()+i*fStepX - nOffset,rc.bottom()+24, HFlags[i]);
            }
            //painter.drawText(rc.center().rx() - 30 ,rc.bottom() + 40, "Gamma");

            for(int i=0; i<=4; i++)
            {
                painter.drawLine(QPoint(rc.left(),rc.top()+i*fStepY),QPoint(rc.right(),rc.top()+i*fStepY));

                int nOffset = 50 ;
                if(i == 4) nOffset = 20 ;
                painter.drawText(rc.left() - nOffset, rc.top()+i*fStepY+8, VFlags[4-i]);
            }
        }
        return false ;
    }

    return QFrame::eventFilter(watched, event);
}
