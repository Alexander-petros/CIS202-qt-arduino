#include "ballanimation.h"
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

bool x_max = false;
bool x_min = true;
bool y_max = true;
bool y_min = false;
QPoint direction;

BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(50,50))
{
    setFixedSize(100,100);
    direction.setX(3);
    direction.setY(2);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::bounce()
{
    if (x_max)
    {
        direction.setX(-direction.x());
        direction.setY(direction.y());
    }
    else if (x_min)
    {
        direction.setX(-direction.x());
        direction.setY(direction.y());
    }
    if (y_max)
    {
        direction.setY(-direction.y());
    }
    else if (y_min)
    {
        direction.setY(-direction.y());
    }
    m_origin += direction;
}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    if (m_origin.x() >= 94)
    {
        x_max = true;
    }
    else if (m_origin.x() <= 6)
    {
        x_min = true;
    }
    else
    {
        x_max = false;
        x_min = false;
    }
    if (m_origin.y() >= 94)
    {
        y_max = true;
    }
    else if (m_origin.y() <= 6)
    {
        y_min = true;
    }
    else
    {
        y_max = false;
        y_min = false;
    }
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawRect(0,0,100,100);
    painter.setBrush(Qt::blue);
    if (x_max == true || x_min == true)
    {
        painter.drawEllipse(m_origin,7,13);
    }
    else if(y_max == true || y_min == true)
    {
        painter.drawEllipse(m_origin,13,7);
    }
    else
    {
        painter.drawEllipse(m_origin,10,10);
    }
}
