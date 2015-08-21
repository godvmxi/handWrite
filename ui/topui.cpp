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


    this->controlPanel = new QWidget();
    this->controlPanel->setFixedWidth(200);



    this->hwArea = new HandWriteCore();
    this->hwArea->setFixedWidth(400);
    this->hwArea->setFixedHeight(400);

    qDebug()<<"3333";

    this->widgetSubBottom = new QWidget();


    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );

    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);





    this->vBoxLayoutMain->addWidget(this->charTable);

    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);

    this->socket = new Socket();
    connect(this->hwArea,
            SIGNAL(add_strokes(QString)),
            this,
            SLOT(handleDrawSignal(QString))
            );

}
 void TopUI::handleDrawSignal(QString xml) {
//        qDebug()<<"receive strokes ->"<<xml;
        QString cmd = QString("<action type= %1 > %2 </action>").arg(CMD_QUERY_STROKES).arg(xml);
        qDebug()<<"action ->" << cmd;
        this->socket->socketSendMessage(cmd);
        emit queryHandWriteCoreCmd(cmd);
 }
