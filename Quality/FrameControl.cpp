#include "FrameControl.h"
#include "ui_FrameControl.h"
#include "DialogToast.h"

#include <QDebug>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QPoint>

typedef enum
{
    ADDR_H_MAX_ALPHA=0x1292,
    ADDR_L_MAX_ALPHA=0x1017,
    ADDR_H_DC_ALPHA=0x1293,
    ADDR_L_DC_ALPHA=0x1018,

    ADDR_lacal_alpha_L_enable=0x1094,
    ADDR_lacal_alpha_R_enable=0x1294,

    ADDR_alpha_ratio=0x1295,
    ADDR_delta_linit=0x1297,
    ADDR_dc_alpha_limit =0x1299,
    ADDR_max_alpha_limit=0x129B,

    ADDR_slope =0x12B1,
    ADDR_offset=0x12B2,
    ADDR_v_fac_limit=0x12B4

}eFixedAddr;

typedef struct{
    quint32 addrL ;
    quint32 addrR ;
    QString function ;
    int  mode;
}sAddrMap;

typedef struct{
    quint32 addr ;
    int  len;
}sRegRead;

static QList<sRegRead> g_Reads ;

static QList<sAddrMap> AddrMap =
{
    {0x100F,0x120F,"LD_ENABLE",0},
    {0x1015,0x1215,"LD_MODE",1},
    {0x1010,0x1210,"SPACE_FILTER_ENABLE",0},
    {0x1011,0x1211,"BLACKLIGHT_GAMMA_ENABLE",0},
    {0x1012,0x1212,"TEMPORAL_FILTER_ENABLE",0},
    {0x1013,0x1213,"CONTRAST_GAMMA_ENABLE",0},
    {0x1014,0x1214,"PIXEL_COMPENSATION_ENABLE",0},
    //{0x100D,0x100D,"PG_GAMMA_ENABLE[暂无]",0},
    //{0x100D,0x100D,"3D_LUT_ENABLE[暂无]",0},
    {0x1829,0x1829,"Temp_Comp_Enable",8},
    {0x109E,0x129E,"Gamut_Maping_Enable",0},
    {0x1036,0x1236,"Post_Proc_Enable",1},
    {0x1052,0x1252,"White_Screen_Mode",2}
};

