#include "DialogConfigPack.h"
#include "ui_DialogConfigPack.h"

#include "DialogToast.h"

#include <QDebug>
#include <QHeaderView>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QSettings>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDesktopServices>
#include <QItemSelectionModel>
#include <QItemSelection>

#include <QXlsx>
using namespace  QXlsx ;

DialogConfigPack::DialogConfigPack(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConfigPack)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::MSWindowsFixedSizeDialogHint ;
    flags &= ~Qt::WindowContextHelpButtonHint ;
    setWindowFlags(flags);
    setWindowTitle("配置打包工具") ;

    const QList<QPushButton *> btns = findChildren<QPushButton *>() ;
    for (QPushButton *btn : btns) {
        btn->setCursor(Qt::PointingHandCursor) ;
        btn->setFocusPolicy(Qt::NoFocus) ;
    }

    m_pSet = new QSettings(QCoreApplication::applicationDirPath() + "/TCLBinConfig.ini",QSettings::IniFormat) ;

    m_pRModel = new QStandardItemModel(this) ;
    ui->tableViewReg->setModel(m_pRModel);

    m_pAModel = new QStandardItemModel(this) ;
    m_pAModel->setHorizontalHeaderLabels({"输出","D","左移","Bytes","Hex","备注","文件","操作(点击)"});
    ui->tableViewRam->setModel(m_pAModel);

    QHeaderView *header = ui->tableViewRam->horizontalHeader() ;
    header->setSectionResizeMode(QHeaderView::Fixed);
    header->setSectionResizeMode(6,QHeaderView::Stretch);

    ui->tableViewRam->setStyleSheet("QTableView::indicator { margin-left: 6px; }");

    header->resizeSection(0,40) ;
    header->resizeSection(1,40) ;
    header->resizeSection(2,50) ;
    header->resizeSection(3,50) ;
    header->resizeSection(4,40) ;
    header->resizeSection(5,150) ;
    header->resizeSection(7,90) ;

    connect(ui->pushButtonAddRam,&QPushButton::clicked,this,[=]{
        QStandardItem *item0 = new QStandardItem("");
        QStandardItem *item1 = new QStandardItem("1");
        QStandardItem *item2 = new QStandardItem("13");
        QStandardItem *item3 = new QStandardItem("2");
        QStandardItem *item4 = new QStandardItem("");
        QStandardItem *item5 = new QStandardItem("备注");
        QStandardItem *item6 = new QStandardItem("请选择文件");
        QStandardItem *item7 = new QStandardItem("选择文件...");

        item0->setEditable(false);
        item4->setEditable(false);
        item7->setEditable(false);

        item0->setCheckable(true);
        item0->setCheckState(Qt::Checked);

        item4->setCheckable(true);

        item1->setTextAlignment(Qt::AlignCenter) ;
        item2->setTextAlignment(Qt::AlignCenter) ;
        item3->setTextAlignment(Qt::AlignCenter) ;

        m_pAModel->appendRow({item0,item1,item2,item3,item4,item5,item6,item7}) ;
    });

    connect(ui->pushButtonSaveRam,&QPushButton::clicked,this,[=]{
        saveLoadRamCfg() ;
        toast(this)->active("RAM 配置表已保存！");
    });

    saveLoadRamCfg(false) ;

    connect(ui->pushButtonDelRam,&QPushButton::clicked,this,[=]{
        if(m_nSelectRam >= 0)
            m_pAModel->removeRow(m_nSelectRam) ;
        m_nSelectRam = -1 ;
        ui->tableViewRam->clearSelection() ;
    }) ;

    connect(ui->tableViewRam,&QTableView::clicked,this,[=](const QModelIndex &index){
        m_nSelectRam = index.row() ;

        if(index.column() == 7)
        {
            QString strFile = QFileDialog::getOpenFileName(this,"选择 RAM 配置文件", nullptr,
                                        tr("所有文件 (*.*);;DAT文件(*.dat);;COE文件(*.coe)"));
            if(strFile.isEmpty())
                return ;
            m_pAModel->item(m_nSelectRam,6)->setText(strFile) ;
        }
    });

    connect(ui->tableViewRam->selectionModel(),&QItemSelectionModel::selectionChanged,this,[=](const QItemSelection &selected,const QItemSelection &deselected){
        Q_UNUSED(deselected)
        if(!selected.indexes().empty())
            m_nSelectRam = selected.indexes().at(0).row() ;
    });

    connect(ui->lineEditXlsxFile,&QLineEdit::textChanged,this,[=](const QString &arg1){
        m_bLoading = true ;
        loadFile(arg1.trimmed()) ;
        m_bLoading = false ;

        ui->comboBoxSheets1->setCurrentIndex(-1);
        QTimer::singleShot(100,this,[=]{ ui->comboBoxSheets1->setCurrentIndex(1); });
    });

    ui->lineEditXlsxFile->setText(m_pSet->value("lastXlsxFile").toString()) ;
    ui->lineEditSavePath->setText(m_pSet->value("binFilePath",QCoreApplication::applicationDirPath() + "/binfiles").toString()) ;
    ui->lineEditTag->setText(m_pSet->value("binFileTag","Tag").toString()) ;
    ui->comboBoxSheets1->setDuplicatesEnabled(false) ;
    ui->comboBoxSheets2->setDuplicatesEnabled(false) ;

    connect(ui->comboBoxSheets1,&QComboBox::currentTextChanged,this,[=](const QString&arg1){
        if(!m_bLoading)
            showSheet(arg1) ;
    }) ;
    connect(ui->pushButtonGetXlsxFile,&QPushButton::clicked,this,[=]{
        QString strFile = QFileDialog::getOpenFileName(this,"选择配置文件", nullptr,
                                                       tr("XLSX文件(*.xlsx);;所有文件 (*.*)"));
        if(strFile.isEmpty())
            return ;
        ui->lineEditXlsxFile->setText(strFile);
    });
    connect(ui->pushButtonGetSavePath,&QPushButton::clicked,this,[=]{
        QString strPath = QFileDialog::getExistingDirectory(this,"选择BIN文件输出目录",
                                            ui->lineEditSavePath->text().trimmed());
        if(strPath.isEmpty())
            return ;
        ui->lineEditSavePath->setText(strPath);
    });
    connect(ui->pushButtonAddSheet,&QPushButton::clicked,this,[=]{
        QString strSheet = ui->comboBoxSheets1->currentText() ;
        if(ui->comboBoxSheets2->findText(strSheet) != -1)
        {
            QMessageBox::information(this,"提示","此表格已在导出列表中!") ;
            return ;
        }
        ui->comboBoxSheets2->addItem(strSheet) ;
    });
    connect(ui->pushButtonRemoveSheet,&QPushButton::clicked,this,[=]{
        int index = ui->comboBoxSheets2->currentIndex() ;
        ui->comboBoxSheets2->removeItem(index) ;
        ui->tableViewRam->clearSelection() ;
    });
    connect(ui->pushButtonGotoSavePath,&QPushButton::clicked,this,[=]{
        QDesktopServices::openUrl(QUrl::fromLocalFile(ui->lineEditSavePath->text().trimmed()));
    });

    connect(m_pRModel, &QStandardItemModel::itemChanged, this, [=](QStandardItem *item) {
        if(m_bLoading)
            return ;
        int nRow = item->row() ;
        int nCol = item->column() ;
        QString strText = item->text().trimmed();

        int nCount = m_whole.count();
        for(int i=0; i<nCount; i++)
        {
            if(m_whole[i].strName != m_strCurSheet)
                continue;

            dataItem &DI = m_whole[i].data[nRow] ;
            if(nCol == 0)
            {
                QString strAddr = QString::asprintf("%04X", strText.toInt(nullptr,16));
                DI.strAddr = strAddr;
                item->setText(strAddr);
                break;
            }

            if(nCol == 1)
            {
                DI.strName = strText.trimmed();
                break;
            }

            if(nCol == 2)
            {
                DI.bBesetted = (item->checkState() == Qt::Checked);
                break;
            }

            QString strVal = QString::asprintf("%02X", strText.toInt(nullptr,16));
            DI.group[nCol-3] = strVal;
            item->setText(strVal);
            break ;
        }
    });

    connect(ui->checkBoxEditable,&QCheckBox::clicked,this,[=]{
        int nCount = m_pRModel->rowCount() ;
        bool bEable = ui->checkBoxEditable->isChecked();
        for(int i=0; i<nCount; i++)
        {
            for(int j=0; j<m_pRModel->columnCount(); j++)
            {
                QStandardItem *item = m_pRModel->item(i,j)  ;
                if(j == 1)
                {
                    item->setEditable(false);
                    continue;
                }

                if(j == 2)
                {
                    item->setEnabled(bEable);
                    continue;
                }

                item->setEditable(bEable);
            }
        }
    });

    ui->tableViewReg->setStyleSheet("QTableView::indicator { margin-left: 6px; }");
    connect(ui->tableViewReg,&QTableView::clicked,this,[=](const QModelIndex &index){
        Q_UNUSED(index)
    });

    connect(ui->tableViewReg->horizontalHeader(),&QHeaderView::sectionClicked,this,[=](int index){
        if(index >= 3)
            ui->comboBoxModels->setCurrentIndex(index-3) ;
    });

    connect(ui->pushButtonBuildCfg,&QPushButton::clicked,this,[=]{
        int nCount = ui->comboBoxSheets2->count() ;
        if(nCount == 0)
            return ;

        QString strWhole ;
        QString strModel = ui->comboBoxModels->currentText() ;
        int nModel = ui->comboBoxModels->currentIndex() ;
        for(int i=0; i<nCount; i++)
        {
            QString strSheet = ui->comboBoxSheets2->itemText(i).trimmed();
            foreach (const dataSheet&sheet, m_whole)
            {
                if(sheet.strName != strSheet)
                    continue ;

                int nLines = 0 ;
                foreach (const dataItem &DI, sheet.data)
                {
                    if(DI.bBesetted)
                        nLines ++;
                }

                if(nLines == 0)
                    continue ;

                QString strBuf = "AA 5A E0 00\n00 00 00 00\n" ;

                quint32 count = nLines * 3 ;
                quint8  b0 = (quint8) (count&0xFF) ;
                quint8  b1 = (quint8)((count&0xFF00)>>8) ;
                quint8  b2 = (quint8)((count&0xFF0000)>>16) ;
                char szLine[100] = {0} ;
                sprintf(szLine,"%02X %02X %02X 03\n",b2,b1,b0);
                strBuf += szLine;

                QString strItem ;
                foreach (const dataItem &DI, sheet.data)
                {
                    if(!DI.bBesetted)
                        continue;

                    strItem = DI.strAddr ;
                    strItem.insert(2,' ') ;
                    strBuf += strItem + " ";
                    strItem = DI.group[nModel] ;
                    strBuf += strItem + "\n";
                }

                strWhole += strBuf ;
            }
        }

        nCount = m_pAModel->rowCount() ;
        for(int i=0; i<nCount; i++)
        {
            if(m_pAModel->item(i,0)->checkState() == Qt::Unchecked)
                continue;
            QString strFile = m_pAModel->item(i,6)->text().trimmed() ;
            QFile RamFile(strFile) ;
            if(!RamFile.open(QIODevice::ReadOnly))
            {
                toast(this)->active(strFile + " 无法打开！") ;
                return ;
            }

            QStringList Lines  ;
            QTextStream in(&RamFile) ;
            while (!in.atEnd()) Lines.push_back(in.readLine().trimmed());
            RamFile.close() ;

            quint32 dValue = m_pAModel->item(i,1)->text().trimmed().toInt() ;
            quint32 LShift = m_pAModel->item(i,2)->text().trimmed().toInt() ;
            quint32 Bytes  = m_pAModel->item(i,3)->text().trimmed().toInt() ;
            bool    bHex   = m_pAModel->item(i,4)->checkState() == Qt::Checked ;
            quint32 addr   = (dValue << LShift) ;

            if(Bytes<=0)
                Bytes = 1 ;

            QString strBuf = "AA 5A E1 00\n" ;

            char szLine[256] = {0} ;
            sprintf(szLine,"%02X %02X %02X 00\n",(addr&0xFF0000) >> 16,(addr&0xFF00) >> 8,addr&0xFF);
            strBuf += szLine ;

            quint32 count = Lines.count() * Bytes ;
            quint8  b0 = (quint8) (count&0xFF) ;
            quint8  b1 = (quint8)((count&0xFF00)>>8) ;
            quint8  b2 = (quint8)((count&0xFF0000)>>16) ;
            sprintf(szLine,"%02X %02X %02X %02X\n",b2,b1,b0,Bytes);
            strBuf += szLine;

            foreach (const QString&strLine, Lines)
            {
                if(Bytes >= 9)
                {
                    QByteArray data = QByteArray::fromHex(strLine.toLatin1()) ;
                    // std::reverse(data.begin(),data.end()) ;
                    strcpy(szLine, data.toHex(' ').toUpper().toStdString().c_str()) ;
                }
                else
                {
                    quint64 value = strLine.toULongLong(nullptr, bHex ? 16 : 10) ;
                    quint8 *b = (quint8 *)&value ;
                    memset(szLine,0,100) ;
                    char szTmp[10] = {0} ;
                    for(quint32 n=0; n < Bytes; n++)
                    {
                        sprintf(szTmp,"%02X ",b[Bytes - n - 1]) ;
                        strcat(szLine,szTmp) ;
                    }
                }

                strcat(szLine,"\n") ;
                strBuf += szLine;
            }
            strWhole += strBuf ;
        }

        strWhole += "FF FF\nFF FF\nFF FF\nFF FF\nFF FF\nFF FF\nFF FF\nFF FF\n" ;

        QString strTag = ui->lineEditTag->text().trimmed() ;
        QString strPath = ui->lineEditSavePath->text().trimmed() ;
        m_pSet->setValue("binFilePath",strPath) ;
        m_pSet->setValue("binFileTag",strTag) ;


        QDir D(strPath) ;
        D.mkdir(strPath) ;
        QString strFile = QString("%1/KLNS_%2_%3.txt").arg(strPath,strModel,strTag);
        QFile textFile(strFile) ;
        if(textFile.open(QIODevice::WriteOnly))
        {
            QTextStream out(&textFile) ;
            out << strWhole ;
            textFile.flush() ;
            textFile.close() ;

            QString strBinFile = QString("%1/KLNS_%2_%3.bin").arg(strPath,strModel,strTag);
            QFile binFile(strBinFile) ;

            if(binFile.open(QIODevice::WriteOnly))
            {
                QByteArray buf = QByteArray::fromHex(strWhole.toLatin1()) ;

                if(ui->checkBoxHeadChecksum->isChecked())
                {
                    quint32 sum = 0 ;
                    quint64 rev = -1 ;
                    quint32 len = buf.size();
                    for(quint32 i=0; i<len; i++)
                        sum += (quint8)buf[i] ;
                    binFile.write((char *)&sum,4) ;
                    binFile.write((char *)&len,4) ;
                    binFile.write((char *)&rev,8) ;
                }

                binFile.write(buf);
                binFile.flush() ;
                binFile.close() ;
            }
            else
            {
                QMessageBox::critical(this,"提示","BIN文件创建失败！\n" + binFile.errorString() ) ;
                return ;
            }
        }

        easyToast("已成功导出Bin文件！",this) ;
    });

    ui->tableViewRam->setMouseTracking(true);
    ui->tableViewRam->installEventFilter(this) ;
}

