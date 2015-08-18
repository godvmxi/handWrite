#ifndef TOPUI_H
#define TOPUI_H

#include <QWidget>
#include "handwritecore.h"
#include "chartable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

class TopUI : public QWidget
{
    Q_OBJECT
public:
    explicit TopUI(QWidget *parent = 0);

signals:

public slots:

private :
    HandWriteCore *hwArea;
    CharTable  *charTable;
    QWidget    *controlPanel;
    QVBoxLayout *vBoxLayoutMain;
    QHBoxLayout *hBoxLayoutSubBottom;
    QWidget *widgetSubBottom;

};

#endif // TOPUI_H
