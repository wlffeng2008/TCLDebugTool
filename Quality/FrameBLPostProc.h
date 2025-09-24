#ifndef FRAMEBLPOSTPROC_H
#define FRAMEBLPOSTPROC_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QSettings>
#include <QStandardItemModel>

namespace Ui {
class FrameBLPostProc;
}

class FrameBLPostProc : public QFrame
{
    Q_OBJECT

public:
    explicit FrameBLPostProc(QWidget *parent = nullptr);
    ~FrameBLPostProc();

private slots:
    void on_checkBoxBLPostProc_clicked();

    void on_pushButtonWriteWB_clicked();
    void on_pushButtonWriteWBL_clicked();

    void on_pushButtonWriteM_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonWriteGM_clicked();

    void on_pushButtonReadGM_clicked();
    void on_checkBoxProcoeSW_clicked();
    void on_checkBoxProBblbadjEn_clicked();

    void on_pushButtonWriteGMEn_clicked();

private:
    Ui::FrameBLPostProc *ui;

    QStandardItemModel *m_pDModel = nullptr;
    QStandardItemModel *m_pGModel = nullptr;
    QStandardItemModel *m_pMModel = nullptr;

    SerialTestDialog *m_pCOMDlg = nullptr ;

    void fillGrid(bool bSelf=false) ;

    QSettings *m_pSet = nullptr ;
    QString m_strCurFile ;
};

#endif // FRAMEBLPOSTPROC_H
