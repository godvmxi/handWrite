#include "hangwriteui.h"

HangWriteUi::HangWriteUi(QWidget *parent)
    : QWidget(parent)
{
}

HangWriteUi::~HangWriteUi()
{

}
void HangWriteUi::mouseMoveEvent(QMouseEvent *event){
   long long point_time =  QDateTime::currentDateTime().toMSecsSinceEpoch() - first_point_time ;
    qDebug()<<"move ->"<<event->x() <<event->y() << point_time;
}
void HangWriteUi::mousePressEvent(QMouseEvent *event){
    this->first_point_time =  QDateTime::currentDateTime().toMSecsSinceEpoch();
    qDebug()<<"press->"<<event->x() <<event->y() << 0;
}
void HangWriteUi::mouseReleaseEvent(QMouseEvent *event){

    qDebug()<<"release->"<<event->x() <<event->y() ;
}


