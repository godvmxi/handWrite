#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "common.h"

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0,bool inputShowState=true,enum INPUT_METHOD  defaultInput = INPUT_HANDWRTE_CH);
    void setAlwaysTop(bool enabled);
    
signals:
    void showInputWidgetSignal(bool showed);
    void switchInputMethodSignal(enum INPUT_METHOD inputType);



public slots:
private slots:
    void onHideShowClickedSlot(void);
    void onSwitchInputMethod(void);
private :
    QVBoxLayout *vBoxLayoutMain;
    QPushButton *buttonSwitch;
    QPushButton *buttonHideShow;
    bool inputWidgetShowState;
    enum INPUT_METHOD inputMethod ;
    
    QString getInputMethodIcon(enum INPUT_METHOD input);
    QString getInputMethodShortName(enum INPUT_METHOD input);
    enum INPUT_METHOD getNextInputMethod(enum INPUT_METHOD input);
};


#endif // CONTROLPANEL_H
