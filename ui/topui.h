#ifndef TOPUI_H
#define TOPUI_H

#include <QWidget>
#include "DrawWidget.h"
#include "chartable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>
#include <QStringList>
#include <QString>
#include "chartable.h"

class TopUI : public QWidget
{
    Q_OBJECT
public:
    explicit TopUI(QWidget *parent = 0);

signals:
    void queryDrawWidgetCmd(QString cmd) ;

public slots:
    void updateRecongnizerResult(QStringList result) ;
private slots :




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

#endif // TOPUI_H
