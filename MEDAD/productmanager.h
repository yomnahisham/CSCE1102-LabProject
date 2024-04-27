#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

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

private:
    Ui::ProductManager *ui;
};

#endif // PRODUCTMANAGER_H
