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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManager
{
public:
    QLabel *logoCorner;
    QLabel *logoSub;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *recsLayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *allproductsLayout;
    QLineEdit *searchLineEdit;
    QLabel *basedonyouLogo;
    QLabel *basedonsearchLogo;
    QComboBox *filterBox;
    QPushButton *addProductB;
    QPushButton *addAdminB;
    QLabel *ourproductsLogo;

    void setupUi(QWidget *ProductManager)
    {
        if (ProductManager->objectName().isEmpty())
            ProductManager->setObjectName("ProductManager");
        ProductManager->resize(1431, 936);
        ProductManager->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252)\n"
"\n"
""));
        logoCorner = new QLabel(ProductManager);
        logoCorner->setObjectName("logoCorner");
        logoCorner->setGeometry(QRect(0, 20, 221, 61));
        logoSub = new QLabel(ProductManager);
        logoSub->setObjectName("logoSub");
        logoSub->setGeometry(QRect(80, 100, 171, 31));
        horizontalLayoutWidget = new QWidget(ProductManager);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 190, 1231, 751));
        recsLayout = new QHBoxLayout(horizontalLayoutWidget);
        recsLayout->setObjectName("recsLayout");
        recsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(ProductManager);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(60, 520, 1231, 451));
        allproductsLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        allproductsLayout->setObjectName("allproductsLayout");
        allproductsLayout->setContentsMargins(0, 0, 0, 0);
        searchLineEdit = new QLineEdit(ProductManager);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(780, 120, 421, 21));
        searchLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252); color:  black;"));
        basedonyouLogo = new QLabel(ProductManager);
        basedonyouLogo->setObjectName("basedonyouLogo");
        basedonyouLogo->setGeometry(QRect(150, 120, 381, 61));
        basedonsearchLogo = new QLabel(ProductManager);
        basedonsearchLogo->setObjectName("basedonsearchLogo");
        basedonsearchLogo->setGeometry(QRect(560, 140, 311, 41));
        filterBox = new QComboBox(ProductManager);
        filterBox->addItem(QString());
        filterBox->addItem(QString());
        filterBox->addItem(QString());
        filterBox->addItem(QString());
        filterBox->addItem(QString());
        filterBox->addItem(QString());
        filterBox->setObjectName("filterBox");
        filterBox->setGeometry(QRect(1210, 120, 161, 21));
        filterBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252); color: black;"));
        addProductB = new QPushButton(ProductManager);
        addProductB->setObjectName("addProductB");
        addProductB->setGeometry(QRect(580, 30, 100, 32));
        addProductB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        addAdminB = new QPushButton(ProductManager);
        addAdminB->setObjectName("addAdminB");
        addAdminB->setGeometry(QRect(760, 30, 100, 32));
        addAdminB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ourproductsLogo = new QLabel(ProductManager);
        ourproductsLogo->setObjectName("ourproductsLogo");
        ourproductsLogo->setGeometry(QRect(60, 490, 111, 31));
        logoCorner->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        basedonyouLogo->raise();
        basedonsearchLogo->raise();
        searchLineEdit->raise();
        filterBox->raise();
        addProductB->raise();
        addAdminB->raise();
        logoSub->raise();
        ourproductsLogo->raise();

        retranslateUi(ProductManager);

        QMetaObject::connectSlotsByName(ProductManager);
    } // setupUi

    void retranslateUi(QWidget *ProductManager)
    {
        ProductManager->setWindowTitle(QCoreApplication::translate("ProductManager", "Form", nullptr));
        logoCorner->setText(QCoreApplication::translate("ProductManager", "MEDAD LOGO", nullptr));
        logoSub->setText(QCoreApplication::translate("ProductManager", "subtitle", nullptr));
        searchLineEdit->setText(QCoreApplication::translate("ProductManager", "Search...", nullptr));
        basedonyouLogo->setText(QCoreApplication::translate("ProductManager", "your preferences", nullptr));
        basedonsearchLogo->setText(QCoreApplication::translate("ProductManager", "your search", nullptr));
        filterBox->setItemText(0, QCoreApplication::translate("ProductManager", "Filter", nullptr));
        filterBox->setItemText(1, QCoreApplication::translate("ProductManager", "Lowest to Highest Price", nullptr));
        filterBox->setItemText(2, QCoreApplication::translate("ProductManager", "Highest to Lowest Price", nullptr));
        filterBox->setItemText(3, QCoreApplication::translate("ProductManager", "A-Z", nullptr));
        filterBox->setItemText(4, QCoreApplication::translate("ProductManager", "Z-A", nullptr));
        filterBox->setItemText(5, QString());

        addProductB->setText(QCoreApplication::translate("ProductManager", "Add Product", nullptr));
        addAdminB->setText(QCoreApplication::translate("ProductManager", "Add Admin", nullptr));
        ourproductsLogo->setText(QCoreApplication::translate("ProductManager", "all prod", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManager: public Ui_ProductManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGER_H
