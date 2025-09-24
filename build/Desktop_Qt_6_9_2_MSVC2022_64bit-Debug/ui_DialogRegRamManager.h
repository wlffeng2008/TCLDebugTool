/********************************************************************************
** Form generated from reading UI file 'DialogRegRamManager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGREGRAMMANAGER_H
#define UI_DIALOGREGRAMMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "framerammanager.h"
#include "frameregmanager.h"

QT_BEGIN_NAMESPACE

class Ui_DialogRegRamManager
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameTop;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonReg;
    QRadioButton *radioButtonRam;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayoutBottom;
    FrameRegManager *frameLeft;
    FrameRamManager *frameRight;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DialogRegRamManager)
    {
        if (DialogRegRamManager->objectName().isEmpty())
            DialogRegRamManager->setObjectName("DialogRegRamManager");
        DialogRegRamManager->resize(1349, 700);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        DialogRegRamManager->setFont(font);
        DialogRegRamManager->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(DialogRegRamManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameTop = new QFrame(DialogRegRamManager);
        frameTop->setObjectName("frameTop");
        frameTop->setMinimumSize(QSize(32, 0));
        frameTop->setMaximumSize(QSize(16777215, 32));
        frameTop->setStyleSheet(QString::fromUtf8("QFrame{background-color: rgb(170, 255, 255);}"));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameTop);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 0, 0, 0);
        radioButtonReg = new QRadioButton(frameTop);
        radioButtonReg->setObjectName("radioButtonReg");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        radioButtonReg->setFont(font1);

        horizontalLayout->addWidget(radioButtonReg);

        radioButtonRam = new QRadioButton(frameTop);
        radioButtonRam->setObjectName("radioButtonRam");
        radioButtonRam->setFont(font1);

        horizontalLayout->addWidget(radioButtonRam);

        horizontalSpacer = new QSpacerItem(658, 68, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frameTop);

        horizontalLayoutBottom = new QHBoxLayout();
        horizontalLayoutBottom->setSpacing(0);
        horizontalLayoutBottom->setObjectName("horizontalLayoutBottom");
        frameLeft = new FrameRegManager(DialogRegRamManager);
        frameLeft->setObjectName("frameLeft");
        frameLeft->setFocusPolicy(Qt::ClickFocus);
        frameLeft->setFrameShape(QFrame::StyledPanel);
        frameLeft->setFrameShadow(QFrame::Raised);

        horizontalLayoutBottom->addWidget(frameLeft);

        frameRight = new FrameRamManager(DialogRegRamManager);
        frameRight->setObjectName("frameRight");
        frameRight->setFrameShape(QFrame::StyledPanel);
        frameRight->setFrameShadow(QFrame::Raised);

        horizontalLayoutBottom->addWidget(frameRight);

        verticalSpacer = new QSpacerItem(1, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayoutBottom->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayoutBottom);


        retranslateUi(DialogRegRamManager);

        QMetaObject::connectSlotsByName(DialogRegRamManager);
    } // setupUi

    void retranslateUi(QDialog *DialogRegRamManager)
    {
        DialogRegRamManager->setWindowTitle(QCoreApplication::translate("DialogRegRamManager", "Reg / Ram \351\205\215\347\275\256", nullptr));
        radioButtonReg->setText(QCoreApplication::translate("DialogRegRamManager", "Reg\350\257\273/\345\206\231", nullptr));
        radioButtonRam->setText(QCoreApplication::translate("DialogRegRamManager", "Ram\350\257\273/\345\206\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRegRamManager: public Ui_DialogRegRamManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGREGRAMMANAGER_H
