/********************************************************************************
** Form generated from reading UI file 'FrameEPCCPanel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEEPCCPANEL_H
#define UI_FRAMEEPCCPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_FrameEPCCPanel
{
public:

    void setupUi(QFrame *FrameEPCCPanel)
    {
        if (FrameEPCCPanel->objectName().isEmpty())
            FrameEPCCPanel->setObjectName("FrameEPCCPanel");
        FrameEPCCPanel->resize(1002, 753);

        retranslateUi(FrameEPCCPanel);

        QMetaObject::connectSlotsByName(FrameEPCCPanel);
    } // setupUi

    void retranslateUi(QFrame *FrameEPCCPanel)
    {
        FrameEPCCPanel->setWindowTitle(QCoreApplication::translate("FrameEPCCPanel", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameEPCCPanel: public Ui_FrameEPCCPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEEPCCPANEL_H
