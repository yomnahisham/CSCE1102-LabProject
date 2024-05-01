#ifndef CLICKABLELABELS_H
#define CLICKABLELABELS_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabels : public QLabel
{
    Q_OBJECT

signals:
    void clicked();

public:
    explicit ClickableLabels(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // CLICKABLELABELS_H
