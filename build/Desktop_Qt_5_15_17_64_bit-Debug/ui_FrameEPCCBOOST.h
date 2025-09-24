/********************************************************************************
** Form generated from reading UI file 'FrameEPCCBOOST.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEEPCCBOOST_H
#define UI_FRAMEEPCCBOOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include "frameepccpanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrameEPCCBOOST
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonRead;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditFilename;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QHBoxLayout *horizontalLayout_6;
    FrameEPCCPanel *framePanel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonLoadICfg;
    QPushButton *pushButtonSaveICfg;
    QLabel *label_2;
    QTableView *tableView5;
    QLabel *label_4;
    QTableView *tableView6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditMinI;
    QLabel *label_6;
    QLineEdit *lineEditMaxI;
    QLabel *label_7;
    QComboBox *comboBoxBits;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButtonMode1;
    QRadioButton *radioButtonMode2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *FrameEPCCBOOST)
    {
        if (FrameEPCCBOOST->objectName().isEmpty())
            FrameEPCCBOOST->setObjectName(QString::fromUtf8("FrameEPCCBOOST"));
        FrameEPCCBOOST->resize(1222, 771);
        verticalLayout_3 = new QVBoxLayout(FrameEPCCBOOST);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton1 = new QRadioButton(FrameEPCCBOOST);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        radioButton1->setChecked(true);

        horizontalLayout->addWidget(radioButton1);

        radioButton2 = new QRadioButton(FrameEPCCBOOST);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        horizontalLayout->addWidget(radioButton2);

        pushButtonWrite = new QPushButton(FrameEPCCBOOST);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));

        horizontalLayout->addWidget(pushButtonWrite);

        pushButtonRead = new QPushButton(FrameEPCCBOOST);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));

        horizontalLayout->addWidget(pushButtonRead);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FrameEPCCBOOST);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEditFilename = new QLineEdit(FrameEPCCBOOST);
        lineEditFilename->setObjectName(QString::fromUtf8("lineEditFilename"));
        lineEditFilename->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(lineEditFilename);

        pushButtonSave = new QPushButton(FrameEPCCBOOST);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(FrameEPCCBOOST);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));

        horizontalLayout->addWidget(pushButtonLoad);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        framePanel = new FrameEPCCPanel(FrameEPCCBOOST);
        framePanel->setObjectName(QString::fromUtf8("framePanel"));
        framePanel->setFocusPolicy(Qt::StrongFocus);
        framePanel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        framePanel->setFrameShape(QFrame::StyledPanel);
        framePanel->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(framePanel);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_6->addWidget(framePanel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FrameEPCCBOOST);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tableView4 = new QTableView(FrameEPCCBOOST);
        tableView4->setObjectName(QString::fromUtf8("tableView4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView4->sizePolicy().hasHeightForWidth());
        tableView4->setSizePolicy(sizePolicy);
        tableView4->setMinimumSize(QSize(400, 0));
        tableView4->setMaximumSize(QSize(16777215, 150));
        tableView4->horizontalHeader()->setHighlightSections(false);
        tableView4->verticalHeader()->setVisible(false);
        tableView4->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButtonLoadICfg = new QPushButton(FrameEPCCBOOST);
        pushButtonLoadICfg->setObjectName(QString::fromUtf8("pushButtonLoadICfg"));

        horizontalLayout_4->addWidget(pushButtonLoadICfg);

        pushButtonSaveICfg = new QPushButton(FrameEPCCBOOST);
        pushButtonSaveICfg->setObjectName(QString::fromUtf8("pushButtonSaveICfg"));

        horizontalLayout_4->addWidget(pushButtonSaveICfg);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(FrameEPCCBOOST);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        tableView5 = new QTableView(FrameEPCCBOOST);
        tableView5->setObjectName(QString::fromUtf8("tableView5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView5->sizePolicy().hasHeightForWidth());
        tableView5->setSizePolicy(sizePolicy1);
        tableView5->setMaximumSize(QSize(16777215, 90));
        tableView5->horizontalHeader()->setVisible(false);
        tableView5->horizontalHeader()->setHighlightSections(false);
        tableView5->verticalHeader()->setVisible(false);
        tableView5->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView5);

        label_4 = new QLabel(FrameEPCCBOOST);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        tableView6 = new QTableView(FrameEPCCBOOST);
        tableView6->setObjectName(QString::fromUtf8("tableView6"));
        sizePolicy.setHeightForWidth(tableView6->sizePolicy().hasHeightForWidth());
        tableView6->setSizePolicy(sizePolicy);
        tableView6->setMaximumSize(QSize(16777215, 150));
        tableView6->horizontalHeader()->setHighlightSections(false);
        tableView6->verticalHeader()->setVisible(false);
        tableView6->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView6);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(FrameEPCCBOOST);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditMinI = new QLineEdit(FrameEPCCBOOST);
        lineEditMinI->setObjectName(QString::fromUtf8("lineEditMinI"));
        lineEditMinI->setMinimumSize(QSize(80, 0));
        lineEditMinI->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lineEditMinI);

        label_6 = new QLabel(FrameEPCCBOOST);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEditMaxI = new QLineEdit(FrameEPCCBOOST);
        lineEditMaxI->setObjectName(QString::fromUtf8("lineEditMaxI"));
        lineEditMaxI->setMinimumSize(QSize(80, 0));
        lineEditMaxI->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lineEditMaxI);

        label_7 = new QLabel(FrameEPCCBOOST);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        comboBoxBits = new QComboBox(FrameEPCCBOOST);
        comboBoxBits->addItem(QString());
        comboBoxBits->addItem(QString());
        comboBoxBits->addItem(QString());
        comboBoxBits->setObjectName(QString::fromUtf8("comboBoxBits"));
        comboBoxBits->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(comboBoxBits);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButtonMode1 = new QRadioButton(FrameEPCCBOOST);
        buttonGroup = new QButtonGroup(FrameEPCCBOOST);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButtonMode1);
        radioButtonMode1->setObjectName(QString::fromUtf8("radioButtonMode1"));
        radioButtonMode1->setChecked(true);

        horizontalLayout_5->addWidget(radioButtonMode1);

        radioButtonMode2 = new QRadioButton(FrameEPCCBOOST);
        buttonGroup->addButton(radioButtonMode2);
        radioButtonMode2->setObjectName(QString::fromUtf8("radioButtonMode2"));

        horizontalLayout_5->addWidget(radioButtonMode2);

        pushButton = new QPushButton(FrameEPCCBOOST);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(FrameEPCCBOOST);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalLayout_6->setStretch(0, 1);

        verticalLayout_3->addLayout(horizontalLayout_6);


        retranslateUi(FrameEPCCBOOST);

        comboBoxBits->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FrameEPCCBOOST);
    } // setupUi

    void retranslateUi(QFrame *FrameEPCCBOOST)
    {
        FrameEPCCBOOST->setWindowTitle(QCoreApplication::translate("FrameEPCCBOOST", "Frame", nullptr));
        radioButton1->setText(QCoreApplication::translate("FrameEPCCBOOST", "QD", nullptr));
        radioButton2->setText(QCoreApplication::translate("FrameEPCCBOOST", "FC", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameEPCCBOOST", "Write", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameEPCCBOOST", "Read", nullptr));
        label_3->setText(QCoreApplication::translate("FrameEPCCBOOST", "File Name:", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameEPCCBOOST", "Save ...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameEPCCBOOST", "Load ...", nullptr));
        label->setText(QCoreApplication::translate("FrameEPCCBOOST", "\347\224\265\346\265\201(mA)\357\274\232", nullptr));
        pushButtonLoadICfg->setText(QCoreApplication::translate("FrameEPCCBOOST", "Save ...", nullptr));
        pushButtonSaveICfg->setText(QCoreApplication::translate("FrameEPCCBOOST", "Load ...", nullptr));
        label_2->setText(QCoreApplication::translate("FrameEPCCBOOST", "\350\256\241\347\256\227\347\273\223\346\236\234\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FrameEPCCBOOST", "\351\205\215\347\275\256\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("FrameEPCCBOOST", "\350\265\267\345\247\213\347\224\265\346\265\201:", nullptr));
        lineEditMinI->setText(QCoreApplication::translate("FrameEPCCBOOST", "0", nullptr));
        label_6->setText(QCoreApplication::translate("FrameEPCCBOOST", "\346\234\200\345\244\247\347\224\265\346\265\201:", nullptr));
        lineEditMaxI->setText(QCoreApplication::translate("FrameEPCCBOOST", "60", nullptr));
        label_7->setText(QCoreApplication::translate("FrameEPCCBOOST", "\344\275\215\345\256\275:", nullptr));
        comboBoxBits->setItemText(0, QCoreApplication::translate("FrameEPCCBOOST", "4", nullptr));
        comboBoxBits->setItemText(1, QCoreApplication::translate("FrameEPCCBOOST", "6", nullptr));
        comboBoxBits->setItemText(2, QCoreApplication::translate("FrameEPCCBOOST", "8", nullptr));

        radioButtonMode1->setText(QCoreApplication::translate("FrameEPCCBOOST", "Mode1", nullptr));
        radioButtonMode2->setText(QCoreApplication::translate("FrameEPCCBOOST", "Mode2", nullptr));
        pushButton->setText(QCoreApplication::translate("FrameEPCCBOOST", "\346\237\245\347\234\213 Step", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FrameEPCCBOOST", "\347\224\237\346\210\220 BL_PAL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameEPCCBOOST: public Ui_FrameEPCCBOOST {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEEPCCBOOST_H
