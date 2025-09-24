/********************************************************************************
** Form generated from reading UI file 'FrameTPFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMETPFILTER_H
#define UI_FRAMETPFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include "frametpfilterpanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrameTPFilter
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QCheckBox *checkBox109D;
    QPushButton *pushButtonRead;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonReset;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditFilename;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QHBoxLayout *horizontalLayout_5;
    FrameTPFilterPanel *framePanel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;

    void setupUi(QFrame *FrameTPFilter)
    {
        if (FrameTPFilter->objectName().isEmpty())
            FrameTPFilter->setObjectName(QString::fromUtf8("FrameTPFilter"));
        FrameTPFilter->resize(1219, 728);
        verticalLayout_3 = new QVBoxLayout(FrameTPFilter);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 2, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton1 = new QRadioButton(FrameTPFilter);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        radioButton1->setChecked(true);

        horizontalLayout->addWidget(radioButton1);

        radioButton2 = new QRadioButton(FrameTPFilter);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        horizontalLayout->addWidget(radioButton2);

        checkBox109D = new QCheckBox(FrameTPFilter);
        checkBox109D->setObjectName(QString::fromUtf8("checkBox109D"));

        horizontalLayout->addWidget(checkBox109D);

        pushButtonRead = new QPushButton(FrameTPFilter);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));

        horizontalLayout->addWidget(pushButtonRead);

        pushButtonWrite = new QPushButton(FrameTPFilter);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));

        horizontalLayout->addWidget(pushButtonWrite);

        pushButtonReset = new QPushButton(FrameTPFilter);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));

        horizontalLayout->addWidget(pushButtonReset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FrameTPFilter);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEditFilename = new QLineEdit(FrameTPFilter);
        lineEditFilename->setObjectName(QString::fromUtf8("lineEditFilename"));

        horizontalLayout->addWidget(lineEditFilename);

        pushButtonSave = new QPushButton(FrameTPFilter);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(FrameTPFilter);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));

        horizontalLayout->addWidget(pushButtonLoad);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        framePanel = new FrameTPFilterPanel(FrameTPFilter);
        framePanel->setObjectName(QString::fromUtf8("framePanel"));
        framePanel->setFocusPolicy(Qt::StrongFocus);
        framePanel->setStyleSheet(QString::fromUtf8(""));
        framePanel->setFrameShape(QFrame::StyledPanel);
        framePanel->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(framePanel);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_5->addWidget(framePanel);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer);

        tableView = new QTableView(FrameTPFilter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(210, 0));
        tableView->setMaximumSize(QSize(210, 16777215));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(true);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tableView);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(FrameTPFilter);

        QMetaObject::connectSlotsByName(FrameTPFilter);
    } // setupUi

    void retranslateUi(QFrame *FrameTPFilter)
    {
        FrameTPFilter->setWindowTitle(QCoreApplication::translate("FrameTPFilter", "Frame", nullptr));
        radioButton1->setText(QCoreApplication::translate("FrameTPFilter", "tp_alpha_up", nullptr));
        radioButton2->setText(QCoreApplication::translate("FrameTPFilter", "tp_alpha_down", nullptr));
        checkBox109D->setText(QCoreApplication::translate("FrameTPFilter", "109D", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameTPFilter", "Read", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameTPFilter", "Write", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("FrameTPFilter", "Reset", nullptr));
        label_3->setText(QCoreApplication::translate("FrameTPFilter", "File Name:", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameTPFilter", "Save ...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameTPFilter", "Load ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameTPFilter: public Ui_FrameTPFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMETPFILTER_H
