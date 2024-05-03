/********************************************************************************
** Form generated from reading UI file 'searchwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QDialog *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName("SearchWindow");
        SearchWindow->resize(1023, 599);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchWindow->sizePolicy().hasHeightForWidth());
        SearchWindow->setSizePolicy(sizePolicy);
        label = new QLabel(SearchWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 161, 61));
        label_2 = new QLabel(SearchWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(430, 40, 191, 20));
        pushButton = new QPushButton(SearchWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(880, 40, 93, 29));
        horizontalLayoutWidget = new QWidget(SearchWindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(39, 90, 951, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_4 = new QWidget(SearchWindow);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(40, 260, 951, 151));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_5 = new QWidget(SearchWindow);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(40, 430, 951, 151));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QDialog *SearchWindow)
    {
        SearchWindow->setWindowTitle(QCoreApplication::translate("SearchWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SearchWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("SearchWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("SearchWindow", "HomePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
