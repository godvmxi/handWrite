#include "topui.h"
#include "socket.h"

TopUI::TopUI(QWidget *parent) :
    QWidget(parent)
{

//    charTable->show();

    QPalette palette;

    palette.setColor(QPalette::Background, QColor(192,253,123));


//    this->charTable = new CharTable();
//     this->charTable->setFixedHeight(100);
//return;

    this->controlPanel = new QWidget();
    this->controlPanel->setFixedWidth(200);



    this->hwArea = new HandWriteCore();
    this->hwArea->setFixedWidth(300);
    this->hwArea->setFixedHeight(300);



    this->widgetSubBottom = new QWidget();


    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );

    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);



    this->lineEditChar =  new QLineEdit();
    this->vBoxLayoutMain->addWidget(this->lineEditChar);

    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);

    this->recongnizer = new Recongnizer(this,"/nfs/dev/HandWrite/model/handwriting-zh_CN.model",
                                            300,300);
    connect(this->recongnizer,
            SIGNAL(notifyRecongnizerResult(QStringList)) ,
            this,
            SLOT(getRecongnizerResult(QStringList) ) );
    this->recongnizer->demo();

}
 void TopUI::handleDrawSignal(QString xml) {

 }
 void TopUI::getRecongnizerResult(QStringList result){
     qDebug()<<result.join("++");
    this->lineEditChar->setText(result.join("   "));
 }

