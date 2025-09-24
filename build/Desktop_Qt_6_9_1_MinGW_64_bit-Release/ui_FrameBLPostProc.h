/********************************************************************************
** Form generated from reading UI file 'FrameBLPostProc.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEBLPOSTPROC_H
#define UI_FRAMEBLPOSTPROC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrameBLPostProc
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_1;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *lineEditAddrLeft;
    QLabel *label_6;
    QLineEdit *lineEditAddrRight;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QLineEdit *lineEditWriteCount;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButtonM1;
    QRadioButton *radioButtonM2;
    QRadioButton *radioButtonM3;
    QRadioButton *radioButtonM4;
    QPushButton *pushButtonWriteM;
    QTableView *tableViewGrid;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonRead;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonE1;
    QRadioButton *radioButtonE2;
    QRadioButton *radioButtonE3;
    QRadioButton *radioButtonE4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *checkBoxBLPostProc;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QCheckBox *checkBoxProcoeSW;
    QCheckBox *checkBoxProBblbadjEn;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpinBox *spinBoxWB;
    QPushButton *pushButtonWriteWB;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButtonWriteWBL;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QCheckBox *checkBoxGMEnable;
    QTableView *tableViewGM;
    QPushButton *pushButtonReadGM;
    QPushButton *pushButtonWriteGM;
    QPushButton *pushButtonWriteGMEn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButtonGM1;
    QRadioButton *radioButtonGM2;
    QRadioButton *radioButtonGM3;
    QRadioButton *radioButtonGM4;
    QButtonGroup *buttonGroup2;
    QButtonGroup *buttonGroup1;
    QButtonGroup *buttonGroup3;

    void setupUi(QFrame *FrameBLPostProc)
    {
        if (FrameBLPostProc->objectName().isEmpty())
            FrameBLPostProc->setObjectName("FrameBLPostProc");
        FrameBLPostProc->resize(1203, 773);
        horizontalLayout = new QHBoxLayout(FrameBLPostProc);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 2, -1, 4);
        groupBox_1 = new QGroupBox(FrameBLPostProc);
        groupBox_1->setObjectName("groupBox_1");
        groupBox_1->setMaximumSize(QSize(800, 16777215));
        tableView = new QTableView(groupBox_1);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 20, 241, 721));
        groupBox_2 = new QGroupBox(groupBox_1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(270, 210, 521, 441));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        horizontalLayout_9->addWidget(label_3);

        lineEditAddrLeft = new QLineEdit(groupBox_2);
        lineEditAddrLeft->setObjectName("lineEditAddrLeft");

        horizontalLayout_9->addWidget(lineEditAddrLeft);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        horizontalLayout_9->addWidget(label_6);

        lineEditAddrRight = new QLineEdit(groupBox_2);
        lineEditAddrRight->setObjectName("lineEditAddrRight");

        horizontalLayout_9->addWidget(lineEditAddrRight);

        horizontalSpacer_4 = new QSpacerItem(160, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        lineEditWriteCount = new QLineEdit(groupBox_2);
        lineEditWriteCount->setObjectName("lineEditWriteCount");

        horizontalLayout_9->addWidget(lineEditWriteCount);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        radioButtonM1 = new QRadioButton(groupBox_2);
        buttonGroup1 = new QButtonGroup(FrameBLPostProc);
        buttonGroup1->setObjectName("buttonGroup1");
        buttonGroup1->addButton(radioButtonM1);
        radioButtonM1->setObjectName("radioButtonM1");
        radioButtonM1->setChecked(true);

        horizontalLayout_5->addWidget(radioButtonM1);

        radioButtonM2 = new QRadioButton(groupBox_2);
        buttonGroup1->addButton(radioButtonM2);
        radioButtonM2->setObjectName("radioButtonM2");

        horizontalLayout_5->addWidget(radioButtonM2);

        radioButtonM3 = new QRadioButton(groupBox_2);
        buttonGroup1->addButton(radioButtonM3);
        radioButtonM3->setObjectName("radioButtonM3");

        horizontalLayout_5->addWidget(radioButtonM3);

        radioButtonM4 = new QRadioButton(groupBox_2);
        buttonGroup1->addButton(radioButtonM4);
        radioButtonM4->setObjectName("radioButtonM4");

        horizontalLayout_5->addWidget(radioButtonM4);

        pushButtonWriteM = new QPushButton(groupBox_2);
        pushButtonWriteM->setObjectName("pushButtonWriteM");

        horizontalLayout_5->addWidget(pushButtonWriteM);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tableViewGrid = new QTableView(groupBox_2);
        tableViewGrid->setObjectName("tableViewGrid");

        verticalLayout_2->addWidget(tableViewGrid);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(15);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pushButtonRead = new QPushButton(groupBox_2);
        pushButtonRead->setObjectName("pushButtonRead");

        horizontalLayout_7->addWidget(pushButtonRead);

        horizontalSpacer_6 = new QSpacerItem(160, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        pushButtonLoad = new QPushButton(groupBox_2);
        pushButtonLoad->setObjectName("pushButtonLoad");

        horizontalLayout_7->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(groupBox_2);
        pushButtonSave->setObjectName("pushButtonSave");

        horizontalLayout_7->addWidget(pushButtonSave);


        verticalLayout_2->addLayout(horizontalLayout_7);

        layoutWidget = new QWidget(groupBox_1);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(271, 21, 521, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 15);
        radioButtonE1 = new QRadioButton(layoutWidget);
        buttonGroup2 = new QButtonGroup(FrameBLPostProc);
        buttonGroup2->setObjectName("buttonGroup2");
        buttonGroup2->addButton(radioButtonE1);
        radioButtonE1->setObjectName("radioButtonE1");
        radioButtonE1->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonE1);

        radioButtonE2 = new QRadioButton(layoutWidget);
        buttonGroup2->addButton(radioButtonE2);
        radioButtonE2->setObjectName("radioButtonE2");

        horizontalLayout_2->addWidget(radioButtonE2);

        radioButtonE3 = new QRadioButton(layoutWidget);
        buttonGroup2->addButton(radioButtonE3);
        radioButtonE3->setObjectName("radioButtonE3");

        horizontalLayout_2->addWidget(radioButtonE3);

        radioButtonE4 = new QRadioButton(layoutWidget);
        buttonGroup2->addButton(radioButtonE4);
        radioButtonE4->setObjectName("radioButtonE4");

        horizontalLayout_2->addWidget(radioButtonE4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(180, 0));
        label_4->setMaximumSize(QSize(150, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        checkBoxBLPostProc = new QCheckBox(layoutWidget);
        checkBoxBLPostProc->setObjectName("checkBoxBLPostProc");

        horizontalLayout_3->addWidget(checkBoxBLPostProc);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(180, 0));
        label_5->setMaximumSize(QSize(150, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_5);

        checkBoxProcoeSW = new QCheckBox(layoutWidget);
        checkBoxProcoeSW->setObjectName("checkBoxProcoeSW");

        horizontalLayout_10->addWidget(checkBoxProcoeSW);

        checkBoxProBblbadjEn = new QCheckBox(layoutWidget);
        checkBoxProBblbadjEn->setObjectName("checkBoxProBblbadjEn");

        horizontalLayout_10->addWidget(checkBoxProBblbadjEn);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(180, 0));
        label_2->setMaximumSize(QSize(150, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_2);

        spinBoxWB = new QSpinBox(layoutWidget);
        spinBoxWB->setObjectName("spinBoxWB");
        spinBoxWB->setMinimumSize(QSize(70, 0));
        spinBoxWB->setMaximumSize(QSize(60, 16777215));
        spinBoxWB->setMaximum(4095);

        horizontalLayout_6->addWidget(spinBoxWB);

        pushButtonWriteWB = new QPushButton(layoutWidget);
        pushButtonWriteWB->setObjectName("pushButtonWriteWB");

        horizontalLayout_6->addWidget(pushButtonWriteWB);

        horizontalSpacer_5 = new QSpacerItem(160, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(180, 0));
        label->setMaximumSize(QSize(150, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimumSize(QSize(70, 0));
        doubleSpinBox->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(5.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox);

        pushButtonWriteWBL = new QPushButton(layoutWidget);
        pushButtonWriteWBL->setObjectName("pushButtonWriteWBL");

        horizontalLayout_4->addWidget(pushButtonWriteWBL);

        horizontalSpacer_3 = new QSpacerItem(160, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(groupBox_1);

        groupBox = new QGroupBox(FrameBLPostProc);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(360, 0));
        groupBox->setMaximumSize(QSize(300, 16777215));
        checkBoxGMEnable = new QCheckBox(groupBox);
        checkBoxGMEnable->setObjectName("checkBoxGMEnable");
        checkBoxGMEnable->setGeometry(QRect(10, 30, 101, 20));
        tableViewGM = new QTableView(groupBox);
        tableViewGM->setObjectName("tableViewGM");
        tableViewGM->setGeometry(QRect(10, 120, 341, 118));
        tableViewGM->setFocusPolicy(Qt::NoFocus);
        tableViewGM->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewGM->horizontalHeader()->setHighlightSections(false);
        tableViewGM->verticalHeader()->setHighlightSections(false);
        pushButtonReadGM = new QPushButton(groupBox);
        pushButtonReadGM->setObjectName("pushButtonReadGM");
        pushButtonReadGM->setGeometry(QRect(10, 60, 101, 23));
        pushButtonWriteGM = new QPushButton(groupBox);
        pushButtonWriteGM->setObjectName("pushButtonWriteGM");
        pushButtonWriteGM->setGeometry(QRect(120, 60, 101, 23));
        pushButtonWriteGMEn = new QPushButton(groupBox);
        pushButtonWriteGMEn->setObjectName("pushButtonWriteGMEn");
        pushButtonWriteGMEn->setGeometry(QRect(10, 90, 211, 23));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 250, 341, 21));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        radioButtonGM1 = new QRadioButton(layoutWidget1);
        buttonGroup3 = new QButtonGroup(FrameBLPostProc);
        buttonGroup3->setObjectName("buttonGroup3");
        buttonGroup3->addButton(radioButtonGM1);
        radioButtonGM1->setObjectName("radioButtonGM1");
        radioButtonGM1->setChecked(true);

        horizontalLayout_8->addWidget(radioButtonGM1);

        radioButtonGM2 = new QRadioButton(layoutWidget1);
        buttonGroup3->addButton(radioButtonGM2);
        radioButtonGM2->setObjectName("radioButtonGM2");

        horizontalLayout_8->addWidget(radioButtonGM2);

        radioButtonGM3 = new QRadioButton(layoutWidget1);
        buttonGroup3->addButton(radioButtonGM3);
        radioButtonGM3->setObjectName("radioButtonGM3");

        horizontalLayout_8->addWidget(radioButtonGM3);

        radioButtonGM4 = new QRadioButton(layoutWidget1);
        buttonGroup3->addButton(radioButtonGM4);
        radioButtonGM4->setObjectName("radioButtonGM4");

        horizontalLayout_8->addWidget(radioButtonGM4);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(FrameBLPostProc);

        QMetaObject::connectSlotsByName(FrameBLPostProc);
    } // setupUi

    void retranslateUi(QFrame *FrameBLPostProc)
    {
        FrameBLPostProc->setWindowTitle(QCoreApplication::translate("FrameBLPostProc", "Frame", nullptr));
        groupBox_1->setTitle(QCoreApplication::translate("FrameBLPostProc", "BL_Post_proc", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FrameBLPostProc", "9X9\347\237\251\351\230\265 -  \350\257\273/\345\206\231", nullptr));
        label_3->setText(QCoreApplication::translate("FrameBLPostProc", "Addr Left:", nullptr));
        lineEditAddrLeft->setText(QCoreApplication::translate("FrameBLPostProc", "1039", nullptr));
        label_6->setText(QCoreApplication::translate("FrameBLPostProc", "Addr Right:", nullptr));
        lineEditAddrRight->setText(QCoreApplication::translate("FrameBLPostProc", "1239", nullptr));
        label_7->setText(QCoreApplication::translate("FrameBLPostProc", "\350\257\273\345\207\272/\345\206\231\345\205\245\346\225\260\351\207\217:", nullptr));
        lineEditWriteCount->setText(QCoreApplication::translate("FrameBLPostProc", "25", nullptr));
        radioButtonM1->setText(QCoreApplication::translate("FrameBLPostProc", "\345\205\250\345\261\217", nullptr));
        radioButtonM2->setText(QCoreApplication::translate("FrameBLPostProc", "\345\267\246\345\215\212\345\261\217", nullptr));
        radioButtonM3->setText(QCoreApplication::translate("FrameBLPostProc", "\345\217\263\345\215\212\345\261\217", nullptr));
        radioButtonM4->setText(QCoreApplication::translate("FrameBLPostProc", "None", nullptr));
        pushButtonWriteM->setText(QCoreApplication::translate("FrameBLPostProc", "Write", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameBLPostProc", "Read", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameBLPostProc", "Load File ...", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameBLPostProc", "Save File ...", nullptr));
        radioButtonE1->setText(QCoreApplication::translate("FrameBLPostProc", "\345\205\250\345\261\217", nullptr));
        radioButtonE2->setText(QCoreApplication::translate("FrameBLPostProc", "\345\267\246\345\215\212\345\261\217", nullptr));
        radioButtonE3->setText(QCoreApplication::translate("FrameBLPostProc", "\345\217\263\345\215\212\345\261\217", nullptr));
        radioButtonE4->setText(QCoreApplication::translate("FrameBLPostProc", "None", nullptr));
        label_4->setText(QCoreApplication::translate("FrameBLPostProc", "BL_Post_proc_mode:", nullptr));
        checkBoxBLPostProc->setText(QCoreApplication::translate("FrameBLPostProc", "Mode 2", nullptr));
        label_5->setText(QCoreApplication::translate("FrameBLPostProc", "pst_pro_sw:", nullptr));
        checkBoxProcoeSW->setText(QCoreApplication::translate("FrameBLPostProc", "pst_pro_coe_sw", nullptr));
        checkBoxProBblbadjEn->setText(QCoreApplication::translate("FrameBLPostProc", "pst_pro_bl_b_adj_en", nullptr));
        label_2->setText(QCoreApplication::translate("FrameBLPostProc", "pst_pro_weight_b:", nullptr));
        pushButtonWriteWB->setText(QCoreApplication::translate("FrameBLPostProc", "Write", nullptr));
        label->setText(QCoreApplication::translate("FrameBLPostProc", "W_BL_r:", nullptr));
        pushButtonWriteWBL->setText(QCoreApplication::translate("FrameBLPostProc", "Write", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FrameBLPostProc", "Gamut_Mapping", nullptr));
        checkBoxGMEnable->setText(QCoreApplication::translate("FrameBLPostProc", "Enable", nullptr));
        pushButtonReadGM->setText(QCoreApplication::translate("FrameBLPostProc", "Read 3x3", nullptr));
        pushButtonWriteGM->setText(QCoreApplication::translate("FrameBLPostProc", "Write 3x3", nullptr));
        pushButtonWriteGMEn->setText(QCoreApplication::translate("FrameBLPostProc", "Calculate and Write 3x3", nullptr));
        radioButtonGM1->setText(QCoreApplication::translate("FrameBLPostProc", "\345\205\250\345\261\217", nullptr));
        radioButtonGM2->setText(QCoreApplication::translate("FrameBLPostProc", "\345\267\246\345\215\212\345\261\217", nullptr));
        radioButtonGM3->setText(QCoreApplication::translate("FrameBLPostProc", "\345\217\263\345\215\212\345\261\217", nullptr));
        radioButtonGM4->setText(QCoreApplication::translate("FrameBLPostProc", "None", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameBLPostProc: public Ui_FrameBLPostProc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEBLPOSTPROC_H
