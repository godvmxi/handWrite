#include "topwrap.h"

TopWrap::TopWrap(QObject *parent) :
    QObject(parent)
{
    this->inputHide =  false;
//    this->currentInput =  INPUT_HANDWRTE_CH;//handwrite
    this->topHw = new TopHW();
    this->controlPanel = new ControlPanel(0,true,INPUT_HANDWRTE_CH);
    this->controlPanel->setAlwaysTop(true);
    this->controlPanel->show();
    this->topHw->show();
    connect(this->controlPanel,
            SIGNAL(showInputWidgetSignal(bool)),
            this,
            SLOT(showInputWidgetSLot(bool)));
}
void TopWrap::showInputWidgetSLot(bool showed){
    if (showed){
        this->topHw->show();
    }
    else{
        this->topHw->hide();
    }

}
