#ifndef TOPWRAP_H
#define TOPWRAP_H

#include <QObject>
#include <tophw.h>
#include <controlpanel.h>
#include "common.h"

class TopWrap : public QObject
{
    Q_OBJECT
public:
    explicit TopWrap(QObject *parent = 0);
    
signals:
    
public slots:
    void showInputWidgetSLot(bool showed);

private :
    TopHW *topHw ;
    ControlPanel *controlPanel ;
    int currentInput ;
    bool inputHide;

    
};

#endif // TOPWRAP_H
