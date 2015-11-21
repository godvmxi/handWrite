#ifndef CHARITEM_H
#define CHARITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QStringList>
#include <QDebug>

class CharItem : public QPushButton
{
    Q_OBJECT
public:
    explicit CharItem(QWidget *parent = 0,int id = -1,QString text = "");

signals:
    void notifyTextString(int id ,QString text);

public slots:
private slots:
    void onClickSlot();

private :
    int id ;


};

#endif // CHARITEM_H
