#include "recongnizer.h"
#include <QFileInfo>

Recongnizer::Recongnizer(QObject *parent,QString model,int width ,int height) :
    QObject(parent)
{
    this->recognizer = zinnia::Recognizer::create();
    this->character = zinnia::Character::create();
    this->result = NULL;
    this->model = model;
    this->width  = 300;
    this->height = height;
    this->setModel(this->model);
    this->character->clear();
    this->character->set_width(this->width);
    this->character->set_height(this->height);

}

bool Recongnizer::setModel(QString model){
    QFileInfo info(model);
    if (info.isFile() == false ){
        qDebug()<<"mode is not exist";
        return false;
    }
    this->model = model;
    this->recognizer->open(this->model.toLocal8Bit());
    this->character->clear();
    this->character->set_width(this->width);
    this->character->set_height(this->height);

    return true;
}

QString  Recongnizer::getModel(void){
    return this->model;
}

void Recongnizer::addStroke(int id ,QVector<QPoint> pointList){
    QPoint temp ;
    for(int i = 0 ;i<pointList.size();i++){
        temp = pointList.at(i);
        this->character->add(id,temp.x(),temp.y());
    }

    this->result = this->recognizer->classify(*this->character,10);
    if(!this->result){
        qDebug()<<"recongnizer no result -->"<< recognizer->what();
        return ;
    }
    QStringList recongnizerResult ;

    for (int i = 0;i<this->result->size();i++){
        QString temp  = QString::fromLocal8Bit(result->value(i) );
        recongnizerResult << this->result->value(i);
        qDebug()<< result->value(i) << "\t" << result->score(i) ;
    }
    delete this->result;
    emit this->notifyRecongnizerResult(recongnizerResult);
}

void Recongnizer::clear(){
    this->character->clear();
    this->character->set_width(this->width);
    this->character->set_height(this->height);
}
void Recongnizer::setWidth(int width ){
    this->width = width;
    this->character->set_width(this->width);
    this->character->clear();

}

void Recongnizer::setHeight(int height ){
    this->height = height;
    this->character->set_height(this->height);
    this->character->clear();
}

int Recongnizer::getWidth(){
    return this->width;
}

int Recongnizer::getHeight(){
    return this->height;
}
void Recongnizer::demo(){
    static const char *input =
      "(character (width 1000)(height 1000)"
      "(strokes ((243 273)(393 450))((700 253)(343 486)(280 716)(393 866)(710 880))))";
    QStringList recongnizerResult ;
    if (!this->character->parse(input)) {
      qDebug()<<this->character->what();
      return ;
    }
    {
      this->result = this->recognizer->classify(*character, 10);
      if (!this->result) {
          qDebug() << this->recognizer->what()  ;
         return ;
      }
      for (size_t i = 0; i < this->result->size(); ++i) {
        qDebug()<< this->result->value(i) << "\t" << this->result->score(i) ;
      }
      delete this->result;
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
         return ;
      }

      for (size_t i = 0; i < result->size(); ++i) {
          QString temp  = QString::fromLocal8Bit(result->value(i) );
//          unsigned char * tmp = (unsigned char *)result->value(i);
//          QString  test = QString().sprintf("\\%02X\\%0X\\%02X",tmp[0],tmp[1],tmp[2]);
          qDebug() <<"--->"<<temp<<"  --> "<< result->value(i) << "\t" << result->score(i) ;
          recongnizerResult.append(temp );

      }

      delete result;
    }


   emit this->notifyRecongnizerResult(recongnizerResult);
}
void Recongnizer::addStrokeSlot(int id ,QVector<QPoint> pointList){
    qDebug()<<id <<pointList;
    this->addStroke(id,pointList);
}
