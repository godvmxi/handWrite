#include "topui.h"

TopUI::TopUI(QWidget *parent) :
    QWidget(parent)
{

//    charTable->show();

    qDebug()<<"1111";
//    return ;
    this->controlPanel = new QWidget();

    this->charTable = new CharTable();
    this->charTable->show();
    return;
    this->controlPanel->setFixedWidth(100);
    qDebug()<<"1111";
    this->hwArea = new HandWriteCore();
    this->widgetSubBottom = new QWidget();

    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );
    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);


    this->vBoxLayoutMain->addWidget(this->charTable);
    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);

}
