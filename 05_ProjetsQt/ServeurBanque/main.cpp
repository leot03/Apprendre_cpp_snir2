#include "banqueserveurwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BanqueServeurWidget w;
    w.show();
    return a.exec();
}
