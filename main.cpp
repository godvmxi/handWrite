#include "hangwriteui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HangWriteUi w;
    w.show();

    return a.exec();
}
