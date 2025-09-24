/********************************************************************************
** Form generated from reading UI file 'FramePixelCompensation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEPIXELCOMPENSATION_H
#define UI_FRAMEPIXELCOMPENSATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FramePixelCompensation
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit1;
    QSlider *horizontalSlider1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QSlider *horizontalSlider2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit3;
    QSlider *horizontalSlider3;
    QPushButton *pushButtonRead;
    QTableView *tableViewGrid;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButtonM1;
    QRadioButton *radioButtonM2;
    QRadioButton *radioButtonM3;
    QRadioButton *radioButtonM4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonReadM;
    QPushButton *pushButtonWriteM;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QButtonGroup *buttonGroup1;

    void setupUi(QFrame *FramePixelCompensation)
    {
        if (FramePixelCompensation->objectName().isEmpty())
            FramePixelCompensation->setObjectName("FramePixelCompensation");
        FramePixelCompensation->resize(1131, 799);
        horizontalLayout = new QHBoxLayout(FramePixelCompensation);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 2, -1, -1);
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tableView = new QTableView(FramePixelCompensation);
        tableView->setObjectName("tableView");
        tableView->setMaximumSize(QSize(250, 16777215));
        tableView->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(tableView, 0, Qt::AlignHCenter);

        groupBox = new QGroupBox(FramePixelCompensation);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(465, 0));
        groupBox->setMaximumSize(QSize(465, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(140, 0));
        label->setMaximumSize(QSize(140, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        lineEdit1 = new QLineEdit(groupBox);
        lineEdit1->setObjectName("lineEdit1");
        lineEdit1->setMinimumSize(QSize(80, 0));
        lineEdit1->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lineEdit1);

        horizontalSlider1 = new QSlider(groupBox);
        horizontalSlider1->setObjectName("horizontalSlider1");
        horizontalSlider1->setMaximum(4095);
        horizontalSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider1);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(140, 0));
        label_2->setMaximumSize(QSize(140, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        lineEdit2 = new QLineEdit(groupBox);
        lineEdit2->setObjectName("lineEdit2");
        lineEdit2->setMinimumSize(QSize(80, 0));
        lineEdit2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(lineEdit2);

        horizontalSlider2 = new QSlider(groupBox);
        horizontalSlider2->setObjectName("horizontalSlider2");
        horizontalSlider2->setMaximum(15);
        horizontalSlider2->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(140, 0));
        label_3->setMaximumSize(QSize(140, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        lineEdit3 = new QLineEdit(groupBox);
        lineEdit3->setObjectName("lineEdit3");
        lineEdit3->setMinimumSize(QSize(80, 0));
        lineEdit3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(lineEdit3);

        horizontalSlider3 = new QSlider(groupBox);
        horizontalSlider3->setObjectName("horizontalSlider3");
        horizontalSlider3->setMaximum(4095);
        horizontalSlider3->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider3);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        pushButtonRead = new QPushButton(groupBox);
        pushButtonRead->setObjectName("pushButtonRead");
        pushButtonRead->setMinimumSize(QSize(100, 30));

        verticalLayout->addWidget(pushButtonRead, 0, Qt::AlignHCenter);

        tableViewGrid = new QTableView(groupBox);
        tableViewGrid->setObjectName("tableViewGrid");
        tableViewGrid->setMinimumSize(QSize(445, 445));

        verticalLayout->addWidget(tableViewGrid);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        radioButtonM1 = new QRadioButton(groupBox);
        buttonGroup1 = new QButtonGroup(FramePixelCompensation);
        buttonGroup1->setObjectName("buttonGroup1");
        buttonGroup1->addButton(radioButtonM1);
        radioButtonM1->setObjectName("radioButtonM1");
        radioButtonM1->setChecked(true);

        horizontalLayout_5->addWidget(radioButtonM1);

        radioButtonM2 = new QRadioButton(groupBox);
        buttonGroup1->addButton(radioButtonM2);
        radioButtonM2->setObjectName("radioButtonM2");

        horizontalLayout_5->addWidget(radioButtonM2);

        radioButtonM3 = new QRadioButton(groupBox);
        buttonGroup1->addButton(radioButtonM3);
        radioButtonM3->setObjectName("radioButtonM3");

        horizontalLayout_5->addWidget(radioButtonM3);

        radioButtonM4 = new QRadioButton(groupBox);
        buttonGroup1->addButton(radioButtonM4);
        radioButtonM4->setObjectName("radioButtonM4");

        horizontalLayout_5->addWidget(radioButtonM4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButtonReadM = new QPushButton(groupBox);
        pushButtonReadM->setObjectName("pushButtonReadM");
        pushButtonReadM->setMinimumSize(QSize(80, 0));
        pushButtonReadM->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(pushButtonReadM);

        pushButtonWriteM = new QPushButton(groupBox);
        pushButtonWriteM->setObjectName("pushButtonWriteM");
        pushButtonWriteM->setMinimumSize(QSize(80, 0));
        pushButtonWriteM->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(pushButtonWriteM);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButtonLoad = new QPushButton(groupBox);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setMinimumSize(QSize(80, 0));
        pushButtonLoad->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setMinimumSize(QSize(80, 0));
        pushButtonSave->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(groupBox, 0, Qt::AlignHCenter);

        horizontalSpacer_2 = new QSpacerItem(149, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(FramePixelCompensation);

        QMetaObject::connectSlotsByName(FramePixelCompensation);
    } // setupUi

    void retranslateUi(QFrame *FramePixelCompensation)
    {
        FramePixelCompensation->setWindowTitle(QCoreApplication::translate("FramePixelCompensation", "Frame", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FramePixelCompensation", "Pixel Compensation ", nullptr));
        label->setText(QCoreApplication::translate("FramePixelCompensation", "\350\203\214\345\205\211\346\234\200\345\244\247\344\272\256\345\272\246\345\200\274:", nullptr));
        label_2->setText(QCoreApplication::translate("FramePixelCompensation", "\345\233\276\345\203\217\350\241\245\345\201\277\347\232\204\345\274\272\345\272\246:", nullptr));
        label_3->setText(QCoreApplication::translate("FramePixelCompensation", "\351\245\261\345\222\214\345\272\246\350\211\262\345\275\251\351\242\234\350\211\262\344\277\235\346\212\244:", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FramePixelCompensation", "Read", nullptr));
        radioButtonM1->setText(QCoreApplication::translate("FramePixelCompensation", "\345\205\250\345\261\217", nullptr));
        radioButtonM2->setText(QCoreApplication::translate("FramePixelCompensation", "\345\267\246\345\215\212\345\261\217", nullptr));
        radioButtonM3->setText(QCoreApplication::translate("FramePixelCompensation", "\345\217\263\345\215\212\345\261\217", nullptr));
        radioButtonM4->setText(QCoreApplication::translate("FramePixelCompensation", "None", nullptr));
        pushButtonReadM->setText(QCoreApplication::translate("FramePixelCompensation", "Read", nullptr));
        pushButtonWriteM->setText(QCoreApplication::translate("FramePixelCompensation", "Write", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FramePixelCompensation", "Load File ...", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FramePixelCompensation", "Save File ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramePixelCompensation: public Ui_FramePixelCompensation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEPIXELCOMPENSATION_H
