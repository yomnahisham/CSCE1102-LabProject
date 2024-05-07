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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
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
    QGroupBox *CreditAddOrSaveGroup;
    QRadioButton *AddNewCreditButton;
    QRadioButton *SavedCredtButton;
    QGroupBox *DelieverinAddorSaveGroup;
    QRadioButton *AddNewAddressButton;
    QRadioButton *SavedAddressButton;
    QGroupBox *CreditCardsGroup;
    QTableWidget *CreditCardsTableWidget;
    QGroupBox *SavedAddressGroup;
    QTableWidget *savedAddressTable;
    QLineEdit *PromoCode;
    QPushButton *enterDiscount;
    QLabel *InValidDiscount;
    QWidget *CreditWidget;
    QPushButton *enterCredit;
    QGroupBox *CreditCardInfoGroupBox;
    QLabel *CreditNumLabel;
    QLineEdit *CreditNum;
    QLabel *CVVLabel;
    QLineEdit *CVV;
    QLabel *ExpDateLabel;
    QComboBox *Month;
    QComboBox *Year;
    QCheckBox *SaveCredit;
    QLabel *InvalidCardNum;
    QLabel *InvalidCVV;
    QPushButton *ConfirmButton;
    QPushButton *ReTurnHome;
    QWidget *AddressWidget;
    QPushButton *enterAddress;
    QGroupBox *AddressGroupBox;
    QLabel *StreetLabel;
    QLineEdit *Street;
    QLabel *ProvinceLabel;
    QComboBox *Province;
    QCheckBox *SaveAddress;
    QLabel *AreaLabel;
    QLineEdit *Area;
    QLabel *BuildingLabel;
    QLineEdit *Building;
    QLabel *AptLabel;
    QLineEdit *Apt;
    QLabel *FloorLabel;
    QLineEdit *Floor;
    QLabel *PhoneNoLabel;
    QLineEdit *PhoneNum;
    QLabel *InvalidArea;
    QLabel *InvalidStreet;
    QLabel *InvalidBuilding;
    QLabel *InvalidApt;
    QLabel *InvalidPhoneNum;

    void setupUi(QWidget *Checkout)
    {
        if (Checkout->objectName().isEmpty())
            Checkout->setObjectName("Checkout");
        Checkout->resize(1757, 933);
        Checkout->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        PaymentWidget = new QWidget(Checkout);
        PaymentWidget->setObjectName("PaymentWidget");
        PaymentWidget->setGeometry(QRect(80, 20, 561, 781));
        DeliveryFee = new QLabel(PaymentWidget);
        DeliveryFee->setObjectName("DeliveryFee");
        DeliveryFee->setGeometry(QRect(10, 630, 509, 61));
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
        Total->setGeometry(QRect(10, 730, 301, 51));
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
        groupBox->setGeometry(QRect(10, 20, 281, 121));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        groupBox->setFont(font2);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        CashButton = new QRadioButton(groupBox);
        CashButton->setObjectName("CashButton");
        CashButton->setGeometry(QRect(10, 80, 201, 26));
        CashButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        CreditButton = new QRadioButton(groupBox);
        CreditButton->setObjectName("CreditButton");
        CreditButton->setGeometry(QRect(10, 50, 181, 26));
        CreditButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        subTotal = new QLabel(PaymentWidget);
        subTotal->setObjectName("subTotal");
        subTotal->setGeometry(QRect(10, 670, 509, 61));
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
        CreditAddOrSaveGroup = new QGroupBox(PaymentWidget);
        CreditAddOrSaveGroup->setObjectName("CreditAddOrSaveGroup");
        CreditAddOrSaveGroup->setGeometry(QRect(10, 190, 161, 111));
        CreditAddOrSaveGroup->setFont(font);
        CreditAddOrSaveGroup->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        AddNewCreditButton = new QRadioButton(CreditAddOrSaveGroup);
        AddNewCreditButton->setObjectName("AddNewCreditButton");
        AddNewCreditButton->setGeometry(QRect(20, 40, 112, 26));
        SavedCredtButton = new QRadioButton(CreditAddOrSaveGroup);
        SavedCredtButton->setObjectName("SavedCredtButton");
        SavedCredtButton->setGeometry(QRect(20, 80, 112, 26));
        DelieverinAddorSaveGroup = new QGroupBox(PaymentWidget);
        DelieverinAddorSaveGroup->setObjectName("DelieverinAddorSaveGroup");
        DelieverinAddorSaveGroup->setGeometry(QRect(20, 450, 151, 91));
        DelieverinAddorSaveGroup->setFont(font);
        DelieverinAddorSaveGroup->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        AddNewAddressButton = new QRadioButton(DelieverinAddorSaveGroup);
        AddNewAddressButton->setObjectName("AddNewAddressButton");
        AddNewAddressButton->setGeometry(QRect(10, 30, 112, 26));
        SavedAddressButton = new QRadioButton(DelieverinAddorSaveGroup);
        SavedAddressButton->setObjectName("SavedAddressButton");
        SavedAddressButton->setGeometry(QRect(10, 60, 112, 26));
        CreditCardsGroup = new QGroupBox(PaymentWidget);
        CreditCardsGroup->setObjectName("CreditCardsGroup");
        CreditCardsGroup->setGeometry(QRect(240, 190, 271, 191));
        CreditCardsGroup->setFont(font);
        CreditCardsGroup->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditCardsTableWidget = new QTableWidget(CreditCardsGroup);
        CreditCardsTableWidget->setObjectName("CreditCardsTableWidget");
        CreditCardsTableWidget->setGeometry(QRect(10, 40, 241, 141));
        SavedAddressGroup = new QGroupBox(PaymentWidget);
        SavedAddressGroup->setObjectName("SavedAddressGroup");
        SavedAddressGroup->setGeometry(QRect(240, 440, 281, 171));
        SavedAddressGroup->setFont(font);
        SavedAddressGroup->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        savedAddressTable = new QTableWidget(SavedAddressGroup);
        savedAddressTable->setObjectName("savedAddressTable");
        savedAddressTable->setGeometry(QRect(10, 40, 261, 121));
        PromoCode = new QLineEdit(PaymentWidget);
        PromoCode->setObjectName("PromoCode");
        PromoCode->setGeometry(QRect(220, 640, 231, 28));
        PromoCode->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        enterDiscount = new QPushButton(PaymentWidget);
        enterDiscount->setObjectName("enterDiscount");
        enterDiscount->setGeometry(QRect(470, 640, 83, 29));
        enterDiscount->setFont(font);
        enterDiscount->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);\n"
