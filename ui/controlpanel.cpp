#include "controlpanel.h"
#include <QDebug>

ControlPanel::ControlPanel(QWidget *parent,bool inputShowState,enum INPUT_METHOD defaultInput) :
    QWidget(parent)
{
    this->vBoxLayoutMain = new QVBoxLayout();
    this->buttonHideShow = new QPushButton();
    this->buttonSwitch = new QPushButton();

    this->vBoxLayoutMain->addWidget(this->buttonHideShow);
    this->vBoxLayoutMain->addWidget(this->buttonSwitch);
    this->setLayout(this->vBoxLayoutMain);
    this->inputWidgetShowState = inputShowState;
    if (this->inputWidgetShowState){
        this->buttonHideShow->setText("Hide");
    }
    else {
        this->buttonHideShow->setText("Show");
    }
    this->inputMethod = defaultInput ;
    connect(this->buttonHideShow,
            SIGNAL(clicked()),
            this,
            SLOT(onHideShowClickedSlot()) );
    connect(this->buttonSwitch,
            SIGNAL(clicked()),
            this,
            SLOT(onSwitchInputMethod()));
}
void ControlPanel::setAlwaysTop(bool enabled){
    Qt::WindowFlags flags =  this->windowFlags();
 //   qDebug()<<"windows flags->"<<flags;
    if (enabled){
        flags |= Qt::WindowStaysOnTopHint;
    }
    else {
        flags &= ~Qt::WindowStaysOnTopHint;
    }
    this->setWindowFlags(flags);
}

void ControlPanel::onHideShowClickedSlot(void){
    this->inputWidgetShowState =  this->inputWidgetShowState ? false :true ;
    if(this->inputWidgetShowState){
        this->buttonHideShow->setText("Hide");
    }
    else {
        this->buttonHideShow->setText("Show");
    }
    emit this->showInputWidgetSignal(this->inputWidgetShowState);
}

void ControlPanel::onSwitchInputMethod(void){
    this->inputMethod = INPUT_NUM;

    emit this->switchInputMethodSignal(this->inputMethod);

}

QString ControlPanel::getInputMethodIcon(enum INPUT_METHOD input){
    QString result ;
    return result;
}

QString ControlPanel::getInputMethodShortName(enum INPUT_METHOD input){

    QString result = "NULL";
    switch(input){
        INPUT_HANDWRTE_CH :
            result = "HW";
            break;
        INPUT_NUM :
            result = "0";
            break;
        INPUT_CHAR :
            result = "A";
            break;
        default :
            break;
    }

    return result;
}

enum INPUT_METHOD ControlPanel::getNextInputMethod(enum INPUT_METHOD input){
    enum INPUT_METHOD result ;
    return result;
}

