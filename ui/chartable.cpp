#include "chartable.h"

CharTable::CharTable(QWidget *parent,int layoutType ,int displayChar ) :
    QWidget(parent)
{
    if (layoutType == 1 ){
        this->layout = (QBoxLayout *) new QHBoxLayout() ;
    }
    else if (layoutType == 2 ){
        this->layout = (QBoxLayout *) new QVBoxLayout() ;
    }
    //to do ,add more layout options
    else{
        return ;
    }
//
    this->displayCharNum = displayChar;
    qDebug()<<layoutType<<this->displayCharNum<<this->maxCharNumber;
    CharItem * temp = NULL;
    for(int i =  0; i<this->displayCharNum;i++){
        temp =  new CharItem();
        temp->setText("NULL");
        temp->setFixedSize(40,40);

        this->layout->addWidget(temp);

        this->charList.append(temp);
    }
    for(int i = 0; i< this->displayCharNum;i++){
//        this->layout->addWidget(this->charList.data()+i );
    }
    this->setLayout(this->layout);
}

bool CharTable::appendChar (QString c)  {
    return true;
}



void CharTable::clear (void)  {
//    QPushButton *button =  (QPushButton *)this->charList.data();
//    for(int i = 0 ;i <this->curCharNum ;i++){
//        button[i].setText("");
//    }
}

