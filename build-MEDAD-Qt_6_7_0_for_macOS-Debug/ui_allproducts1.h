/********************************************************************************
** Form generated from reading UI file 'allproducts1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLPRODUCTS1_H
#define UI_ALLPRODUCTS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllProducts1
{
public:
    QLabel *logo;
    QLabel *sublogo;
    QComboBox *filter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *firstlayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *secondlayout;

    void setupUi(QDialog *AllProducts1)
    {
        if (AllProducts1->objectName().isEmpty())
            AllProducts1->setObjectName("AllProducts1");
        AllProducts1->resize(1110, 609);
        AllProducts1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252)\n"
""));
        logo = new QLabel(AllProducts1);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 10, 111, 51));
        sublogo = new QLabel(AllProducts1);
        sublogo->setObjectName("sublogo");
        sublogo->setGeometry(QRect(90, 70, 81, 31));
        filter = new QComboBox(AllProducts1);
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->setObjectName("filter");
        filter->setGeometry(QRect(970, 30, 80, 26));
        horizontalLayoutWidget = new QWidget(AllProducts1);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 140, 1051, 211));
        firstlayout = new QHBoxLayout(horizontalLayoutWidget);
        firstlayout->setObjectName("firstlayout");
        firstlayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(AllProducts1);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 380, 1051, 211));
        secondlayout = new QHBoxLayout(horizontalLayoutWidget_2);
        secondlayout->setObjectName("secondlayout");
        secondlayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(AllProducts1);

        QMetaObject::connectSlotsByName(AllProducts1);
    } // setupUi

    void retranslateUi(QDialog *AllProducts1)
    {
        AllProducts1->setWindowTitle(QCoreApplication::translate("AllProducts1", "Dialog", nullptr));
        logo->setText(QCoreApplication::translate("AllProducts1", "TextLabel", nullptr));
        sublogo->setText(QCoreApplication::translate("AllProducts1", "TextLabel", nullptr));
        filter->setItemText(0, QCoreApplication::translate("AllProducts1", "filter", nullptr));
        filter->setItemText(1, QCoreApplication::translate("AllProducts1", "Highest to Lowest Price", nullptr));
        filter->setItemText(2, QCoreApplication::translate("AllProducts1", "Lowest to Highest Price", nullptr));
        filter->setItemText(3, QCoreApplication::translate("AllProducts1", "A-Z", nullptr));
        filter->setItemText(4, QCoreApplication::translate("AllProducts1", "Z-A", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AllProducts1: public Ui_AllProducts1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPRODUCTS1_H
