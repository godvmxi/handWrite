#ifndef TopHW_H
#define TopHW_H

#include <QWidget>
#include "drawwidget.h"
#include "chartable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>
#include <QStringList>
#include <QString>
#include "chartable.h"


class TopHW : public QWidget
{
    Q_OBJECT
public:
    explicit TopHW(QWidget *parent = 0);

signals:
    void queryDrawWidgetCmd(QString cmd) ;

public slots:

private slots :
    void selectCharItemSLot(int id,QString text);




private :
    DrawWidget *hwArea;
    CharTable  *charTable;
    QWidget    *controlPanel;
    QVBoxLayout *vBoxLayoutMain;
    QHBoxLayout *hBoxLayoutSubBottom;
    QWidget *widgetSubBottom;

    QLineEdit *lineEditChar ;
    Recongnizer *recongnizer;
    CharTable   *candidateTable ;

};

#endif // TopHW_H
