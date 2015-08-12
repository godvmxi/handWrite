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
#include <QColor>
#define MAX_STROKE_NUM    20
#define MAX_POINT_PER_LINE_NUM 20
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
    int drawTimeout = 0;
    QTimer *timer ;
    Point lastPoint ;
    Point curPoint;
   QPoint  pointArray[MAX_STROKE_NUM][MAX_POINT_PER_LINE_NUM];
   long long pointArrayTime[MAX_STROKE_NUM][MAX_POINT_PER_LINE_NUM];
   int pointNumInLine[MAX_STROKE_NUM];
   int curStrokeIndex = 0;
   int curPointIndex = 0;
   int lineWidth;
   QColor lineColor;
public:
    HandWriteCore(QWidget *parent = 0);
    ~HandWriteCore();



    int getLineWidth() const;
    void setLineWidth(int value);

    int getDrawTimeout() const;
    void setDrawTimeout(int value);

    QColor getLineColor() const;
    void setLineColor(const QColor &value);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent ( QPaintEvent *event ) ;
};

#endif // HandWriteCore_H
