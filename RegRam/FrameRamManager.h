#ifndef FRAMERAMMANAGER_H
#define FRAMERAMMANAGER_H

#include <QFrame>
#include <QTimer>
#include <QKeyEvent>
#include <QStandardItemModel>


namespace Ui {
class FrameRamManager;
}

class SerialTestDialog;

class FrameRamManager : public QFrame
{
    Q_OBJECT

public:
    explicit FrameRamManager(QWidget *parent = nullptr);
    ~FrameRamManager();

    static FrameRamManager *getInstance() ;

    void setModel(const QString &strModel) ;
    void readHugeRamOutside(quint32 nAddr,quint32 nLen) ;
    void writeHugeRamOutside(quint32 nAddr,const QByteArray&ramData) ;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override ;

private slots:

    void on_pushButtonAddFile_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonRemoveFile_clicked();

    void on_pushButtonWriteFile_clicked();

    void on_pushButtonOpenFile_clicked();

    void on_pushButtonReLoad_clicked();

signals:


private:
    Ui::FrameRamManager *ui;
    QStandardItemModel *m_pDataModel = nullptr;
    QStandardItemModel *m_pFileModel = nullptr ;

    SerialTestDialog *m_pCOMDlg = nullptr ;

    bool m_bCtrlPress = false;
    bool m_bShiftPress = false;
    bool m_bAltPress = false;

    int m_nSelectData = -1;

    int m_nSelectFile = -1;
    QString m_strSelectFile;

    void addFileTolist(const QString&strFile,const QString&strAddr) ;
    void saveLoadFileList(bool bToSave=true) ;

    void loadDataFromFile(const QString&strFile) ;
    void addDataTolist(const QString&strLine) ;
    void addDataTolist(const QStringList&dataGroup) ;

    QTimer m_TMReadEnd ;

    bool m_bReadFromOut  = false ;
    bool m_bWriteFromOut = false ;

    void writeHugeRam() ;
    void readHugeRam() ;
    quint32  m_RdWrUnit = 200;

    quint32  m_readAddr  = 0;
    quint32  m_readCount = 0;

    quint32  m_writeAddr = 0;

    QByteArray m_writeBuf ;
};

#endif // FRAMERAMMANAGER_H
