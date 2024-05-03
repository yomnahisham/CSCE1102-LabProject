/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QPushButton *pushButton;
    QLabel *Logo;
    QLabel *Based;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_;
    QLabel *LogoSub;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(1269, 733);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Search->sizePolicy().hasHeightForWidth());
        Search->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(Search);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(690, 20, 93, 29));
        Logo = new QLabel(Search);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(20, 20, 111, 41));
        Based = new QLabel(Search);
        Based->setObjectName("Based");
        Based->setGeometry(QRect(380, 50, 321, 20));
        horizontalLayoutWidget_2 = new QWidget(Search);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 420, 1231, 281));
        horizontalLayout_ = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_->setObjectName("horizontalLayout_");
        horizontalLayout_->setContentsMargins(0, 0, 0, 0);
        LogoSub = new QLabel(Search);
        LogoSub->setObjectName("LogoSub");
        LogoSub->setGeometry(QRect(100, 80, 121, 20));
        horizontalLayoutWidget_3 = new QWidget(Search);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(20, 120, 1231, 281));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Search", "HomePage", nullptr));
        Logo->setText(QCoreApplication::translate("Search", "TextLabel", nullptr));
        Based->setText(QCoreApplication::translate("Search", "Based", nullptr));
        LogoSub->setText(QCoreApplication::translate("Search", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
