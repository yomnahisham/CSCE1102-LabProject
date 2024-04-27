#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QWidget>

namespace Ui {
class Checkout;
}

class Checkout : public QWidget
{
    Q_OBJECT

public:
    explicit Checkout(QWidget *parent = nullptr);
    ~Checkout();

private:
    Ui::Checkout *ui;
};

#endif // CHECKOUT_H
