#include "topui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TopUI ui;
    ui.show();

    return a.exec();
}
