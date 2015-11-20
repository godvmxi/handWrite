#include "handwritecore.h"
#include <QString>
#include <QDebug>
#include<zinnia.h>


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



int HandWriteCore::getWidgetWidth() const
{
    return widgetWidth;
}

void HandWriteCore::setWidgetWidth(int value)
{
    widgetWidth = value;
    this->setFixedWidth(this->widgetWidth);
}

int HandWriteCore::getWidgetHeight() const
{
    return widgetHeight;
}

void HandWriteCore::setWidgetHeight(int value)
{
    widgetHeight = value;
    this->setFixedHeight(this->widgetHeight);
}
HandWriteCore::HandWriteCore(QWidget *parent)
    : QWidget(parent)
{
    this->drawTimeout =  1000;//1s


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
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));
    this->setPalette(palette);
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

//   qDebug()<<"move->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;


   if(this->curPointIndex < MAX_POINT_PER_STROKE_NUM){
       this->curPointIndex++;
       this->update();
   }
   else {
       qDebug()<<"reach the max point per line";
   }
}

void HandWriteCore::mouseReleaseEvent(QMouseEvent *event){


    this->pointNumPerStroke[this->curStrokeIndex] = this->curPointIndex ;
    qDebug()<<"release->"<<this->curStrokeIndex<<this->curPointIndex << this->pointNumPerStroke[this->curStrokeIndex] ;

    if(this->curStrokeIndex <  MAX_STROKE_NUM ) {
        this->curStrokeIndex++;
        this->update();
    }
    else {
        qDebug()<<"reach max stroke";
    }
    this->keyState = 1;
    emit  this->add_strokes( this->getStrokesXmlString() );
}
void HandWriteCore::HandWriteCore::paintEvent ( QPaintEvent * event) {
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
        if ( keyState) {
//            qDebug()<<"painter-->"<<curStrokeIndex << this->pointNumPerStroke[i] ;

        }

        for(int j = 1;j < this->pointNumPerStroke[i];j++){

            start.setX(this->pointPosArray[i][j-1].x );
            start.setY(this->pointPosArray[i][j-1].y );
            end.setX( this->pointPosArray[i][j].x);
            end.setY(this->pointPosArray[i][j].y);
//            qDebug()<<"draw line-->"<<start<<end;
            painter.drawLine(start ,end );
//            painter.drawLine(0,0,100,100);


        }
    }
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
}
 void HandWriteCore::cleanStroke(void){
    this->curPointIndex = 0;
     for(int i =0;i<MAX_STROKE_NUM;i++){
         pointNumPerStroke[i] = 0;
     }
 }
QString HandWriteCore::getStrokesXmlString(void){

    QString Temp ;
    QString result;
    qDebug()<<"1111";


    qDebug()<<result;

    Temp =  QString(tr("<strokes width=%1 height=%2>") ).arg(this->getWidgetWidth()).arg(this->getWidgetHeight());
    result  =  Temp;

    for(int i = 0 ;i <= this->curStrokeIndex;i++){
        if(this->pointNumPerStroke[i] == 0)
            continue;
        Temp =  QString(tr("<stroke>") );
         result .append( Temp );
        for(int j = 0;j < this->pointNumPerStroke[i];j++){
            Point *p = &pointPosArray[i][j];
            Temp =  QString(tr("<point x=%1 y=%2 timestamp=%3 />") ).arg(p->x).arg(p->y).arg(p->timestamp);
             result .append( Temp );
        }
        Temp =  QString(tr("</stroke>") );
         result .append( Temp );
    }
    Temp =  QString(tr("</strokes>") );
    result .append( Temp );
//    qDebug()<<result ;
    return result;
}

int HandWriteCore::demo(void){
    static const char *input =
      "(character (width 1000)(height 1000)"
      "(strokes ((243 273)(393 450))((700 253)(343 486)(280 716)(393 866)(710 880))))";
    zinnia::Recognizer *recognizer = zinnia::Recognizer::create();
    if (!recognizer->open("/nfs/dev/HandWrite/model/handwriting-zh_CN.model")) {
      qDebug()<< recognizer->what() ;
      return -1;
    }

    zinnia::Character *character = zinnia::Character::create();
    if (!character->parse(input)) {
      qDebug()<<character->what();
      return -1;
    }

    {
      zinnia::Result *result = recognizer->classify(*character, 10);
      if (!result) {
          qDebug() << recognizer->what()  ;
         return -1;
      }
      for (size_t i = 0; i < result->size(); ++i) {
        qDebug()<< result->value(i) << "\t" << result->score(i) ;
      }
      delete result;
    }

    character->clear();
    character->set_width(300);
    character->set_height(300);
    character->add(0, 51, 29);
    character->add(0, 117, 41);
    character->add(1, 99, 65);
    character->add(1, 219, 77);
    character->add(2, 27, 131);
    character->add(2, 261, 131);
    character->add(3, 129, 17);
    character->add(3, 57, 203);
    character->add(4, 111, 71);
    character->add(4, 219, 173);
    character->add(5, 81, 161);
    character->add(5, 93, 281);
    character->add(6, 99, 167);
    character->add(6, 207, 167);
    character->add(6, 189, 245);
    character->add(7, 99, 227);
    character->add(7, 189, 227);
    character->add(8, 111, 257);
    character->add(8, 189, 245);
    {
      zinnia::Result *result = recognizer->classify(*character, 10);
      if (!result) {
          qDebug()<< recognizer->what() ;
         return -1;
      }
      for (size_t i = 0; i < result->size(); ++i) {
          QString temp  = QString::fromLocal8Bit(result->value(i) );
        unsigned char * tmp = (unsigned char *)result->value(i);
        QString  test = QString().sprintf("\\%02X\\%0X\\%02X",tmp[0],tmp[1],tmp[2]);
         qDebug() <<"--->"<<temp<<"  --> "<< result->value(i) << "\t" << result->score(i) ;

      }
      delete result;
    }
    delete character;
    delete recognizer;
    return 0;
}
