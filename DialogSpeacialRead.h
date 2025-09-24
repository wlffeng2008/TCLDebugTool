#ifndef DIALOGSPEACIALREAD_H
#define DIALOGSPEACIALREAD_H

#include <QDialog>

namespace Ui {
class DialogSpeacialRead;
}

class DialogSpeacialRead : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSpeacialRead(QWidget *parent = nullptr);
    ~DialogSpeacialRead();

private:
    Ui::DialogSpeacialRead *ui;
};

#endif // DIALOGSPEACIALREAD_H
