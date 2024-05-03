/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
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

    void setupUi(QWidget *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName("ShoppingCart");
        ShoppingCart->resize(633, 545);
        ShoppingCart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252);\n"
"color: rgb(0, 0, 0);"));
        cartTable = new QTableWidget(ShoppingCart);
        cartTable->setObjectName("cartTable");
        cartTable->setGeometry(QRect(150, 70, 301, 301));
        CheckOutButton = new QPushButton(ShoppingCart);
        CheckOutButton->setObjectName("CheckOutButton");
        CheckOutButton->setGeometry(QRect(350, 400, 171, 51));
        DeleteItem = new QPushButton(ShoppingCart);
        DeleteItem->setObjectName("DeleteItem");
        DeleteItem->setGeometry(QRect(100, 400, 141, 51));

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QWidget *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QCoreApplication::translate("ShoppingCart", "Form", nullptr));
        CheckOutButton->setText(QCoreApplication::translate("ShoppingCart", "Proceed to checkout", nullptr));
        DeleteItem->setText(QCoreApplication::translate("ShoppingCart", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
