/********************************************************************************
** Form generated from reading UI file 'FrameBLGammaPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEBLGAMMAPANEL_H
#define UI_FRAMEBLGAMMAPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_FrameBLGammaPanel
{
public:

    void setupUi(QFrame *FrameBLGammaPanel)
    {
        if (FrameBLGammaPanel->objectName().isEmpty())
            FrameBLGammaPanel->setObjectName(QString::fromUtf8("FrameBLGammaPanel"));
        FrameBLGammaPanel->resize(715, 532);
        FrameBLGammaPanel->setFocusPolicy(Qt::StrongFocus);

        retranslateUi(FrameBLGammaPanel);

        QMetaObject::connectSlotsByName(FrameBLGammaPanel);
    } // setupUi

    void retranslateUi(QFrame *FrameBLGammaPanel)
    {
        FrameBLGammaPanel->setWindowTitle(QCoreApplication::translate("FrameBLGammaPanel", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameBLGammaPanel: public Ui_FrameBLGammaPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEBLGAMMAPANEL_H
