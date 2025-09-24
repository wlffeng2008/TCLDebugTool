/********************************************************************************
** Form generated from reading UI file 'FramePQGamma.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEPQGAMMA_H
#define UI_FRAMEPQGAMMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FramePQGamma
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayoutY_2;
    QHBoxLayout *horizontalLayoutX;
    QSpinBox *spinBoxX;
    QSlider *hSliderX;
    QLabel *labelCurve;
    QVBoxLayout *verticalLayoutY;
    QSpinBox *spinBoxY;
    QSlider *vSliderY;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutShow;
    QCheckBox *checkBoxGamma;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxG;
    QCheckBox *checkBoxB;
    QHBoxLayout *horizontalLayoutCtrl;
    QLabel *label;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QHBoxLayout *horizontalLayoutRW;
    QPushButton *pushButtonRead;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QTableView *tableView;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *FramePQGamma)
    {
        if (FramePQGamma->objectName().isEmpty())
            FramePQGamma->setObjectName(QString::fromUtf8("FramePQGamma"));
        FramePQGamma->resize(1175, 710);
        horizontalLayout = new QHBoxLayout(FramePQGamma);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayoutY_2 = new QVBoxLayout();
        verticalLayoutY_2->setObjectName(QString::fromUtf8("verticalLayoutY_2"));
        horizontalLayoutX = new QHBoxLayout();
        horizontalLayoutX->setObjectName(QString::fromUtf8("horizontalLayoutX"));
        spinBoxX = new QSpinBox(FramePQGamma);
        spinBoxX->setObjectName(QString::fromUtf8("spinBoxX"));
        spinBoxX->setMinimumSize(QSize(60, 0));
        spinBoxX->setMaximum(255);

        horizontalLayoutX->addWidget(spinBoxX);

        hSliderX = new QSlider(FramePQGamma);
        hSliderX->setObjectName(QString::fromUtf8("hSliderX"));
        hSliderX->setMaximum(255);
        hSliderX->setOrientation(Qt::Horizontal);

        horizontalLayoutX->addWidget(hSliderX);


        verticalLayoutY_2->addLayout(horizontalLayoutX);

        labelCurve = new QLabel(FramePQGamma);
        labelCurve->setObjectName(QString::fromUtf8("labelCurve"));
        QFont font;
        font.setPointSize(150);
        font.setBold(true);
        labelCurve->setFont(font);
        labelCurve->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelCurve->setAlignment(Qt::AlignCenter);

        verticalLayoutY_2->addWidget(labelCurve);

        verticalLayoutY_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayoutY_2);

        verticalLayoutY = new QVBoxLayout();
        verticalLayoutY->setObjectName(QString::fromUtf8("verticalLayoutY"));
        spinBoxY = new QSpinBox(FramePQGamma);
        spinBoxY->setObjectName(QString::fromUtf8("spinBoxY"));
        spinBoxY->setMinimumSize(QSize(60, 0));
        spinBoxY->setMaximum(4095);

        verticalLayoutY->addWidget(spinBoxY);

        vSliderY = new QSlider(FramePQGamma);
        vSliderY->setObjectName(QString::fromUtf8("vSliderY"));
        vSliderY->setMaximum(4095);
        vSliderY->setOrientation(Qt::Vertical);

        verticalLayoutY->addWidget(vSliderY, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayoutY);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutShow = new QHBoxLayout();
        horizontalLayoutShow->setObjectName(QString::fromUtf8("horizontalLayoutShow"));
        checkBoxGamma = new QCheckBox(FramePQGamma);
        checkBoxGamma->setObjectName(QString::fromUtf8("checkBoxGamma"));
        checkBoxGamma->setChecked(false);

        horizontalLayoutShow->addWidget(checkBoxGamma);

        checkBoxR = new QCheckBox(FramePQGamma);
        checkBoxR->setObjectName(QString::fromUtf8("checkBoxR"));
        checkBoxR->setChecked(true);

        horizontalLayoutShow->addWidget(checkBoxR);

        checkBoxG = new QCheckBox(FramePQGamma);
        checkBoxG->setObjectName(QString::fromUtf8("checkBoxG"));
        checkBoxG->setChecked(true);

        horizontalLayoutShow->addWidget(checkBoxG);

        checkBoxB = new QCheckBox(FramePQGamma);
        checkBoxB->setObjectName(QString::fromUtf8("checkBoxB"));
        checkBoxB->setChecked(true);

        horizontalLayoutShow->addWidget(checkBoxB);


        verticalLayout->addLayout(horizontalLayoutShow);

        horizontalLayoutCtrl = new QHBoxLayout();
        horizontalLayoutCtrl->setObjectName(QString::fromUtf8("horizontalLayoutCtrl"));
        label = new QLabel(FramePQGamma);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayoutCtrl->addWidget(label, 0, Qt::AlignRight);

        radioButton1 = new QRadioButton(FramePQGamma);
        buttonGroup = new QButtonGroup(FramePQGamma);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton1);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        radioButton1->setChecked(true);

        horizontalLayoutCtrl->addWidget(radioButton1);

        radioButton2 = new QRadioButton(FramePQGamma);
        buttonGroup->addButton(radioButton2);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        horizontalLayoutCtrl->addWidget(radioButton2);

        radioButton3 = new QRadioButton(FramePQGamma);
        buttonGroup->addButton(radioButton3);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));

        horizontalLayoutCtrl->addWidget(radioButton3);


        verticalLayout->addLayout(horizontalLayoutCtrl);

        horizontalLayoutRW = new QHBoxLayout();
        horizontalLayoutRW->setObjectName(QString::fromUtf8("horizontalLayoutRW"));
        pushButtonRead = new QPushButton(FramePQGamma);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));

        horizontalLayoutRW->addWidget(pushButtonRead);

        pushButtonWrite = new QPushButton(FramePQGamma);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));

        horizontalLayoutRW->addWidget(pushButtonWrite);

        pushButtonLoad = new QPushButton(FramePQGamma);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));

        horizontalLayoutRW->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(FramePQGamma);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayoutRW->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayoutRW);

        tableView = new QTableView(FramePQGamma);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);

        retranslateUi(FramePQGamma);

        QMetaObject::connectSlotsByName(FramePQGamma);
    } // setupUi

    void retranslateUi(QFrame *FramePQGamma)
    {
        FramePQGamma->setWindowTitle(QCoreApplication::translate("FramePQGamma", "Frame", nullptr));
        labelCurve->setText(QCoreApplication::translate("FramePQGamma", "<html><head/><body><p><span style=\" color:#ff0000;\">R</span><span style=\" color:#00ff00;\">G</span><span style=\" color:#0000ff;\">B</span></p></body></html>", nullptr));
        checkBoxGamma->setText(QCoreApplication::translate("FramePQGamma", "001F", nullptr));
        checkBoxR->setText(QCoreApplication::translate("FramePQGamma", "R", nullptr));
        checkBoxG->setText(QCoreApplication::translate("FramePQGamma", "G", nullptr));
        checkBoxB->setText(QCoreApplication::translate("FramePQGamma", "B", nullptr));
        label->setText(QCoreApplication::translate("FramePQGamma", "\346\223\215\346\216\247\347\233\256\346\240\207\357\274\232", nullptr));
        radioButton1->setText(QCoreApplication::translate("FramePQGamma", "R", nullptr));
        radioButton2->setText(QCoreApplication::translate("FramePQGamma", "G", nullptr));
        radioButton3->setText(QCoreApplication::translate("FramePQGamma", "B", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FramePQGamma", "Read", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FramePQGamma", "Write", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FramePQGamma", "Load ...", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FramePQGamma", "Save ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramePQGamma: public Ui_FramePQGamma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEPQGAMMA_H
