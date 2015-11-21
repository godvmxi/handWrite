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
    explicit CharTable(QWidget *parent = 0,int layoutType =  1,int displayChar = 5);

    void clear (void) ;
    void setStringList(QStringList list);


    int getMaxCharNumber() const;
    void setMaxCharNumber(int value);


signals:

public slots:

private :
    QBoxLayout *layout;
    int curCharNum;
    int curCharIndex;
    int maxCharNumber ;
    int displayCharNum;
    QVector <CharItem *> charList;

};

#endif // CHARTABLE_H
