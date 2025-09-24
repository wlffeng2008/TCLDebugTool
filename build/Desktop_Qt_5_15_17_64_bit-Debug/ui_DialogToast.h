/********************************************************************************
** Form generated from reading UI file 'DialogToast.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTOAST_H
#define UI_DIALOGTOAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogToast
{
public:
    QLabel *label;

    void setupUi(QDialog *DialogToast)
    {
        if (DialogToast->objectName().isEmpty())
            DialogToast->setObjectName(QString::fromUtf8("DialogToast"));
        DialogToast->resize(600, 50);
        DialogToast->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255); border: solid 2px blue ; border-radius:8px;"));
        label = new QLabel(DialogToast);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 5, 511, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(DialogToast);

        QMetaObject::connectSlotsByName(DialogToast);
    } // setupUi

    void retranslateUi(QDialog *DialogToast)
    {
        DialogToast->setWindowTitle(QCoreApplication::translate("DialogToast", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogToast", "\346\217\220\347\244\272\344\277\241\346\201\257\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogToast: public Ui_DialogToast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTOAST_H
