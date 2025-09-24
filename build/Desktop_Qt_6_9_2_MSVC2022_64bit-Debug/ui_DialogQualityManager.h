/********************************************************************************
** Form generated from reading UI file 'DialogQualityManager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGQUALITYMANAGER_H
#define UI_DIALOGQUALITYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <framectgamma.h>
#include "frameblgamma.h"
#include "frameblpostproc.h"
#include "framecontrol.h"
#include "framedemo.h"
#include "frameepccboost.h"
#include "framelocaldimmingprofile.h"
#include "framepixelcompensation.h"
#include "framepqgamma.h"
#include "frametpfilter.h"

QT_BEGIN_NAMESPACE

class Ui_DialogQualityManager
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameTop;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton0;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QRadioButton *radioButton5;
    QRadioButton *radioButton6;
    QRadioButton *radioButton7;
    QRadioButton *radioButton8;
    QRadioButton *radioButton9;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    FrameControl *frame0;
    FrameBLGamma *frame1;
    FrameTPFilter *frame2;
    FrameBLPostProc *frame3;
    FrameEPCCBOOST *frame4;
    FrameDemo *frame5;
    FramePixelCompensation *frame6;
    FrameLocalDimmingProfile *frame7;
    FramePQGamma *frame8;
    FrameCTGamma *frame9;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogQualityManager)
    {
        if (DialogQualityManager->objectName().isEmpty())
            DialogQualityManager->setObjectName("DialogQualityManager");
        DialogQualityManager->resize(1457, 480);
        QFont font;
        font.setBold(true);
        DialogQualityManager->setFont(font);
        DialogQualityManager->setStyleSheet(QString::fromUtf8("QDailog #DialogQualityManager{rgb(85, 170, 255)}"));
        verticalLayout = new QVBoxLayout(DialogQualityManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameTop = new QFrame(DialogQualityManager);
        frameTop->setObjectName("frameTop");
        frameTop->setMaximumSize(QSize(16777215, 32));
        frameTop->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameTop);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 0, 0, 0);
        radioButton0 = new QRadioButton(frameTop);
        buttonGroup = new QButtonGroup(DialogQualityManager);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButton0);
        radioButton0->setObjectName("radioButton0");
        radioButton0->setMinimumSize(QSize(0, 30));
        radioButton0->setMaximumSize(QSize(16777215, 24));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        radioButton0->setFont(font1);
        radioButton0->setChecked(true);

        horizontalLayout_3->addWidget(radioButton0);

        radioButton1 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton1);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setMinimumSize(QSize(0, 30));
        radioButton1->setMaximumSize(QSize(16777215, 24));
        radioButton1->setFont(font1);

        horizontalLayout_3->addWidget(radioButton1);

        radioButton2 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton2);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setMinimumSize(QSize(0, 30));
        radioButton2->setMaximumSize(QSize(16777215, 24));
        radioButton2->setFont(font1);

        horizontalLayout_3->addWidget(radioButton2);

        radioButton3 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton3);
        radioButton3->setObjectName("radioButton3");
        radioButton3->setMinimumSize(QSize(0, 30));
        radioButton3->setMaximumSize(QSize(16777215, 24));
        radioButton3->setFont(font1);

        horizontalLayout_3->addWidget(radioButton3);

        radioButton4 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton4);
        radioButton4->setObjectName("radioButton4");
        radioButton4->setMinimumSize(QSize(0, 30));
        radioButton4->setMaximumSize(QSize(16777215, 24));
        radioButton4->setFont(font1);

        horizontalLayout_3->addWidget(radioButton4);

        radioButton5 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton5);
        radioButton5->setObjectName("radioButton5");
        radioButton5->setMinimumSize(QSize(0, 30));
        radioButton5->setMaximumSize(QSize(16777215, 24));
        radioButton5->setFont(font1);

        horizontalLayout_3->addWidget(radioButton5);

        radioButton6 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton6);
        radioButton6->setObjectName("radioButton6");
        radioButton6->setMinimumSize(QSize(0, 30));
        radioButton6->setMaximumSize(QSize(16777215, 24));
        radioButton6->setFont(font1);

        horizontalLayout_3->addWidget(radioButton6);

        radioButton7 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton7);
        radioButton7->setObjectName("radioButton7");
        radioButton7->setMinimumSize(QSize(0, 30));
        radioButton7->setMaximumSize(QSize(16777215, 24));
        radioButton7->setFont(font1);

        horizontalLayout_3->addWidget(radioButton7);

        radioButton8 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton8);
        radioButton8->setObjectName("radioButton8");
        radioButton8->setMinimumSize(QSize(0, 30));
        radioButton8->setMaximumSize(QSize(16777215, 24));
        radioButton8->setFont(font1);

        horizontalLayout_3->addWidget(radioButton8);

        radioButton9 = new QRadioButton(frameTop);
        buttonGroup->addButton(radioButton9);
        radioButton9->setObjectName("radioButton9");
        radioButton9->setMinimumSize(QSize(0, 30));
        radioButton9->setMaximumSize(QSize(16777215, 24));
        radioButton9->setFont(font1);

        horizontalLayout_3->addWidget(radioButton9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(frameTop);

        frame = new QFrame(DialogQualityManager);
        frame->setObjectName("frame");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        frame->setFont(font2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame0 = new FrameControl(frame);
        frame0->setObjectName("frame0");
        frame0->setFont(font2);
        frame0->setFrameShape(QFrame::StyledPanel);
        frame0->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame0);

        frame1 = new FrameBLGamma(frame);
        frame1->setObjectName("frame1");
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame1);

        frame2 = new FrameTPFilter(frame);
        frame2->setObjectName("frame2");
        frame2->setFrameShape(QFrame::StyledPanel);
        frame2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame2);

        frame3 = new FrameBLPostProc(frame);
        frame3->setObjectName("frame3");
        frame3->setFrameShape(QFrame::StyledPanel);
        frame3->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame3);

        frame4 = new FrameEPCCBOOST(frame);
        frame4->setObjectName("frame4");
        frame4->setFrameShape(QFrame::StyledPanel);
        frame4->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame4);

        frame5 = new FrameDemo(frame);
        frame5->setObjectName("frame5");
        frame5->setFrameShape(QFrame::StyledPanel);
        frame5->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame5);

        frame6 = new FramePixelCompensation(frame);
        frame6->setObjectName("frame6");
        frame6->setStyleSheet(QString::fromUtf8(""));
        frame6->setFrameShape(QFrame::StyledPanel);
        frame6->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame6);

        frame7 = new FrameLocalDimmingProfile(frame);
        frame7->setObjectName("frame7");
        frame7->setFrameShape(QFrame::StyledPanel);
        frame7->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame7);

        frame8 = new FramePQGamma(frame);
        frame8->setObjectName("frame8");
        frame8->setFrameShape(QFrame::StyledPanel);
        frame8->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame8);

        frame9 = new FrameCTGamma(frame);
        frame9->setObjectName("frame9");
        frame9->setFrameShape(QFrame::StyledPanel);
        frame9->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame9);


        verticalLayout->addWidget(frame);


        retranslateUi(DialogQualityManager);

        QMetaObject::connectSlotsByName(DialogQualityManager);
    } // setupUi

    void retranslateUi(QDialog *DialogQualityManager)
    {
        DialogQualityManager->setWindowTitle(QCoreApplication::translate("DialogQualityManager", "\347\224\273\350\264\250\350\260\203\350\257\225", nullptr));
        radioButton0->setText(QCoreApplication::translate("DialogQualityManager", "Control (PQ)", nullptr));
        radioButton1->setText(QCoreApplication::translate("DialogQualityManager", "BL Gamma", nullptr));
        radioButton2->setText(QCoreApplication::translate("DialogQualityManager", "TP Filter", nullptr));
        radioButton3->setText(QCoreApplication::translate("DialogQualityManager", "BL_Post_Proc", nullptr));
        radioButton4->setText(QCoreApplication::translate("DialogQualityManager", "EPCC+BOOST", nullptr));
        radioButton5->setText(QCoreApplication::translate("DialogQualityManager", "Demo", nullptr));
        radioButton6->setText(QCoreApplication::translate("DialogQualityManager", "Pixel Compensation", nullptr));
        radioButton7->setText(QCoreApplication::translate("DialogQualityManager", "Local Dimming Profile", nullptr));
        radioButton8->setText(QCoreApplication::translate("DialogQualityManager", "PQ-Gamma", nullptr));
        radioButton9->setText(QCoreApplication::translate("DialogQualityManager", "CT-Gamma", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogQualityManager: public Ui_DialogQualityManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGQUALITYMANAGER_H
