/********************************************************************************
** Form generated from reading UI file 'checkout.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUT_H
#define UI_CHECKOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkout
{
public:

    void setupUi(QWidget *Checkout)
    {
        if (Checkout->objectName().isEmpty())
            Checkout->setObjectName("Checkout");
        Checkout->resize(400, 300);

        retranslateUi(Checkout);

        QMetaObject::connectSlotsByName(Checkout);
    } // setupUi

    void retranslateUi(QWidget *Checkout)
    {
        Checkout->setWindowTitle(QCoreApplication::translate("Checkout", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkout: public Ui_Checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUT_H
