#include "topui.h"
#include <QApplication>
#include "zinnia.h"
#include<QDebug>
#include <QTextCodec>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    qDebug()<<QTextCodec::codecForLocale();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("BIG-5"));
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
           QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


//    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForCStrings(  QTextCodec::codecForLocale())  ;

    QApplication a(argc, argv);
    TopUI ui;
    ui.show();

    return a.exec();
}
