#ifndef ALLPRODUCTS1_H
#define ALLPRODUCTS1_H
#include "user.h"
#include "allusers.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include"productmanager.h"
#include"products.h"
#include <QDialog>
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
using namespace std;
namespace Ui {
class AllProducts1;
}

class AllProducts1 : public QDialog
{
    Q_OBJECT

public:
    explicit AllProducts1(QWidget *parent=nullptr);
    void allproductsdisplay(vector<Products*>& displayedProducts);
    void clearLayout(QLayout *layout);
    ~AllProducts1();

private:
    Ui::AllProducts1 *ui;
    vector<Products*> alreadyDisplayed;

};

#endif // ALLPRODUCTS1_H
