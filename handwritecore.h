#ifndef HandWriteCore_H
#define HandWriteCore_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
typedef  struct {
    int x ;
    int y;
    long long timestamp;
} Point;
class HandWriteCore : public QWidget
{
    Q_OBJECT
private :
    long long first_point_time ;
    int timeout = 0;
    QTimer *timer ;
public:
    HandWriteCore(QWidget *parent = 0);
    ~HandWriteCore();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // HandWriteCore_H
