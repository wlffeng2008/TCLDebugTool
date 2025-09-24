/********************************************************************************
** Form generated from reading UI file 'SerialTestDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALTESTDIALOG_H
#define UI_SERIALTESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SerialTestDialog
{
public:
    QLabel *label_1;
    QComboBox *comboBoxCOM;
    QPushButton *pushButtonScan;
    QTableView *tableView;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonSaveAs;
    QPushButton *pushButtonHide;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBoxBaud;
    QComboBox *comboBoxData;
    QLabel *label_4;
    QComboBox *comboBoxStop;
    QComboBox *comboBoxParity;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonSendAll;
    QCheckBox *checkBoxLoop;
    QLabel *label_7;
    QComboBox *comboBoxFlow;
    QCheckBox *checkBoxOpen;
    QLabel *labelStatus;
    QCheckBox *checkBoxHexCmd;
    QLabel *label_8;
    QRadioButton *radioButtonRegRead;
    QRadioButton *radioButtonRegWrite;
    QRadioButton *radioButtonRamWrite;
    QRadioButton *radioButtonRamRead;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEditAddr;
    QLineEdit *lineEditLen;
    QLabel *label_11;
    QLineEdit *lineEditWrite;
    QCheckBox *checkBoxHexData;
    QPushButton *pushButtonLog;
    QCheckBox *checkBoxReply;
    QLineEdit *lineEditReply;
    QTextEdit *textEditCommand;
    QCheckBox *checkBoxWriteNotify;
    QCheckBox *checkBoxHandShake;
    QFrame *line;
    QLabel *label_12;
    QSpinBox *spinBoxPackIndex;
    QCheckBox *checkBoxAutoCnnt;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *SerialTestDialog)
    {
        if (SerialTestDialog->objectName().isEmpty())
            SerialTestDialog->setObjectName("SerialTestDialog");
        SerialTestDialog->resize(660, 750);
        QFont font;
        font.setBold(true);
        SerialTestDialog->setFont(font);
        label_1 = new QLabel(SerialTestDialog);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(3, 10, 81, 22));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBoxCOM = new QComboBox(SerialTestDialog);
        comboBoxCOM->setObjectName("comboBoxCOM");
        comboBoxCOM->setGeometry(QRect(90, 10, 461, 24));
        comboBoxCOM->setEditable(false);
        pushButtonScan = new QPushButton(SerialTestDialog);
        pushButtonScan->setObjectName("pushButtonScan");
        pushButtonScan->setGeometry(QRect(560, 5, 81, 30));
        pushButtonScan->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonScan->setFocusPolicy(Qt::NoFocus);
        tableView = new QTableView(SerialTestDialog);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 180, 621, 381));
        QFont font1;
        font1.setBold(false);
        tableView->setFont(font1);
        tableView->setFocusPolicy(Qt::NoFocus);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(true);
        pushButtonLoad = new QPushButton(SerialTestDialog);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setGeometry(QRect(20, 140, 111, 30));
        pushButtonLoad->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonLoad->setFocusPolicy(Qt::NoFocus);
        pushButtonSave = new QPushButton(SerialTestDialog);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(140, 140, 81, 30));
        pushButtonSave->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSave->setFocusPolicy(Qt::NoFocus);
        pushButtonSaveAs = new QPushButton(SerialTestDialog);
        pushButtonSaveAs->setObjectName("pushButtonSaveAs");
        pushButtonSaveAs->setGeometry(QRect(230, 140, 101, 30));
        pushButtonSaveAs->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSaveAs->setFocusPolicy(Qt::NoFocus);
        pushButtonHide = new QPushButton(SerialTestDialog);
        pushButtonHide->setObjectName("pushButtonHide");
        pushButtonHide->setGeometry(QRect(560, 40, 81, 30));
        pushButtonHide->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonHide->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(SerialTestDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(13, 40, 71, 22));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(SerialTestDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(13, 70, 71, 22));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBoxBaud = new QComboBox(SerialTestDialog);
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->addItem(QString());
        comboBoxBaud->setObjectName("comboBoxBaud");
        comboBoxBaud->setGeometry(QRect(90, 40, 80, 24));
        comboBoxBaud->setMaxVisibleItems(30);
        comboBoxBaud->setMaxCount(30);
        comboBoxData = new QComboBox(SerialTestDialog);
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->addItem(QString());
        comboBoxData->setObjectName("comboBoxData");
        comboBoxData->setGeometry(QRect(250, 40, 80, 24));
        label_4 = new QLabel(SerialTestDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(173, 40, 71, 22));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBoxStop = new QComboBox(SerialTestDialog);
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->addItem(QString());
        comboBoxStop->setObjectName("comboBoxStop");
        comboBoxStop->setGeometry(QRect(90, 70, 80, 24));
        comboBoxParity = new QComboBox(SerialTestDialog);
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->setObjectName("comboBoxParity");
        comboBoxParity->setGeometry(QRect(250, 70, 80, 24));
        label_5 = new QLabel(SerialTestDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 70, 64, 22));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(SerialTestDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(-1, 630, 71, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonNew = new QPushButton(SerialTestDialog);
        pushButtonNew->setObjectName("pushButtonNew");
        pushButtonNew->setGeometry(QRect(400, 710, 151, 30));
        pushButtonNew->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonNew->setFocusPolicy(Qt::NoFocus);
        pushButtonDel = new QPushButton(SerialTestDialog);
        pushButtonDel->setObjectName("pushButtonDel");
        pushButtonDel->setGeometry(QRect(560, 710, 81, 30));
        pushButtonDel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonDel->setFocusPolicy(Qt::NoFocus);
        pushButtonSend = new QPushButton(SerialTestDialog);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setGeometry(QRect(70, 710, 101, 30));
        pushButtonSend->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSend->setFocusPolicy(Qt::NoFocus);
        pushButtonSendAll = new QPushButton(SerialTestDialog);
        pushButtonSendAll->setObjectName("pushButtonSendAll");
        pushButtonSendAll->setEnabled(false);
        pushButtonSendAll->setGeometry(QRect(210, 710, 101, 30));
        pushButtonSendAll->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        checkBoxLoop = new QCheckBox(SerialTestDialog);
        checkBoxLoop->setObjectName("checkBoxLoop");
        checkBoxLoop->setEnabled(false);
        checkBoxLoop->setGeometry(QRect(320, 710, 80, 30));
        checkBoxLoop->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_7 = new QLabel(SerialTestDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(13, 100, 71, 22));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBoxFlow = new QComboBox(SerialTestDialog);
        comboBoxFlow->addItem(QString());
        comboBoxFlow->addItem(QString());
        comboBoxFlow->addItem(QString());
        comboBoxFlow->setObjectName("comboBoxFlow");
        comboBoxFlow->setGeometry(QRect(90, 100, 80, 24));
        checkBoxOpen = new QCheckBox(SerialTestDialog);
        checkBoxOpen->setObjectName("checkBoxOpen");
        checkBoxOpen->setGeometry(QRect(338, 40, 111, 24));
        checkBoxOpen->setMinimumSize(QSize(81, 0));
        checkBoxOpen->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        labelStatus = new QLabel(SerialTestDialog);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(460, 40, 91, 24));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        labelStatus->setFont(font2);
        checkBoxHexCmd = new QCheckBox(SerialTestDialog);
        checkBoxHexCmd->setObjectName("checkBoxHexCmd");
        checkBoxHexCmd->setEnabled(true);
        checkBoxHexCmd->setGeometry(QRect(560, 630, 91, 20));
        checkBoxHexCmd->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_8 = new QLabel(SerialTestDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 570, 71, 20));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radioButtonRegRead = new QRadioButton(SerialTestDialog);
        buttonGroup = new QButtonGroup(SerialTestDialog);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButtonRegRead);
        radioButtonRegRead->setObjectName("radioButtonRegRead");
        radioButtonRegRead->setGeometry(QRect(70, 570, 71, 20));
        radioButtonRegRead->setMinimumSize(QSize(71, 0));
        radioButtonRegRead->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        radioButtonRegRead->setChecked(true);
        radioButtonRegWrite = new QRadioButton(SerialTestDialog);
        buttonGroup->addButton(radioButtonRegWrite);
        radioButtonRegWrite->setObjectName("radioButtonRegWrite");
        radioButtonRegWrite->setGeometry(QRect(150, 570, 71, 20));
        radioButtonRegWrite->setMinimumSize(QSize(71, 0));
        radioButtonRegWrite->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        radioButtonRamWrite = new QRadioButton(SerialTestDialog);
        buttonGroup->addButton(radioButtonRamWrite);
        radioButtonRamWrite->setObjectName("radioButtonRamWrite");
        radioButtonRamWrite->setGeometry(QRect(310, 570, 71, 20));
        radioButtonRamWrite->setMinimumSize(QSize(71, 0));
        radioButtonRamWrite->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        radioButtonRamRead = new QRadioButton(SerialTestDialog);
        buttonGroup->addButton(radioButtonRamRead);
        radioButtonRamRead->setObjectName("radioButtonRamRead");
        radioButtonRamRead->setGeometry(QRect(230, 570, 71, 20));
        radioButtonRamRead->setMinimumSize(QSize(71, 0));
        radioButtonRamRead->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_9 = new QLabel(SerialTestDialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(390, 570, 41, 20));
        label_10 = new QLabel(SerialTestDialog);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(520, 570, 41, 20));
        lineEditAddr = new QLineEdit(SerialTestDialog);
        lineEditAddr->setObjectName("lineEditAddr");
        lineEditAddr->setGeometry(QRect(429, 570, 81, 20));
        lineEditAddr->setMaxLength(8);
        lineEditLen = new QLineEdit(SerialTestDialog);
        lineEditLen->setObjectName("lineEditLen");
        lineEditLen->setGeometry(QRect(560, 570, 81, 20));
        lineEditLen->setMaxLength(5);
        label_11 = new QLabel(SerialTestDialog);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 600, 71, 20));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditWrite = new QLineEdit(SerialTestDialog);
        lineEditWrite->setObjectName("lineEditWrite");
        lineEditWrite->setGeometry(QRect(70, 600, 481, 20));
        checkBoxHexData = new QCheckBox(SerialTestDialog);
        checkBoxHexData->setObjectName("checkBoxHexData");
        checkBoxHexData->setEnabled(true);
        checkBoxHexData->setGeometry(QRect(560, 600, 91, 20));
        checkBoxHexData->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonLog = new QPushButton(SerialTestDialog);
        pushButtonLog->setObjectName("pushButtonLog");
        pushButtonLog->setGeometry(QRect(499, 140, 141, 30));
        pushButtonLog->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonLog->setFocusPolicy(Qt::NoFocus);
        checkBoxReply = new QCheckBox(SerialTestDialog);
        checkBoxReply->setObjectName("checkBoxReply");
        checkBoxReply->setGeometry(QRect(338, 100, 161, 24));
        checkBoxReply->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lineEditReply = new QLineEdit(SerialTestDialog);
        lineEditReply->setObjectName("lineEditReply");
        lineEditReply->setGeometry(QRect(500, 100, 51, 22));
        lineEditReply->setMaxLength(5);
        textEditCommand = new QTextEdit(SerialTestDialog);
        textEditCommand->setObjectName("textEditCommand");
        textEditCommand->setGeometry(QRect(70, 630, 481, 71));
        checkBoxWriteNotify = new QCheckBox(SerialTestDialog);
        checkBoxWriteNotify->setObjectName("checkBoxWriteNotify");
        checkBoxWriteNotify->setGeometry(QRect(338, 140, 161, 24));
        checkBoxWriteNotify->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        checkBoxHandShake = new QCheckBox(SerialTestDialog);
        checkBoxHandShake->setObjectName("checkBoxHandShake");
        checkBoxHandShake->setGeometry(QRect(338, 70, 211, 24));
        checkBoxHandShake->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        line = new QFrame(SerialTestDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 125, 621, 16));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_12 = new QLabel(SerialTestDialog);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(560, 660, 81, 20));
        spinBoxPackIndex = new QSpinBox(SerialTestDialog);
        spinBoxPackIndex->setObjectName("spinBoxPackIndex");
        spinBoxPackIndex->setGeometry(QRect(560, 680, 81, 22));
        spinBoxPackIndex->setMaximum(255);
        checkBoxAutoCnnt = new QCheckBox(SerialTestDialog);
        checkBoxAutoCnnt->setObjectName("checkBoxAutoCnnt");
        checkBoxAutoCnnt->setGeometry(QRect(190, 100, 141, 21));
        checkBoxAutoCnnt->setMinimumSize(QSize(81, 0));
        checkBoxAutoCnnt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        retranslateUi(SerialTestDialog);

        comboBoxBaud->setCurrentIndex(7);
        comboBoxData->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SerialTestDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialTestDialog)
    {
        SerialTestDialog->setWindowTitle(QCoreApplication::translate("SerialTestDialog", "\344\270\262\345\217\243\346\265\213\350\257\225 [\351\273\230\350\256\244\345\221\275\344\273\244]", nullptr));
        label_1->setText(QCoreApplication::translate("SerialTestDialog", "\344\270\262\345\217\243\351\200\211\346\213\251\357\274\232", nullptr));
        pushButtonScan->setText(QCoreApplication::translate("SerialTestDialog", "\345\210\267\346\226\260", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("SerialTestDialog", "\350\275\275\345\205\245\345\221\275\344\273\244\346\226\207\344\273\266...", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("SerialTestDialog", "\344\277\235\345\255\230", nullptr));
        pushButtonSaveAs->setText(QCoreApplication::translate("SerialTestDialog", "\345\217\246\345\255\230\344\270\272...", nullptr));
        pushButtonHide->setText(QCoreApplication::translate("SerialTestDialog", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("SerialTestDialog", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("SerialTestDialog", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBoxBaud->setItemText(0, QCoreApplication::translate("SerialTestDialog", "1200", nullptr));
        comboBoxBaud->setItemText(1, QCoreApplication::translate("SerialTestDialog", "2400", nullptr));
        comboBoxBaud->setItemText(2, QCoreApplication::translate("SerialTestDialog", "4800", nullptr));
        comboBoxBaud->setItemText(3, QCoreApplication::translate("SerialTestDialog", "9600", nullptr));
        comboBoxBaud->setItemText(4, QCoreApplication::translate("SerialTestDialog", "19200", nullptr));
        comboBoxBaud->setItemText(5, QCoreApplication::translate("SerialTestDialog", "38400", nullptr));
        comboBoxBaud->setItemText(6, QCoreApplication::translate("SerialTestDialog", "57600", nullptr));
        comboBoxBaud->setItemText(7, QCoreApplication::translate("SerialTestDialog", "115200", nullptr));
        comboBoxBaud->setItemText(8, QCoreApplication::translate("SerialTestDialog", "128000", nullptr));
        comboBoxBaud->setItemText(9, QCoreApplication::translate("SerialTestDialog", "230400", nullptr));
        comboBoxBaud->setItemText(10, QCoreApplication::translate("SerialTestDialog", "256000", nullptr));
        comboBoxBaud->setItemText(11, QCoreApplication::translate("SerialTestDialog", "460800", nullptr));
        comboBoxBaud->setItemText(12, QCoreApplication::translate("SerialTestDialog", "500000", nullptr));
        comboBoxBaud->setItemText(13, QCoreApplication::translate("SerialTestDialog", "512000", nullptr));
        comboBoxBaud->setItemText(14, QCoreApplication::translate("SerialTestDialog", "600000", nullptr));
        comboBoxBaud->setItemText(15, QCoreApplication::translate("SerialTestDialog", "750000", nullptr));
        comboBoxBaud->setItemText(16, QCoreApplication::translate("SerialTestDialog", "921600", nullptr));
        comboBoxBaud->setItemText(17, QCoreApplication::translate("SerialTestDialog", "1000000", nullptr));
        comboBoxBaud->setItemText(18, QCoreApplication::translate("SerialTestDialog", "1500000", nullptr));
        comboBoxBaud->setItemText(19, QCoreApplication::translate("SerialTestDialog", "2000000", nullptr));

        comboBoxBaud->setCurrentText(QCoreApplication::translate("SerialTestDialog", "115200", nullptr));
        comboBoxData->setItemText(0, QCoreApplication::translate("SerialTestDialog", "5", nullptr));
        comboBoxData->setItemText(1, QCoreApplication::translate("SerialTestDialog", "6", nullptr));
        comboBoxData->setItemText(2, QCoreApplication::translate("SerialTestDialog", "7", nullptr));
        comboBoxData->setItemText(3, QCoreApplication::translate("SerialTestDialog", "8", nullptr));

        comboBoxData->setCurrentText(QCoreApplication::translate("SerialTestDialog", "8", nullptr));
        label_4->setText(QCoreApplication::translate("SerialTestDialog", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        comboBoxStop->setItemText(0, QCoreApplication::translate("SerialTestDialog", "1", nullptr));
        comboBoxStop->setItemText(1, QCoreApplication::translate("SerialTestDialog", "1.5", nullptr));
        comboBoxStop->setItemText(2, QCoreApplication::translate("SerialTestDialog", "2", nullptr));

        comboBoxParity->setItemText(0, QCoreApplication::translate("SerialTestDialog", "\346\227\240", nullptr));
        comboBoxParity->setItemText(1, QCoreApplication::translate("SerialTestDialog", "\345\201\266\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(2, QCoreApplication::translate("SerialTestDialog", "\345\245\207\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(3, QCoreApplication::translate("SerialTestDialog", "\347\251\272\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(4, QCoreApplication::translate("SerialTestDialog", "\346\216\251\347\240\201", nullptr));

        label_5->setText(QCoreApplication::translate("SerialTestDialog", "\346\240\241\351\252\214\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("SerialTestDialog", "\345\221\275\344\273\244\357\274\232", nullptr));
        pushButtonNew->setText(QCoreApplication::translate("SerialTestDialog", "\346\267\273\345\212\240\345\221\275\344\273\244\345\210\260\345\210\227\350\241\250 \342\206\221", nullptr));
        pushButtonDel->setText(QCoreApplication::translate("SerialTestDialog", "\345\210\240\351\231\244\345\221\275\344\273\244", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("SerialTestDialog", "\345\217\221\351\200\201\345\215\225\346\235\241\345\221\275\344\273\244", nullptr));
        pushButtonSendAll->setText(QCoreApplication::translate("SerialTestDialog", "\345\217\221\351\200\201\345\244\232\346\235\241\345\221\275\344\273\244", nullptr));
        checkBoxLoop->setText(QCoreApplication::translate("SerialTestDialog", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        label_7->setText(QCoreApplication::translate("SerialTestDialog", "\346\265\201\346\216\247\357\274\232", nullptr));
        comboBoxFlow->setItemText(0, QCoreApplication::translate("SerialTestDialog", "\346\227\240", nullptr));
        comboBoxFlow->setItemText(1, QCoreApplication::translate("SerialTestDialog", "\347\241\254\344\273\266", nullptr));
        comboBoxFlow->setItemText(2, QCoreApplication::translate("SerialTestDialog", "\350\275\257\344\273\266", nullptr));

        checkBoxOpen->setText(QCoreApplication::translate("SerialTestDialog", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        labelStatus->setText(QCoreApplication::translate("SerialTestDialog", "\344\270\262\345\217\243\346\234\252\346\211\223\345\274\200", nullptr));
        checkBoxHexCmd->setText(QCoreApplication::translate("SerialTestDialog", "Hex Cmd", nullptr));
        label_8->setText(QCoreApplication::translate("SerialTestDialog", "\345\214\205\347\261\273\345\236\213\357\274\232", nullptr));
        radioButtonRegRead->setText(QCoreApplication::translate("SerialTestDialog", "\350\257\273Reg", nullptr));
        radioButtonRegWrite->setText(QCoreApplication::translate("SerialTestDialog", "\345\206\231Reg", nullptr));
        radioButtonRamWrite->setText(QCoreApplication::translate("SerialTestDialog", "\345\206\231Ram", nullptr));
        radioButtonRamRead->setText(QCoreApplication::translate("SerialTestDialog", "\350\257\273Ram", nullptr));
        label_9->setText(QCoreApplication::translate("SerialTestDialog", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("SerialTestDialog", "\351\225\277\345\272\246\357\274\232", nullptr));
        lineEditAddr->setText(QCoreApplication::translate("SerialTestDialog", "0000", nullptr));
        lineEditLen->setText(QCoreApplication::translate("SerialTestDialog", "32", nullptr));
        label_11->setText(QCoreApplication::translate("SerialTestDialog", "\345\206\231\346\225\260\346\215\256\357\274\232", nullptr));
        checkBoxHexData->setText(QCoreApplication::translate("SerialTestDialog", "Hex Data", nullptr));
        pushButtonLog->setText(QCoreApplication::translate("SerialTestDialog", "Log View ..", nullptr));
        checkBoxReply->setText(QCoreApplication::translate("SerialTestDialog", "\345\274\271\346\241\206\350\255\246\347\244\272\345\272\224\347\255\224\350\266\205\346\227\266(ms)", nullptr));
        lineEditReply->setText(QCoreApplication::translate("SerialTestDialog", "1500", nullptr));
        checkBoxWriteNotify->setText(QCoreApplication::translate("SerialTestDialog", "\345\274\271\346\241\206\346\217\220\347\244\272\346\225\260\346\215\256\345\206\231\345\205\245\347\273\223\346\236\234", nullptr));
        checkBoxHandShake->setText(QCoreApplication::translate("SerialTestDialog", "\344\270\262\345\217\243\346\211\223\345\274\200\345\220\216\345\217\221\351\200\201\346\217\241\346\211\213\346\214\207\344\273\244", nullptr));
        label_12->setText(QCoreApplication::translate("SerialTestDialog", "Pack Index\357\274\232", nullptr));
        checkBoxAutoCnnt->setText(QCoreApplication::translate("SerialTestDialog", "\345\210\267\346\226\260\346\227\266\350\207\252\345\212\250\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialTestDialog: public Ui_SerialTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALTESTDIALOG_H
