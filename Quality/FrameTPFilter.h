#ifndef FRAMETPFILTER_H
#define FRAMETPFILTER_H

#include <QFrame>
#include <QStandardItemModel>

#include "SerialTestDialog.h"

namespace Ui {
class FrameTPFilter;
}

class FrameTPFilter : public QFrame
{
    Q_OBJECT

public:
    explicit FrameTPFilter(QWidget *parent = nullptr);
    ~FrameTPFilter();

private slots:
    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonReset_clicked();

private:
    Ui::FrameTPFilter *ui;

    QStandardItemModel *m_pDModel = nullptr ;

    bool m_bLoading = false ;
    void LoadBuf(const QString&strFile,bool bForLinar=false) ;

    SerialTestDialog *m_pCOMDlg = nullptr ;

    quint32 m_addr = (4<<13);
};

#endif // FRAMETPFILTER_H
