/********************************************************************************
** Form generated from reading UI file 'loginwinodw.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINODW_H
#define UI_LOGINWINODW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWinodw
{
public:
    QLabel *UsernameL;
    QLabel *PasswordL;
    QLineEdit *userLE;
    QLineEdit *passLE;
    QPushButton *LoginB;
    QPushButton *RegB;
    QLabel *passError;
    QLabel *userError;
    QPushButton *adminB;
    QPushButton *CustomerB;
    QLabel *LoginAsL;

    void setupUi(QWidget *LoginWinodw)
    {
        if (LoginWinodw->objectName().isEmpty())
            LoginWinodw->setObjectName("LoginWinodw");
        LoginWinodw->resize(400, 217);
        UsernameL = new QLabel(LoginWinodw);
        UsernameL->setObjectName("UsernameL");
        UsernameL->setGeometry(QRect(20, 60, 71, 16));
        PasswordL = new QLabel(LoginWinodw);
        PasswordL->setObjectName("PasswordL");
        PasswordL->setGeometry(QRect(20, 100, 61, 16));
        userLE = new QLineEdit(LoginWinodw);
        userLE->setObjectName("userLE");
        userLE->setGeometry(QRect(100, 60, 113, 21));
        passLE = new QLineEdit(LoginWinodw);
        passLE->setObjectName("passLE");
        passLE->setGeometry(QRect(100, 100, 113, 21));
        passLE->setEchoMode(QLineEdit::Password);
        LoginB = new QPushButton(LoginWinodw);
        LoginB->setObjectName("LoginB");
        LoginB->setGeometry(QRect(20, 170, 100, 32));
        RegB = new QPushButton(LoginWinodw);
        RegB->setObjectName("RegB");
        RegB->setGeometry(QRect(180, 170, 100, 32));
        passError = new QLabel(LoginWinodw);
        passError->setObjectName("passError");
        passError->setGeometry(QRect(240, 100, 101, 16));
        userError = new QLabel(LoginWinodw);
        userError->setObjectName("userError");
        userError->setGeometry(QRect(240, 60, 151, 16));
        adminB = new QPushButton(LoginWinodw);
        adminB->setObjectName("adminB");
        adminB->setGeometry(QRect(80, 130, 100, 32));
        CustomerB = new QPushButton(LoginWinodw);
        CustomerB->setObjectName("CustomerB");
        CustomerB->setGeometry(QRect(230, 130, 100, 32));
        LoginAsL = new QLabel(LoginWinodw);
        LoginAsL->setObjectName("LoginAsL");
        LoginAsL->setGeometry(QRect(170, 70, 58, 16));

        retranslateUi(LoginWinodw);

        QMetaObject::connectSlotsByName(LoginWinodw);
    } // setupUi

    void retranslateUi(QWidget *LoginWinodw)
    {
        LoginWinodw->setWindowTitle(QCoreApplication::translate("LoginWinodw", "Form", nullptr));
        UsernameL->setText(QCoreApplication::translate("LoginWinodw", "Username:", nullptr));
        PasswordL->setText(QCoreApplication::translate("LoginWinodw", "Password:", nullptr));
        LoginB->setText(QCoreApplication::translate("LoginWinodw", "Login", nullptr));
        RegB->setText(QCoreApplication::translate("LoginWinodw", "Register", nullptr));
        passError->setText(QCoreApplication::translate("LoginWinodw", "<html><head/><body><p><span style=\" color:#941100;\">Wrong Pasword</span></p></body></html>", nullptr));
        userError->setText(QCoreApplication::translate("LoginWinodw", "<html><head/><body><p><span style=\" color:#941100;\">Username Does not Exist</span></p></body></html>", nullptr));
        adminB->setText(QCoreApplication::translate("LoginWinodw", "Admin", nullptr));
        CustomerB->setText(QCoreApplication::translate("LoginWinodw", "Customer", nullptr));
        LoginAsL->setText(QCoreApplication::translate("LoginWinodw", "Login as:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWinodw: public Ui_LoginWinodw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINODW_H
