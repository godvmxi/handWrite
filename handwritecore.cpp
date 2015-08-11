#include "handwritecore.h"

HandWriteCore::HandWriteCore(QWidget *parent)
    : QWidget(parent)
{
    this->timer = new QTimer();
    this->timer->setInterval(this->timeout);
    this->timer->setSingleShot(true);
}

HandWriteCore::~HandWriteCore()
{

}
void HandWriteCore::mouseMoveEvent(QMouseEvent *event){
   long long point_time =  QDateTime::currentDateTime().toMSecsSinceEpoch() - first_point_time ;
    qDebug()<<"move ->"<<event->x() <<event->y() << point_time;
}
void HandWriteCore::mousePressEvent(QMouseEvent *event){
    this->first_point_time =  QDateTime::currentDateTime().toMSecsSinceEpoch();
    qDebug()<<"press->"<<event->x() <<event->y() << 0;
}
void HandWriteCore::mouseReleaseEvent(QMouseEvent *event){

    qDebug()<<"release->"<<event->x() <<event->y() ;
}



