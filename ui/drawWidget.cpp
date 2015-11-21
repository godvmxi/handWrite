#include "DrawWidget.h"
#include <QString>
#include <QDebug>
#include<zinnia.h>

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget(parent)
{
    this->drawTimeout =  2000;//1s

    /**/
    this->curStrokeIndex =  0;
    this->curStrokeIndex = 0;
    this->setLineWidth(5);
    this->setLineColor(QColor(Qt::red) );
    for(int i = 0 ;i <MAX_STROKE_NUM;i++ ){
        this->pointNumPerStroke[i] = 0;
    }
    this->timer = new QTimer();
    this->timer->setInterval(this->drawTimeout);
    this->timer->setSingleShot(true);
    connect(this->timer,
            SIGNAL(timeout()),
            this,
            SLOT(drawTimeoutEvent())
            );

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));
    this->setPalette(palette);
    this->timer->start();
    this->setStyleSheet("border:3px solid #222");
}
int DrawWidget::getLineWidth() const
{
    return lineWidth;
}

void DrawWidget::setLineWidth(int value)
{
    lineWidth = value;
}

int DrawWidget::getDrawTimeout() const
{
    return drawTimeout;
}

void DrawWidget::setDrawTimeout(int value)
{
    drawTimeout = value;
}

QColor DrawWidget::getLineColor() const
{
    return lineColor;
}

void DrawWidget::setLineColor(const QColor &value)
{
    lineColor = value;

}



int DrawWidget::getWidgetWidth() const
{
    return widgetWidth;
}

void DrawWidget::setWidgetWidth(int value)
{
    widgetWidth = value;
    this->setFixedWidth(this->widgetWidth);
}

int DrawWidget::getWidgetHeight() const
{
    return widgetHeight;
}

void DrawWidget::setWidgetHeight(int value)
{
    widgetHeight = value;
    this->setFixedHeight(this->widgetHeight);
}


DrawWidget::~DrawWidget()
{

}


void DrawWidget::mousePressEvent(QMouseEvent *event){
    this->updateTimer();

    this->keyState = 0;

    this->curPointIndex =  0;
    this->pointNumPerStroke[this->curStrokeIndex] = 1;
    this->pointPosArray[this->curStrokeIndex][this->curPointIndex].x = event->x()  ;
    this->pointPosArray[this->curStrokeIndex][this->curPointIndex].y = event->y()  ;

  //  qDebug()<<"press->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;
     this->curPointIndex =  1;

    this->pointList.clear();
    QPoint temp = QPoint(event->x(),event->y());

    this->pointList.append(temp);




}
void DrawWidget::mouseMoveEvent(QMouseEvent *event){
   this->updateTimer();
//   long long pointTime =  0 ;


   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].x = event->x()  ;
   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].y = event->y()  ;
//   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].timestamp = pointTime ;

  this->pointNumPerStroke[this->curStrokeIndex]++;

//   qDebug()<<"move->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;
   QPoint temp = QPoint(event->x(),event->y());
   this->pointList.append(temp);

   if(this->curPointIndex < MAX_POINT_PER_STROKE_NUM){
       this->curPointIndex++;
       this->update();
   }
   else {
       qDebug()<<"reach the max point per line";
   }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event){

    this->updateTimer();
    this->pointNumPerStroke[this->curStrokeIndex] = this->curPointIndex ;
   // qDebug()<<"release->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;
    QPoint temp = QPoint(event->x(),event->y());
    this->pointList.append(temp);
    this->keyState = 1;
    emit addStrokeSignal(this->curStrokeIndex,this->pointList);

    if(this->curStrokeIndex <  MAX_STROKE_NUM ) {
        this->curStrokeIndex++;
        this->update();
    }
    else {
        qDebug()<<"reach max stroke";
    }

}
void DrawWidget::DrawWidget::paintEvent ( QPaintEvent * event) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(this->lineColor);  //设置画笔为红色
    pen.setWidth(this->lineWidth);
//    qDebug()<<this->lineColor ;
    //pen.setColor(QColor(Qt::red));  //设置画笔为红色
//    pen.setWidth(10);
    painter.setPen(pen);  //选择画笔

    QPoint start ,end ;


    for(int i = 0 ;i <= this->curStrokeIndex;i++){
        if ( this->keyState) {
//            qDebug()<<"painter-->"<<curStrokeIndex << this->pointNumPerStroke[i] ;
 //           qDebug()<<"key state error-->"<<keyState;
        }

        for(int j = 1;j < this->pointNumPerStroke[i];j++){

            start.setX(this->pointPosArray[i][j-1].x );
            start.setY(this->pointPosArray[i][j-1].y );
            end.setX( this->pointPosArray[i][j].x);
            end.setY(this->pointPosArray[i][j].y);
            painter.drawLine(start ,end );
        }
    }
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
}
void DrawWidget::cleanDrawArea(void){
    this->curStrokeIndex = 0;
    this->curPointIndex = 0;
     for(int i =0;i<MAX_STROKE_NUM;i++){
         pointNumPerStroke[i] = 0;
     }
     this->update();
}


void DrawWidget::updateTimer(void){
    this->timer->stop();
    this->timer->setInterval(this->drawTimeout);
    this->timer->start();
//    this->curStrokeIndex = 0;
//    this->update();
}

void DrawWidget::drawTimeoutEvent(){
 //   qDebug()<<"draw time out";
    this->curStrokeIndex = 0;
    this->cleanDrawArea();
    return;
}
