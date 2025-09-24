/********************************************************************************
** Form generated from reading UI file 'DialogAgingTest.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAGINGTEST_H
#define UI_DIALOGAGINGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogAgingTest
{
public:
    QTableView *tableView;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QTableView *tableViewReg;
    QPushButton *pushButtonSave;
    QLabel *labelTime;
    QCheckBox *checkBoxSave;
    QPushButton *pushButtonGoto;
    QLabel *labelFile;
    QLabel *label;

    void setupUi(QDialog *DialogAgingTest)
    {
        if (DialogAgingTest->objectName().isEmpty())
            DialogAgingTest->setObjectName("DialogAgingTest");
        DialogAgingTest->resize(1366, 768);
        DialogAgingTest->setMinimumSize(QSize(1366, 768));
        DialogAgingTest->setMaximumSize(QSize(1366, 768));
        tableView = new QTableView(DialogAgingTest);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 1131, 711));
        tableView->setMouseTracking(false);
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);
        pushButtonAdd = new QPushButton(DialogAgingTest);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(10, 730, 101, 32));
        pushButtonDelete = new QPushButton(DialogAgingTest);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(144, 730, 101, 32));
        tableViewReg = new QTableView(DialogAgingTest);
        tableViewReg->setObjectName("tableViewReg");
        tableViewReg->setGeometry(QRect(1150, 10, 201, 711));
        tableViewReg->setSelectionMode(QAbstractItemView::NoSelection);
        tableViewReg->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewReg->horizontalHeader()->setHighlightSections(false);
        tableViewReg->verticalHeader()->setVisible(false);
        tableViewReg->verticalHeader()->setHighlightSections(false);
        pushButtonSave = new QPushButton(DialogAgingTest);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(280, 730, 101, 32));
        labelTime = new QLabel(DialogAgingTest);
        labelTime->setObjectName("labelTime");
        labelTime->setGeometry(QRect(1160, 730, 191, 30));
        checkBoxSave = new QCheckBox(DialogAgingTest);
        checkBoxSave->setObjectName("checkBoxSave");
        checkBoxSave->setGeometry(QRect(930, 730, 91, 30));
        checkBoxSave->setChecked(true);
        pushButtonGoto = new QPushButton(DialogAgingTest);
        pushButtonGoto->setObjectName("pushButtonGoto");
        pushButtonGoto->setGeometry(QRect(1040, 730, 101, 32));
        labelFile = new QLabel(DialogAgingTest);
        labelFile->setObjectName("labelFile");
        labelFile->setGeometry(QRect(460, 730, 461, 30));
        labelFile->setWordWrap(true);
        label = new QLabel(DialogAgingTest);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 730, 53, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(DialogAgingTest);

        QMetaObject::connectSlotsByName(DialogAgingTest);
    } // setupUi

    void retranslateUi(QDialog *DialogAgingTest)
    {
        DialogAgingTest->setWindowTitle(QCoreApplication::translate("DialogAgingTest", "\350\200\201\345\214\226\346\265\213\350\257\225", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("DialogAgingTest", "\346\267\273\345\212\240", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("DialogAgingTest", "\345\210\240\351\231\244", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("DialogAgingTest", "\344\277\235\345\255\230", nullptr));
        labelTime->setText(QCoreApplication::translate("DialogAgingTest", "0000-00-00 00:00:00.000", nullptr));
        checkBoxSave->setText(QCoreApplication::translate("DialogAgingTest", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", nullptr));
        pushButtonGoto->setText(QCoreApplication::translate("DialogAgingTest", "\346\211\223\345\274\200\346\226\207\344\273\266 ...", nullptr));
        labelFile->setText(QString());
        label->setText(QCoreApplication::translate("DialogAgingTest", "\346\226\207\344\273\266:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAgingTest: public Ui_DialogAgingTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAGINGTEST_H
