/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
    QLabel *langL;
    QLabel *authorL;
    QGroupBox *groupBox;
    QCheckBox *eng;
    QCheckBox *arab;
    QGroupBox *groupBox_2;
    QCheckBox *rooney;
    QCheckBox *riordan;
    QCheckBox *Claire;
    QCheckBox *king;
    QLabel *authorL_2;
    QGroupBox *genreL;
    QCheckBox *fantasy;
    QCheckBox *mystery;
    QCheckBox *thriller;
    QCheckBox *selfHelp;
    QCheckBox *romance;
    QCheckBox *horror;
    QLineEdit *userLE;
    QLineEdit *passLE;
    QLineEdit *passRLE;
    QPushButton *regB;
    QPushButton *backB;
    QLabel *userError;
    QLabel *passError;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 514);
        userL = new QLabel(RegisterWindow);
        userL->setObjectName("userL");
        userL->setGeometry(QRect(50, 30, 71, 16));
        passL = new QLabel(RegisterWindow);
        passL->setObjectName("passL");
        passL->setGeometry(QRect(50, 60, 71, 16));
        passRL = new QLabel(RegisterWindow);
        passRL->setObjectName("passRL");
        passRL->setGeometry(QRect(10, 90, 111, 16));
        langL = new QLabel(RegisterWindow);
        langL->setObjectName("langL");
        langL->setGeometry(QRect(10, 140, 241, 16));
        authorL = new QLabel(RegisterWindow);
        authorL->setObjectName("authorL");
        authorL->setGeometry(QRect(10, 330, 191, 16));
        groupBox = new QGroupBox(RegisterWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 160, 231, 41));
        eng = new QCheckBox(groupBox);
        eng->setObjectName("eng");
        eng->setGeometry(QRect(0, 20, 85, 20));
        arab = new QCheckBox(groupBox);
        arab->setObjectName("arab");
        arab->setGeometry(QRect(140, 20, 85, 20));
        groupBox_2 = new QGroupBox(RegisterWindow);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 340, 401, 80));
        rooney = new QCheckBox(groupBox_2);
        rooney->setObjectName("rooney");
        rooney->setGeometry(QRect(10, 20, 111, 20));
        riordan = new QCheckBox(groupBox_2);
        riordan->setObjectName("riordan");
        riordan->setGeometry(QRect(120, 20, 111, 20));
        Claire = new QCheckBox(groupBox_2);
        Claire->setObjectName("Claire");
        Claire->setGeometry(QRect(250, 20, 131, 20));
        king = new QCheckBox(groupBox_2);
        king->setObjectName("king");
        king->setGeometry(QRect(10, 50, 111, 20));
        authorL_2 = new QLabel(RegisterWindow);
        authorL_2->setObjectName("authorL_2");
        authorL_2->setGeometry(QRect(10, 220, 191, 16));
        genreL = new QGroupBox(RegisterWindow);
        genreL->setObjectName("genreL");
        genreL->setGeometry(QRect(10, 230, 341, 80));
        fantasy = new QCheckBox(genreL);
        fantasy->setObjectName("fantasy");
        fantasy->setGeometry(QRect(10, 20, 85, 20));
        mystery = new QCheckBox(genreL);
        mystery->setObjectName("mystery");
        mystery->setGeometry(QRect(120, 20, 85, 20));
        thriller = new QCheckBox(genreL);
        thriller->setObjectName("thriller");
        thriller->setGeometry(QRect(250, 20, 85, 20));
        selfHelp = new QCheckBox(genreL);
        selfHelp->setObjectName("selfHelp");
        selfHelp->setGeometry(QRect(10, 50, 85, 20));
        romance = new QCheckBox(genreL);
        romance->setObjectName("romance");
        romance->setGeometry(QRect(120, 50, 85, 20));
        horror = new QCheckBox(genreL);
        horror->setObjectName("horror");
        horror->setGeometry(QRect(250, 50, 85, 20));
        userLE = new QLineEdit(RegisterWindow);
        userLE->setObjectName("userLE");
        userLE->setGeometry(QRect(120, 30, 113, 21));
        passLE = new QLineEdit(RegisterWindow);
        passLE->setObjectName("passLE");
        passLE->setGeometry(QRect(120, 60, 113, 21));
        passRLE = new QLineEdit(RegisterWindow);
        passRLE->setObjectName("passRLE");
        passRLE->setGeometry(QRect(120, 90, 113, 21));
        regB = new QPushButton(RegisterWindow);
        regB->setObjectName("regB");
        regB->setGeometry(QRect(270, 460, 100, 32));
        backB = new QPushButton(RegisterWindow);
        backB->setObjectName("backB");
        backB->setGeometry(QRect(20, 460, 100, 32));
        userError = new QLabel(RegisterWindow);
        userError->setObjectName("userError");
        userError->setGeometry(QRect(260, 30, 131, 16));
        passError = new QLabel(RegisterWindow);
        passError->setObjectName("passError");
        passError->setGeometry(QRect(250, 90, 131, 16));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        userL->setText(QCoreApplication::translate("RegisterWindow", "Username:", nullptr));
        passL->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        passRL->setText(QCoreApplication::translate("RegisterWindow", "Repeat Password:", nullptr));
        langL->setText(QCoreApplication::translate("RegisterWindow", "Select Language of Books you prefer:", nullptr));
        authorL->setText(QCoreApplication::translate("RegisterWindow", "Select Your Preffered Authors:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RegisterWindow", "Lang", nullptr));
        eng->setText(QCoreApplication::translate("RegisterWindow", "English", nullptr));
        arab->setText(QCoreApplication::translate("RegisterWindow", "Arabic", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RegisterWindow", "Author", nullptr));
        rooney->setText(QCoreApplication::translate("RegisterWindow", "Nancy Rooney", nullptr));
        riordan->setText(QCoreApplication::translate("RegisterWindow", "Rick Riordan", nullptr));
        Claire->setText(QCoreApplication::translate("RegisterWindow", "Cassandra Claire", nullptr));
        king->setText(QCoreApplication::translate("RegisterWindow", "Stephan King", nullptr));
        authorL_2->setText(QCoreApplication::translate("RegisterWindow", "Select Your Preffered Authors:", nullptr));
        genreL->setTitle(QCoreApplication::translate("RegisterWindow", "Genre", nullptr));
        fantasy->setText(QCoreApplication::translate("RegisterWindow", "Fantasy", nullptr));
        mystery->setText(QCoreApplication::translate("RegisterWindow", "Mystery", nullptr));
        thriller->setText(QCoreApplication::translate("RegisterWindow", "Thriller", nullptr));
        selfHelp->setText(QCoreApplication::translate("RegisterWindow", "Self Help", nullptr));
        romance->setText(QCoreApplication::translate("RegisterWindow", "Romance", nullptr));
        horror->setText(QCoreApplication::translate("RegisterWindow", "Horror", nullptr));
        regB->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        backB->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
        userError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#941100;\">user already exists</span></p></body></html>", nullptr));
        passError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#941100;\">password does not match</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
