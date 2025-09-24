#ifndef DIALOGCONFIGPACK_H
#define DIALOGCONFIGPACK_H

#include <QDialog>
#include <QTimer>
#include <QStandardItemModel>
#include <QSettings>

#include <QXlsx>
using namespace  QXlsx ;

namespace Ui {
class DialogConfigPack;
}

typedef struct
{
    QString strAddr ;
    QString strName ;
    bool bBesetted ;
    QStringList group ;
}dataItem;

typedef struct
{
    QString strName ;
    bool bExported ;
    QList<dataItem> data ;
}dataSheet;


class DialogConfigPack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigPack(QWidget *parent = nullptr);
    ~DialogConfigPack();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    Ui::DialogConfigPack *ui;

    QSettings *m_pSet = nullptr ;

    QStandardItemModel *m_pRModel = nullptr ;
    QStandardItemModel *m_pAModel = nullptr ;
    QStringList m_readCols ;
    QString m_strCurSheet ;
    dataSheet m_dataheet ;

    QStringList m_expModels ;
    QStringList m_expSheets ;
    QList<dataSheet> m_whole ;
    bool m_bLoading = false ;

    int m_nSelectRam = -1 ;

    void loadSheet(Document & xlsx, const QString&strSheet) ;
    void showSheet(const QString&strSheet) ;
    void loadFile(const QString&strFile) ;

    void saveLoadRamCfg(bool bToSave=true) ;
};

#endif // DIALOGCONFIGPACK_H
