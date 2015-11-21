#include "chartable.h"

CharTable::CharTable(QWidget *parent ,int itemNum ) :
    QWidget(parent)
{

    this->layout =  new QHBoxLayout() ;

    this->charItemNum = itemNum;
    qDebug()<<this->charItemNum;
    CharItem * temp = NULL;
    for(int i =  0; i<this->charItemNum;i++){
        temp =  new CharItem(this,i,QString(""));
        temp->setFixedSize(40,40);

        this->layout->addWidget(temp);

//        this->charList.append((void *)temp);
    }

    this->setLayout(this->layout);
}




void CharTable::clear (void)  {

}
void CharTable::setStringList(QStringList list){
    qDebug()<<"display list ->" << list;
    CharItem *item ;
    qDebug()<<this->charItemNum;

//    for(int i = 0 ;i <this->displayCharNum ;i++){

//    }
}

