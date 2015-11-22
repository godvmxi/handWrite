#include "tophw.h"
#include "topwrap.h"
#include <QApplication>
#include<QDebug>
#include <QTextCodec>


int main(int argc, char *argv[])
{

    QTextCodec::setCodecForTr(QTextCodec::codecForName("BIG-5"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    TopWrap wrap;
   // ui.show();

    return a.exec();
}