FrameControl::FrameControl(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameControl)
{
    ui->setupUi(this);

    m_pCOMDlg = SerialTestDialog::getInstance() ;

    ui->horizontalSlider_1->setRange(0,0x100) ;
    ui->horizontalSlider_2->setRange(0,0x100) ;
    ui->horizontalSlider_3->setRange(0,0x3FF) ;
    ui->horizontalSlider_4->setRange(0,0x3FF) ;
    ui->horizontalSlider_5->setRange(0,0x100) ;
    ui->horizontalSlider_6->setRange(0,0x100) ;
    ui->horizontalSlider_7->setRange(0,0x0FF) ;
    ui->horizontalSlider_8->setRange(0,0x1FF) ;
    ui->horizontalSlider_9->setRange(0,0x100) ;
    ui->spinBox_1->setRange(0,0x100) ;
    ui->spinBox_2->setRange(0,0x100) ;
    ui->spinBox_3->setRange(0,0x3FF) ;
    ui->spinBox_4->setRange(0,0x3FF) ;
    ui->spinBox_5->setRange(0,0x100) ;
    ui->spinBox_6->setRange(0,0x100) ;
    ui->spinBox_7->setRange(0,0x0FF) ;
    ui->spinBox_8->setRange(0,0x1FF) ;
    ui->spinBox_9->setRange(0,0x100) ;

    ui->horizontalSlider_1->setValue(0) ;
    ui->horizontalSlider_2->setValue(0) ;

    connect(ui->spinBox_1, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_1, &QSlider::setValue);
    connect(ui->horizontalSlider_1, &QSlider::valueChanged, ui->spinBox_1, &QSpinBox::setValue);
    connect(ui->spinBox_2, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_2, &QSlider::setValue);
    connect(ui->horizontalSlider_2, &QSlider::valueChanged, ui->spinBox_2, &QSpinBox::setValue);
    connect(ui->spinBox_3, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_3, &QSlider::setValue);
    connect(ui->horizontalSlider_3, &QSlider::valueChanged, ui->spinBox_3, &QSpinBox::setValue);
    connect(ui->spinBox_4, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_4, &QSlider::setValue);
    connect(ui->horizontalSlider_4, &QSlider::valueChanged, ui->spinBox_4, &QSpinBox::setValue);
    connect(ui->spinBox_5, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_5, &QSlider::setValue);
    connect(ui->horizontalSlider_5, &QSlider::valueChanged, ui->spinBox_5, &QSpinBox::setValue);
    connect(ui->spinBox_6, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_6, &QSlider::setValue);
    connect(ui->horizontalSlider_6, &QSlider::valueChanged, ui->spinBox_6, &QSpinBox::setValue);
    connect(ui->spinBox_7, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_7, &QSlider::setValue);
    connect(ui->horizontalSlider_7, &QSlider::valueChanged, ui->spinBox_7, &QSpinBox::setValue);
    connect(ui->spinBox_8, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_8, &QSlider::setValue);
    connect(ui->horizontalSlider_8, &QSlider::valueChanged, ui->spinBox_8, &QSpinBox::setValue);
    connect(ui->spinBox_9, QOverload<int>::of(&QSpinBox::valueChanged), ui->horizontalSlider_9, &QSlider::setValue);
    connect(ui->horizontalSlider_9, &QSlider::valueChanged, ui->spinBox_9, &QSpinBox::setValue);

    connect(ui->horizontalSlider_1, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(1); });
    connect(ui->horizontalSlider_2, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(2); });
    connect(ui->horizontalSlider_3, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(3); });
    connect(ui->horizontalSlider_4, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(4); });
    connect(ui->horizontalSlider_5, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(5); });
    connect(ui->horizontalSlider_6, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(6); });
    connect(ui->horizontalSlider_7, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(7); });
    connect(ui->horizontalSlider_8, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(8); });
    connect(ui->horizontalSlider_9, &QSlider::valueChanged, this, [=](int value){ Q_UNUSED(value) sendData(9); });

    connect(&m_TMSendSliderValue,&QTimer::timeout,this,[=](){
        m_TMSendSliderValue.stop();

        qint16 value1 = ui->horizontalSlider_1->value();
        qint16 value2 = ui->horizontalSlider_2->value();
        qint16 value3 = ui->horizontalSlider_3->value();
        qint16 value4 = ui->horizontalSlider_4->value();
        qint16 value5 = ui->horizontalSlider_5->value();
        qint16 value6 = ui->horizontalSlider_6->value();
        qint16 value7 = ui->horizontalSlider_7->value();
        qint16 value8 = ui->horizontalSlider_8->value();
        qint16 value9 = ui->horizontalSlider_9->value();

        switch (m_sendIndex)
        {
        case 1:
            m_pCOMDlg->sendInt8(ADDR_H_MAX_ALPHA,((value1&0xFF00)>>8),this);
            m_pCOMDlg->sendInt8(ADDR_L_MAX_ALPHA,(value1&0xFF),this);
            break;

        case 2:
            m_pCOMDlg->sendInt8(ADDR_H_DC_ALPHA,((value2&0xFF00)>>8),this);
            m_pCOMDlg->sendInt8(ADDR_L_DC_ALPHA,(value2&0xFF),this);
            break;

        case 3:
             m_pCOMDlg->sendInt16(ADDR_alpha_ratio,value3,this);
            break;

        case 4:
            m_pCOMDlg->sendInt16(ADDR_delta_linit,value4,this);
            break;

        case 5:
            m_pCOMDlg->sendInt16(ADDR_dc_alpha_limit,value5,this);
            break;

        case 6:
            m_pCOMDlg->sendInt16(ADDR_max_alpha_limit,value6,this);
            break;

        case 7:
            m_pCOMDlg->sendInt8(ADDR_slope,value7,this);
            break;

        case 8:
            m_pCOMDlg->sendInt16(ADDR_offset,value8,this);
            break;
        case 9:
            m_pCOMDlg->sendInt16(ADDR_v_fac_limit,value9,this);
            break;

        default:
            break;
        }
    });

    connect(ui->radioButton1,&QRadioButton::clicked,this,[=](){
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_L_enable,0,this);
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_R_enable,0,this);
    });
    connect(ui->radioButton2,&QRadioButton::clicked,this,[=](){
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_L_enable,1,this);
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_R_enable,1,this);
    });
    connect(ui->radioButton3,&QRadioButton::clicked,this,[=](){
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_L_enable,2,this);
        m_pCOMDlg->sendInt8(ADDR_lacal_alpha_R_enable,2,this);
    });

    connect(ui->pushButtonReadLeft,&QPushButton::clicked,this,[=](){
        if(!m_pCOMDlg->isConnected(false))
        {
            return false;
        }
        g_Reads.clear();
        int nCount = m_pModel->rowCount() ;
        for(int i=0; i<nCount; i++)
        {
            quint32 nAddrL = m_pModel->item(i,1)->text().trimmed().toInt(nullptr,16) ;
            g_Reads.push_back({nAddrL,1}) ;

            if(nAddrL != 0x1829)
            {
                quint32 nAddrR = m_pModel->item(i,3)->text().trimmed().toInt(nullptr,16) ;
                g_Reads.push_back({nAddrR,1}) ;
            }
        }

        doReadReg() ;
        QTimer::singleShot(5000,this,[=]{ m_bReading = false; }) ;
    }) ;

    connect(ui->pushButtonReadRight,&QPushButton::clicked,this,[=](){
        if(!m_pCOMDlg->isConnected(false))
        {
            return false;
        }
        g_Reads.clear();

        g_Reads.push_back({ADDR_lacal_alpha_L_enable,1}) ;
        g_Reads.push_back({ADDR_lacal_alpha_R_enable,1}) ;

        g_Reads.push_back({ADDR_H_MAX_ALPHA,1}) ;
        g_Reads.push_back({ADDR_L_MAX_ALPHA,1}) ;
        g_Reads.push_back({ADDR_H_DC_ALPHA,1}) ;
        g_Reads.push_back({ADDR_L_DC_ALPHA,1}) ;

        g_Reads.push_back({ADDR_alpha_ratio,2}) ;
        g_Reads.push_back({ADDR_delta_linit,2}) ;
        g_Reads.push_back({ADDR_dc_alpha_limit,2}) ;
        g_Reads.push_back({ADDR_max_alpha_limit,2}) ;
        g_Reads.push_back({ADDR_slope,1}) ;
        g_Reads.push_back({ADDR_offset,2}) ;
        g_Reads.push_back({ADDR_v_fac_limit,2}) ;

        doReadReg() ;
        QTimer::singleShot(5000,this,[=]{ m_bReading = false; }) ;
    }) ;

    connect(m_pCOMDlg,&SerialTestDialog::COMDataIn,this,[=](const QByteArray&data, QWidget *pSender){
        if(pSender != this)  return;

        quint8      *pData = m_pCOMDlg->GetDataBody() ;
        sPackHeader *pHD   = m_pCOMDlg->GetDataHead() ;

        if(data.size() == 15 && pHD->type == TYPE_REG_WRITE)
        {
            return ;
        }

        quint16 nValue = *(quint16 *)pData ;
        static quint8 bufSPRead[20]={0} ;
        quint8 nVal = pData[0] ;

        switch(pHD->addr)
        {
        case ADDR_lacal_alpha_L_enable:
        case ADDR_lacal_alpha_R_enable:
            if(nVal == 0) ui->radioButton1->setChecked(true);
            if(nVal == 1) ui->radioButton2->setChecked(true);
            if(nVal == 2) ui->radioButton3->setChecked(true);
        break;

        case ADDR_H_MAX_ALPHA:      bufSPRead[1] = nVal ;                      break;
        case ADDR_L_MAX_ALPHA:      bufSPRead[0] = nVal ;
            ui->horizontalSlider_1->setValue(*(quint16 *)bufSPRead);           break;
        case ADDR_H_DC_ALPHA:       bufSPRead[1] = nVal ;                      break;
        case ADDR_L_DC_ALPHA:       bufSPRead[0] = nVal ;
            ui->horizontalSlider_2->setValue(*(quint16 *)bufSPRead);           break;
        case ADDR_alpha_ratio:      ui->horizontalSlider_3->setValue(nValue) ; break;
        case ADDR_delta_linit:      ui->horizontalSlider_4->setValue(nValue) ; break;
        case ADDR_dc_alpha_limit:   ui->horizontalSlider_5->setValue(nValue) ; break;
        case ADDR_max_alpha_limit:  ui->horizontalSlider_6->setValue(nValue) ; break;
        case ADDR_slope:            ui->horizontalSlider_7->setValue(nValue) ; break;
        case ADDR_offset:           ui->horizontalSlider_8->setValue(nValue) ; break;
        case ADDR_v_fac_limit:      ui->horizontalSlider_9->setValue(nValue) ; break;
        }

        int nCount = m_pModel->rowCount() ;
        for(int i=0; i<nCount; i++)
        {
            quint32 nAddrL = m_pModel->item(i,1)->text().trimmed().toInt(nullptr,16) ;
            quint32 nAddrR = m_pModel->item(i,3)->text().trimmed().toInt(nullptr,16) ;
            QStandardItem *item = nullptr ;

            if(pHD->addr == nAddrL)
                item = m_pModel->item(i,2) ;
            if(pHD->addr == nAddrR)
                item = m_pModel->item(i,4) ;

            if(!item)
                continue ;

            int nMode = item->data().toInt() ;

            if(nMode == 0)
                item->setCheckState(nVal > 0 ? Qt::Checked:Qt::Unchecked) ;

            if(nMode == 8)
                item->setCheckState(nVal == 0 ? Qt::Checked:Qt::Unchecked) ;

            if(nMode == 1)
            {
                if(nVal == 0) item->setText("0:关") ;
                if(nVal == 1) item->setText("1:开(模式1)") ;
                if(nVal == 2) item->setText("2:开(模式2)") ;
            }

            if(nMode == 2)
            {
                if(nVal == 0) item->setText("0:关") ;
                if(nVal == 1) item->setText("1:开(演示模式1)") ;
                if(nVal == 2) item->setText("2:开(演示模式2)") ;
            }

            break ;
        }

        doReadReg() ;
    });

    m_pModel = new QStandardItemModel(0,5,this) ;
    m_pModel->setHorizontalHeaderLabels(QString("名称(功能),地址(L),Enable(L),地址(R),Enable(R),--BOTH--").split(',')) ;
    ui->tableView->setModel(m_pModel) ;

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(1,QHeaderView::Fixed);
    header->resizeSection(1,80) ;
    header->setSectionResizeMode(2,QHeaderView::Fixed);
    header->resizeSection(2,120) ;
    header->setSectionResizeMode(3,QHeaderView::Fixed);
    header->resizeSection(3,80) ;
    header->setSectionResizeMode(4,QHeaderView::Fixed);
    header->resizeSection(4,120) ;
    header->setSectionResizeMode(5,QHeaderView::Fixed);
    header->resizeSection(5,120) ;

    for(const sAddrMap& AM : std::as_const(AddrMap))
    {
        QString strFunc(AM.function) ;
        QStandardItem *item0 = new QStandardItem(strFunc) ;
        item0->setEditable(false) ;
        item0->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter) ;
        item0->setForeground(QBrush(Qt::blue)) ;

        QStandardItem *item1 = new QStandardItem(QString("%1").arg(AM.addrL,4,16,QLatin1Char('0')).toUpper()) ;
        QStandardItem *item3 = new QStandardItem(QString("%1").arg(AM.addrR,4,16,QLatin1Char('0')).toUpper()) ;
        QStandardItem *item2 = new QStandardItem("Yes") ;
        QStandardItem *item4 = new QStandardItem("Yes") ;
        QStandardItem *item5 = new QStandardItem("Yes") ;
        if(AM.mode == 0 || AM.mode == 8)
        {
            item2->setCheckable(true);

            if(AM.addrL != 0x1829)
            {
                item4->setCheckable(true);
                item5->setCheckable(true);
            }
        }

        if(AM.mode == 1 || AM.mode == 2)
        {
            item2->setText("0:关") ;
            item2->setForeground(QBrush(Qt::blue)) ;
            item4->setText("0:关") ;
            item4->setForeground(QBrush(Qt::blue)) ;
            item5->setText("0:关") ;
            item5->setForeground(QBrush(Qt::blue)) ;
        }

        item2->setEditable(false) ;
        item2->setData(AM.mode) ;

        item4->setEditable(false) ;
        item4->setData(AM.mode) ;

        item5->setEditable(false) ;
        item5->setData(AM.mode) ;

        item1->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;
        item2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;
        item3->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;
        item4->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter) ;

        if(AM.addrL == 0x1829)
        {
            item3->setText("");
            item4->setText("");
            item5->setText("");

            item3->setEnabled(false) ;
            item4->setEnabled(false) ;
            item5->setEnabled(false) ;

            item4->setData(10) ;
        }

        m_pModel->appendRow({item0, item1, item2, item3, item4, item5}) ;
    }

    connect(m_pModel,&QStandardItemModel::itemChanged,this,[=](QStandardItem *item){

        int nCol = item->column() ;
        int nRow = item->row() ;
        if(m_bReading)
            return ;

        int nMode = item->data().toInt() ;
        if(nCol == 2 || nCol == 4)
        {
            quint32 nAddr = m_pModel->item(nRow,nCol == 4 ? 3 : 1)->text().trimmed().toUInt(nullptr,16);

            if((nMode == 8 || nMode == 0))
            {
                bool bChecked = (item->checkState() == Qt::Checked);
                if(nMode == 8) bChecked = !bChecked;
                m_pCOMDlg->sendSwitch(nAddr,bChecked,this);
            }

            if(nMode == 1 || nMode == 2)
            {
                QString strText = item->text().at(0);
                quint8 nVal = strText.toInt();
                m_pCOMDlg->sendInt8(nAddr,nVal,this);
            }
        }

        if(nCol == 5)
        {
            if((nMode == 8 || nMode == 0))
            {
                bool bChecked = (item->checkState() == Qt::Checked);
                if(nMode == 8) bChecked = !bChecked;
                m_pModel->item(nRow,2)->setCheckState(bChecked?Qt::Checked:Qt::Unchecked) ;
                m_pModel->item(nRow,4)->setCheckState(bChecked?Qt::Checked:Qt::Unchecked) ;
            }
        }
    }) ;

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,&QTableView::customContextMenuRequested,this,[=](const QPoint &pos){
        QModelIndex index = ui->tableView->indexAt(pos) ;
        QRect cellRect = ui->tableView->visualRect(index);
        qDebug() << cellRect << QCursor::pos() << pos ;
    }) ;

    connect(ui->tableView,&QTableView::clicked,this,[=](const QModelIndex &index)
    {
        QRect cellRect = ui->tableView->visualRect(index);

        QPoint clp = ui->tableView->viewport()->mapFromGlobal(QCursor::pos())  ;

        int nx = clp.x() ;
        int ny = clp.y() ;

        for(int i=0; i<index.column(); i++)
            nx -= ui->tableView->columnWidth(i) ;
        for(int i=0; i<index.row(); i++)
            ny -= ui->tableView->rowHeight(i) ;

        /*QHeaderView *pV = ui->tableView->verticalHeader() ;
        if(pV && pV->isVisible())
            nx -= pV->width() ;

        QHeaderView *pH = ui->tableView->horizontalHeader() ;
        if(pH && pH->isVisible())
            ny -= pH->height() ;*/

        qDebug() << cellRect << QCursor::pos() << nx << ny  ;// << ui->tableView->rowViewportPosition(index.row()) <<  ui->tableView->columnViewportPosition(index.column());

        int nRow = index.row() ;
        int nCol = index.column() ;
        m_nSelect = nRow;
        m_nCol = nCol;
        if(nCol == 2 || nCol == 4 || nCol == 5)
        {
            QStandardItem *item = m_pModel->item(nRow,nCol) ;

            int nMode = item->data().toInt() ;
            if(nMode == 1 || nMode == 2)
            {
                m_nAddr = m_pModel->item(nRow,nCol == 4 ? 3 : 1)->text().trimmed().toInt(nullptr,16);

                static QMenu   *pMenu = new QMenu(this) ;
                static QAction *pAct0 = new QAction("0:关",this) ;
                static QAction *pAct1 = new QAction("1",this) ;
                static QAction *pAct2 = new QAction("2",this) ;
                static bool addItem = false ;

                if(nMode == 1)
                {
                    pAct1->setText("1:开(模式1)") ;
                    pAct2->setText("2:开(模式2)") ;
                }

                if(nMode == 2)
                {
                    pAct1->setText("1:开(演示模式1)") ;
                    pAct2->setText("2:开(演示模式2)") ;
                }

                if(!addItem)
                {
                    addItem = true ;
                    pMenu->addAction(pAct0);
                    pMenu->addAction(pAct1);
                    pMenu->addAction(pAct2);

                    connect(pAct0,&QAction::triggered,this,[=](bool checked ){
                        Q_UNUSED(checked)
                        if(m_nCol == 5)
                        {
                            m_pModel->item(m_nSelect,2)->setText(pAct0->text());
                            m_pModel->item(m_nSelect,4)->setText(pAct0->text());
                            m_pModel->item(m_nSelect,5)->setText(pAct0->text());
                        }
                        else
                        {
                            m_pModel->item(m_nSelect,m_nCol)->setText(pAct0->text()) ;
                        }
                    }) ;

                    connect(pAct1,&QAction::triggered,this,[=](bool checked){
                        Q_UNUSED(checked)
                        if(m_nCol == 5)
                        {
                            m_pModel->item(m_nSelect,2)->setText(pAct1->text());
                            m_pModel->item(m_nSelect,4)->setText(pAct1->text());
                            m_pModel->item(m_nSelect,5)->setText(pAct1->text());
                        }
                        else
                        {
                            m_pModel->item(m_nSelect,m_nCol)->setText(pAct1->text()) ;
                        }
                    }) ;

                    connect(pAct2,&QAction::triggered,this,[=](bool checked){
                        Q_UNUSED(checked)
                        if(m_nCol == 5)
                        {
                            m_pModel->item(m_nSelect,2)->setText(pAct2->text());
                            m_pModel->item(m_nSelect,4)->setText(pAct2->text());
                            m_pModel->item(m_nSelect,5)->setText(pAct2->text());
                        }
                        else
                        {
                            m_pModel->item(m_nSelect,m_nCol)->setText(pAct2->text()) ;
                        }
                    }) ;
                }

                pMenu->exec(QCursor::pos());
            }
            else
            {
                if(nx > 20)
                {
                    if(item->isCheckable())
                    {
                        if(item->checkState() == Qt::Checked)
                            item->setCheckState(Qt::Unchecked);
                        else
                            item->setCheckState(Qt::Checked);
                    }
                }
            }
        }

    }) ;

    connect(m_pCOMDlg,&SerialTestDialog::COMStatusChanged,this,[=](bool bOpen){
        if(bOpen)
            ui->pushButtonReadLeft->click();
    });

    setStyleSheet("font: bold 14px 微软雅黑; ") ;  //color:white; background-color: #303030;
}

FrameControl::~FrameControl()
{
    delete ui;
}

void  FrameControl::doReadReg()
{
    int nCount = g_Reads.count() ;
    if(nCount == 0)
    {
        toast()->active("读取完毕！") ;
        m_bReading = false ;
        return ;
    }

    m_bReading = true ;

    sRegRead A = g_Reads[0] ;
    g_Reads.removeFirst() ;

    m_pCOMDlg->readRegData(A.addr, A.len, this) ;
}

void FrameControl::sendData(int nIndex)
{
    if(m_bReading)
        return ;

    m_sendIndex = nIndex ;
    m_TMSendSliderValue.stop();
    m_TMSendSliderValue.start(200) ;
}

