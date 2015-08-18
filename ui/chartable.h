#ifndef CHARTABLE_H
#define CHARTABLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QBoxLayout>
#include <QDebug>

class CharTable : public QWidget
{
    Q_OBJECT
public:
    explicit CharTable(QWidget *parent = 0,int layoutType =  1,int displayChar = 5,int maxChar=15);
    bool appendChar(QString c);
    void clear (void) ;


    int getMaxCharNumber() const;
    void setMaxCharNumber(int value);

    int getCurCharNum() const;
    void setCurCharNum(int value);

signals:

public slots:

private :
    QBoxLayout *layout;
    int curCharNum;
    int curCharIndex;
    int maxCharNumber ;
    int displayCharNum;
    QPushButton* charList[] ;
};

#endif // CHARTABLE_H
