#ifndef FRAMEREGMANAGER_H
#define FRAMEREGMANAGER_H

#include <QTimer>
#include <QFrame>
#include <QKeyEvent>
#include <QStandardItemModel>
#include <QTableView>
#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>

namespace Ui {
class FrameRegManager;
}

class SerialTestDialog;

class UppercaseHexSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit UppercaseHexSpinBox(QWidget *parent = nullptr) : QSpinBox(parent)
    {
        // 设置为16进制显示
        //setDisplayIntegerBase(16);
    }

protected:
    QString textFromValue(int value) const override
    {
        if(displayIntegerBase() == 16)
        return QString("%1").arg(value, 0, 16).toUpper();

        return QString("%1").arg(value, 0, 10).toUpper();
    }
};

class SideValueDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    SideValueDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {
        connect(this,&SideValueDelegate::onSaveOldText,this,[=](int nRow,const QString&text){
            setText(nRow,text);
        }) ;
    }
    void setText(int nRow,const QString&text){ _texts[nRow] = text ; } ;
    void setTableView(QTableView *pView){ tableView = pView ;} ;
    void setHexMode(bool set=true){ m_bHexMode = set ;}

protected:
    QMap<int,QString> _texts ;
    QTableView *tableView = nullptr ;
    bool m_bHexMode = false ;

signals:
    void onButtonClicked(int row,int col);
    void onSaveOldText(int nRow,const QString&text) const ;

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)

        QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
        QString strText = pModel->item(index.row(),index.column())->text() ;
        emit onSaveOldText(index.row(),strText);

        UppercaseHexSpinBox *pBox = new UppercaseHexSpinBox(parent) ;
        pBox->setRange(-1000000,1000000);
        if(m_bHexMode)
        {
            pBox->setPrefix("0x") ;
            pBox->setDisplayIntegerBase(16) ;
        }
        return pBox;
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyledItemDelegate::paint(painter,option,index) ;

        painter->save() ;

        QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
        QStandardItem *item = pModel->item(index.row(),index.column()) ;
        QString strText = item->text() ;

        QRect rect = option.rect ;
        rect.adjust(4,4,-4,-4) ;

        QPen pen(Qt::darkGray) ;
        painter->setPen(pen) ;
        painter->drawText(rect,Qt::AlignRight|Qt::AlignVCenter,_texts[index.row()]);

        painter->restore() ;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        QString strValue = index.model()->data(index, Qt::EditRole).toString();
        int value = m_bHexMode ? strValue.toInt(nullptr,16) : strValue.toInt();
        spinBox->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();

        if(m_bHexMode)
        {
            QString value = spinBox->text() ;
            value.replace(spinBox->prefix(),"") ;
            model->setData(index, value.toUpper(), Qt::EditRole);
        }
        else
        {
            int value = spinBox->value();
            model->setData(index, value, Qt::EditRole);
        }
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override
    {
        if(event->type() == QEvent::MouseButtonRelease && tableView)
        {
            QRect cellRect = tableView->visualRect(index);

            QPoint clp = tableView->viewport()->mapFromGlobal(QCursor::pos())  ;

            int nx = clp.x() ;
            int ny = clp.y() ;

            for(int i=0; i<index.column(); i++)
                nx -= tableView->columnWidth(i) ;
            for(int i=0; i<index.row(); i++)
                ny -= tableView->rowHeight(i) ;
            if(nx * 10 / cellRect.width() > 6)
            {
                QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
                QStandardItem *item = pModel->item(index.row(),index.column()) ;
                if(item && !_texts[index.row()].isEmpty()) item->setText(_texts[index.row()]) ;
            }
        }
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option ;
        opt.rect.adjust(0,0,opt.rect.width()/2 * -1 + 20 ,0);
        QStyledItemDelegate::updateEditorGeometry(editor,opt,index);
    }
};


class FrameRegManager : public QFrame
{
    Q_OBJECT

public:
    explicit FrameRegManager(QWidget *parent = nullptr);
    ~FrameRegManager();

protected:

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonSaveAs_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_comboBoxReg_currentIndexChanged(int index);

    void on_checkBoxShowRegEx_clicked();

    void on_comboBoxRegEx_currentIndexChanged(int index);

    void on_pushButtonClear_clicked();

signals:
    void onWriteReply() ;
    void onReadReply() ;

protected:

private:
    Ui::FrameRegManager *ui;
    QStandardItemModel *m_pTVModel = nullptr;

    int m_nSelect = -1;
    bool  m_bCtrlPress = false;
    bool  m_bShiftPress = false;
    bool  m_isCustumReg = false;
    SerialTestDialog *m_pCOMDlg = nullptr ;

    void addItem(const QStringList&values);
    void addItem(const QString &strLine);

    void resetAddress();
    QString m_strModel ;
    void buildFileName() ;
    QString m_strCurFile ;
    bool LoadDataFromFile() ;
    bool SaveDataToFile() ;

    bool  m_bWriting = false;
    bool  m_bReading = false;
    bool  m_bLoading = false ;

    QList<int> m_selectRows ;
    void doSendList() ;
    void doReadList() ;

    void saveLoadMenuStatus(bool bSave=true) ;
};

#endif // FRAMEREGMANAGER_H