DialogConfigPack::~DialogConfigPack()
{
    delete ui;
}


bool DialogConfigPack::eventFilter(QObject *watched, QEvent *event)
{
    QApplication::restoreOverrideCursor();

    if(watched == ui->tableViewRam)
    {
        if( event->type() == QEvent::Paint ||
            event->type() == QEvent::ToolTip)
        {
            QPoint clp = ui->tableViewRam->viewport()->mapFromGlobal(QCursor::pos())  ;
            QModelIndex index = ui->tableViewRam->indexAt(clp) ;
            if(index.column() == 7)
            {
                QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
                return true ;
            }
        }
    }

    return QDialog::eventFilter(watched, event);
}


void DialogConfigPack::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
    // QFrame::dragEnterEvent(event);
}

void DialogConfigPack::saveLoadRamCfg(bool bToSave)
{
    if(bToSave)
    {
        int nCount = m_pAModel->rowCount() ;
        m_pSet->setValue("RamSetting/RamCount",nCount);
        for(int i=0; i<nCount; i++)
        {
            QStandardItem *item0 = m_pAModel->item(i,0) ;
            QStandardItem *item1 = m_pAModel->item(i,1) ;
            QStandardItem *item2 = m_pAModel->item(i,2) ;
            QStandardItem *item3 = m_pAModel->item(i,3) ;
            QStandardItem *item4 = m_pAModel->item(i,4) ;
            QStandardItem *item5 = m_pAModel->item(i,5) ;
            QStandardItem *item6 = m_pAModel->item(i,6) ;
            QString strLine = QString::asprintf("%d,%d,%d,%d,%d,%s,%s",
                                                item0->checkState() == Qt::Checked,
                                                item1->text().toInt(),
                                                item2->text().toInt(),
                                                item3->text().toInt(),
                                                item4->checkState() == Qt::Checked,
                                                item5->text().toStdString().c_str(),
                                                item6->text().toStdString().c_str()
                                                ) ;

            m_pSet->setValue("RamSetting/RamItem" + QString::number(i),strLine);
        }
    }
    else
    {
        int nCount = m_pSet->value("RamSetting/RamCount",0).toInt();
        for(int i=0; i<nCount; i++)
        {
            ui->pushButtonAddRam->click() ;

            QStandardItem *item0 = m_pAModel->item(i,0) ;
            QStandardItem *item1 = m_pAModel->item(i,1) ;
            QStandardItem *item2 = m_pAModel->item(i,2) ;
            QStandardItem *item3 = m_pAModel->item(i,3) ;
            QStandardItem *item4 = m_pAModel->item(i,4) ;
            QStandardItem *item5 = m_pAModel->item(i,5) ;
            QStandardItem *item6 = m_pAModel->item(i,6) ;

            QStringList Values = m_pSet->value("RamSetting/RamItem" + QString::number(i)).toString().split(',');

            item0->setCheckState(Values[0] == "1" ? Qt::Checked:Qt::Unchecked);
            item1->setText(Values[1]);
            item2->setText(Values[2]);
            item3->setText(Values[3]);
            item4->setCheckState(Values[4] == "1" ? Qt::Checked:Qt::Unchecked);
            item5->setText(Values[5]);
            item6->setText(Values[6]);
        }
    }
}

