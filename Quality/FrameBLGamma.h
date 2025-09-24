#ifndef FRAMEBLGAMMA_H
#define FRAMEBLGAMMA_H

#include "SerialTestDialog.h"

#include <QFrame>
#include <QStandardItemModel>

namespace Ui {
class FrameBLGamma;
}

class FrameBLGamma : public QFrame
{
    Q_OBJECT

public:
    explicit FrameBLGamma(QWidget *parent = nullptr);
    ~FrameBLGamma();

private slots:
    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonReset_clicked();

private:
    Ui::FrameBLGamma *ui;
    QStandardItemModel *m_pDModel = nullptr ;

    bool m_bLoading = false ;
    void LoadBuf(const QString&strFile,bool bForLinar=false) ;

    quint32 m_nAddr = (2<<13) ;
    SerialTestDialog *m_pCOMDlg = nullptr ;
    quint16 m_orgData[5000];
    quint16 m_calData[5000];
    void doCal() ;
};

#endif // FRAMEBLGAMMA_H
