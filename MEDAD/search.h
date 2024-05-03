#ifndef SEARCH_H
#define SEARCH_H
#include "user.h"
#include "allusers.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include <QWidget>
#include <vector>
#include <QLayoutItem>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringList>
#include <algorithm>
#include<QScrollArea>
#include"search.h"
#include <QMainWindow>
#include<QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    void DisplaySearch(vector<Products *> &searchResults);
    void clearLayout(QLayout *layout);

    ~Search();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Search *ui;
    AllUsers* allusers;
    User* loggedUser;

};

#endif // SEARCH_H
