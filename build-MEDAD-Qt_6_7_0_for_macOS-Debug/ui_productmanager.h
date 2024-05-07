/********************************************************************************
** Form generated from reading UI file 'productmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
    QPushButton *addProductButton;
    QLabel *ourproductsLogo;
    QLabel *XLogo;
    QLabel *sellerLogo;

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
        horizontalLayoutWidget->setGeometry(QRect(70, 180, 1231, 651));
        recsLayout = new QHBoxLayout(horizontalLayoutWidget);
        recsLayout->setObjectName("recsLayout");
        recsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(ProductManager);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(60, 520, 1231, 311));
        allproductsLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        allproductsLayout->setObjectName("allproductsLayout");
        allproductsLayout->setContentsMargins(0, 0, 0, 0);
        searchLineEdit = new QLineEdit(ProductManager);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(780, 120, 421, 21));
        searchLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252); color:  black;"));
        basedonyouLogo = new QLabel(ProductManager);
        basedonyouLogo->setObjectName("basedonyouLogo");
        basedonyouLogo->setGeometry(QRect(120, 130, 381, 41));
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
        filterBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252); color: black;\n"
"font: italic 13pt \"Helvetica\";"));
        addProductButton = new QPushButton(ProductManager);
        addProductButton->setObjectName("addProductButton");
        addProductButton->setGeometry(QRect(580, 30, 100, 32));
        addProductButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ourproductsLogo = new QLabel(ProductManager);
        ourproductsLogo->setObjectName("ourproductsLogo");
        ourproductsLogo->setGeometry(QRect(60, 480, 111, 31));
        XLogo = new QLabel(ProductManager);
        XLogo->setObjectName("XLogo");
        XLogo->setGeometry(QRect(240, 60, 16, 51));
        XLogo->setStyleSheet(QString::fromUtf8(""));
        sellerLogo = new QLabel(ProductManager);
        sellerLogo->setObjectName("sellerLogo");
        sellerLogo->setGeometry(QRect(270, 50, 291, 91));
        sellerLogo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0)"));
        logoCorner->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        basedonyouLogo->raise();
        basedonsearchLogo->raise();
        searchLineEdit->raise();
        filterBox->raise();
        addProductButton->raise();
        logoSub->raise();
        ourproductsLogo->raise();
        XLogo->raise();
        sellerLogo->raise();

        retranslateUi(ProductManager);

        QMetaObject::connectSlotsByName(ProductManager);
    } // setupUi

    void retranslateUi(QWidget *ProductManager)
    {
        ProductManager->setWindowTitle(QCoreApplication::translate("ProductManager", "Form", nullptr));
        logoCorner->setText(QCoreApplication::translate("ProductManager", "MEDAD LOGO", nullptr));
        logoSub->setText(QCoreApplication::translate("ProductManager", "subtitle", nullptr));
        searchLineEdit->setText(QString());
        basedonyouLogo->setText(QCoreApplication::translate("ProductManager", "your preferences", nullptr));
        basedonsearchLogo->setText(QCoreApplication::translate("ProductManager", "your search", nullptr));
        filterBox->setItemText(0, QCoreApplication::translate("ProductManager", "Filter", nullptr));
        filterBox->setItemText(1, QCoreApplication::translate("ProductManager", "Lowest to Highest Price", nullptr));
        filterBox->setItemText(2, QCoreApplication::translate("ProductManager", "Highest to Lowest Price", nullptr));
        filterBox->setItemText(3, QCoreApplication::translate("ProductManager", "A-Z", nullptr));
        filterBox->setItemText(4, QCoreApplication::translate("ProductManager", "Z-A", nullptr));
        filterBox->setItemText(5, QString());

        addProductButton->setText(QCoreApplication::translate("ProductManager", "Add Product", nullptr));
        ourproductsLogo->setText(QCoreApplication::translate("ProductManager", "all prod", nullptr));
        XLogo->setText(QCoreApplication::translate("ProductManager", "X", nullptr));
        sellerLogo->setText(QCoreApplication::translate("ProductManager", "SellerLogo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManager: public Ui_ProductManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGER_H
