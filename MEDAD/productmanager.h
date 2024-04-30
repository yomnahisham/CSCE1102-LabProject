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
    explicit ProductManager(QWidget *parent = nullptr, User* loggedUser = nullptr);
    ~ProductManager();

private:
    Ui::ProductManager *ui;
};

#endif // PRODUCTMANAGER_H
