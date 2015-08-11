#ifndef HandWriteCore_H
#define HandWriteCore_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QList>
#include <QPainter>
#include <QPaintEvent>
typedef  struct {
    int x ;
    int y;
    long long timestamp;
} Point;
typedef struct {
    Point start ;
    Point end;
}Line;
class HandWriteCore : public QWidget
{
    Q_OBJECT
private :
    long long firstPointTime ;
    int timeout = 0;
    QTimer *timer ;
    Point lastPoint ;
    Point curPoint;
   QList<Line> lineList;
public:
    HandWriteCore(QWidget *parent = 0);
    ~HandWriteCore();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent ( QPaintEvent *event ) ;
};

#endif // HandWriteCore_H
