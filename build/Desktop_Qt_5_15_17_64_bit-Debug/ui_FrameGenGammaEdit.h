/********************************************************************************
** Form generated from reading UI file 'FrameGenGammaEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEGENGAMMAEDIT_H
#define UI_FRAMEGENGAMMAEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrameGenGammaEdit
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIndex;
    QComboBox *comboBoxIndex;
    QLabel *labelAddr;
    QComboBox *comboBoxAddr;
    QPushButton *pushButtonRead;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonReset;
    QCheckBox *checkBoxSelectPiont;
    QLabel *labelPoints;
    QSlider *horizontalSliderPoints;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QComboBox *comboBoxFile;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QHBoxLayout *horizontalLayoutBottom;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBoxX;
    QSlider *hSliderX;
    QLabel *labelCurve;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBoxY;
    QSlider *vSliderY;
    QTableView *tableView;

    void setupUi(QFrame *FrameGenGammaEdit)
    {
        if (FrameGenGammaEdit->objectName().isEmpty())
            FrameGenGammaEdit->setObjectName(QString::fromUtf8("FrameGenGammaEdit"));
        FrameGenGammaEdit->resize(1068, 505);
        verticalLayout_3 = new QVBoxLayout(FrameGenGammaEdit);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelIndex = new QLabel(FrameGenGammaEdit);
        labelIndex->setObjectName(QString::fromUtf8("labelIndex"));

        horizontalLayout->addWidget(labelIndex);

        comboBoxIndex = new QComboBox(FrameGenGammaEdit);
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->addItem(QString());
        comboBoxIndex->setObjectName(QString::fromUtf8("comboBoxIndex"));
        comboBoxIndex->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        comboBoxIndex->setFont(font);
        comboBoxIndex->setMaxVisibleItems(20);
        comboBoxIndex->setMaxCount(30);

        horizontalLayout->addWidget(comboBoxIndex);

        labelAddr = new QLabel(FrameGenGammaEdit);
        labelAddr->setObjectName(QString::fromUtf8("labelAddr"));

        horizontalLayout->addWidget(labelAddr);

        comboBoxAddr = new QComboBox(FrameGenGammaEdit);
        comboBoxAddr->addItem(QString());
        comboBoxAddr->addItem(QString());
        comboBoxAddr->addItem(QString());
        comboBoxAddr->addItem(QString());
        comboBoxAddr->addItem(QString());
        comboBoxAddr->setObjectName(QString::fromUtf8("comboBoxAddr"));
        comboBoxAddr->setMinimumSize(QSize(80, 0));
        comboBoxAddr->setFont(font);
        comboBoxAddr->setMaxVisibleItems(20);
        comboBoxAddr->setMaxCount(30);

        horizontalLayout->addWidget(comboBoxAddr);

        pushButtonRead = new QPushButton(FrameGenGammaEdit);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonRead);

        pushButtonWrite = new QPushButton(FrameGenGammaEdit);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonWrite);

        pushButtonReset = new QPushButton(FrameGenGammaEdit);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        pushButtonReset->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonReset);

        checkBoxSelectPiont = new QCheckBox(FrameGenGammaEdit);
        checkBoxSelectPiont->setObjectName(QString::fromUtf8("checkBoxSelectPiont"));

        horizontalLayout->addWidget(checkBoxSelectPiont);

        labelPoints = new QLabel(FrameGenGammaEdit);
        labelPoints->setObjectName(QString::fromUtf8("labelPoints"));
        labelPoints->setMinimumSize(QSize(16, 0));

        horizontalLayout->addWidget(labelPoints);

        horizontalSliderPoints = new QSlider(FrameGenGammaEdit);
        horizontalSliderPoints->setObjectName(QString::fromUtf8("horizontalSliderPoints"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(FrameGenGammaEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBoxFile = new QComboBox(FrameGenGammaEdit);
        comboBoxFile->setObjectName(QString::fromUtf8("comboBoxFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxFile->sizePolicy().hasHeightForWidth());
        comboBoxFile->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBoxFile);

        pushButtonSave = new QPushButton(FrameGenGammaEdit);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(FrameGenGammaEdit);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonLoad);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayoutBottom = new QHBoxLayout();
        horizontalLayoutBottom->setObjectName(QString::fromUtf8("horizontalLayoutBottom"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBoxX = new QSpinBox(FrameGenGammaEdit);
        spinBoxX->setObjectName(QString::fromUtf8("spinBoxX"));
        sizePolicy.setHeightForWidth(spinBoxX->sizePolicy().hasHeightForWidth());
        spinBoxX->setSizePolicy(sizePolicy);
        spinBoxX->setMinimumSize(QSize(50, 0));
        spinBoxX->setMaximum(4095);
        spinBoxX->setValue(0);

        horizontalLayout_2->addWidget(spinBoxX);

        hSliderX = new QSlider(FrameGenGammaEdit);
        hSliderX->setObjectName(QString::fromUtf8("hSliderX"));
        hSliderX->setMaximum(4095);
        hSliderX->setValue(0);
        hSliderX->setTracking(true);
        hSliderX->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hSliderX);


        verticalLayout_2->addLayout(horizontalLayout_2);

        labelCurve = new QLabel(FrameGenGammaEdit);
        labelCurve->setObjectName(QString::fromUtf8("labelCurve"));
        labelCurve->setStyleSheet(QString::fromUtf8("background-color: rgb(132, 132, 132);"));
        labelCurve->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelCurve);

        verticalLayout_2->setStretch(1, 1);

        horizontalLayoutBottom->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        spinBoxY = new QSpinBox(FrameGenGammaEdit);
        spinBoxY->setObjectName(QString::fromUtf8("spinBoxY"));
        sizePolicy.setHeightForWidth(spinBoxY->sizePolicy().hasHeightForWidth());
        spinBoxY->setSizePolicy(sizePolicy);
        spinBoxY->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setBold(true);
        spinBoxY->setFont(font1);
        spinBoxY->setMaximum(4095);
        spinBoxY->setValue(0);

        verticalLayout->addWidget(spinBoxY);

        vSliderY = new QSlider(FrameGenGammaEdit);
        vSliderY->setObjectName(QString::fromUtf8("vSliderY"));
        vSliderY->setMinimumSize(QSize(40, 0));
        vSliderY->setMaximum(4095);
        vSliderY->setValue(255);
        vSliderY->setTracking(true);
        vSliderY->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(vSliderY, 0, Qt::AlignHCenter);


        horizontalLayoutBottom->addLayout(verticalLayout);

        tableView = new QTableView(FrameGenGammaEdit);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(120, 0));
        tableView->setMaximumSize(QSize(140, 16777215));
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);

        horizontalLayoutBottom->addWidget(tableView);

        horizontalLayoutBottom->setStretch(0, 5);

        verticalLayout_3->addLayout(horizontalLayoutBottom);

#if QT_CONFIG(shortcut)
        labelPoints->setBuddy(horizontalSliderPoints);
#endif // QT_CONFIG(shortcut)

        retranslateUi(FrameGenGammaEdit);

        QMetaObject::connectSlotsByName(FrameGenGammaEdit);
    } // setupUi

    void retranslateUi(QFrame *FrameGenGammaEdit)
    {
        FrameGenGammaEdit->setWindowTitle(QCoreApplication::translate("FrameGenGammaEdit", "Frame", nullptr));
        labelIndex->setText(QCoreApplication::translate("FrameGenGammaEdit", "Index:", nullptr));
        comboBoxIndex->setItemText(0, QCoreApplication::translate("FrameGenGammaEdit", "0", nullptr));
        comboBoxIndex->setItemText(1, QCoreApplication::translate("FrameGenGammaEdit", "1", nullptr));
        comboBoxIndex->setItemText(2, QCoreApplication::translate("FrameGenGammaEdit", "2", nullptr));
        comboBoxIndex->setItemText(3, QCoreApplication::translate("FrameGenGammaEdit", "3", nullptr));
        comboBoxIndex->setItemText(4, QCoreApplication::translate("FrameGenGammaEdit", "All", nullptr));

        labelAddr->setText(QCoreApplication::translate("FrameGenGammaEdit", "Addr:", nullptr));
        comboBoxAddr->setItemText(0, QCoreApplication::translate("FrameGenGammaEdit", "0", nullptr));
        comboBoxAddr->setItemText(1, QCoreApplication::translate("FrameGenGammaEdit", "1", nullptr));
        comboBoxAddr->setItemText(2, QCoreApplication::translate("FrameGenGammaEdit", "2", nullptr));
        comboBoxAddr->setItemText(3, QCoreApplication::translate("FrameGenGammaEdit", "3", nullptr));
        comboBoxAddr->setItemText(4, QCoreApplication::translate("FrameGenGammaEdit", "All", nullptr));

        pushButtonRead->setText(QCoreApplication::translate("FrameGenGammaEdit", "Read", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameGenGammaEdit", "Write", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("FrameGenGammaEdit", "Reset", nullptr));
        checkBoxSelectPiont->setText(QCoreApplication::translate("FrameGenGammaEdit", "Hots Points:", nullptr));
        labelPoints->setText(QCoreApplication::translate("FrameGenGammaEdit", "20", nullptr));
        label_4->setText(QCoreApplication::translate("FrameGenGammaEdit", "File Name:", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameGenGammaEdit", "Save ...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameGenGammaEdit", "Load ...", nullptr));
        labelCurve->setText(QCoreApplication::translate("FrameGenGammaEdit", "Curve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameGenGammaEdit: public Ui_FrameGenGammaEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEGENGAMMAEDIT_H
