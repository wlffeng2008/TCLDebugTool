#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "SerialTestDialog.h"
#include "DialogRegRamManager.h"
#include "DialogQualityManager.h"
#include "DialogAgingTest.h"
#include "DialogPackMaker.h"
#include "DialogConfigPack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *pEvt) override ;
    bool eventFilter(QObject *watched, QEvent *event) override;
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result)  override;
    void closeEvent(QCloseEvent *event) override ;

private slots:
    void on_pushButtonSerial_clicked();

    void on_pushButtonScreenConfig_clicked();

    void on_pushButtonTestTool_clicked();

    void on_comboBoxModel_currentIndexChanged(int index);

    void on_pushButtonBrightness_clicked();

    void on_pushButtonPictureControl_clicked();

private:
    Ui::MainWindow *ui;

    QTimer m_TMSearial ;

    SerialTestDialog *m_pCOMDlg = nullptr ;
    DialogRegRamManager *m_pRegRam =  nullptr ;
    DialogQualityManager *m_pQuality =  nullptr ;
    DialogAgingTest *m_pAging =  nullptr ;
    DialogPackMaker *m_pPack =  nullptr ;
    DialogConfigPack *m_pConfig =  nullptr ;
    void pushButtonFocusInOutAnimation(QObject *watched, bool bFocusIn);
};




#endif // MAINWINDOW_H
