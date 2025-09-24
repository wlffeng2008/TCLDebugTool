#ifndef DIALOGLOGVIEW_H
#define DIALOGLOGVIEW_H

#include <QDialog>

namespace Ui {
class DialogLogView;
}

class DialogLogView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogView(QWidget *parent = nullptr);
    ~DialogLogView();

    void pushLogText(const QString&strLog,bool isSend=true) ;

private slots:
    void on_pushButtonClear_clicked();

private:
    Ui::DialogLogView *ui;
};

#endif // DIALOGLOGVIEW_H
