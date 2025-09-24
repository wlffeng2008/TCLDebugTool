/********************************************************************************
** Form generated from reading UI file 'FrameRamManager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMERAMMANAGER_H
#define UI_FRAMERAMMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrameRamManager
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditFileName;
    QPushButton *pushButtonReLoad;
    QTableView *tableViewData;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox1;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonRead;
    QLabel *label_2;
    QLineEdit *lineEditDataAddr;
    QLabel *label_3;
    QSpinBox *spinBoxDataCount;
    QPushButton *pushButtonGenData;
    QPushButton *pushButtonClearData;
    QLabel *label_4;
    QSpinBox *spinBoxD;
    QSpinBox *spinBoxL;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableViewFile;
    QGroupBox *groupBox2;
    QPushButton *pushButtonAddFile;
    QPushButton *pushButtonRemoveFile;
    QPushButton *pushButtonWriteFile;
    QPushButton *pushButtonOpenFile;
    QCheckBox *checkBoxHexFile;
    QLabel *label_7;
    QSpinBox *spinBoxLineCount;
    QLabel *label_8;
    QLineEdit *lineEditFileAddr;
    QLabel *label_6;

    void setupUi(QFrame *FrameRamManager)
    {
        if (FrameRamManager->objectName().isEmpty())
            FrameRamManager->setObjectName(QString::fromUtf8("FrameRamManager"));
        FrameRamManager->resize(1241, 721);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        FrameRamManager->setFont(font);
        FrameRamManager->setFocusPolicy(Qt::StrongFocus);
        FrameRamManager->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(FrameRamManager);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FrameRamManager);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditFileName = new QLineEdit(FrameRamManager);
        lineEditFileName->setObjectName(QString::fromUtf8("lineEditFileName"));
        lineEditFileName->setMinimumSize(QSize(600, 0));

        horizontalLayout->addWidget(lineEditFileName);

        pushButtonReLoad = new QPushButton(FrameRamManager);
        pushButtonReLoad->setObjectName(QString::fromUtf8("pushButtonReLoad"));
        pushButtonReLoad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonReLoad->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButtonReLoad);


        verticalLayout_2->addLayout(horizontalLayout);

        tableViewData = new QTableView(FrameRamManager);
        tableViewData->setObjectName(QString::fromUtf8("tableViewData"));
        tableViewData->setFocusPolicy(Qt::NoFocus);
        tableViewData->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewData->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableViewData);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox1 = new QGroupBox(FrameRamManager);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        groupBox1->setMinimumSize(QSize(250, 0));
        groupBox1->setMaximumSize(QSize(250, 16777215));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        groupBox1->setFont(font1);
        pushButtonLoad = new QPushButton(groupBox1);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(20, 30, 100, 32));
        pushButtonLoad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonLoad->setFocusPolicy(Qt::NoFocus);
        pushButtonSave = new QPushButton(groupBox1);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(130, 30, 100, 32));
        pushButtonSave->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSave->setFocusPolicy(Qt::NoFocus);
        pushButtonWrite = new QPushButton(groupBox1);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setGeometry(QRect(20, 220, 100, 32));
        pushButtonWrite->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonWrite->setFocusPolicy(Qt::NoFocus);
        pushButtonRead = new QPushButton(groupBox1);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setGeometry(QRect(20, 270, 100, 32));
        pushButtonRead->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonRead->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(groupBox1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 111, 21));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDataAddr = new QLineEdit(groupBox1);
        lineEditDataAddr->setObjectName(QString::fromUtf8("lineEditDataAddr"));
        lineEditDataAddr->setGeometry(QRect(130, 150, 100, 20));
        lineEditDataAddr->setFont(font1);
        label_3 = new QLabel(groupBox1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 101, 21));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxDataCount = new QSpinBox(groupBox1);
        spinBoxDataCount->setObjectName(QString::fromUtf8("spinBoxDataCount"));
        spinBoxDataCount->setGeometry(QRect(130, 180, 101, 22));
        spinBoxDataCount->setMinimum(1);
        spinBoxDataCount->setMaximum(10000000);
        spinBoxDataCount->setValue(100);
        spinBoxDataCount->setDisplayIntegerBase(10);
        pushButtonGenData = new QPushButton(groupBox1);
        pushButtonGenData->setObjectName(QString::fromUtf8("pushButtonGenData"));
        pushButtonGenData->setGeometry(QRect(130, 220, 101, 32));
        pushButtonGenData->setFocusPolicy(Qt::NoFocus);
        pushButtonClearData = new QPushButton(groupBox1);
        pushButtonClearData->setObjectName(QString::fromUtf8("pushButtonClearData"));
        pushButtonClearData->setGeometry(QRect(130, 270, 101, 32));
        pushButtonClearData->setFocusPolicy(Qt::NoFocus);
        label_4 = new QLabel(groupBox1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 80, 91, 20));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxD = new QSpinBox(groupBox1);
        spinBoxD->setObjectName(QString::fromUtf8("spinBoxD"));
        spinBoxD->setGeometry(QRect(130, 80, 101, 22));
        spinBoxD->setMaximum(1024);
        spinBoxL = new QSpinBox(groupBox1);
        spinBoxL->setObjectName(QString::fromUtf8("spinBoxL"));
        spinBoxL->setGeometry(QRect(130, 110, 101, 22));
        spinBoxL->setMaximum(64);
        spinBoxL->setValue(13);
        label_5 = new QLabel(groupBox1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 110, 91, 20));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(groupBox1);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableViewFile = new QTableView(FrameRamManager);
        tableViewFile->setObjectName(QString::fromUtf8("tableViewFile"));
        tableViewFile->setFocusPolicy(Qt::NoFocus);
        tableViewFile->setAlternatingRowColors(false);
        tableViewFile->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewFile->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewFile->setWordWrap(false);
        tableViewFile->horizontalHeader()->setHighlightSections(false);
        tableViewFile->verticalHeader()->setHighlightSections(false);

        horizontalLayout_3->addWidget(tableViewFile);

        groupBox2 = new QGroupBox(FrameRamManager);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setMinimumSize(QSize(250, 0));
        groupBox2->setMaximumSize(QSize(250, 16777215));
        groupBox2->setFont(font1);
        pushButtonAddFile = new QPushButton(groupBox2);
        pushButtonAddFile->setObjectName(QString::fromUtf8("pushButtonAddFile"));
        pushButtonAddFile->setGeometry(QRect(130, 30, 100, 32));
        pushButtonAddFile->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddFile->setFocusPolicy(Qt::NoFocus);
        pushButtonRemoveFile = new QPushButton(groupBox2);
        pushButtonRemoveFile->setObjectName(QString::fromUtf8("pushButtonRemoveFile"));
        pushButtonRemoveFile->setGeometry(QRect(130, 70, 100, 32));
        pushButtonRemoveFile->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonRemoveFile->setFocusPolicy(Qt::NoFocus);
        pushButtonWriteFile = new QPushButton(groupBox2);
        pushButtonWriteFile->setObjectName(QString::fromUtf8("pushButtonWriteFile"));
        pushButtonWriteFile->setGeometry(QRect(20, 110, 100, 32));
        pushButtonWriteFile->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonWriteFile->setFocusPolicy(Qt::NoFocus);
        pushButtonOpenFile = new QPushButton(groupBox2);
        pushButtonOpenFile->setObjectName(QString::fromUtf8("pushButtonOpenFile"));
        pushButtonOpenFile->setGeometry(QRect(130, 110, 100, 32));
        pushButtonOpenFile->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonOpenFile->setFocusPolicy(Qt::NoFocus);
        checkBoxHexFile = new QCheckBox(groupBox2);
        checkBoxHexFile->setObjectName(QString::fromUtf8("checkBoxHexFile"));
        checkBoxHexFile->setGeometry(QRect(25, 30, 80, 22));
        checkBoxHexFile->setChecked(true);
        label_7 = new QLabel(groupBox2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(5, 58, 51, 22));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxLineCount = new QSpinBox(groupBox2);
        spinBoxLineCount->setObjectName(QString::fromUtf8("spinBoxLineCount"));
        spinBoxLineCount->setGeometry(QRect(55, 58, 65, 20));
        spinBoxLineCount->setMinimum(0);
        spinBoxLineCount->setMaximum(1000000);
        spinBoxLineCount->setValue(0);
        label_8 = new QLabel(groupBox2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(5, 85, 51, 22));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFileAddr = new QLineEdit(groupBox2);
        lineEditFileAddr->setObjectName(QString::fromUtf8("lineEditFileAddr"));
        lineEditFileAddr->setGeometry(QRect(55, 85, 65, 20));
        lineEditFileAddr->setFont(font1);
        label_6 = new QLabel(groupBox2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 160, 211, 16));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(groupBox2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 8);

        retranslateUi(FrameRamManager);

        QMetaObject::connectSlotsByName(FrameRamManager);
    } // setupUi

    void retranslateUi(QFrame *FrameRamManager)
    {
        FrameRamManager->setWindowTitle(QCoreApplication::translate("FrameRamManager", "Frame", nullptr));
        label->setText(QCoreApplication::translate("FrameRamManager", "\345\275\223\345\211\215\346\226\207\344\273\266\357\274\232", nullptr));
        pushButtonReLoad->setText(QCoreApplication::translate("FrameRamManager", "\351\207\215\346\226\260\350\275\275\345\205\245", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("FrameRamManager", "\346\225\260\346\215\256\345\235\227", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("FrameRamManager", "\346\211\223\345\274\200\346\226\207\344\273\266...", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FrameRamManager", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("FrameRamManager", "\345\206\231\345\205\245\350\256\276\345\244\207", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("FrameRamManager", "\344\273\216\350\256\276\345\244\207\350\257\273\345\217\226", nullptr));
        label_2->setText(QCoreApplication::translate("FrameRamManager", "\350\265\267\345\247\213\345\234\260\345\235\200(Hex):", nullptr));
        lineEditDataAddr->setText(QCoreApplication::translate("FrameRamManager", "0000", nullptr));
        label_3->setText(QCoreApplication::translate("FrameRamManager", "\350\257\273/\345\206\231\346\225\260\351\207\217:", nullptr));
        pushButtonGenData->setText(QCoreApplication::translate("FrameRamManager", "\347\224\237\346\210\220\351\232\217\346\234\272\346\225\260\346\215\256", nullptr));
        pushButtonClearData->setText(QCoreApplication::translate("FrameRamManager", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        label_4->setText(QCoreApplication::translate("FrameRamManager", "D:", nullptr));
        label_5->setText(QCoreApplication::translate("FrameRamManager", "\345\267\246\347\247\273:", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("FrameRamManager", "\346\226\207\344\273\266\346\223\215\344\275\234", nullptr));
        pushButtonAddFile->setText(QCoreApplication::translate("FrameRamManager", "\346\267\273\345\212\240\346\226\207\344\273\266...", nullptr));
        pushButtonRemoveFile->setText(QCoreApplication::translate("FrameRamManager", "\344\273\216\345\210\227\350\241\250\347\247\273\351\231\244", nullptr));
        pushButtonWriteFile->setText(QCoreApplication::translate("FrameRamManager", "\345\206\231\345\205\245\350\256\276\345\244\207", nullptr));
        pushButtonOpenFile->setText(QCoreApplication::translate("FrameRamManager", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        checkBoxHexFile->setText(QCoreApplication::translate("FrameRamManager", "HEX \346\240\274\345\274\217", nullptr));
        label_7->setText(QCoreApplication::translate("FrameRamManager", "\350\241\214\346\225\260\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("FrameRamManager", "\345\234\260\345\235\200\357\274\232", nullptr));
        lineEditFileAddr->setText(QCoreApplication::translate("FrameRamManager", "0000", nullptr));
        label_6->setText(QCoreApplication::translate("FrameRamManager", "\346\263\250\346\204\217\357\274\232\350\241\214\346\225\260\344\270\272 0 \350\241\250\347\244\272\346\225\264\344\270\252\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameRamManager: public Ui_FrameRamManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMERAMMANAGER_H
