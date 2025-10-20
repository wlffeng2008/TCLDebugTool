/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFirmware;
    QAction *actionConfig;
    QAction *actionCalc;
    QAction *actionNotepad;
    QAction *actionPainter;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QFrame *frameTop;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSerial;
    QLabel *label;
    QComboBox *comboBoxModel;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frameLeft;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelLogo;
    QFrame *frameRight;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonScreenConfig;
    QPushButton *pushButtonTestTool;
    QPushButton *pushButtonBrightness;
    QPushButton *pushButtonPictureControl;
    QPushButton *pushButtonLightBoardFlash;
    QPushButton *pushButtonAdjust;
    QSpacerItem *verticalSpacer_2;
    QFrame *frameLBottom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelStatus;
    QMenuBar *menubar;
    QMenu *menuSystem;
    QMenu *menuSetting;
    QMenu *menuTool;
    QMenu *menuFixed;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1366, 768);
        MainWindow->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionFirmware = new QAction(MainWindow);
        actionFirmware->setObjectName("actionFirmware");
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName("actionConfig");
        actionCalc = new QAction(MainWindow);
        actionCalc->setObjectName("actionCalc");
        actionNotepad = new QAction(MainWindow);
        actionNotepad->setObjectName("actionNotepad");
        actionPainter = new QAction(MainWindow);
        actionPainter->setObjectName("actionPainter");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        frameTop = new QFrame(centralwidget);
        frameTop->setObjectName("frameTop");
        frameTop->setMinimumSize(QSize(0, 50));
        frameTop->setFrameShape(QFrame::Shape::StyledPanel);
        frameTop->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frameTop);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 0, 0);
        pushButtonSerial = new QPushButton(frameTop);
        pushButtonSerial->setObjectName("pushButtonSerial");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSerial->sizePolicy().hasHeightForWidth());
        pushButtonSerial->setSizePolicy(sizePolicy);
        pushButtonSerial->setMinimumSize(QSize(150, 36));
        pushButtonSerial->setMaximumSize(QSize(150, 36));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        pushButtonSerial->setFont(font1);

        horizontalLayout->addWidget(pushButtonSerial);

        label = new QLabel(frameTop);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        comboBoxModel = new QComboBox(frameTop);
        comboBoxModel->setObjectName("comboBoxModel");
        comboBoxModel->setMinimumSize(QSize(150, 0));
        comboBoxModel->setMaximumSize(QSize(150, 16777215));
        comboBoxModel->setFont(font2);
        comboBoxModel->setMaxVisibleItems(20);

        horizontalLayout->addWidget(comboBoxModel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frameTop);

        frameLeft = new QFrame(centralwidget);
        frameLeft->setObjectName("frameLeft");
        frameLeft->setFrameShape(QFrame::Shape::StyledPanel);
        frameLeft->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameLeft);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);

        verticalLayout->addWidget(frameLeft);

        labelLogo = new QLabel(centralwidget);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumSize(QSize(0, 100));
        labelLogo->setScaledContents(true);

        verticalLayout->addWidget(labelLogo);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        frameRight = new QFrame(centralwidget);
        frameRight->setObjectName("frameRight");
        frameRight->setMinimumSize(QSize(250, 0));
        frameRight->setMaximumSize(QSize(250, 16777215));
        frameRight->setFrameShape(QFrame::Shape::StyledPanel);
        frameRight->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frameRight);
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 40, 0, 0);
        pushButtonScreenConfig = new QPushButton(frameRight);
        pushButtonScreenConfig->setObjectName("pushButtonScreenConfig");
        pushButtonScreenConfig->setMinimumSize(QSize(0, 50));
        pushButtonScreenConfig->setMaximumSize(QSize(244, 16777215));
        pushButtonScreenConfig->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonScreenConfig->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/MWToolBarTestToolIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonScreenConfig->setIcon(icon);
        pushButtonScreenConfig->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonScreenConfig);

        pushButtonTestTool = new QPushButton(frameRight);
        pushButtonTestTool->setObjectName("pushButtonTestTool");
        pushButtonTestTool->setMinimumSize(QSize(0, 50));
        pushButtonTestTool->setMaximumSize(QSize(244, 16777215));
        pushButtonTestTool->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonTestTool->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/MWToolBarScreenConfigIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonTestTool->setIcon(icon1);
        pushButtonTestTool->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonTestTool);

        pushButtonBrightness = new QPushButton(frameRight);
        pushButtonBrightness->setObjectName("pushButtonBrightness");
        pushButtonBrightness->setMinimumSize(QSize(0, 50));
        pushButtonBrightness->setMaximumSize(QSize(244, 16777215));
        pushButtonBrightness->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonBrightness->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/MWToolBarBrightnessIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonBrightness->setIcon(icon2);
        pushButtonBrightness->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonBrightness);

        pushButtonPictureControl = new QPushButton(frameRight);
        pushButtonPictureControl->setObjectName("pushButtonPictureControl");
        pushButtonPictureControl->setMinimumSize(QSize(0, 50));
        pushButtonPictureControl->setMaximumSize(QSize(244, 16777215));
        pushButtonPictureControl->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonPictureControl->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/MWToolBarPictureControlIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonPictureControl->setIcon(icon3);
        pushButtonPictureControl->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonPictureControl);

        pushButtonLightBoardFlash = new QPushButton(frameRight);
        pushButtonLightBoardFlash->setObjectName("pushButtonLightBoardFlash");
        pushButtonLightBoardFlash->setMinimumSize(QSize(0, 50));
        pushButtonLightBoardFlash->setMaximumSize(QSize(244, 16777215));
        pushButtonLightBoardFlash->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonLightBoardFlash->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/MWToolBarLightBoardFlashIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonLightBoardFlash->setIcon(icon4);
        pushButtonLightBoardFlash->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonLightBoardFlash);

        pushButtonAdjust = new QPushButton(frameRight);
        pushButtonAdjust->setObjectName("pushButtonAdjust");
        pushButtonAdjust->setMinimumSize(QSize(0, 50));
        pushButtonAdjust->setMaximumSize(QSize(244, 16777215));
        pushButtonAdjust->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonAdjust->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/MWToolBarAdjustIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonAdjust->setIcon(icon5);
        pushButtonAdjust->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(pushButtonAdjust);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        frameLBottom = new QFrame(frameRight);
        frameLBottom->setObjectName("frameLBottom");
        frameLBottom->setMinimumSize(QSize(240, 0));
        frameLBottom->setFrameShape(QFrame::Shape::StyledPanel);
        frameLBottom->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameLBottom);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 5, 0);
        label_2 = new QLabel(frameLBottom);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        labelStatus = new QLabel(frameLBottom);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setFont(font1);
        labelStatus->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        labelStatus->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(labelStatus);


        verticalLayout_2->addWidget(frameLBottom, 0, Qt::AlignmentFlag::AlignRight);


        horizontalLayout_3->addWidget(frameRight, 0, Qt::AlignmentFlag::AlignHCenter);

        horizontalLayout_3->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1366, 22));
        menubar->setFont(font);
        menubar->setStyleSheet(QString::fromUtf8("background-color:white;"));
        menuSystem = new QMenu(menubar);
        menuSystem->setObjectName("menuSystem");
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName("menuSetting");
        menuTool = new QMenu(menubar);
        menuTool->setObjectName("menuTool");
        menuFixed = new QMenu(menubar);
        menuFixed->setObjectName("menuFixed");
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuSystem->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuTool->menuAction());
        menubar->addAction(menuFixed->menuAction());
        menuSystem->addAction(actionFirmware);
        menuSystem->addAction(actionConfig);
        menuTool->addAction(actionCalc);
        menuTool->addAction(actionNotepad);
        menuTool->addAction(actionPainter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TCL Debug Tool", nullptr));
        actionFirmware->setText(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266\346\211\223\345\214\205", nullptr));
        actionConfig->setText(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256\346\211\223\345\214\205", nullptr));
        actionCalc->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", nullptr));
        actionNotepad->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\272\213\346\234\254", nullptr));
        actionPainter->setText(QCoreApplication::translate("MainWindow", "\347\224\273\347\254\224", nullptr));
        pushButtonSerial->setText(QCoreApplication::translate("MainWindow", "        \344\270\262\345\217\243\350\277\236\346\216\245        ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\272\345\236\213\351\200\211\346\213\251\357\274\232", nullptr));
        labelLogo->setText(QCoreApplication::translate("MainWindow", "Logo", nullptr));
        pushButtonScreenConfig->setText(QCoreApplication::translate("MainWindow", "       \344\270\223\344\270\232\350\260\203\350\257\225", nullptr));
        pushButtonTestTool->setText(QCoreApplication::translate("MainWindow", "       \347\224\273\350\264\250\350\260\203\350\257\225", nullptr));
        pushButtonBrightness->setText(QCoreApplication::translate("MainWindow", "       \350\200\201\345\214\226\346\265\213\350\257\225", nullptr));
        pushButtonPictureControl->setText(QCoreApplication::translate("MainWindow", "       \345\276\205\345\256\232", nullptr));
        pushButtonLightBoardFlash->setText(QCoreApplication::translate("MainWindow", "       \345\276\205\345\256\232", nullptr));
        pushButtonAdjust->setText(QCoreApplication::translate("MainWindow", "       \345\276\205\345\256\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\345\244\261\350\264\245", nullptr));
        menuSystem->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        menuTool->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        menuFixed->setTitle(QCoreApplication::translate("MainWindow", "\346\240\241\346\255\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
