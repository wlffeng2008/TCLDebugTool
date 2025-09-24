#ifndef FRAMEPIXELCOMPENSATION_H
#define FRAMEPIXELCOMPENSATION_H

#include <QFrame>
#include <QSettings>

#include "SerialTestDialog.h"

namespace Ui {
class FramePixelCompensation;
}

class FramePixelCompensation : public QFrame
{
    Q_OBJECT

public:
    explicit FramePixelCompensation(QWidget *parent = nullptr);
    ~FramePixelCompensation();

private slots:
    void on_pushButtonWriteM_clicked();

    void on_pushButtonReadM_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::FramePixelCompensation *ui;

    QStandardItemModel *m_pDModel = nullptr;
    QStandardItemModel *m_pGModel = nullptr;
    void fillGrid(bool bSelf=false) ;

    QSettings *m_pSet = nullptr ;

    bool m_bAutoSEnd = false ;
    SerialTestDialog *m_pCOMDlg = nullptr ;

    QString  m_strCurFile ;
    bool m_bLoading = false ;

    void sendValue(int nIndex) ;
};

#endif // FRAMEPIXELCOMPENSATION_H