""));
        InValidDiscount = new QLabel(PaymentWidget);
        InValidDiscount->setObjectName("InValidDiscount");
        InValidDiscount->setGeometry(QRect(220, 680, 271, 20));
        InValidDiscount->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        CreditWidget = new QWidget(Checkout);
        CreditWidget->setObjectName("CreditWidget");
        CreditWidget->setGeometry(QRect(650, 150, 401, 391));
        enterCredit = new QPushButton(CreditWidget);
        enterCredit->setObjectName("enterCredit");
        enterCredit->setGeometry(QRect(130, 340, 111, 41));
        enterCredit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        CreditCardInfoGroupBox = new QGroupBox(CreditWidget);
        CreditCardInfoGroupBox->setObjectName("CreditCardInfoGroupBox");
        CreditCardInfoGroupBox->setGeometry(QRect(10, 40, 361, 291));
        CreditCardInfoGroupBox->setFont(font2);
        CreditCardInfoGroupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNumLabel = new QLabel(CreditCardInfoGroupBox);
        CreditNumLabel->setObjectName("CreditNumLabel");
        CreditNumLabel->setGeometry(QRect(10, 50, 181, 20));
        CreditNumLabel->setFont(font3);
        CreditNumLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CreditNum = new QLineEdit(CreditCardInfoGroupBox);
        CreditNum->setObjectName("CreditNum");
        CreditNum->setGeometry(QRect(10, 80, 331, 28));
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
        SaveCredit->setGeometry(QRect(10, 260, 311, 26));
        InvalidCardNum = new QLabel(CreditCardInfoGroupBox);
        InvalidCardNum->setObjectName("InvalidCardNum");
        InvalidCardNum->setGeometry(QRect(180, 110, 161, 20));
        InvalidCardNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        InvalidCVV = new QLabel(CreditCardInfoGroupBox);
        InvalidCVV->setObjectName("InvalidCVV");
        InvalidCVV->setGeometry(QRect(140, 150, 161, 20));
        InvalidCVV->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        ConfirmButton = new QPushButton(Checkout);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setGeometry(QRect(1150, 670, 281, 71));
        ConfirmButton->setFont(font);
        ConfirmButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        ReTurnHome = new QPushButton(Checkout);
        ReTurnHome->setObjectName("ReTurnHome");
        ReTurnHome->setGeometry(QRect(820, 670, 281, 71));
        ReTurnHome->setFont(font);
        ReTurnHome->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        AddressWidget = new QWidget(Checkout);
        AddressWidget->setObjectName("AddressWidget");
        AddressWidget->setGeometry(QRect(1080, 140, 441, 491));
        enterAddress = new QPushButton(AddressWidget);
        enterAddress->setObjectName("enterAddress");
        enterAddress->setGeometry(QRect(170, 440, 111, 41));
        enterAddress->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(249, 184, 158);"));
        AddressGroupBox = new QGroupBox(AddressWidget);
        AddressGroupBox->setObjectName("AddressGroupBox");
        AddressGroupBox->setGeometry(QRect(10, 20, 421, 411));
        AddressGroupBox->setFont(font2);
        AddressGroupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        StreetLabel = new QLabel(AddressGroupBox);
        StreetLabel->setObjectName("StreetLabel");
        StreetLabel->setGeometry(QRect(10, 120, 71, 20));
        StreetLabel->setFont(font3);
        Street = new QLineEdit(AddressGroupBox);
        Street->setObjectName("Street");
        Street->setGeometry(QRect(10, 140, 113, 28));
        ProvinceLabel = new QLabel(AddressGroupBox);
        ProvinceLabel->setObjectName("ProvinceLabel");
        ProvinceLabel->setGeometry(QRect(10, 50, 181, 20));
        ProvinceLabel->setFont(font3);
        Province = new QComboBox(AddressGroupBox);
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->addItem(QString());
        Province->setObjectName("Province");
        Province->setGeometry(QRect(10, 80, 171, 28));
        SaveAddress = new QCheckBox(AddressGroupBox);
        SaveAddress->setObjectName("SaveAddress");
        SaveAddress->setGeometry(QRect(10, 380, 311, 26));
        AreaLabel = new QLabel(AddressGroupBox);
        AreaLabel->setObjectName("AreaLabel");
        AreaLabel->setGeometry(QRect(230, 50, 181, 20));
        AreaLabel->setFont(font3);
        AreaLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Area = new QLineEdit(AddressGroupBox);
        Area->setObjectName("Area");
        Area->setGeometry(QRect(230, 80, 131, 28));
        BuildingLabel = new QLabel(AddressGroupBox);
        BuildingLabel->setObjectName("BuildingLabel");
        BuildingLabel->setGeometry(QRect(230, 140, 181, 31));
        BuildingLabel->setFont(font3);
        BuildingLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Building = new QLineEdit(AddressGroupBox);
        Building->setObjectName("Building");
        Building->setGeometry(QRect(230, 180, 151, 28));
        AptLabel = new QLabel(AddressGroupBox);
        AptLabel->setObjectName("AptLabel");
        AptLabel->setGeometry(QRect(10, 200, 171, 20));
        AptLabel->setFont(font3);
        Apt = new QLineEdit(AddressGroupBox);
        Apt->setObjectName("Apt");
        Apt->setGeometry(QRect(10, 230, 113, 28));
        FloorLabel = new QLabel(AddressGroupBox);
        FloorLabel->setObjectName("FloorLabel");
        FloorLabel->setGeometry(QRect(230, 230, 171, 20));
        FloorLabel->setFont(font3);
        Floor = new QLineEdit(AddressGroupBox);
        Floor->setObjectName("Floor");
        Floor->setGeometry(QRect(230, 260, 113, 28));
        PhoneNoLabel = new QLabel(AddressGroupBox);
        PhoneNoLabel->setObjectName("PhoneNoLabel");
        PhoneNoLabel->setGeometry(QRect(10, 300, 171, 20));
        PhoneNoLabel->setFont(font3);
        PhoneNum = new QLineEdit(AddressGroupBox);
        PhoneNum->setObjectName("PhoneNum");
        PhoneNum->setGeometry(QRect(10, 330, 231, 28));
        InvalidArea = new QLabel(AddressGroupBox);
        InvalidArea->setObjectName("InvalidArea");
        InvalidArea->setGeometry(QRect(300, 110, 101, 21));
        InvalidArea->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        InvalidStreet = new QLabel(AddressGroupBox);
        InvalidStreet->setObjectName("InvalidStreet");
        InvalidStreet->setGeometry(QRect(10, 170, 111, 21));
        InvalidStreet->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        InvalidBuilding = new QLabel(AddressGroupBox);
        InvalidBuilding->setObjectName("InvalidBuilding");
        InvalidBuilding->setGeometry(QRect(290, 210, 111, 21));
        InvalidBuilding->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        InvalidApt = new QLabel(AddressGroupBox);
        InvalidApt->setObjectName("InvalidApt");
        InvalidApt->setGeometry(QRect(10, 260, 111, 21));
        InvalidApt->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        InvalidPhoneNum = new QLabel(AddressGroupBox);
        InvalidPhoneNum->setObjectName("InvalidPhoneNum");
        InvalidPhoneNum->setGeometry(QRect(240, 360, 161, 21));
        InvalidPhoneNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        PaymentWidget->raise();
        ConfirmButton->raise();
        CreditWidget->raise();
        ReTurnHome->raise();
        AddressWidget->raise();

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
        CreditAddOrSaveGroup->setTitle(QCoreApplication::translate("Checkout", "Saved or Add New", nullptr));
        AddNewCreditButton->setText(QCoreApplication::translate("Checkout", "Add New", nullptr));
        SavedCredtButton->setText(QCoreApplication::translate("Checkout", "Saved", nullptr));
        DelieverinAddorSaveGroup->setTitle(QCoreApplication::translate("Checkout", "Delivering To", nullptr));
        AddNewAddressButton->setText(QCoreApplication::translate("Checkout", "Add New", nullptr));
        SavedAddressButton->setText(QCoreApplication::translate("Checkout", "Saved", nullptr));
        CreditCardsGroup->setTitle(QCoreApplication::translate("Checkout", "Credit Cards", nullptr));
        SavedAddressGroup->setTitle(QCoreApplication::translate("Checkout", "Saved Address", nullptr));
        enterDiscount->setText(QCoreApplication::translate("Checkout", "Enter", nullptr));
        InValidDiscount->setText(QCoreApplication::translate("Checkout", "*Invalid Promo Code", nullptr));
        enterCredit->setText(QCoreApplication::translate("Checkout", "Enter", nullptr));
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
        InvalidCardNum->setText(QCoreApplication::translate("Checkout", "*Invalid Card Number", nullptr));
        InvalidCVV->setText(QCoreApplication::translate("Checkout", "*Invalid CVV", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("Checkout", "Order Confirmation", nullptr));
        ReTurnHome->setText(QCoreApplication::translate("Checkout", "Return to Home Page", nullptr));
        enterAddress->setText(QCoreApplication::translate("Checkout", "Enter", nullptr));
        AddressGroupBox->setTitle(QCoreApplication::translate("Checkout", "Address Info", nullptr));
        StreetLabel->setText(QCoreApplication::translate("Checkout", "Street", nullptr));
        ProvinceLabel->setText(QCoreApplication::translate("Checkout", "Province", nullptr));
        Province->setItemText(0, QCoreApplication::translate("Checkout", "Fifth Settlement", nullptr));
        Province->setItemText(1, QCoreApplication::translate("Checkout", "First Settlement", nullptr));
        Province->setItemText(2, QCoreApplication::translate("Checkout", "Third Settlement", nullptr));
        Province->setItemText(3, QCoreApplication::translate("Checkout", "El Yasmeen ", nullptr));
        Province->setItemText(4, QCoreApplication::translate("Checkout", "Al Rehab City", nullptr));
        Province->setItemText(5, QCoreApplication::translate("Checkout", "Madinaty", nullptr));
        Province->setItemText(6, QCoreApplication::translate("Checkout", "Shoroul City", nullptr));
        Province->setItemText(7, QCoreApplication::translate("Checkout", "Al Narges", nullptr));

        SaveAddress->setText(QCoreApplication::translate("Checkout", "Save Address Info", nullptr));
        AreaLabel->setText(QCoreApplication::translate("Checkout", "Area", nullptr));
        BuildingLabel->setText(QCoreApplication::translate("Checkout", "Building", nullptr));
        AptLabel->setText(QCoreApplication::translate("Checkout", "Apartment No.", nullptr));
        FloorLabel->setText(QCoreApplication::translate("Checkout", "Floor", nullptr));
        PhoneNoLabel->setText(QCoreApplication::translate("Checkout", "Phone No.", nullptr));
        InvalidArea->setText(QCoreApplication::translate("Checkout", "*Invalid Area", nullptr));
        InvalidStreet->setText(QCoreApplication::translate("Checkout", "*Invalid Street", nullptr));
        InvalidBuilding->setText(QCoreApplication::translate("Checkout", "*Invalid Building", nullptr));
        InvalidApt->setText(QCoreApplication::translate("Checkout", "*Invalid Apt.", nullptr));
        InvalidPhoneNum->setText(QCoreApplication::translate("Checkout", "*Invalid Phone Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkout: public Ui_Checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUT_H
