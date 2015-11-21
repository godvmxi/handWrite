#include "topui.h"


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



    this->hwArea = new DrawWidget();
    this->hwArea->setFixedWidth(300);
    this->hwArea->setFixedHeight(300);



    this->widgetSubBottom = new QWidget();


    this->hBoxLayoutSubBottom = new QHBoxLayout();
    this->vBoxLayoutMain = new QVBoxLayout();

    this->hBoxLayoutSubBottom->addWidget(this->hwArea);
    this->hBoxLayoutSubBottom->addWidget(this->controlPanel );

    this->widgetSubBottom->setLayout(this->hBoxLayoutSubBottom);



    this->lineEditChar =  new QLineEdit();
    this->lineEditChar->setFixedHeight(60);\
    this->lineEditChar->setStyleSheet("color:red");//文本颜色

    this->lineEditChar->setFont(QFont("Timers" , 14 ,  QFont::Bold));
    this->vBoxLayoutMain->addWidget(this->lineEditChar);
    this->candidateTable =  new CharTable(this,10);
    this->vBoxLayoutMain->addWidget(this->candidateTable);
    this->vBoxLayoutMain->addWidget(this->widgetSubBottom);
    this->setLayout(this->vBoxLayoutMain);

    this->recongnizer = new Recongnizer(this,"/nfs/dev/HandWrite/model/handwriting-zh_CN.model",
                                            300,300,15);
    connect(this->hwArea,
            SIGNAL(addStrokeSignal(int,QVector<QPoint>)),
            this->recongnizer,
            SLOT(addStrokeSlot(int,QVector<QPoint>))
            );
    connect(this->recongnizer,
            SIGNAL(notifyRecongnizerResult(QStringList)) ,
            this->candidateTable,
            SLOT(updateStringListSlot(QStringList) ) );
    //this->recongnizer->demo();

}

 void TopUI::updateRecongnizerResult(QStringList result){
 //    qDebug()<<result.join("++");
    //this->lineEditChar->setText(result.join(" "));
     //this->charTable->setStringList(result);
 }

