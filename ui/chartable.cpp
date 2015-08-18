#include "chartable.h"

CharTable::CharTable(QWidget *parent,int layoutType ,int displayChar ,int maxChar ) :
    QWidget(parent)
{
    if (layoutType == 1 ){
        this->layout = (QBoxLayout *) new QHBoxLayout() ;
    }
    else if (layoutType == 2 ){
        this->layout = (QBoxLayout *) new QVBoxLayout() ;
    }
    else{
        return ;
    }
//
    this->displayCharNum = displayChar;
    this->maxCharNumber = maxChar;
    qDebug()<<layoutType<<this->displayCharNum<<this->maxCharNumber;
    for(int i =  0; i<this->maxCharNumber;i++){
         this->charList[i] =  new QPushButton("test");
    }
    for(int i = 0; i< this->displayCharNum;i++){
         this->layout->addWidget(this->charList[i] );
    }
//    qDebug("????");
//    return ;
    this->setLayout(this->layout);
}

bool CharTable::appendChar (QString c)  {
    return true;
}
int CharTable::getMaxCharNumber() const
{
    return maxCharNumber;
}

void CharTable::setMaxCharNumber(int value)
{
    maxCharNumber = value;
}
int CharTable::getCurCharNum() const
{
    return curCharNum;
}

void CharTable::setCurCharNum(int value)
{
    curCharNum = value;
}


void CharTable::clear (void)  {
    for(int i = 0 ;i <this->curCharNum ;i++){
        this->charList[i]->setText("");
    }
}

