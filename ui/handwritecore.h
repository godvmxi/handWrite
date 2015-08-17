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
#include <QString>
#define MAX_STROKE_NUM    20
#define MAX_POINT_PER_STROKE_NUM 40
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
   QString strokesXmlString ;

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
    void cleanStroke(void);


    int getWidgetWidth() const;
    void setWidgetWidth(int value);

    int getWidgetHeight() const;
    void setWidgetHeight(int value);
    bool toXml(void);
private slots :
    void drawTimeoutEvent() ;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent ( QPaintEvent *event ) ;

};

#endif // HandWriteCore_H
