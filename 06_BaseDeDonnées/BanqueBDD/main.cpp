#include "banque.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Banque w;
    w.show();
    return a.exec();
}
