#include "handwritecore.h"



int HandWriteCore::getLineWidth() const
{
    return lineWidth;
}

void HandWriteCore::setLineWidth(int value)
{
    lineWidth = value;
}

int HandWriteCore::getDrawTimeout() const
{
    return drawTimeout;
}

void HandWriteCore::setDrawTimeout(int value)
{
    drawTimeout = value;
}

QColor HandWriteCore::getLineColor() const
{
    return lineColor;
}

void HandWriteCore::setLineColor(const QColor &value)
{
    lineColor = value;
}
HandWriteCore::HandWriteCore(QWidget *parent)
    : QWidget(parent)
{
    this->drawTimeout =  1000;//1s
    this->lineWidth =  5;
    this->lineColor =  QColor(Qt::red) ;
    /**/
    this->curStrokeIndex =  0;
    this->timer = new QTimer();
    this->timer->setInterval(this->drawTimeout);
    this->timer->setSingleShot(true);
    //init data
    memset(this->pointNumPerStroke,0,sizeof(int)*MAX_POINT_PER_STROKE_NUM) ;
    this->curStrokeIndex = 0;
}

HandWriteCore::~HandWriteCore()
{

}
void HandWriteCore::drawTimeoutEvent(){
    qDebug()<<"draw time out";
}

void HandWriteCore::mousePressEvent(QMouseEvent *event){
    this->firstPointTime =  QDateTime::currentDateTime().toMSecsSinceEpoch();

//    Point p ;
//    p.x  = event->x();
//    p.y = event->y();
//    p.timestamp = 0;

//    this->lastPoint = p;
//    this->curPoint = p;
    this->keyState = 0;
//    qDebug()<<"press->"<<p.x <<p.y << p.timestamp;
    this->curPointIndex =  0;
    this->pointNumPerStroke[this->curStrokeIndex] = 1;
    this->pointPosArray[this->curStrokeIndex][this->curPointIndex].x = event->x()  ;
    this->pointPosArray[this->curStrokeIndex][this->curPointIndex].y = event->y()  ;
    this->pointPosArray[this->curStrokeIndex][this->curPointIndex].timestamp = 0 ;
    qDebug()<<"press->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;
     this->curPointIndex =  1;




}
void HandWriteCore::mouseMoveEvent(QMouseEvent *event){
   long long pointTime =  QDateTime::currentDateTime().toMSecsSinceEpoch() - this->firstPointTime ;


   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].x = event->x()  ;
   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].y = event->y()  ;
   this->pointPosArray[this->curStrokeIndex][this->curPointIndex].timestamp = pointTime ;

  this->pointNumPerStroke[this->curStrokeIndex]++;

   qDebug()<<"move->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;


   if(this->curPointIndex < MAX_POINT_PER_STROKE_NUM){
       this->curPointIndex++;
       this->update();
   }
   else {
       qDebug()<<"reach the max point per line";
   }
}

void HandWriteCore::mouseReleaseEvent(QMouseEvent *event){


    this->pointNumPerStroke[this->curStrokeIndex] = this->curPointIndex +1;
    qDebug()<<"release->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;
    this->keyState = 1;
    if(this->curStrokeIndex <  MAX_STROKE_NUM ) {
        this->curStrokeIndex++;
        this->update();
    }
    else {
        qDebug()<<"reach max stroke";
    }
}
void HandWriteCore::HandWriteCore::paintEvent ( QPaintEvent * event) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(this->lineColor);  //设置画笔为红色
    pen.setWidth(this->lineWidth);
    painter.setPen(pen);  //选择画笔

    QPoint start ,end ;

    for(int i = 0 ;i <= this->curStrokeIndex;i++){
        if ( keyState) {
            qDebug()<<"painter-->"<<curStrokeIndex << this->pointNumPerStroke[i] ;
        }

        for(int j = 1;j < this->pointNumPerStroke[i];j++){

            start.setX(this->pointPosArray[i][j-1].x );
            start.setY(this->pointPosArray[i][j-1].y );
            end.setX( this->pointPosArray[i][j].x);
            end.setY(this->pointPosArray[i][j].y);
//            qDebug()<<start<<end;
            painter.drawLine(start ,end );
        }
    }
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
}


