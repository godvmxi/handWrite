#include "handwritecore.h"

HandWriteCore::HandWriteCore(QWidget *parent)
    : QWidget(parent)
{
    this->timer = new QTimer();
    this->timer->setInterval(this->timeout);
    this->timer->setSingleShot(true);
    lineList.clear();
}

HandWriteCore::~HandWriteCore()
{

}
void HandWriteCore::mouseMoveEvent(QMouseEvent *event){
   long long pointTime =  QDateTime::currentDateTime().toMSecsSinceEpoch() - this->firstPointTime ;

    Point p ;
    p.x  = event->x();
    p.y = event->y();
    p.timestamp = pointTime;

//    this->lastPoint = p;
//    this->curPoint = p;
    Line  line ;
    line.start = this->lastPoint;
    line.end =  p ;
    this->lineList.append(line);
    this->lastPoint =  p ;
    this->curPoint = p;


    qDebug()<<"move ->"<<p.x <<p.y << p.timestamp;
}
void HandWriteCore::mousePressEvent(QMouseEvent *event){
    this->firstPointTime =  QDateTime::currentDateTime().toMSecsSinceEpoch();

    Point p ;
    p.x  = event->x();
    p.y = event->y();
    p.timestamp = 0;

    this->lastPoint = p;
    this->curPoint = p;

    qDebug()<<"press->"<<p.x <<p.y << p.timestamp;
    this->repaint();
}
void HandWriteCore::mouseReleaseEvent(QMouseEvent *event){

    qDebug()<<"release->"<<event->x() <<event->y() ;
    qDebug()<<this->lineList.size();
    this->update();
}
void HandWriteCore::HandWriteCore::paintEvent ( QPaintEvent * event) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    pen.setWidth(5);
    painter.setPen(pen);  //选择画笔
    Line line ;
    foreach(line,this->lineList){
//        qDebug()<<line.start.x<<line.start.y<<line.end.x<<line.end.y;
        painter.drawLine(line.start.x,line.start.y,line.end.x,line.end.y); //用该红色画笔画一条线，起点(0,0)，终点(100,100)
    }
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
}


