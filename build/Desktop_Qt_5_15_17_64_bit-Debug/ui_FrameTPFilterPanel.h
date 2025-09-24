/********************************************************************************
** Form generated from reading UI file 'FrameTPFilterPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMETPFILTERPANEL_H
#define UI_FRAMETPFILTERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_FrameTPFilterPanel
{
public:

    void setupUi(QFrame *FrameTPFilterPanel)
    {
        if (FrameTPFilterPanel->objectName().isEmpty())
            FrameTPFilterPanel->setObjectName(QString::fromUtf8("FrameTPFilterPanel"));
        FrameTPFilterPanel->resize(400, 300);

        retranslateUi(FrameTPFilterPanel);

        QMetaObject::connectSlotsByName(FrameTPFilterPanel);
    } // setupUi

    void retranslateUi(QFrame *FrameTPFilterPanel)
    {
        FrameTPFilterPanel->setWindowTitle(QCoreApplication::translate("FrameTPFilterPanel", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameTPFilterPanel: public Ui_FrameTPFilterPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMETPFILTERPANEL_H
