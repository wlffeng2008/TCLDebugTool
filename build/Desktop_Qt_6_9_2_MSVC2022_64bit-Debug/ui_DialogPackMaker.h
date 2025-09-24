/********************************************************************************
** Form generated from reading UI file 'DialogPackMaker.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPACKMAKER_H
#define UI_DIALOGPACKMAKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPackMaker
{
public:
    QLabel *label;
    QLineEdit *lineEditVersi;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEditFile1;
    QLineEdit *lineEditFile2;
    QPushButton *pushButtonGo;
    QLabel *labelSwitch;
    QLabel *label_6;
    QLabel *labelFileInfo;
    QLabel *label_8;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonHide;
    QPushButton *pushButtonClear;

    void setupUi(QDialog *DialogPackMaker)
    {
        if (DialogPackMaker->objectName().isEmpty())
            DialogPackMaker->setObjectName("DialogPackMaker");
        DialogPackMaker->resize(730, 580);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        DialogPackMaker->setFont(font);
        label = new QLabel(DialogPackMaker);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 170, 131, 21));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditVersi = new QLineEdit(DialogPackMaker);
        lineEditVersi->setObjectName("lineEditVersi");
        lineEditVersi->setGeometry(QRect(140, 170, 211, 21));
        lineEditVersi->setReadOnly(true);
        label_3 = new QLabel(DialogPackMaker);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 81, 21));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(DialogPackMaker);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 140, 81, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(DialogPackMaker);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 210, 81, 21));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        plainTextEdit = new QPlainTextEdit(DialogPackMaker);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(140, 210, 571, 311));
        lineEditFile1 = new QLineEdit(DialogPackMaker);
        lineEditFile1->setObjectName("lineEditFile1");
        lineEditFile1->setGeometry(QRect(140, 70, 571, 21));
        lineEditFile2 = new QLineEdit(DialogPackMaker);
        lineEditFile2->setObjectName("lineEditFile2");
        lineEditFile2->setGeometry(QRect(140, 140, 571, 21));
        pushButtonGo = new QPushButton(DialogPackMaker);
        pushButtonGo->setObjectName("pushButtonGo");
        pushButtonGo->setGeometry(QRect(580, 170, 131, 31));
        labelSwitch = new QLabel(DialogPackMaker);
        labelSwitch->setObjectName("labelSwitch");
        labelSwitch->setGeometry(QRect(360, 170, 71, 21));
        labelSwitch->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(DialogPackMaker);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 100, 81, 21));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelFileInfo = new QLabel(DialogPackMaker);
        labelFileInfo->setObjectName("labelFileInfo");
        labelFileInfo->setGeometry(QRect(140, 100, 401, 21));
        labelFileInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(DialogPackMaker);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 20, 571, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        pushButtonLoad = new QPushButton(DialogPackMaker);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setGeometry(QRect(580, 100, 131, 31));
        pushButtonHide = new QPushButton(DialogPackMaker);
        pushButtonHide->setObjectName("pushButtonHide");
        pushButtonHide->setGeometry(QRect(580, 530, 131, 31));
        pushButtonClear = new QPushButton(DialogPackMaker);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(140, 530, 131, 31));

        retranslateUi(DialogPackMaker);

        QMetaObject::connectSlotsByName(DialogPackMaker);
    } // setupUi

    void retranslateUi(QDialog *DialogPackMaker)
    {
        DialogPackMaker->setWindowTitle(QCoreApplication::translate("DialogPackMaker", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogPackMaker", "Magic Number\357\274\232", nullptr));
        lineEditVersi->setText(QCoreApplication::translate("DialogPackMaker", "41475046534E4C4B", nullptr));
        label_3->setText(QCoreApplication::translate("DialogPackMaker", "\346\272\220\346\226\207\344\273\266\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("DialogPackMaker", "\350\276\223\345\207\272\346\226\207\344\273\266\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("DialogPackMaker", "\350\276\223\345\207\272\344\277\241\346\201\257\357\274\232", nullptr));
        pushButtonGo->setText(QCoreApplication::translate("DialogPackMaker", "\345\274\200\345\247\213\346\211\223\345\214\205", nullptr));
        labelSwitch->setText(QCoreApplication::translate("DialogPackMaker", "\357\274\210HEX)", nullptr));
        label_6->setText(QCoreApplication::translate("DialogPackMaker", "\345\237\272\346\234\254\344\277\241\346\201\257\357\274\232", nullptr));
        labelFileInfo->setText(QCoreApplication::translate("DialogPackMaker", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232\346\234\252\347\237\245   \346\227\245\346\234\237: \346\234\252\347\237\245", nullptr));
        label_8->setText(QCoreApplication::translate("DialogPackMaker", "\346\213\226\346\213\275\344\270\200\344\270\252Bin\346\226\207\344\273\266\345\210\260\346\255\244\345\257\271\350\257\235\346\241\206\347\234\213\347\234\213...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("DialogPackMaker", "\351\200\211\346\213\251\346\272\220\346\226\207\344\273\266...", nullptr));
        pushButtonHide->setText(QCoreApplication::translate("DialogPackMaker", "\350\277\224\345\233\236", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("DialogPackMaker", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPackMaker: public Ui_DialogPackMaker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPACKMAKER_H
