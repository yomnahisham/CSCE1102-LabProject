/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *userL;
    QLabel *passL;
    QLabel *passRL;
    QLabel *authorL_2;
    QGroupBox *genreL;
    QCheckBox *classics;
    QCheckBox *arabLit;
    QCheckBox *philo;
    QCheckBox *poetry;
    QCheckBox *palestine;
    QCheckBox *arabAmerican;
    QCheckBox *comic;
    QPushButton *returnB;
    QPushButton *loginB;
    QLineEdit *userLE;
    QLineEdit *passLE;
    QLineEdit *passRLE;
    QPushButton *regB;
    QPushButton *backB;
    QLabel *userError;
    QLabel *passError;
    QLabel *preferenceError;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(856, 635);
        RegisterWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 252);\n"
"\n"
""));
        userL = new QLabel(RegisterWindow);
        userL->setObjectName("userL");
        userL->setGeometry(QRect(250, 80, 71, 16));
        userL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        passL = new QLabel(RegisterWindow);
        passL->setObjectName("passL");
        passL->setGeometry(QRect(250, 110, 71, 16));
        passL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        passRL = new QLabel(RegisterWindow);
        passRL->setObjectName("passRL");
        passRL->setGeometry(QRect(210, 140, 111, 16));
        passRL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        authorL_2 = new QLabel(RegisterWindow);
        authorL_2->setObjectName("authorL_2");
        authorL_2->setGeometry(QRect(210, 190, 191, 16));
        authorL_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        genreL = new QGroupBox(RegisterWindow);
        genreL->setObjectName("genreL");
        genreL->setGeometry(QRect(210, 210, 461, 80));
        genreL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);"));
        classics = new QCheckBox(genreL);
        classics->setObjectName("classics");
        classics->setGeometry(QRect(10, 20, 85, 20));
        arabLit = new QCheckBox(genreL);
        arabLit->setObjectName("arabLit");
        arabLit->setGeometry(QRect(10, 50, 131, 20));
        philo = new QCheckBox(genreL);
        philo->setObjectName("philo");
        philo->setGeometry(QRect(230, 20, 101, 20));
        poetry = new QCheckBox(genreL);
        poetry->setObjectName("poetry");
        poetry->setGeometry(QRect(120, 20, 85, 20));
        palestine = new QCheckBox(genreL);
        palestine->setObjectName("palestine");
        palestine->setGeometry(QRect(170, 50, 85, 20));
        arabAmerican = new QCheckBox(genreL);
        arabAmerican->setObjectName("arabAmerican");
        arabAmerican->setGeometry(QRect(280, 50, 131, 20));
        comic = new QCheckBox(genreL);
        comic->setObjectName("comic");
        comic->setGeometry(QRect(350, 20, 101, 20));
        returnB = new QPushButton(genreL);
        returnB->setObjectName("returnB");
        returnB->setGeometry(QRect(60, 10, 141, 32));
        returnB->setStyleSheet(QString::fromUtf8(""));
        loginB = new QPushButton(genreL);
        loginB->setObjectName("loginB");
        loginB->setGeometry(QRect(260, 10, 181, 32));
        loginB->setStyleSheet(QString::fromUtf8(""));
        userLE = new QLineEdit(RegisterWindow);
        userLE->setObjectName("userLE");
        userLE->setGeometry(QRect(320, 80, 113, 21));
        userLE->setStyleSheet(QString::fromUtf8(""));
        passLE = new QLineEdit(RegisterWindow);
        passLE->setObjectName("passLE");
        passLE->setGeometry(QRect(320, 110, 113, 21));
        passLE->setStyleSheet(QString::fromUtf8(""));
        passRLE = new QLineEdit(RegisterWindow);
        passRLE->setObjectName("passRLE");
        passRLE->setGeometry(QRect(320, 140, 113, 21));
        passRLE->setStyleSheet(QString::fromUtf8(""));
        regB = new QPushButton(RegisterWindow);
        regB->setObjectName("regB");
        regB->setGeometry(QRect(510, 330, 100, 32));
        regB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        backB = new QPushButton(RegisterWindow);
        backB->setObjectName("backB");
        backB->setGeometry(QRect(260, 330, 100, 32));
        backB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        userError = new QLabel(RegisterWindow);
        userError->setObjectName("userError");
        userError->setGeometry(QRect(460, 80, 141, 16));
        passError = new QLabel(RegisterWindow);
        passError->setObjectName("passError");
        passError->setGeometry(QRect(450, 140, 271, 16));
        preferenceError = new QLabel(RegisterWindow);
        preferenceError->setObjectName("preferenceError");
        preferenceError->setGeometry(QRect(410, 190, 271, 16));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        userL->setText(QCoreApplication::translate("RegisterWindow", "Username:", nullptr));
        passL->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        passRL->setText(QCoreApplication::translate("RegisterWindow", "Repeat Password:", nullptr));
        authorL_2->setText(QCoreApplication::translate("RegisterWindow", "Select Your Preffered Genres:", nullptr));
        genreL->setTitle(QCoreApplication::translate("RegisterWindow", "Genre", nullptr));
        classics->setText(QCoreApplication::translate("RegisterWindow", "Classics", nullptr));
        arabLit->setText(QCoreApplication::translate("RegisterWindow", "Arabic Literature", nullptr));
        philo->setText(QCoreApplication::translate("RegisterWindow", "Philosophy", nullptr));
        poetry->setText(QCoreApplication::translate("RegisterWindow", "Poetry", nullptr));
        palestine->setText(QCoreApplication::translate("RegisterWindow", "Palestine", nullptr));
        arabAmerican->setText(QCoreApplication::translate("RegisterWindow", "Arab-American", nullptr));
        comic->setText(QCoreApplication::translate("RegisterWindow", "Comic Books", nullptr));
        returnB->setText(QCoreApplication::translate("RegisterWindow", "Return to Home Page", nullptr));
        loginB->setText(QCoreApplication::translate("RegisterWindow", "Login as Registered Admin", nullptr));
        regB->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        backB->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
        userError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#941100;\">user already exists</span></p></body></html>", nullptr));
        passError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#941100;\">password does not match</span></p></body></html>", nullptr));
        preferenceError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#941100;\">* Please select at least one preference</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
