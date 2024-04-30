#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "user.h"

#include <QWidget>

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

private:
    Ui::ProductManager *ui;
    User* user;
};

#endif // PRODUCTMANAGER_H
