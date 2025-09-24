#ifndef DIALOGPACKMAKER_H
#define DIALOGPACKMAKER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class DialogPackMaker;
}

class DialogPackMaker : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPackMaker(QWidget *parent = nullptr);
    ~DialogPackMaker();

    static DialogPackMaker *getInstance() ;

    void  makeUpdatePack(const QString &strInFile,const QString &strOutFile) ;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject*watched,QEvent *event) override;


private:
    Ui::DialogPackMaker *ui;

    int m_nCount = 0 ;
    QTimer m_TMSwitch ;
};

#endif // DIALOGPACKMAKER_H
