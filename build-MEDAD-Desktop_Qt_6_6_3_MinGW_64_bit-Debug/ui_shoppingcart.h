/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShoppingCart
{
public:
    QTableWidget *cartTable;
    QPushButton *CheckOutButton;
    QPushButton *DeleteItem;
    QLabel *ShoppingCartLogo;

    void setupUi(QWidget *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName("ShoppingCart");
        ShoppingCart->resize(1129, 676);
        ShoppingCart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252);\n"
"color: rgb(0, 0, 0);"));
        cartTable = new QTableWidget(ShoppingCart);
        cartTable->setObjectName("cartTable");
        cartTable->setGeometry(QRect(50, 110, 521, 451));
        cartTable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(252, 255, 198);\n"
""));
        CheckOutButton = new QPushButton(ShoppingCart);
        CheckOutButton->setObjectName("CheckOutButton");
        CheckOutButton->setGeometry(QRect(730, 270, 171, 51));
        CheckOutButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        DeleteItem = new QPushButton(ShoppingCart);
        DeleteItem->setObjectName("DeleteItem");
        DeleteItem->setGeometry(QRect(730, 170, 171, 51));
        DeleteItem->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        ShoppingCartLogo = new QLabel(ShoppingCart);
        ShoppingCartLogo->setObjectName("ShoppingCartLogo");
        ShoppingCartLogo->setGeometry(QRect(40, 30, 151, 41));

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QWidget *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QCoreApplication::translate("ShoppingCart", "Form", nullptr));
        CheckOutButton->setText(QCoreApplication::translate("ShoppingCart", "Proceed to checkout", nullptr));
        DeleteItem->setText(QCoreApplication::translate("ShoppingCart", "Delete", nullptr));
        ShoppingCartLogo->setText(QCoreApplication::translate("ShoppingCart", "ShoppingCartLogo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
