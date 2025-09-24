/********************************************************************************
** Form generated from reading UI file 'FrameControl.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMECONTROL_H
#define UI_FRAMECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrameControl
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonReadLeft;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox2;
    QSlider *horizontalSlider_1;
    QRadioButton *radioButton2;
    QSlider *horizontalSlider_2;
    QRadioButton *radioButton3;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_25;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_29;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_8;
    QSlider *horizontalSlider_9;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QPushButton *pushButtonReadRight;
    QRadioButton *radioButton1;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *FrameControl)
    {
        if (FrameControl->objectName().isEmpty())
            FrameControl->setObjectName("FrameControl");
        FrameControl->resize(1384, 721);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        FrameControl->setFont(font);
        horizontalLayout = new QHBoxLayout(FrameControl);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 2, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox1 = new QGroupBox(FrameControl);
        groupBox1->setObjectName("groupBox1");
        groupBox1->setMinimumSize(QSize(850, 599));
        verticalLayout = new QVBoxLayout(groupBox1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, 5);
        tableView = new QTableView(groupBox1);
        tableView->setObjectName("tableView");
        tableView->setFocusPolicy(Qt::NoFocus);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButtonReadLeft = new QPushButton(groupBox1);
        pushButtonReadLeft->setObjectName("pushButtonReadLeft");
        pushButtonReadLeft->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(pushButtonReadLeft);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(groupBox1);

        groupBox2 = new QGroupBox(FrameControl);
        groupBox2->setObjectName("groupBox2");
        groupBox2->setMinimumSize(QSize(450, 599));
        horizontalSlider_1 = new QSlider(groupBox2);
        horizontalSlider_1->setObjectName("horizontalSlider_1");
        horizontalSlider_1->setGeometry(QRect(270, 120, 160, 22));
        horizontalSlider_1->setMaximum(255);
        horizontalSlider_1->setTracking(true);
        horizontalSlider_1->setOrientation(Qt::Horizontal);
        radioButton2 = new QRadioButton(groupBox2);
        buttonGroup = new QButtonGroup(FrameControl);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButton2);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setGeometry(QRect(180, 55, 130, 24));
        radioButton2->setChecked(false);
        horizontalSlider_2 = new QSlider(groupBox2);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(270, 150, 160, 22));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setTracking(true);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        radioButton3 = new QRadioButton(groupBox2);
        buttonGroup->addButton(radioButton3);
        radioButton3->setObjectName("radioButton3");
        radioButton3->setGeometry(QRect(180, 80, 131, 24));
        label_14 = new QLabel(groupBox2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 150, 150, 24));
        label_14->setMinimumSize(QSize(150, 0));
        label_14->setMaximumSize(QSize(150, 16777215));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(groupBox2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 30, 140, 24));
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(groupBox2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 120, 150, 24));
        label_13->setMinimumSize(QSize(150, 0));
        label_13->setMaximumSize(QSize(150, 16777215));
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_22 = new QLabel(groupBox2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(20, 180, 150, 24));
        label_22->setMinimumSize(QSize(150, 0));
        label_22->setMaximumSize(QSize(150, 16777215));
        label_22->setStyleSheet(QString::fromUtf8(""));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_23 = new QLabel(groupBox2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(20, 210, 150, 24));
        label_23->setMinimumSize(QSize(150, 0));
        label_23->setMaximumSize(QSize(150, 16777215));
        label_23->setStyleSheet(QString::fromUtf8(""));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_25 = new QLabel(groupBox2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 240, 150, 24));
        label_25->setMinimumSize(QSize(150, 0));
        label_25->setMaximumSize(QSize(150, 16777215));
        label_25->setStyleSheet(QString::fromUtf8(""));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalSlider_3 = new QSlider(groupBox2);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(270, 180, 160, 22));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setTracking(true);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(groupBox2);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setGeometry(QRect(270, 210, 160, 22));
        horizontalSlider_4->setMaximum(255);
        horizontalSlider_4->setTracking(true);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(groupBox2);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setGeometry(QRect(270, 240, 160, 22));
        horizontalSlider_5->setMaximum(255);
        horizontalSlider_5->setTracking(true);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(groupBox2);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setGeometry(QRect(270, 270, 160, 22));
        horizontalSlider_6->setMaximum(255);
        horizontalSlider_6->setTracking(true);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        label_27 = new QLabel(groupBox2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 270, 150, 24));
        label_27->setMinimumSize(QSize(150, 0));
        label_27->setMaximumSize(QSize(150, 16777215));
        label_27->setStyleSheet(QString::fromUtf8(""));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_26 = new QLabel(groupBox2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(20, 300, 150, 24));
        label_26->setMinimumSize(QSize(150, 0));
        label_26->setMaximumSize(QSize(150, 16777215));
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_28 = new QLabel(groupBox2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 330, 150, 24));
        label_28->setMinimumSize(QSize(150, 0));
        label_28->setMaximumSize(QSize(150, 16777215));
        label_28->setStyleSheet(QString::fromUtf8(""));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_29 = new QLabel(groupBox2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 360, 150, 24));
        label_29->setMinimumSize(QSize(150, 0));
        label_29->setMaximumSize(QSize(150, 16777215));
        label_29->setStyleSheet(QString::fromUtf8(""));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_1 = new QSpinBox(groupBox2);
        spinBox_1->setObjectName("spinBox_1");
        spinBox_1->setGeometry(QRect(180, 120, 80, 22));
        spinBox_2 = new QSpinBox(groupBox2);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(180, 150, 80, 22));
        spinBox_3 = new QSpinBox(groupBox2);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(180, 180, 80, 22));
        horizontalSlider_7 = new QSlider(groupBox2);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        horizontalSlider_7->setGeometry(QRect(270, 300, 160, 22));
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        horizontalSlider_8 = new QSlider(groupBox2);
        horizontalSlider_8->setObjectName("horizontalSlider_8");
        horizontalSlider_8->setGeometry(QRect(270, 330, 160, 22));
        horizontalSlider_8->setOrientation(Qt::Horizontal);
        horizontalSlider_9 = new QSlider(groupBox2);
        horizontalSlider_9->setObjectName("horizontalSlider_9");
        horizontalSlider_9->setGeometry(QRect(270, 360, 160, 22));
        horizontalSlider_9->setOrientation(Qt::Horizontal);
        spinBox_4 = new QSpinBox(groupBox2);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(180, 210, 80, 22));
        spinBox_5 = new QSpinBox(groupBox2);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(180, 240, 80, 22));
        spinBox_6 = new QSpinBox(groupBox2);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setGeometry(QRect(180, 270, 80, 22));
        spinBox_7 = new QSpinBox(groupBox2);
        spinBox_7->setObjectName("spinBox_7");
        spinBox_7->setGeometry(QRect(180, 300, 80, 22));
        spinBox_8 = new QSpinBox(groupBox2);
        spinBox_8->setObjectName("spinBox_8");
        spinBox_8->setGeometry(QRect(180, 330, 80, 22));
        spinBox_9 = new QSpinBox(groupBox2);
        spinBox_9->setObjectName("spinBox_9");
        spinBox_9->setGeometry(QRect(180, 360, 80, 22));
        pushButtonReadRight = new QPushButton(groupBox2);
        pushButtonReadRight->setObjectName("pushButtonReadRight");
        pushButtonReadRight->setGeometry(QRect(180, 400, 120, 31));
        radioButton1 = new QRadioButton(groupBox2);
        buttonGroup->addButton(radioButton1);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setGeometry(QRect(180, 30, 130, 24));
        radioButton1->setChecked(true);

        horizontalLayout->addWidget(groupBox2);


        retranslateUi(FrameControl);

        QMetaObject::connectSlotsByName(FrameControl);
    } // setupUi

    void retranslateUi(QFrame *FrameControl)
    {
        FrameControl->setWindowTitle(QCoreApplication::translate("FrameControl", "Frame", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("FrameControl", "Control", nullptr));
        pushButtonReadLeft->setText(QCoreApplication::translate("FrameControl", "Read", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("FrameControl", "LD_BL_Calc", nullptr));
        radioButton2->setText(QCoreApplication::translate("FrameControl", "Local Alpha", nullptr));
        radioButton3->setText(QCoreApplication::translate("FrameControl", "AI Local Alpha", nullptr));
        label_14->setText(QCoreApplication::translate("FrameControl", "dc_alpha:", nullptr));
        label_12->setText(QCoreApplication::translate("FrameControl", "LD_BL_Calc_type:", nullptr));
        label_13->setText(QCoreApplication::translate("FrameControl", "max_alpha:", nullptr));
        label_22->setText(QCoreApplication::translate("FrameControl", "alpha_ratio:", nullptr));
        label_23->setText(QCoreApplication::translate("FrameControl", "delta_linit:", nullptr));
        label_25->setText(QCoreApplication::translate("FrameControl", "dc_alpha_limit:", nullptr));
        label_27->setText(QCoreApplication::translate("FrameControl", "max_alpha_limit:", nullptr));
        label_26->setText(QCoreApplication::translate("FrameControl", "slope:", nullptr));
        label_28->setText(QCoreApplication::translate("FrameControl", "offset:", nullptr));
        label_29->setText(QCoreApplication::translate("FrameControl", "v_fac_limit:", nullptr));
        pushButtonReadRight->setText(QCoreApplication::translate("FrameControl", "Read", nullptr));
        radioButton1->setText(QCoreApplication::translate("FrameControl", "Global Alpha", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameControl: public Ui_FrameControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMECONTROL_H
