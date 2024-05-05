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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkout
{
public:
    QWidget *PaymentWidget;
    QLabel *DeliveryFee;
    QLabel *Total;
    QGroupBox *groupBox;
    QRadioButton *CashButton;
    QRadioButton *CreditButton;
    QLabel *subTotal;
    QWidget *CreditWidget;
    QGroupBox *CreditCardInfoGroupBox;
    QLabel *CreditNumLabel;
    QLineEdit *CreditNum;
    QLabel *CVVLabel;
    QLineEdit *CVV;
    QLabel *ExpDateLabel;
    QComboBox *Month;
    QComboBox *Year;
    QCheckBox *SaveCredit;
    QPushButton *pushButton;

    void setupUi(QWidget *Checkout)
    {
        if (Checkout->objectName().isEmpty())
            Checkout->setObjectName("Checkout");
        Checkout->resize(1278, 933);
        Checkout->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        PaymentWidget = new QWidget(Checkout);
        PaymentWidget->setObjectName("PaymentWidget");
        PaymentWidget->setGeometry(QRect(60, 70, 601, 781));
        DeliveryFee = new QLabel(PaymentWidget);
        DeliveryFee->setObjectName("DeliveryFee");
        DeliveryFee->setGeometry(QRect(20, 380, 509, 61));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeliveryFee->sizePolicy().hasHeightForWidth());
        DeliveryFee->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        DeliveryFee->setFont(font);
        DeliveryFee->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Total = new QLabel(PaymentWidget);
        Total->setObjectName("Total");
        Total->setGeometry(QRect(20, 440, 291, 111));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setKerning(true);
        Total->setFont(font1);
        Total->setLayoutDirection(Qt::LeftToRight);
        Total->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        Total->setWordWrap(false);
        groupBox = new QGroupBox(PaymentWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 60, 321, 191));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        groupBox->setFont(font2);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        CashButton = new QRadioButton(groupBox);
        CashButton->setObjectName("CashButton");
        CashButton->setGeometry(QRect(10, 130, 201, 26));
        CashButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        CreditButton = new QRadioButton(groupBox);
        CreditButton->setObjectName("CreditButton");
        CreditButton->setGeometry(QRect(10, 80, 181, 26));
        CreditButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        subTotal = new QLabel(PaymentWidget);
        subTotal->setObjectName("subTotal");
        subTotal->setGeometry(QRect(20, 420, 509, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(subTotal->sizePolicy().hasHeightForWidth());
        subTotal->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        subTotal->setFont(font3);
        subTotal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditWidget = new QWidget(Checkout);
        CreditWidget->setObjectName("CreditWidget");
        CreditWidget->setGeometry(QRect(700, 60, 511, 451));
        CreditCardInfoGroupBox = new QGroupBox(CreditWidget);
        CreditCardInfoGroupBox->setObjectName("CreditCardInfoGroupBox");
        CreditCardInfoGroupBox->setGeometry(QRect(30, 60, 459, 319));
        CreditCardInfoGroupBox->setFont(font2);
        CreditCardInfoGroupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNumLabel = new QLabel(CreditCardInfoGroupBox);
        CreditNumLabel->setObjectName("CreditNumLabel");
        CreditNumLabel->setGeometry(QRect(10, 50, 181, 20));
        CreditNumLabel->setFont(font3);
        CreditNumLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNum = new QLineEdit(CreditCardInfoGroupBox);
        CreditNum->setObjectName("CreditNum");
        CreditNum->setGeometry(QRect(10, 80, 301, 28));
        CVVLabel = new QLabel(CreditCardInfoGroupBox);
        CVVLabel->setObjectName("CVVLabel");
        CVVLabel->setGeometry(QRect(10, 110, 71, 20));
        CVVLabel->setFont(font3);
        CVV = new QLineEdit(CreditCardInfoGroupBox);
        CVV->setObjectName("CVV");
        CVV->setGeometry(QRect(10, 140, 113, 28));
        ExpDateLabel = new QLabel(CreditCardInfoGroupBox);
        ExpDateLabel->setObjectName("ExpDateLabel");
        ExpDateLabel->setGeometry(QRect(10, 190, 181, 20));
        ExpDateLabel->setFont(font3);
        Month = new QComboBox(CreditCardInfoGroupBox);
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->addItem(QString());
        Month->setObjectName("Month");
        Month->setGeometry(QRect(10, 220, 82, 28));
        Year = new QComboBox(CreditCardInfoGroupBox);
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->addItem(QString());
        Year->setObjectName("Year");
        Year->setGeometry(QRect(120, 220, 82, 28));
        SaveCredit = new QCheckBox(CreditCardInfoGroupBox);
        SaveCredit->setObjectName("SaveCredit");
        SaveCredit->setGeometry(QRect(20, 280, 311, 26));
        pushButton = new QPushButton(Checkout);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(780, 690, 391, 71));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));

        retranslateUi(Checkout);

        QMetaObject::connectSlotsByName(Checkout);
    } // setupUi

    void retranslateUi(QWidget *Checkout)
    {
        Checkout->setWindowTitle(QCoreApplication::translate("Checkout", "Form", nullptr));
        DeliveryFee->setText(QCoreApplication::translate("Checkout", "Delievery Fee: EGP 50.00", nullptr));
        Total->setText(QCoreApplication::translate("Checkout", "Total:  EGP 20.00", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Checkout", "Pick Payment Method", nullptr));
        CashButton->setText(QCoreApplication::translate("Checkout", "Cash on Delievery", nullptr));
        CreditButton->setText(QCoreApplication::translate("Checkout", "Credit Card", nullptr));
        subTotal->setText(QCoreApplication::translate("Checkout", "Subtotal: EGP 20.00", nullptr));
        CreditCardInfoGroupBox->setTitle(QCoreApplication::translate("Checkout", "Credit Card Info", nullptr));
        CreditNumLabel->setText(QCoreApplication::translate("Checkout", "Credit Card Num:", nullptr));
        CVVLabel->setText(QCoreApplication::translate("Checkout", "CVV", nullptr));
        ExpDateLabel->setText(QCoreApplication::translate("Checkout", "Expiry Date:", nullptr));
        Month->setItemText(0, QCoreApplication::translate("Checkout", "01", nullptr));
        Month->setItemText(1, QCoreApplication::translate("Checkout", "02", nullptr));
        Month->setItemText(2, QCoreApplication::translate("Checkout", "03", nullptr));
        Month->setItemText(3, QCoreApplication::translate("Checkout", "04", nullptr));
        Month->setItemText(4, QCoreApplication::translate("Checkout", "05", nullptr));
        Month->setItemText(5, QCoreApplication::translate("Checkout", "06", nullptr));
        Month->setItemText(6, QCoreApplication::translate("Checkout", "07", nullptr));
        Month->setItemText(7, QCoreApplication::translate("Checkout", "08", nullptr));
        Month->setItemText(8, QCoreApplication::translate("Checkout", "09", nullptr));
        Month->setItemText(9, QCoreApplication::translate("Checkout", "10", nullptr));
        Month->setItemText(10, QCoreApplication::translate("Checkout", "11", nullptr));
        Month->setItemText(11, QCoreApplication::translate("Checkout", "12", nullptr));

        Year->setItemText(0, QCoreApplication::translate("Checkout", "2024", nullptr));
        Year->setItemText(1, QCoreApplication::translate("Checkout", "2025", nullptr));
        Year->setItemText(2, QCoreApplication::translate("Checkout", "2026", nullptr));
        Year->setItemText(3, QCoreApplication::translate("Checkout", "2027", nullptr));
        Year->setItemText(4, QCoreApplication::translate("Checkout", "2028", nullptr));
        Year->setItemText(5, QCoreApplication::translate("Checkout", "2029", nullptr));
        Year->setItemText(6, QCoreApplication::translate("Checkout", "2030", nullptr));
        Year->setItemText(7, QCoreApplication::translate("Checkout", "2031", nullptr));
        Year->setItemText(8, QCoreApplication::translate("Checkout", "2032", nullptr));
        Year->setItemText(9, QCoreApplication::translate("Checkout", "2033", nullptr));
        Year->setItemText(10, QCoreApplication::translate("Checkout", "2034", nullptr));
        Year->setItemText(11, QString());

        SaveCredit->setText(QCoreApplication::translate("Checkout", "Save Credit Card Info", nullptr));
        pushButton->setText(QCoreApplication::translate("Checkout", "Order Confirmation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkout: public Ui_Checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUT_H
