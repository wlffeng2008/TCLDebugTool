/********************************************************************************
** Form generated from reading UI file 'DialogLogView.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOGVIEW_H
#define UI_DIALOGLOGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogLogView
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxSetTop;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClear;

    void setupUi(QDialog *DialogLogView)
    {
        if (DialogLogView->objectName().isEmpty())
            DialogLogView->setObjectName("DialogLogView");
        DialogLogView->resize(817, 616);
        verticalLayout = new QVBoxLayout(DialogLogView);
        verticalLayout->setObjectName("verticalLayout");
        plainTextEdit = new QPlainTextEdit(DialogLogView);
        plainTextEdit->setObjectName("plainTextEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Fixedsys")});
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBoxSetTop = new QCheckBox(DialogLogView);
        checkBoxSetTop->setObjectName("checkBoxSetTop");

        horizontalLayout->addWidget(checkBoxSetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonClear = new QPushButton(DialogLogView);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButtonClear);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(DialogLogView);

        QMetaObject::connectSlotsByName(DialogLogView);
    } // setupUi

    void retranslateUi(QDialog *DialogLogView)
    {
        DialogLogView->setWindowTitle(QCoreApplication::translate("DialogLogView", "\344\270\262\345\217\243\351\200\232\344\277\241\346\227\245\345\277\227\350\247\202\345\257\237", nullptr));
        checkBoxSetTop->setText(QCoreApplication::translate("DialogLogView", "\347\275\256\351\241\266", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("DialogLogView", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLogView: public Ui_DialogLogView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOGVIEW_H
