#ifndef CHARTABLE_H
#define CHARTABLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QBoxLayout>
#include <QDebug>
#include <QVector>
#include <charitem.h>

class CharTable : public QWidget
{
    Q_OBJECT
public:
    explicit CharTable(QWidget *parent = 0,int itemNum = 5);

    void clear (void) ;
    void setStringList(QStringList list);


signals:

public slots:

private :
    QHBoxLayout *layout;
    int charItemNum;
    QVector <void*> charList;

};

#endif // CHARTABLE_H
