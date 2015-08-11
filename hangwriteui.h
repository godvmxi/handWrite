#ifndef HANGWRITEUI_H
#define HANGWRITEUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
typedef  struct {
    int x ;
    int y;
    long long timestamp;
} Point;
class HangWriteUi : public QWidget
{
    Q_OBJECT
private :
    long long first_point_time ;
public:
    HangWriteUi(QWidget *parent = 0);
    ~HangWriteUi();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // HANGWRITEUI_H
