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
    QLabel *logoCorner;
    QLabel *logoSub;

    void setupUi(QWidget *ProductManager)
    {
        if (ProductManager->objectName().isEmpty())
            ProductManager->setObjectName("ProductManager");
        ProductManager->resize(1041, 637);
        ProductManager->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
""));
        logoCorner = new QLabel(ProductManager);
        logoCorner->setObjectName("logoCorner");
        logoCorner->setGeometry(QRect(0, 20, 221, 61));
        logoSub = new QLabel(ProductManager);
        logoSub->setObjectName("logoSub");
        logoSub->setGeometry(QRect(80, 100, 171, 31));

        retranslateUi(ProductManager);

        QMetaObject::connectSlotsByName(ProductManager);
    } // setupUi

    void retranslateUi(QWidget *ProductManager)
    {
        ProductManager->setWindowTitle(QCoreApplication::translate("ProductManager", "Form", nullptr));
        logoCorner->setText(QCoreApplication::translate("ProductManager", "MEDAD LOGO", nullptr));
        logoSub->setText(QCoreApplication::translate("ProductManager", "subtitle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManager: public Ui_ProductManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGER_H
