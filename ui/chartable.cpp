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
        connect(temp,SIGNAL(notifyTextString(int,QString)),
                this,
                SLOT(charItemClickSlot(int,QString))
                );
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
        if (list.at(i).isEmpty()){
            temp->setDisabled(true);
        }
        else{
            temp->setText(list.at(i));
        }
    }
}
void CharTable::charItemClickSlot(int id,QString text){
    QString result = QString(text);
    int itemId =  id;
    qDebug()<<"get click item -> "<<itemId<<result;
    emit selectCharSignal(itemId,result);
}

