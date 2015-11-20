#include "topui.h"
#include "socket.h"

TopUI::TopUI(QWidget *parent) :
    QWidget(parent)
{

//    charTable->show();

    QPalette palette;

    palette.setColor(QPalette::Background, QColor(192,253,123));


    this->charTable = new CharTable();
     this->charTable->setFixedHeight(100);

qDebug()<<"2222";
    this->controlPanel = new QWidget();
    this->controlPanel->setFixedWidth(200);
qDebug()<<"2222";


    this->hwArea = new HandWriteCore();
    this->hwArea->setFixedWidth(300);
    this->hwArea->setFixedHeight(300);



    this->widgetSubBottom = new QWidget();


    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );

    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);





    this->vBoxLayoutMain->addWidget(this->charTable);

    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);
    this->hwArea->demo();


}
 void TopUI::handleDrawSignal(QString xml) {
//        qDebug()<<"receive strokes ->"<<xml;
        QString cmd = QString("<action type= %1 > %2 </action>").arg(CMD_QUERY_STROKES).arg(xml);
        qDebug()<<"action ->" << cmd;
        this->socket->socketSendMessage(cmd);
  //      emit queryHandWriteCoreCmd(cmd);
 }
