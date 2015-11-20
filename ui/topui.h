#ifndef TOPUI_H
#define TOPUI_H

#include <QWidget>
#include "handwritecore.h"
#include "chartable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include "socket.h"
 #include <QLineEdit>

class TopUI : public QWidget
{
    Q_OBJECT
public:
    explicit TopUI(QWidget *parent = 0);

signals:
    void queryHandWriteCoreCmd(QString cmd) ;

public slots:

private slots :
    void handleDrawSignal(QString xml) ;


private :
    HandWriteCore *hwArea;
    CharTable  *charTable;
    QWidget    *controlPanel;
    QVBoxLayout *vBoxLayoutMain;
    QHBoxLayout *hBoxLayoutSubBottom;
    QWidget *widgetSubBottom;

    QLineEdit *lineEditChar ;

};

#endif // TOPUI_H
