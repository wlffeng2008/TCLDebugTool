#ifndef SERIALTESTDIALOG_H
#define SERIALTESTDIALOG_H

#include "gencomport.h"
#include "DialogLogView.h"
#include "FrameRamManager.h"

#include <QTimer>
#include <QDialog>
#include <QByteArray>
#include <QStandardItem>
#include <QStandardItemModel>

#include <windows.h>
#include <dbt.h>

namespace Ui {
class SerialTestDialog;
}


typedef enum
{
    HEAD_SEND = 0xD555,
    HEAD_RECV = 0x55AA,
    TYPE_REG_WRITE=0x00,
    TYPE_REG_READ=0x01,
    TYPE_RAM_WRITE=0x10,
    TYPE_RAM_READ=0x11,
    TYPE_WRITE_ACK=0x20,
    TYPE_WRITE_SUCCESS=0x50,
    TYPE_WRITE_FAILED=0x51
}TCLDebugEnum;

#pragma pack(1)
typedef struct
{
    quint16 head ;
    quint8 index ;
    quint8 type ;
    quint32 addr ;
    quint16 len ;
}sPackHeader;
#pragma pack()


class SerialTestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialTestDialog(QWidget *parent = nullptr);
    ~SerialTestDialog();

    static SerialTestDialog* getInstance() ;
    static QString getDataPath() ;
    static QString getModel() ;

    bool readRegData(quint32 nAddr,int nLen, QWidget *pSender) ;
    bool writeRegData(quint32 nAddr,const char *data,int nLen, QWidget *pSender) ;
    bool readRamData(quint32 nAddr,int nLen, QWidget *pSender) ;
    bool writeRamData(quint32 nAddr,const char *data,int nLen, QWidget *pSender) ;

    void sendSwitch(quint32 addr, bool bOn, QWidget *pSender);
    void sendInt8(quint32 addr, quint8 Byte, QWidget *pSender);
    void sendInt16(quint32 addr, quint16 value, QWidget *pSender);
    void sendInt32(quint32 addr, quint32 value, QWidget *pSender);
    void sendInt64(quint32 addr, quint64 value, QWidget *pSender);

    QWidget *getSender(){ return m_pSender; } ;

    void setPackIndex(quint8 nIndex=0);
    quint8 getPackIndex();
    bool isConnected(bool showBox=true);
    QByteArray GetBuf() { return m_buf; }
    sPackHeader *GetDataHead();
    quint8 *GetDataBody();

    void setModel(const QString &strModel) ;
    QString model(){ return m_strCurModel ; }
    QString dataPath(){ return m_strDataPath ; }

    void OnUSBChanged() ;

    void readHugeRam(quint32 nAddr,quint32 nLen, QWidget *pSender) ;
    void writeHugeRam(quint32 nAddr,const QByteArray&ramData, QWidget *pSender) ;
    void notifyReadHugeRamDone(const QByteArray&ramData) ;
    void notifyWriteHugeRamDone() ;

protected:

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
#else
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
#endif

private slots:
    void on_pushButtonScan_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonSaveAs_clicked();

    void on_pushButtonHide_clicked();

    void on_checkBoxOpen_clicked();

    void on_comboBoxCOM_currentIndexChanged(int index);

    void on_pushButtonSend_clicked();

    void on_pushButtonNew_clicked() ;

    void on_pushButtonDel_clicked() ;

    void on_radioButtonRegRead_clicked();

    void on_radioButtonRegWrite_clicked();

    void on_radioButtonRamRead_clicked();

    void on_radioButtonRamWrite_clicked();

    void on_lineEditAddr_textChanged(const QString &arg1);

    void on_lineEditLen_textChanged(const QString &arg1);

    void on_pushButtonLog_clicked();

    void on_lineEditReply_textEdited(const QString &arg1);

    void on_lineEditWrite_textChanged(const QString &arg1);

    void on_checkBoxHexData_clicked();

    void on_spinBoxPackIndex_valueChanged(int arg1);

signals:
    void COMStatusChanged(bool bOpen) ;
    void COMDataIn(const QByteArray&data,QWidget *pSender) ;
    void COMReplyTimeout() ;
    void COMModelChanged(const QString &strModel) ;
    void COMReadHugeRamDone(const QByteArray&data, QWidget *pSender) ;
    void COMWriteHugeRamDone(QWidget *pSender) ;

private:
    Ui::SerialTestDialog *ui;

    QStandardItemModel *m_model = nullptr ;

    bool m_bCOMConnected = false ;
    bool m_bScanCOM = false ;
    GenComport *m_pCOM = nullptr ;
    QWidget *m_pSender = nullptr ;
    QWidget *m_pHugeRamReader = nullptr ;
    void updateCOMStatus() ;

    QString m_strCurFile ;
    void LoadCmdFile(const QString&strFile) ;

    int m_nCurRow = -1 ;

    bool m_bCanMakePack = true ;

    QString m_strLastCmd ;
    bool sendCommand(const QString&strCmd) ;

    int m_nMakeType = 0 ;
    void makePack() ;

    QTimer m_ReplyTM ;
    QByteArray m_buf ;

    DialogLogView *m_pLogDlg = nullptr;

    QString m_strCurModel ;
    QString m_strDataPath ;

    bool m_bWriteOK = false ;
    QTimer m_TMWriteNotify ;
    void saveSetting() ;

    FrameRamManager *m_pRamReader = nullptr ;
};

#endif // SERIALTESTDIALOG_H
