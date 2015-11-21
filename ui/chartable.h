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



signals:
    void selectCharSignal(int id ,QString text);
public slots:
    void updateStringListSlot(QStringList list);
    void charItemClickSlot(int id,QString text);

private :
    QHBoxLayout *layout;
    int charItemNum;
    QVector <CharItem *> charList;

};

#endif // CHARTABLE_H
