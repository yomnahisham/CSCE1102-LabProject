/********************************************************************************
** Form generated from reading UI file 'checkout.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkout
{
public:
    QWidget *PaymentWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *PaymentLayout;
    QLabel *subTotal;
    QGroupBox *groupBox;
    QRadioButton *CashButton;
    QRadioButton *CreditButton;
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
        PaymentWidget->setGeometry(QRect(60, 200, 601, 451));
        verticalLayoutWidget = new QWidget(PaymentWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(80, 20, 371, 341));
        PaymentLayout = new QVBoxLayout(verticalLayoutWidget);
        PaymentLayout->setObjectName("PaymentLayout");
        PaymentLayout->setContentsMargins(0, 0, 0, 0);
        subTotal = new QLabel(verticalLayoutWidget);
        subTotal->setObjectName("subTotal");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setKerning(true);
        subTotal->setFont(font);
        subTotal->setLayoutDirection(Qt::LeftToRight);
        subTotal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        subTotal->setWordWrap(false);

        PaymentLayout->addWidget(subTotal);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName("groupBox");
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        groupBox->setFont(font1);
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

        PaymentLayout->addWidget(groupBox);

        CreditWidget = new QWidget(Checkout);
        CreditWidget->setObjectName("CreditWidget");
        CreditWidget->setGeometry(QRect(710, 210, 511, 451));
        CreditCardInfoGroupBox = new QGroupBox(CreditWidget);
        CreditCardInfoGroupBox->setObjectName("CreditCardInfoGroupBox");
        CreditCardInfoGroupBox->setGeometry(QRect(30, 50, 459, 319));
        CreditCardInfoGroupBox->setFont(font1);
        CreditCardInfoGroupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNumLabel = new QLabel(CreditCardInfoGroupBox);
        CreditNumLabel->setObjectName("CreditNumLabel");
        CreditNumLabel->setGeometry(QRect(10, 50, 181, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        CreditNumLabel->setFont(font2);
        CreditNumLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNum = new QLineEdit(CreditCardInfoGroupBox);
        CreditNum->setObjectName("CreditNum");
        CreditNum->setGeometry(QRect(10, 80, 301, 28));
        CVVLabel = new QLabel(CreditCardInfoGroupBox);
        CVVLabel->setObjectName("CVVLabel");
        CVVLabel->setGeometry(QRect(10, 110, 71, 20));
        CVVLabel->setFont(font2);
        CVV = new QLineEdit(CreditCardInfoGroupBox);
        CVV->setObjectName("CVV");
        CVV->setGeometry(QRect(10, 140, 113, 28));
        ExpDateLabel = new QLabel(CreditCardInfoGroupBox);
        ExpDateLabel->setObjectName("ExpDateLabel");
        ExpDateLabel->setGeometry(QRect(10, 190, 181, 20));
        ExpDateLabel->setFont(font2);
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
        pushButton->setGeometry(QRect(470, 790, 391, 71));
        QFont font3;
        font3.setBold(true);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));

        retranslateUi(Checkout);

        QMetaObject::connectSlotsByName(Checkout);
    } // setupUi

    void retranslateUi(QWidget *Checkout)
    {
        Checkout->setWindowTitle(QCoreApplication::translate("Checkout", "Form", nullptr));
        subTotal->setText(QCoreApplication::translate("Checkout", "Subtotal:  $20.00", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Checkout", "Pick Payment Method", nullptr));
        CashButton->setText(QCoreApplication::translate("Checkout", "Cash on Delievery", nullptr));
        CreditButton->setText(QCoreApplication::translate("Checkout", "Credit Card", nullptr));
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
