/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *loginB;
    QPushButton *regB;
    QLabel *LoginAsL;
    QPushButton *customerB;
    QPushButton *adminB;
    QLabel *userL;
    QLabel *passL;
    QLineEdit *userLE;
    QLineEdit *passLE;
    QLabel *userError;
    QLabel *passError;
    QPushButton *sellerB;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1305, 764);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252);\n"
""));
        loginB = new QPushButton(LoginWindow);
        loginB->setObjectName("loginB");
        loginB->setGeometry(QRect(650, 460, 100, 32));
        loginB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        regB = new QPushButton(LoginWindow);
        regB->setObjectName("regB");
        regB->setGeometry(QRect(440, 460, 100, 32));
        regB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        LoginAsL = new QLabel(LoginWindow);
        LoginAsL->setObjectName("LoginAsL");
        LoginAsL->setGeometry(QRect(570, 340, 58, 16));
        customerB = new QPushButton(LoginWindow);
        customerB->setObjectName("customerB");
        customerB->setGeometry(QRect(380, 390, 100, 32));
        customerB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        adminB = new QPushButton(LoginWindow);
        adminB->setObjectName("adminB");
        adminB->setGeometry(QRect(710, 390, 100, 32));
        adminB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        userL = new QLabel(LoginWindow);
        userL->setObjectName("userL");
        userL->setGeometry(QRect(430, 340, 71, 16));
        userL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        passL = new QLabel(LoginWindow);
        passL->setObjectName("passL");
        passL->setGeometry(QRect(430, 390, 81, 16));
        passL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        userLE = new QLineEdit(LoginWindow);
        userLE->setObjectName("userLE");
        userLE->setGeometry(QRect(520, 340, 113, 21));
        userLE->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        passLE = new QLineEdit(LoginWindow);
        passLE->setObjectName("passLE");
        passLE->setGeometry(QRect(520, 390, 113, 21));
        passLE->setStyleSheet(QString::fromUtf8(""));
        passLE->setEchoMode(QLineEdit::Password);
        userError = new QLabel(LoginWindow);
        userError->setObjectName("userError");
        userError->setGeometry(QRect(650, 340, 131, 16));
        passError = new QLabel(LoginWindow);
        passError->setObjectName("passError");
        passError->setGeometry(QRect(650, 390, 131, 16));
        sellerB = new QPushButton(LoginWindow);
        sellerB->setObjectName("sellerB");
        sellerB->setGeometry(QRect(540, 390, 100, 32));
        sellerB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        loginB->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        regB->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
        LoginAsL->setText(QCoreApplication::translate("LoginWindow", "Login as:", nullptr));
        customerB->setText(QCoreApplication::translate("LoginWindow", "Customer", nullptr));
        adminB->setText(QCoreApplication::translate("LoginWindow", "Admin", nullptr));
        userL->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        passL->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        userError->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" color:#941100;\">Incorrect Username</span></p></body></html>", nullptr));
        passError->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" color:#941100;\">Incorrect Password</span></p></body></html>", nullptr));
        sellerB->setText(QCoreApplication::translate("LoginWindow", "Seller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
