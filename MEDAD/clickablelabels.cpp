#include "clickablelabels.h"

ClickableLabels::ClickableLabels(QWidget *parent) : QLabel(parent) {}

void ClickableLabels::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QLabel::mousePressEvent(event);
}
