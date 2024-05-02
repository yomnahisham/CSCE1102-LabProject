#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "user.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include <QWidget>
#include <vector>

using namespace std;

namespace Ui {
class ProductManager;
}

class ProductManager : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManager(QWidget *parent = nullptr);
    ~ProductManager();
    void setUser(User* loggedUser);
    User* getUser();

    Books* createBook(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& genre, const QString& author, const QString& ISBN);
    Accessories* createAccessory(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& type, char size);
    Techs* createTech(const QString& name, double price, int quantity, bool availability, const QPixmap& image, int type);

    void initializeProducts();
    vector<Products*> suggestSimilarItems(const vector<Products*>& allProducts);
private slots:
    void onCartClicked();
    void onSignOutClicked();
private:
    Ui::ProductManager *ui;
    User* user;
    QVector<Books*> *bookProducts;
    QVector<Accessories*> *accessoryProducts;
    QVector<Techs*> *techyProducts;
};

#endif // PRODUCTMANAGER_H
