/********************************************************************************
** Form generated from reading UI file 'orderconfirmation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERCONFIRMATION_H
#define UI_ORDERCONFIRMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderConfirmation
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

    void setupUi(QDialog *OrderConfirmation)
    {
        if (OrderConfirmation->objectName().isEmpty())
            OrderConfirmation->setObjectName("OrderConfirmation");
        OrderConfirmation->resize(1264, 699);
        ConfirmWidget = new QWidget(OrderConfirmation);
        ConfirmWidget->setObjectName("ConfirmWidget");
        ConfirmWidget->setGeometry(QRect(320, 50, 691, 561));
        OrderPlacedLabel = new QLabel(ConfirmWidget);
        OrderPlacedLabel->setObjectName("OrderPlacedLabel");
        OrderPlacedLabel->setGeometry(QRect(30, 30, 641, 51));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        OrderPlacedLabel->setFont(font);
        groupBox = new QGroupBox(ConfirmWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 120, 601, 361));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        groupBox->setFont(font1);
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
        TotalLabel->setGeometry(QRect(10, 120, 211, 21));
        DeliveringToLabel = new QLabel(groupBox);
        DeliveringToLabel->setObjectName("DeliveringToLabel");
        DeliveringToLabel->setGeometry(QRect(10, 160, 191, 51));
        AddressLabel = new QLabel(groupBox);
        AddressLabel->setObjectName("AddressLabel");
        AddressLabel->setGeometry(QRect(190, 180, 401, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        AddressLabel->setFont(font3);
        PaymentMethodLabel = new QLabel(groupBox);
        PaymentMethodLabel->setObjectName("PaymentMethodLabel");
        PaymentMethodLabel->setGeometry(QRect(10, 230, 221, 41));
        PaymentMethod = new QLabel(groupBox);
        PaymentMethod->setObjectName("PaymentMethod");
        PaymentMethod->setGeometry(QRect(240, 240, 301, 20));
        PaymentMethod->setFont(font3);
        DelievryDateLabel = new QLabel(groupBox);
        DelievryDateLabel->setObjectName("DelievryDateLabel");
        DelievryDateLabel->setGeometry(QRect(10, 290, 211, 41));
        DeliveryDate = new QLabel(groupBox);
        DeliveryDate->setObjectName("DeliveryDate");
        DeliveryDate->setGeometry(QRect(240, 300, 291, 20));
        DeliveryDate->setFont(font3);
        pushButton = new QPushButton(ConfirmWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 500, 191, 51));
        QFont font4;
        font4.setBold(true);
        pushButton->setFont(font4);

        retranslateUi(OrderConfirmation);

        QMetaObject::connectSlotsByName(OrderConfirmation);
    } // setupUi

    void retranslateUi(QDialog *OrderConfirmation)
    {
        OrderConfirmation->setWindowTitle(QCoreApplication::translate("OrderConfirmation", "Dialog", nullptr));
        OrderPlacedLabel->setText(QCoreApplication::translate("OrderConfirmation", "Order Successfully Placed!", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OrderConfirmation", "Order Summary", nullptr));
        SubTotalLabel->setText(QCoreApplication::translate("OrderConfirmation", "subtotal: EGP 20.00", nullptr));
        DeliveryLabel->setText(QCoreApplication::translate("OrderConfirmation", "Delivery Fee: EGP 20.00", nullptr));
        TotalLabel->setText(QCoreApplication::translate("OrderConfirmation", "Total: EGP 20.00", nullptr));
        DeliveringToLabel->setText(QCoreApplication::translate("OrderConfirmation", "Delivering To:", nullptr));
        AddressLabel->setText(QCoreApplication::translate("OrderConfirmation", "Al Rehab City, Al Rehab City 1, Othman Ibn Affan", nullptr));
        PaymentMethodLabel->setText(QCoreApplication::translate("OrderConfirmation", "Payment Method:", nullptr));
        PaymentMethod->setText(QCoreApplication::translate("OrderConfirmation", "Cash on Delivery (COD)", nullptr));
        DelievryDateLabel->setText(QCoreApplication::translate("OrderConfirmation", "Delivery Date:", nullptr));
        DeliveryDate->setText(QCoreApplication::translate("OrderConfirmation", "5 buisness Days", nullptr));
        pushButton->setText(QCoreApplication::translate("OrderConfirmation", "Continue Shopping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderConfirmation: public Ui_OrderConfirmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERCONFIRMATION_H
