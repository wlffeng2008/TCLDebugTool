#ifndef DIALOGTOAST_H
#define DIALOGTOAST_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class DialogToast;
}

class DialogToast : public QDialog
{
    Q_OBJECT

public:
    explicit DialogToast(QWidget *parent = nullptr);
    ~DialogToast();

    void active(const QString&text,int durtion=1200) ;

private:
    Ui::DialogToast *ui;

    qreal m_opacity = 1.0 ;
    QTimer m_TMShow ;
    QTimer m_TMHide ;
};

DialogToast *toast(QWidget *parent=nullptr) ;
void easyToast(const QString&text,QWidget *parent=nullptr,quint32 durtaion=1200) ;

#endif // DIALOGTOAST_H
