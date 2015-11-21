#ifndef RECONGNIZER_H
#define RECONGNIZER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <zinnia.h>
#include <QVector>
#include <QPoint>

class Recongnizer : public QObject
{
    Q_OBJECT
public:
    explicit Recongnizer(QObject *parent = 0,QString model="",int width = 300,int height = 300,int candidateNum=10);
    bool setModel(QString model);
    QString getModel(void);
    void addStroke();
    void clear();
    void setWidth(int width );
    void setHeight(int height );
    int getWidth();
    int getHeight();
    void addStroke(int id ,QVector<QPoint> pointList) ;
    void demo();
    void setCandidateNum(int num);
    int getCandidateNum(void);


signals:
    void notifyRecongnizerResult(QStringList result);

public slots:
    void addStrokeSlot(int id ,QVector<QPoint> pointList);

private :
    QString model ;
    zinnia::Recognizer *recognizer ;
    zinnia::Character *character;
    zinnia::Result *result;
    int width ;
    int height;
    int candidateNum;

};

#endif // RECONGNIZER_H
