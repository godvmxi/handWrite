#ifndef DrawWidget_H
#define DrawWidget_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QList>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QString>
#include <recongnizer.h>
#define MAX_STROKE_NUM    30
#define MAX_POINT_PER_STROKE_NUM 200
typedef  struct {
    int x ;
    int y;
    long long timestamp;
} Point;
typedef struct {
    Point start ;
    Point end;
}Line;
class DrawWidget : public QWidget
{
    Q_OBJECT
private :
    long long firstPointTime ;
    int drawTimeout ;
    QTimer *timer ;
    Point lastPoint ;
    Point curPoint;
   Point  pointPosArray[MAX_STROKE_NUM][MAX_POINT_PER_STROKE_NUM];

   int pointNumPerStroke[MAX_STROKE_NUM];
   int curStrokeIndex ;
   int curPointIndex ;
    int keyState ;
   //draw feature
   int lineWidth;
   int widgetWidth ;
   int widgetHeight ;






   QColor lineColor;
   QVector <QPoint> pointList ;
   void updateTimer(void);

public:
    DrawWidget(QWidget *parent = 0);
    ~DrawWidget();



    int getLineWidth() const;
    void setLineWidth(int value);

    int getDrawTimeout() const;
    void setDrawTimeout(int value);

    QColor getLineColor() const;
    void setLineColor(const QColor &value);
    void cleanDrawArea(void);


    int getWidgetWidth() const;
    void setWidgetWidth(int value);

    int getWidgetHeight() const;
    void setWidgetHeight(int value);



private slots :
    void drawTimeoutEvent() ;
public slots :


protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent ( QPaintEvent *event ) ;
signals :
    void addStrokeSignal(int id ,QVector<QPoint> pointList);
};

#endif // DrawWidget_H
