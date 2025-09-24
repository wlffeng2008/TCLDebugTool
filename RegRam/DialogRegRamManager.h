#ifndef DIALOGREGRAMMANAGER_H
#define DIALOGREGRAMMANAGER_H

#include <QDialog>

namespace Ui {
class DialogRegRamManager;
}

class DialogRegRamManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegRamManager(QWidget *parent = nullptr);
    ~DialogRegRamManager();

private slots:
    void on_radioButtonReg_clicked();

    void on_radioButtonRam_clicked();

private:
    Ui::DialogRegRamManager *ui;
};

#endif // DIALOGREGRAMMANAGER_H
