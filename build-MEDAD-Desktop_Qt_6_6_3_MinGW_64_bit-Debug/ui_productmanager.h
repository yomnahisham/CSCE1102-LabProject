/********************************************************************************
** Form generated from reading UI file 'productmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGER_H
#define UI_PRODUCTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManager
{
public:
    QLabel *label;

    void setupUi(QWidget *ProductManager)
    {
        if (ProductManager->objectName().isEmpty())
            ProductManager->setObjectName("ProductManager");
        ProductManager->resize(854, 632);
        label = new QLabel(ProductManager);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 310, 171, 16));

        retranslateUi(ProductManager);

        QMetaObject::connectSlotsByName(ProductManager);
    } // setupUi

    void retranslateUi(QWidget *ProductManager)
    {
        ProductManager->setWindowTitle(QCoreApplication::translate("ProductManager", "Form", nullptr));
        label->setText(QCoreApplication::translate("ProductManager", "Reached Product manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManager: public Ui_ProductManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGER_H
