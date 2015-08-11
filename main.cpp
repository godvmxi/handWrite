#include "handwritecore.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HandWriteCore w;
    w.show();

    return a.exec();
}
