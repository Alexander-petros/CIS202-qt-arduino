#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void bounce();

signals:

public slots:
    void paintEvent(QPaintEvent* event);

private:
    QPoint m_origin;
};

#endif // BALLANIMATION_H
