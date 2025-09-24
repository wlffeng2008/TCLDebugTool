#ifndef DIALOGAGINGTEST_H
#define DIALOGAGINGTEST_H
#include "SerialTestDialog.h"

#include <QDialog>
#include <QTimer>
#include <QStandardItemModel>

namespace Ui {
class DialogAgingTest;
}

class DialogAgingTest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAgingTest(QWidget *parent = nullptr);
    ~DialogAgingTest();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    Ui::DialogAgingTest *ui;

    void addNew(const QString&strLine) ;
    void doTest() ;
    int     m_selectItem = -1 ;

    QTimer  m_TMTest ;
    bool    m_bInTesting = false ;
    int     m_testItem = -1 ;
    quint32 m_testTime  = 0 ;
    quint32 m_testCount = 0 ;
    SerialTestDialog *m_pCOMDlg= nullptr ;
    QStandardItemModel *m_pModel = nullptr ;
    QStandardItemModel *m_pRegModel = nullptr ;

    QString m_strBak ;
};

#endif // DIALOGAGINGTEST_H
