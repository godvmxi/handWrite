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

        this->charList.append(temp);
    }

    this->setLayout(this->layout);
}




void CharTable::clear (void)  {

}
void CharTable::updateStringListSlot(QStringList list){
    qDebug()<<"display list ->" << list;
//    CharItem *item ;
    qDebug()<<this->charList.count() <<this->charList.size();
    CharItem * temp ;
    for(int i = 0 ;i <this->charItemNum ;i++){
        temp = this->charList.at(i);
        temp->setText(list.at(i));
    }
}

