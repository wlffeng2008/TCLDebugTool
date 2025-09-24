/********************************************************************************
** Form generated from reading UI file 'FrameDemo.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEDEMO_H
#define UI_FRAMEDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FrameDemo
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QLabel *label_1;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label_3;
    QCheckBox *checkBoxSelectArea;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditSrcW;
    QLineEdit *lineEditSrcH;
    QFrame *frame;
    QPushButton *pushButtonSetEara;
    QLineEdit *lineEdit_Y1;
    QLabel *label_6;
    QLineEdit *lineEdit_X1;
    QLabel *label_7;
    QLineEdit *lineEdit_X2;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_Y2;
    QCheckBox *checkBoxFullSrceen;
    QSpacerItem *horizontalSpacer_2;
    QButtonGroup *buttonGroup1;
    QButtonGroup *buttonGroup2;

    void setupUi(QFrame *FrameDemo)
    {
        if (FrameDemo->objectName().isEmpty())
            FrameDemo->setObjectName("FrameDemo");
        FrameDemo->resize(1230, 760);
        horizontalLayout = new QHBoxLayout(FrameDemo);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 2, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox = new QGroupBox(FrameDemo);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(1200, 0));
        groupBox->setMaximumSize(QSize(800, 16777215));
        label_1 = new QLabel(groupBox);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(0, 30, 161, 24));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radioButton_1 = new QRadioButton(groupBox);
        buttonGroup1 = new QButtonGroup(FrameDemo);
        buttonGroup1->setObjectName("buttonGroup1");
        buttonGroup1->addButton(radioButton_1);
        radioButton_1->setObjectName("radioButton_1");
        radioButton_1->setGeometry(QRect(170, 30, 161, 24));
        radioButton_1->setMinimumSize(QSize(0, 24));
        radioButton_1->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        buttonGroup1->addButton(radioButton_2);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(170, 60, 181, 24));
        radioButton_2->setMinimumSize(QSize(0, 24));
        radioButton_3 = new QRadioButton(groupBox);
        buttonGroup1->addButton(radioButton_3);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(170, 90, 191, 24));
        radioButton_3->setMinimumSize(QSize(0, 24));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 150, 161, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radioButton_4 = new QRadioButton(groupBox);
        buttonGroup2 = new QButtonGroup(FrameDemo);
        buttonGroup2->setObjectName("buttonGroup2");
        buttonGroup2->addButton(radioButton_4);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(170, 150, 121, 24));
        radioButton_4->setMinimumSize(QSize(0, 24));
        radioButton_4->setChecked(true);
        radioButton_5 = new QRadioButton(groupBox);
        buttonGroup2->addButton(radioButton_5);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(170, 180, 141, 24));
        radioButton_5->setMinimumSize(QSize(0, 24));
        radioButton_6 = new QRadioButton(groupBox);
        buttonGroup2->addButton(radioButton_6);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setGeometry(QRect(170, 210, 141, 24));
        radioButton_6->setMinimumSize(QSize(0, 24));
        radioButton_7 = new QRadioButton(groupBox);
        buttonGroup2->addButton(radioButton_7);
        radioButton_7->setObjectName("radioButton_7");
        radioButton_7->setGeometry(QRect(170, 240, 141, 24));
        radioButton_7->setMinimumSize(QSize(0, 24));
        radioButton_8 = new QRadioButton(groupBox);
        buttonGroup2->addButton(radioButton_8);
        radioButton_8->setObjectName("radioButton_8");
        radioButton_8->setGeometry(QRect(170, 270, 161, 24));
        radioButton_8->setMinimumSize(QSize(0, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 30, 141, 24));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBoxSelectArea = new QCheckBox(groupBox);
        checkBoxSelectArea->setObjectName("checkBoxSelectArea");
        checkBoxSelectArea->setGeometry(QRect(600, 30, 91, 30));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 70, 121, 20));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 105, 121, 20));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSrcW = new QLineEdit(groupBox);
        lineEditSrcW->setObjectName("lineEditSrcW");
        lineEditSrcW->setGeometry(QRect(600, 70, 60, 21));
        lineEditSrcW->setMaxLength(5);
        lineEditSrcH = new QLineEdit(groupBox);
        lineEditSrcH->setObjectName("lineEditSrcH");
        lineEditSrcH->setGeometry(QRect(600, 105, 60, 21));
        lineEditSrcH->setMaxLength(5);
        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(440, 150, 720, 405));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButtonSetEara = new QPushButton(groupBox);
        pushButtonSetEara->setObjectName("pushButtonSetEara");
        pushButtonSetEara->setGeometry(QRect(1080, 100, 81, 30));
        lineEdit_Y1 = new QLineEdit(groupBox);
        lineEdit_Y1->setObjectName("lineEdit_Y1");
        lineEdit_Y1->setGeometry(QRect(760, 105, 60, 21));
        lineEdit_Y1->setMaxLength(5);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(720, 70, 30, 20));
        label_6->setMinimumSize(QSize(30, 0));
        label_6->setMaximumSize(QSize(30, 16777215));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_X1 = new QLineEdit(groupBox);
        lineEdit_X1->setObjectName("lineEdit_X1");
        lineEdit_X1->setGeometry(QRect(760, 70, 60, 21));
        lineEdit_X1->setMaxLength(5);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(720, 105, 30, 20));
        label_7->setMinimumSize(QSize(30, 0));
        label_7->setMaximumSize(QSize(30, 16777215));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_X2 = new QLineEdit(groupBox);
        lineEdit_X2->setObjectName("lineEdit_X2");
        lineEdit_X2->setGeometry(QRect(900, 70, 60, 21));
        lineEdit_X2->setMaxLength(5);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(860, 70, 30, 20));
        label_8->setMinimumSize(QSize(30, 0));
        label_8->setMaximumSize(QSize(30, 16777215));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(860, 105, 30, 20));
        label_9->setMinimumSize(QSize(30, 0));
        label_9->setMaximumSize(QSize(30, 16777215));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_Y2 = new QLineEdit(groupBox);
        lineEdit_Y2->setObjectName("lineEdit_Y2");
        lineEdit_Y2->setGeometry(QRect(900, 105, 60, 21));
        lineEdit_Y2->setMaxLength(5);
        checkBoxFullSrceen = new QCheckBox(groupBox);
        checkBoxFullSrceen->setObjectName("checkBoxFullSrceen");
        checkBoxFullSrceen->setGeometry(QRect(1080, 65, 90, 30));

        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(FrameDemo);

        QMetaObject::connectSlotsByName(FrameDemo);
    } // setupUi

    void retranslateUi(QFrame *FrameDemo)
    {
        FrameDemo->setWindowTitle(QCoreApplication::translate("FrameDemo", "Frame", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrameDemo", "Demo", nullptr));
        label_1->setText(QCoreApplication::translate("FrameDemo", "sent_white_screen:", nullptr));
        radioButton_1->setText(QCoreApplication::translate("FrameDemo", "\350\276\223\345\207\272\346\255\243\345\270\270\345\233\276\345\203\217\345\210\260Tcon", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FrameDemo", "\350\276\223\345\207\272\347\272\257\347\231\275\350\211\262\345\233\276\345\203\217\345\210\260Tcon", nullptr));
        radioButton_3->setText(QCoreApplication::translate("FrameDemo", "\350\276\223\345\207\272BMA\345\233\276\345\203\217\345\210\260Tcon", nullptr));
        label_2->setText(QCoreApplication::translate("FrameDemo", "dcon_adjust_bypass:", nullptr));
        radioButton_4->setText(QCoreApplication::translate("FrameDemo", "\346\255\243\345\270\270\347\224\273\351\235\242", nullptr));
        radioButton_5->setText(QCoreApplication::translate("FrameDemo", "\346\211\223\345\205\250\345\261\217\345\205\250\347\231\275\347\224\273\351\235\242", nullptr));
        radioButton_6->setText(QCoreApplication::translate("FrameDemo", "\346\211\223\345\267\246\345\215\212\345\261\217\345\205\250\347\231\275\347\224\273\351\235\242", nullptr));
        radioButton_7->setText(QCoreApplication::translate("FrameDemo", "\346\211\223\345\217\263\345\215\212\345\261\217\345\205\250\347\231\275\347\224\273\351\235\242", nullptr));
        radioButton_8->setText(QCoreApplication::translate("FrameDemo", "\346\211\223\345\233\272\345\256\232\347\252\227\345\217\243\345\205\250\347\231\275\347\224\273\351\235\242", nullptr));
        label_3->setText(QCoreApplication::translate("FrameDemo", "select_area_enable:", nullptr));
        checkBoxSelectArea->setText(QCoreApplication::translate("FrameDemo", "Yes", nullptr));
        label_4->setText(QCoreApplication::translate("FrameDemo", "Screen width:", nullptr));
        label_5->setText(QCoreApplication::translate("FrameDemo", "Screen height:", nullptr));
        lineEditSrcW->setText(QCoreApplication::translate("FrameDemo", "600", nullptr));
        lineEditSrcH->setText(QCoreApplication::translate("FrameDemo", "480", nullptr));
        pushButtonSetEara->setText(QCoreApplication::translate("FrameDemo", "Send", nullptr));
        lineEdit_Y1->setText(QCoreApplication::translate("FrameDemo", "0", nullptr));
        label_6->setText(QCoreApplication::translate("FrameDemo", "X1:", nullptr));
        lineEdit_X1->setText(QCoreApplication::translate("FrameDemo", "0", nullptr));
        label_7->setText(QCoreApplication::translate("FrameDemo", "Y1:", nullptr));
        lineEdit_X2->setText(QCoreApplication::translate("FrameDemo", "600", nullptr));
        label_8->setText(QCoreApplication::translate("FrameDemo", "X2:", nullptr));
        label_9->setText(QCoreApplication::translate("FrameDemo", "Y2:", nullptr));
        lineEdit_Y2->setText(QCoreApplication::translate("FrameDemo", "480", nullptr));
        checkBoxFullSrceen->setText(QCoreApplication::translate("FrameDemo", "\351\200\211\346\213\251\345\205\250\345\261\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameDemo: public Ui_FrameDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEDEMO_H