void DialogConfigPack::dropEvent(QDropEvent *event) {

    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
        QRect rc1 = ui->tableViewReg->geometry() ;
        QRect rc2 = ui->tableViewRam->geometry() ;
        rc1 = QRect(ui->groupBox1->mapToParent(rc1.topLeft()),ui->groupBox1->mapToParent(rc1.bottomRight())) ;
        rc2 = QRect(ui->groupBox2->mapToParent(rc2.topLeft()),ui->groupBox2->mapToParent(rc2.bottomRight())) ;

        QPoint pos = event->pos() ;

        QList<QUrl> urlList = mimeData->urls();
        for (const QUrl &url : qAsConst(urlList))
        {
            QString strFile = url.toLocalFile();
            if(rc1.contains(pos))
            {
                ui->lineEditXlsxFile->setText(strFile) ;
                break ;
            }

            if(rc2.contains(pos))
            {
                ui->pushButtonAddRam->click() ;

                int row = m_pAModel->rowCount() -1 ;
                m_pAModel->item(row,6)->setText(strFile) ;
            }
        }
        saveLoadRamCfg() ;
    }
    //QFrame::dropEvent(event);
}

void DialogConfigPack::loadFile(const QString&strFile)
{
    m_pRModel->clear() ;
    m_readCols.clear() ;
    ui->comboBoxSheets1->clear() ;
    ui->comboBoxModels->clear() ;
    ui->comboBoxSheets2->clear() ;

    if(strFile.isEmpty())
        return ;

    Document xlsx(strFile);
    if(!xlsx.load())
    {
        QMessageBox::critical(this,"提示","文件无法加载！\n" + strFile) ;
        return ;
    }

    if(!xlsx.selectSheet("REG.ld_ip"))
    {
        QMessageBox::warning(this,"提示","此XLSX文档不符合约定格式，无法继续读取数据！");
        return ;
    }

    m_pSet->setValue("lastXlsxFile",strFile) ;

    QStringList sheets = xlsx.sheetNames() ;
    foreach (const QString &strSheet, sheets)
    {
        if(!strSheet.toUpper().contains("REG"))
            sheets.removeAll(strSheet) ;
    }

    ui->comboBoxSheets1->addItems(sheets) ;
    ui->comboBoxSheets2->addItems(sheets) ;

    QStringList headers = QStringList{"地址","名称","配置"} ;

    m_readCols = QStringList{"G"   ,"H"   ,"L"   } ;
    for(int i=0; i<100; i++)
    {
        QString strCell = QString("%1").arg((char)('M'+i)) ;
        strCell.append('2') ;
        QString strValue = xlsx.read(strCell).toString().trimmed() ;
        if(strValue.contains("备注") || strValue.isEmpty())
            break;

        m_readCols.push_back(QString((char)('M'+i))) ;
        headers.push_back(strValue) ;
        ui->comboBoxModels->addItem(strValue) ;
    }
    m_pRModel->setHorizontalHeaderLabels(headers) ;

    QHeaderView *header = ui->tableViewReg->horizontalHeader() ;
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(2,QHeaderView::Fixed);
    header->resizeSection(2,40) ;
    header->setSectionResizeMode(1,QHeaderView::Fixed);
    header->resizeSection(1,240) ;
    header->setSectionResizeMode(0,QHeaderView::Fixed);
    header->resizeSection(0,40) ;

    m_whole.clear();
    foreach (const QString &strSheet, sheets)
        loadSheet(xlsx,strSheet) ;
}

