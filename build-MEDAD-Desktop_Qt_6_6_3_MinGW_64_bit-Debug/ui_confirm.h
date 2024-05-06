/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confirm
{
public:
    QWidget *ConfirmWidget;
    QLabel *OrderPlacedLabel;
    QGroupBox *groupBox;
    QLabel *SubTotalLabel;
    QLabel *DeliveryLabel;
    QLabel *TotalLabel;
    QLabel *DeliveringToLabel;
    QLabel *AddressLabel;
    QLabel *PaymentMethodLabel;
    QLabel *PaymentMethod;
    QLabel *DelievryDateLabel;
    QLabel *DeliveryDate;
    QPushButton *pushButton;

    void setupUi(QWidget *Confirm)
    {
        if (Confirm->objectName().isEmpty())
            Confirm->setObjectName("Confirm");
        Confirm->resize(1278, 754);
        Confirm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ConfirmWidget = new QWidget(Confirm);
        ConfirmWidget->setObjectName("ConfirmWidget");
        ConfirmWidget->setGeometry(QRect(320, 70, 741, 621));
        OrderPlacedLabel = new QLabel(ConfirmWidget);
        OrderPlacedLabel->setObjectName("OrderPlacedLabel");
        OrderPlacedLabel->setGeometry(QRect(70, 50, 641, 51));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        OrderPlacedLabel->setFont(font);
        OrderPlacedLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox = new QGroupBox(ConfirmWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 130, 601, 361));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        SubTotalLabel = new QLabel(groupBox);
        SubTotalLabel->setObjectName("SubTotalLabel");
        SubTotalLabel->setGeometry(QRect(10, 60, 171, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        SubTotalLabel->setFont(font2);
        DeliveryLabel = new QLabel(groupBox);
        DeliveryLabel->setObjectName("DeliveryLabel");
        DeliveryLabel->setGeometry(QRect(10, 90, 201, 20));
        DeliveryLabel->setFont(font2);
        TotalLabel = new QLabel(groupBox);
        TotalLabel->setObjectName("TotalLabel");
        TotalLabel->setGeometry(QRect(10, 120, 361, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        TotalLabel->setFont(font3);
        TotalLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        DeliveringToLabel = new QLabel(groupBox);
        DeliveringToLabel->setObjectName("DeliveringToLabel");
        DeliveringToLabel->setGeometry(QRect(10, 160, 191, 51));
        DeliveringToLabel->setFont(font1);
        AddressLabel = new QLabel(groupBox);
        AddressLabel->setObjectName("AddressLabel");
        AddressLabel->setGeometry(QRect(190, 180, 401, 20));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        AddressLabel->setFont(font4);
        PaymentMethodLabel = new QLabel(groupBox);
        PaymentMethodLabel->setObjectName("PaymentMethodLabel");
        PaymentMethodLabel->setGeometry(QRect(10, 230, 221, 41));
        PaymentMethodLabel->setFont(font1);
        PaymentMethod = new QLabel(groupBox);
        PaymentMethod->setObjectName("PaymentMethod");
        PaymentMethod->setGeometry(QRect(240, 240, 301, 20));
        PaymentMethod->setFont(font4);
        DelievryDateLabel = new QLabel(groupBox);
        DelievryDateLabel->setObjectName("DelievryDateLabel");
        DelievryDateLabel->setGeometry(QRect(10, 290, 211, 41));
        DelievryDateLabel->setFont(font1);
        DeliveryDate = new QLabel(groupBox);
        DeliveryDate->setObjectName("DeliveryDate");
        DeliveryDate->setGeometry(QRect(240, 300, 291, 20));
        DeliveryDate->setFont(font4);
        pushButton = new QPushButton(ConfirmWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 520, 211, 71));
        QFont font5;
        font5.setBold(true);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));

        retranslateUi(Confirm);

        QMetaObject::connectSlotsByName(Confirm);
    } // setupUi

    void retranslateUi(QWidget *Confirm)
    {
        Confirm->setWindowTitle(QCoreApplication::translate("Confirm", "Form", nullptr));
        OrderPlacedLabel->setText(QCoreApplication::translate("Confirm", "Order Successfully Placed!", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Confirm", "Order Summary", nullptr));
        SubTotalLabel->setText(QCoreApplication::translate("Confirm", "subtotal: EGP 20.00", nullptr));
        DeliveryLabel->setText(QCoreApplication::translate("Confirm", "Delivery Fee: EGP 20.00", nullptr));
        TotalLabel->setText(QCoreApplication::translate("Confirm", "Total: EGP 20.00", nullptr));
        DeliveringToLabel->setText(QCoreApplication::translate("Confirm", "Delivering To:", nullptr));
        AddressLabel->setText(QCoreApplication::translate("Confirm", "Al Rehab City, Al Rehab City 1, Othman Ibn Affan", nullptr));
        PaymentMethodLabel->setText(QCoreApplication::translate("Confirm", "Payment Method:", nullptr));
        PaymentMethod->setText(QCoreApplication::translate("Confirm", "Cash on Delivery (COD)", nullptr));
        DelievryDateLabel->setText(QCoreApplication::translate("Confirm", "Delivery Date:", nullptr));
        DeliveryDate->setText(QCoreApplication::translate("Confirm", "5 buisness Days", nullptr));
        pushButton->setText(QCoreApplication::translate("Confirm", "Continue Shopping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Confirm: public Ui_Confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
