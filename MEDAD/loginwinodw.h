#ifndef LOGINWINODW_H
#define LOGINWINODW_H

#include <QWidget>

namespace Ui {
class LoginWinodw;
}

class LoginWinodw : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWinodw(QWidget *parent = nullptr);
    ~LoginWinodw();

private:
    Ui::LoginWinodw *ui;
};

#endif // LOGINWINODW_H