void DialogConfigPack::showSheet(const QString&strSheet)
{
    m_bLoading = true ;
    m_pRModel->setRowCount(0) ;
    ui->checkBoxEditable->setChecked(false) ;
    foreach (const dataSheet&sheet, m_whole)
    {
        if(sheet.strName != strSheet)
            continue;

        m_strCurSheet = strSheet;
        foreach (const dataItem &DI, sheet.data)
        {
            QStandardItem *item0 = new QStandardItem(DI.strAddr) ;
            QStandardItem *item1 = new QStandardItem(DI.strName) ;
            QStandardItem *item2 = new QStandardItem(DI.bBesetted ? "Y" : "N") ;

            item0->setEditable(false);
            item1->setEditable(false);
            item1->setSelectable(false) ;
            item2->setEditable(false);
            item2->setCheckable(true);
            item2->setEnabled(false) ;
            item2->setTextAlignment(Qt::AlignCenter) ;
            item2->setCheckState(DI.bBesetted ? Qt::Checked : Qt::Unchecked);
            item2->setText("") ;
            item2->setSizeHint(QSize(20,18)) ;

            QList<QStandardItem*>Row{item0,item1,item2} ;
            for(int i=0; i<DI.group.size(); i++)
            {
                QStandardItem *item = new QStandardItem(DI.group[i]) ;
                item->setTextAlignment(Qt::AlignCenter) ;
                item->setEditable(false);
                Row.push_back(item);
            }
            m_pRModel->appendRow(Row);
        }
        break ;
    }
    m_bLoading = false;
}

