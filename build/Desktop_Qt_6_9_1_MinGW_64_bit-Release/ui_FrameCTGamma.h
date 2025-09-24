/********************************************************************************
** Form generated from reading UI file 'FrameCTGamma.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMECTGAMMA_H
#define UI_FRAMECTGAMMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrameCTGamma
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *FrameCTGamma)
    {
        if (FrameCTGamma->objectName().isEmpty())
            FrameCTGamma->setObjectName("FrameCTGamma");
        FrameCTGamma->resize(1042, 658);
        verticalLayout = new QVBoxLayout(FrameCTGamma);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton1 = new QPushButton(FrameCTGamma);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setCheckable(true);

        horizontalLayout->addWidget(pushButton1);

        pushButton2 = new QPushButton(FrameCTGamma);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setCheckable(true);

        horizontalLayout->addWidget(pushButton2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FrameCTGamma);

        QMetaObject::connectSlotsByName(FrameCTGamma);
    } // setupUi

    void retranslateUi(QFrame *FrameCTGamma)
    {
        FrameCTGamma->setWindowTitle(QCoreApplication::translate("FrameCTGamma", "Frame", nullptr));
        pushButton1->setText(QCoreApplication::translate("FrameCTGamma", "sct_gamma", nullptr));
        pushButton2->setText(QCoreApplication::translate("FrameCTGamma", "dct_gamma", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameCTGamma: public Ui_FrameCTGamma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMECTGAMMA_H
