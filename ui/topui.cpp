#include "topui.h"

TopUI::TopUI(QWidget *parent) :
    QWidget(parent)
{

//    charTable->show();

//    this->controlPanel = new QWidget();

    this->charTable = new CharTable();
    this->charTable->show();
        return ;
    QWidget *charWidget  = new QWidget();



    qDebug()<<"2222";
//    return ;
    this->hwArea = new HandWriteCore();
    qDebug()<<"3333";
    return ;
    this->widgetSubBottom = new QWidget();
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));

    this->charTable->setPalette(palette);
    this->controlPanel->setPalette(palette);

    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );

    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);




 //   this->vBoxLayoutMain->addWidget(this->charTable);
    this->vBoxLayoutMain->addWidget(charWidget);
    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);

}