void DialogConfigPack::loadSheet(Document & xlsx,const QString&strSheet)
{
    foreach (const dataSheet&sheet, m_whole)
    {
        if(sheet.strName == strSheet)
            return ;
    }

    if(!xlsx.selectSheet(strSheet))
        return ;

    dataSheet Sh ;
    Sh.strName = strSheet ;
    bool bEnding = false ;
    for(int i=3; i<2000; i++)
    {
        dataItem Line ;
        for(int col=0; col<m_readCols.count(); col++)
        {
            QString strCell  = QString::asprintf("%s%d",m_readCols[col].toStdString().c_str(),i) ;
            QString strValue = xlsx.read(strCell).toString().trimmed() ;
            if(strValue.isEmpty() && col == 0)
            {
                bEnding = true ;
                break;
            }

            if(col == 0)
                Line.strAddr = strValue ;
            if(col == 1)
                Line.strName = strValue ;
            if(col == 2)
                Line.bBesetted = (strValue == "1") ;

            if(col >= 3)
            {
                strValue.replace("0X","");
                strValue.replace("0x","");
                if(strValue.length() == 1 && col > 1)
                    strValue.insert(0,"0") ;
                if(strValue.length() > 2  && col > 1)
                    strValue.insert(0,"0") ;
                if(strValue.isEmpty() || strValue.length()>6)
                    strValue = "00" ;
                Line.group.push_back(strValue.toUpper()) ;
            }
        }

        if(bEnding)
            break;

        Sh.data.push_back(Line) ;
    }
    m_whole.push_back(Sh) ;
}
