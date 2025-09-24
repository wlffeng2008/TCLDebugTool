/********************************************************************************
** Form generated from reading UI file 'FrameBLGamma.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEBLGAMMA_H
#define UI_FRAMEBLGAMMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include "frameblgammapanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrameBLGamma
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxShowGammaIn;
    QCheckBox *checkBoxShowRemap;
    QLabel *label_2;
    QComboBox *comboBoxIndex;
    QCheckBox *checkBox109D;
    QPushButton *pushButtonRead;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonReset;
    QCheckBox *checkBoxSelectPiont;
    QLabel *labelPoints;
    QSlider *horizontalSliderPoints;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditFilename;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBoxX;
    QSlider *horizontalSliderPos;
    QHBoxLayout *horizontalLayout_4;
    FrameBLGammaPanel *framePanel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBoxY;
    QSlider *verticalSliderValue;
    QTableView *tableView;

    void setupUi(QFrame *FrameBLGamma)
    {
        if (FrameBLGamma->objectName().isEmpty())
            FrameBLGamma->setObjectName("FrameBLGamma");
        FrameBLGamma->resize(1340, 558);
        verticalLayout_3 = new QVBoxLayout(FrameBLGamma);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 2, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBoxShowGammaIn = new QCheckBox(FrameBLGamma);
        checkBoxShowGammaIn->setObjectName("checkBoxShowGammaIn");
        checkBoxShowGammaIn->setChecked(true);

        horizontalLayout->addWidget(checkBoxShowGammaIn);

        checkBoxShowRemap = new QCheckBox(FrameBLGamma);
        checkBoxShowRemap->setObjectName("checkBoxShowRemap");
        checkBoxShowRemap->setChecked(true);

        horizontalLayout->addWidget(checkBoxShowRemap);

        label_2 = new QLabel(FrameBLGamma);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        comboBoxIndex = new QComboBox(FrameBLGamma);
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->setObjectName("comboBoxIndex");
        comboBoxIndex->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        comboBoxIndex->setFont(font);
        comboBoxIndex->setMaxVisibleItems(20);
        comboBoxIndex->setMaxCount(30);

        horizontalLayout->addWidget(comboBoxIndex);

        checkBox109D = new QCheckBox(FrameBLGamma);
        checkBox109D->setObjectName("checkBox109D");

        horizontalLayout->addWidget(checkBox109D);

        pushButtonRead = new QPushButton(FrameBLGamma);
        pushButtonRead->setObjectName("pushButtonRead");
        pushButtonRead->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonRead);

        pushButtonWrite = new QPushButton(FrameBLGamma);
        pushButtonWrite->setObjectName("pushButtonWrite");
        pushButtonWrite->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonWrite);

        pushButtonReset = new QPushButton(FrameBLGamma);
        pushButtonReset->setObjectName("pushButtonReset");
        pushButtonReset->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonReset);

        checkBoxSelectPiont = new QCheckBox(FrameBLGamma);
        checkBoxSelectPiont->setObjectName("checkBoxSelectPiont");

        horizontalLayout->addWidget(checkBoxSelectPiont);

        labelPoints = new QLabel(FrameBLGamma);
        labelPoints->setObjectName("labelPoints");
        labelPoints->setMinimumSize(QSize(16, 0));

        horizontalLayout->addWidget(labelPoints);

        horizontalSliderPoints = new QSlider(FrameBLGamma);
        horizontalSliderPoints->setObjectName("horizontalSliderPoints");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSliderPoints->sizePolicy().hasHeightForWidth());
        horizontalSliderPoints->setSizePolicy(sizePolicy);
        horizontalSliderPoints->setMinimumSize(QSize(100, 0));
        horizontalSliderPoints->setMinimum(10);
        horizontalSliderPoints->setMaximum(200);
        horizontalSliderPoints->setValue(24);
        horizontalSliderPoints->setTracking(true);
        horizontalSliderPoints->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSliderPoints);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FrameBLGamma);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        lineEditFilename = new QLineEdit(FrameBLGamma);
        lineEditFilename->setObjectName("lineEditFilename");

        horizontalLayout->addWidget(lineEditFilename);

        pushButtonSave = new QPushButton(FrameBLGamma);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(FrameBLGamma);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonLoad);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spinBoxX = new QSpinBox(FrameBLGamma);
        spinBoxX->setObjectName("spinBoxX");
        sizePolicy.setHeightForWidth(spinBoxX->sizePolicy().hasHeightForWidth());
        spinBoxX->setSizePolicy(sizePolicy);
        spinBoxX->setMinimumSize(QSize(50, 0));
        spinBoxX->setMaximum(4095);
        spinBoxX->setValue(0);

        horizontalLayout_2->addWidget(spinBoxX);

        horizontalSliderPos = new QSlider(FrameBLGamma);
        horizontalSliderPos->setObjectName("horizontalSliderPos");
        horizontalSliderPos->setMaximum(4095);
        horizontalSliderPos->setValue(0);
        horizontalSliderPos->setTracking(true);
        horizontalSliderPos->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderPos);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        framePanel = new FrameBLGammaPanel(FrameBLGamma);
        framePanel->setObjectName("framePanel");
        framePanel->setFocusPolicy(Qt::StrongFocus);
        framePanel->setStyleSheet(QString::fromUtf8(""));
        framePanel->setFrameShape(QFrame::StyledPanel);
        framePanel->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(framePanel);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(framePanel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        spinBoxY = new QSpinBox(FrameBLGamma);
        spinBoxY->setObjectName("spinBoxY");
        sizePolicy.setHeightForWidth(spinBoxY->sizePolicy().hasHeightForWidth());
        spinBoxY->setSizePolicy(sizePolicy);
        spinBoxY->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setBold(true);
        spinBoxY->setFont(font1);
        spinBoxY->setMaximum(4095);
        spinBoxY->setValue(0);

        verticalLayout->addWidget(spinBoxY);

        verticalSliderValue = new QSlider(FrameBLGamma);
        verticalSliderValue->setObjectName("verticalSliderValue");
        verticalSliderValue->setMinimumSize(QSize(40, 0));
        verticalSliderValue->setMaximum(4095);
        verticalSliderValue->setValue(255);
        verticalSliderValue->setTracking(true);
        verticalSliderValue->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(verticalSliderValue, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout);

        tableView = new QTableView(FrameBLGamma);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(150, 0));
        tableView->setMaximumSize(QSize(100, 16777215));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(true);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tableView);


        verticalLayout_3->addLayout(horizontalLayout_5);

#if QT_CONFIG(shortcut)
        labelPoints->setBuddy(horizontalSliderPoints);
#endif // QT_CONFIG(shortcut)

        retranslateUi(FrameBLGamma);

        QMetaObject::connectSlotsByName(FrameBLGamma);
    } // setupUi

    void retranslateUi(QFrame *FrameBLGamma)
    {
        FrameBLGamma->setWindowTitle(QCoreApplication::translate("FrameBLGamma", "Frame", nullptr));
        checkBoxShowGammaIn->setText(QCoreApplication::translate("FrameBLGamma", "Gamma(In)", nullptr));
        checkBoxShowRemap->setText(QCoreApplication::translate("FrameBLGamma", "Remap(Out)", nullptr));
        label_2->setText(QCoreApplication::translate("FrameBLGamma", "Index:", nullptr));
        comboBoxIndex->setItemText(0, QCoreApplication::translate("FrameBLGamma", "0", nullptr));
        comboBoxIndex->setItemText(1, QCoreApplication::translate("FrameBLGamma", "1", nullptr));
        comboBoxIndex->setItemText(2, QCoreApplication::translate("FrameBLGamma", "2", nullptr));
        comboBoxIndex->setItemText(3, QCoreApplication::translate("FrameBLGamma", "3", nullptr));
        comboBoxIndex->setItemText(4, QCoreApplication::translate("FrameBLGamma", "All", nullptr));

        checkBox109D->setText(QCoreApplication::translate("FrameBLGamma", "109D", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameBLGamma", "Read", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameBLGamma", "Write", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("FrameBLGamma", "Reset", nullptr));
        checkBoxSelectPiont->setText(QCoreApplication::translate("FrameBLGamma", "Select Point:", nullptr));
        labelPoints->setText(QCoreApplication::translate("FrameBLGamma", "20", nullptr));
        label_3->setText(QCoreApplication::translate("FrameBLGamma", "File Name:", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameBLGamma", "Save ...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameBLGamma", "Load ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameBLGamma: public Ui_FrameBLGamma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEBLGAMMA_H
