/********************************************************************************
** Form generated from reading UI file 'DialogConfigPack.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIGPACK_H
#define UI_DIALOGCONFIGPACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConfigPack
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox1;
    QLabel *label;
    QLineEdit *lineEditXlsxFile;
    QTableView *tableViewReg;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxSheets1;
    QPushButton *pushButtonAddSheet;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBoxSheets2;
    QPushButton *pushButtonRemoveSheet;
    QPushButton *pushButtonGetXlsxFile;
    QComboBox *comboBoxModels;
    QCheckBox *checkBoxEditable;
    QGroupBox *groupBox2;
    QTableView *tableViewRam;
    QPushButton *pushButtonAddRam;
    QPushButton *pushButtonDelRam;
    QPushButton *pushButtonSaveRam;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *lineEditSavePath;
    QPushButton *pushButtonGetSavePath;
    QPushButton *pushButtonGotoSavePath;
    QLabel *label_2;
    QLineEdit *lineEditTag;
    QCheckBox *checkBoxHeadChecksum;
    QPushButton *pushButtonBuildCfg;

    void setupUi(QDialog *DialogConfigPack)
    {
        if (DialogConfigPack->objectName().isEmpty())
            DialogConfigPack->setObjectName(QString::fromUtf8("DialogConfigPack"));
        DialogConfigPack->resize(1200, 767);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        DialogConfigPack->setFont(font);
        DialogConfigPack->setAcceptDrops(true);
        verticalLayout = new QVBoxLayout(DialogConfigPack);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox1 = new QGroupBox(DialogConfigPack);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        groupBox1->setFont(font);
        groupBox1->setAcceptDrops(true);
        label = new QLabel(groupBox1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 25, 91, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditXlsxFile = new QLineEdit(groupBox1);
        lineEditXlsxFile->setObjectName(QString::fromUtf8("lineEditXlsxFile"));
        lineEditXlsxFile->setGeometry(QRect(110, 25, 981, 21));
        tableViewReg = new QTableView(groupBox1);
        tableViewReg->setObjectName(QString::fromUtf8("tableViewReg"));
        tableViewReg->setGeometry(QRect(110, 85, 1060, 411));
        tableViewReg->setAcceptDrops(true);
        tableViewReg->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableViewReg->horizontalHeader()->setHighlightSections(false);
        tableViewReg->horizontalHeader()->setStretchLastSection(false);
        tableViewReg->verticalHeader()->setHighlightSections(false);
        tableViewReg->verticalHeader()->setStretchLastSection(false);
        label_3 = new QLabel(groupBox1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 91, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalLayoutWidget = new QWidget(groupBox1);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 50, 310, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBoxSheets1 = new QComboBox(horizontalLayoutWidget);
        comboBoxSheets1->setObjectName(QString::fromUtf8("comboBoxSheets1"));
        comboBoxSheets1->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(comboBoxSheets1);

        pushButtonAddSheet = new QPushButton(horizontalLayoutWidget);
        pushButtonAddSheet->setObjectName(QString::fromUtf8("pushButtonAddSheet"));
        pushButtonAddSheet->setMinimumSize(QSize(130, 0));

        horizontalLayout->addWidget(pushButtonAddSheet);

        horizontalLayout->setStretch(0, 1);
        label_4 = new QLabel(groupBox1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 91, 30));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(430, 55, 131, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(930, 55, 111, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBoxSheets2 = new QComboBox(groupBox1);
        comboBoxSheets2->setObjectName(QString::fromUtf8("comboBoxSheets2"));
        comboBoxSheets2->setGeometry(QRect(570, 55, 141, 21));
        pushButtonRemoveSheet = new QPushButton(groupBox1);
        pushButtonRemoveSheet->setObjectName(QString::fromUtf8("pushButtonRemoveSheet"));
        pushButtonRemoveSheet->setGeometry(QRect(720, 50, 81, 28));
        pushButtonGetXlsxFile = new QPushButton(groupBox1);
        pushButtonGetXlsxFile->setObjectName(QString::fromUtf8("pushButtonGetXlsxFile"));
        pushButtonGetXlsxFile->setGeometry(QRect(1100, 22, 71, 24));
        comboBoxModels = new QComboBox(groupBox1);
        comboBoxModels->setObjectName(QString::fromUtf8("comboBoxModels"));
        comboBoxModels->setGeometry(QRect(1050, 55, 120, 21));
        comboBoxModels->setMinimumSize(QSize(120, 0));
        checkBoxEditable = new QCheckBox(groupBox1);
        checkBoxEditable->setObjectName(QString::fromUtf8("checkBoxEditable"));
        checkBoxEditable->setGeometry(QRect(820, 50, 111, 26));

        verticalLayout->addWidget(groupBox1);

        groupBox2 = new QGroupBox(DialogConfigPack);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setAcceptDrops(true);
        tableViewRam = new QTableView(groupBox2);
        tableViewRam->setObjectName(QString::fromUtf8("tableViewRam"));
        tableViewRam->setGeometry(QRect(110, 21, 1060, 171));
        tableViewRam->setAcceptDrops(true);
        tableViewRam->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewRam->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewRam->horizontalHeader()->setHighlightSections(false);
        tableViewRam->verticalHeader()->setHighlightSections(false);
        pushButtonAddRam = new QPushButton(groupBox2);
        pushButtonAddRam->setObjectName(QString::fromUtf8("pushButtonAddRam"));
        pushButtonAddRam->setGeometry(QRect(20, 30, 81, 31));
        pushButtonDelRam = new QPushButton(groupBox2);
        pushButtonDelRam->setObjectName(QString::fromUtf8("pushButtonDelRam"));
        pushButtonDelRam->setGeometry(QRect(20, 162, 81, 31));
        pushButtonSaveRam = new QPushButton(groupBox2);
        pushButtonSaveRam->setObjectName(QString::fromUtf8("pushButtonSaveRam"));
        pushButtonSaveRam->setGeometry(QRect(20, 80, 81, 31));

        verticalLayout->addWidget(groupBox2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(DialogConfigPack);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(105, 0));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_8);

        lineEditSavePath = new QLineEdit(DialogConfigPack);
        lineEditSavePath->setObjectName(QString::fromUtf8("lineEditSavePath"));

        horizontalLayout_2->addWidget(lineEditSavePath);

        pushButtonGetSavePath = new QPushButton(DialogConfigPack);
        pushButtonGetSavePath->setObjectName(QString::fromUtf8("pushButtonGetSavePath"));

        horizontalLayout_2->addWidget(pushButtonGetSavePath);

        pushButtonGotoSavePath = new QPushButton(DialogConfigPack);
        pushButtonGotoSavePath->setObjectName(QString::fromUtf8("pushButtonGotoSavePath"));

        horizontalLayout_2->addWidget(pushButtonGotoSavePath);

        label_2 = new QLabel(DialogConfigPack);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditTag = new QLineEdit(DialogConfigPack);
        lineEditTag->setObjectName(QString::fromUtf8("lineEditTag"));
        lineEditTag->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lineEditTag);

        checkBoxHeadChecksum = new QCheckBox(DialogConfigPack);
        checkBoxHeadChecksum->setObjectName(QString::fromUtf8("checkBoxHeadChecksum"));

        horizontalLayout_2->addWidget(checkBoxHeadChecksum);

        pushButtonBuildCfg = new QPushButton(DialogConfigPack);
        pushButtonBuildCfg->setObjectName(QString::fromUtf8("pushButtonBuildCfg"));

        horizontalLayout_2->addWidget(pushButtonBuildCfg);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);

        retranslateUi(DialogConfigPack);

        QMetaObject::connectSlotsByName(DialogConfigPack);
    } // setupUi

    void retranslateUi(QDialog *DialogConfigPack)
    {
        DialogConfigPack->setWindowTitle(QCoreApplication::translate("DialogConfigPack", "Dialog", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("DialogConfigPack", "Reg", nullptr));
        label->setText(QCoreApplication::translate("DialogConfigPack", "XLSX\346\226\207\344\273\266\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("DialogConfigPack", "Sheets\357\274\232", nullptr));
        pushButtonAddSheet->setText(QCoreApplication::translate("DialogConfigPack", "\346\267\273\345\212\240\345\210\260\345\257\274\345\207\272\345\210\227\350\241\250 -->", nullptr));
        label_4->setText(QCoreApplication::translate("DialogConfigPack", "\346\225\260\346\215\256\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("DialogConfigPack", "\345\257\274\345\207\272Sheets\345\210\227\350\241\250\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("DialogConfigPack", "\345\257\274\345\207\272\350\256\276\345\244\207\345\236\213\345\217\267\357\274\232", nullptr));
        pushButtonRemoveSheet->setText(QCoreApplication::translate("DialogConfigPack", "\347\247\273\351\231\244", nullptr));
        pushButtonGetXlsxFile->setText(QCoreApplication::translate("DialogConfigPack", "...", nullptr));
        checkBoxEditable->setText(QCoreApplication::translate("DialogConfigPack", "\345\205\201\350\256\270\347\274\226\350\276\221\346\225\260\346\215\256", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("DialogConfigPack", "Ram", nullptr));
        pushButtonAddRam->setText(QCoreApplication::translate("DialogConfigPack", "\346\226\260\345\242\236", nullptr));
        pushButtonDelRam->setText(QCoreApplication::translate("DialogConfigPack", "\347\247\273\351\231\244", nullptr));
        pushButtonSaveRam->setText(QCoreApplication::translate("DialogConfigPack", "\344\277\235\345\255\230", nullptr));
        label_8->setText(QCoreApplication::translate("DialogConfigPack", "\350\276\223\345\207\272\347\233\256\345\275\225\357\274\232", nullptr));
        pushButtonGetSavePath->setText(QCoreApplication::translate("DialogConfigPack", "...", nullptr));
        pushButtonGotoSavePath->setText(QCoreApplication::translate("DialogConfigPack", "Goto ...", nullptr));
        label_2->setText(QCoreApplication::translate("DialogConfigPack", "Tag:", nullptr));
        lineEditTag->setText(QCoreApplication::translate("DialogConfigPack", "Tag", nullptr));
        checkBoxHeadChecksum->setText(QCoreApplication::translate("DialogConfigPack", "\346\267\273\345\212\240\345\244\264\351\203\250\346\240\241\351\252\214", nullptr));
        pushButtonBuildCfg->setText(QCoreApplication::translate("DialogConfigPack", "\347\224\237\346\210\220Bin\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConfigPack: public Ui_DialogConfigPack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGPACK_H
