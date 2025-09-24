#ifndef DIALOGQUALITYMANAGER_H
#define DIALOGQUALITYMANAGER_H

#include <QDialog>

namespace Ui {
class DialogQualityManager;
}

class DialogQualityManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQualityManager(QWidget *parent = nullptr);
    ~DialogQualityManager();

private:
    Ui::DialogQualityManager *ui;

    void showFrame(int nIndex) ;
};

#endif // DIALOGQUALITYMANAGER_H
