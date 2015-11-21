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
//    result <<QString("2");
//    result <<QString("3");
//    result <<QString("4");
    for (int i = 0;i<this->result->size();i++){
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

}

void Recongnizer::setHeight(int height ){
    this->height = height;
    this->character->set_height(this->height);
}

int Recongnizer::getWidth(){
    return this->width;
}

int Recongnizer::getHeight(){
    return this->height;
}
