/********************************************************************************
** Form generated from reading UI file 'FrameRegManager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEREGMANAGER_H
#define UI_FRAMEREGMANAGER_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrameRegManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_1;
    QComboBox *comboBoxReg;
    QComboBox *comboBoxRegEx;
    QCheckBox *checkBoxShowRegEx;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBoxSyncRead;
    QPushButton *pushButtonSetting;
    QPushButton *pushButtonRead;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonSaveAs;
    QPushButton *pushButtonLoad;
    QLabel *labelQuickTip;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditAddCount;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonClear;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *FrameRegManager)
    {
        if (FrameRegManager->objectName().isEmpty())
            FrameRegManager->setObjectName("FrameRegManager");
        FrameRegManager->resize(1624, 600);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        FrameRegManager->setFont(font);
        FrameRegManager->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        verticalLayout = new QVBoxLayout(FrameRegManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 0, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_1 = new QLabel(FrameRegManager);
        label_1->setObjectName("label_1");

        horizontalLayout_2->addWidget(label_1);

        comboBoxReg = new QComboBox(FrameRegManager);
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->addItem(QString());
        comboBoxReg->setObjectName("comboBoxReg");
        comboBoxReg->setMinimumSize(QSize(120, 0));
        comboBoxReg->setMaximumSize(QSize(150, 16777215));
        comboBoxReg->setMaxVisibleItems(20);

        horizontalLayout_2->addWidget(comboBoxReg);

        comboBoxRegEx = new QComboBox(FrameRegManager);
        comboBoxRegEx->addItem(QString());
        comboBoxRegEx->addItem(QString());
        comboBoxRegEx->addItem(QString());
        comboBoxRegEx->addItem(QString());
        comboBoxRegEx->addItem(QString());
        comboBoxRegEx->setObjectName("comboBoxRegEx");
        comboBoxRegEx->setMinimumSize(QSize(120, 0));
        comboBoxRegEx->setMaximumSize(QSize(150, 16777215));
        comboBoxRegEx->setMaxVisibleItems(20);

        horizontalLayout_2->addWidget(comboBoxRegEx);

        checkBoxShowRegEx = new QCheckBox(FrameRegManager);
        checkBoxShowRegEx->setObjectName("checkBoxShowRegEx");

        horizontalLayout_2->addWidget(checkBoxShowRegEx);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        checkBoxSyncRead = new QCheckBox(FrameRegManager);
        checkBoxSyncRead->setObjectName("checkBoxSyncRead");

        horizontalLayout_2->addWidget(checkBoxSyncRead);

        pushButtonSetting = new QPushButton(FrameRegManager);
        pushButtonSetting->setObjectName("pushButtonSetting");
        pushButtonSetting->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSetting->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonSetting);

        pushButtonRead = new QPushButton(FrameRegManager);
        pushButtonRead->setObjectName("pushButtonRead");
        pushButtonRead->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonRead->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonRead);

        pushButtonWrite = new QPushButton(FrameRegManager);
        pushButtonWrite->setObjectName("pushButtonWrite");
        pushButtonWrite->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonWrite->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonWrite);

        pushButtonSave = new QPushButton(FrameRegManager);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSave->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonSaveAs = new QPushButton(FrameRegManager);
        pushButtonSaveAs->setObjectName("pushButtonSaveAs");
        pushButtonSaveAs->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSaveAs->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonSaveAs);

        pushButtonLoad = new QPushButton(FrameRegManager);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonLoad->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonLoad);

        labelQuickTip = new QLabel(FrameRegManager);
        labelQuickTip->setObjectName("labelQuickTip");
        labelQuickTip->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(labelQuickTip);

        horizontalSpacer = new QSpacerItem(40, 30, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(FrameRegManager);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        lineEditAddCount = new QLineEdit(FrameRegManager);
        lineEditAddCount->setObjectName("lineEditAddCount");
        lineEditAddCount->setMinimumSize(QSize(40, 0));
        lineEditAddCount->setMaximumSize(QSize(40, 16777215));
        lineEditAddCount->setInputMask(QString::fromUtf8(""));
        lineEditAddCount->setMaxLength(1000);

        horizontalLayout_2->addWidget(lineEditAddCount);

        pushButtonAdd = new QPushButton(FrameRegManager);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonAdd->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(FrameRegManager);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonDelete->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonDelete);

        pushButtonClear = new QPushButton(FrameRegManager);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(pushButtonClear);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(FrameRegManager);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setFont(font);
        tableView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tableView);

        verticalSpacer = new QSpacerItem(1, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FrameRegManager);

        comboBoxReg->setCurrentIndex(0);
        comboBoxRegEx->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrameRegManager);
    } // setupUi

    void retranslateUi(QFrame *FrameRegManager)
    {
        FrameRegManager->setWindowTitle(QCoreApplication::translate("FrameRegManager", "Frame", nullptr));
        label_1->setText(QCoreApplication::translate("FrameRegManager", "Reg:", nullptr));
        comboBoxReg->setItemText(0, QCoreApplication::translate("FrameRegManager", "Reg0", nullptr));
        comboBoxReg->setItemText(1, QCoreApplication::translate("FrameRegManager", "Reg1", nullptr));
        comboBoxReg->setItemText(2, QCoreApplication::translate("FrameRegManager", "Reg2", nullptr));
        comboBoxReg->setItemText(3, QCoreApplication::translate("FrameRegManager", "Reg3", nullptr));
        comboBoxReg->setItemText(4, QCoreApplication::translate("FrameRegManager", "Reg4", nullptr));
        comboBoxReg->setItemText(5, QCoreApplication::translate("FrameRegManager", "Reg5", nullptr));
        comboBoxReg->setItemText(6, QCoreApplication::translate("FrameRegManager", "Reg6", nullptr));
        comboBoxReg->setItemText(7, QCoreApplication::translate("FrameRegManager", "Reg7", nullptr));
        comboBoxReg->setItemText(8, QCoreApplication::translate("FrameRegManager", "Reg9", nullptr));

        comboBoxRegEx->setItemText(0, QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg0", nullptr));
        comboBoxRegEx->setItemText(1, QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg1", nullptr));
        comboBoxRegEx->setItemText(2, QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg2", nullptr));
        comboBoxRegEx->setItemText(3, QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg3", nullptr));
        comboBoxRegEx->setItemText(4, QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg4", nullptr));

        checkBoxShowRegEx->setText(QCoreApplication::translate("FrameRegManager", "\350\207\252\345\256\232\344\271\211Reg", nullptr));
        checkBoxSyncRead->setText(QCoreApplication::translate("FrameRegManager", "\350\257\273\345\217\226\346\227\266\345\220\214\346\255\245\345\210\260\345\206\231\345\205\245\346\240\217", nullptr));
        pushButtonSetting->setText(QCoreApplication::translate("FrameRegManager", "\351\205\215\347\275\256", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameRegManager", "\344\273\216\350\256\276\345\244\207\350\257\273\345\217\226", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameRegManager", "\345\206\231\345\205\245\350\256\276\345\244\207", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameRegManager", "\344\277\235\345\255\230", nullptr));
        pushButtonSaveAs->setText(QCoreApplication::translate("FrameRegManager", "\345\217\246\345\255\230\344\270\272 ...", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameRegManager", "\346\211\223\345\274\200\346\226\207\344\273\266...", nullptr));
        labelQuickTip->setText(QCoreApplication::translate("FrameRegManager", "Tip\357\274\232Shift+R\350\257\273\345\217\226/S\345\206\231\345\205\245", nullptr));
        label_3->setText(QCoreApplication::translate("FrameRegManager", "\346\225\260\346\215\256\351\207\217:", nullptr));
        lineEditAddCount->setText(QCoreApplication::translate("FrameRegManager", "1", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonAdd->setToolTip(QCoreApplication::translate("FrameRegManager", "\346\214\211\344\275\217Ctrl\351\224\256\345\217\257\346\217\222\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonAdd->setText(QCoreApplication::translate("FrameRegManager", "\346\226\260\345\242\236", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("FrameRegManager", "\345\210\240\351\231\244", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("FrameRegManager", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameRegManager: public Ui_FrameRegManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEREGMANAGER_H
