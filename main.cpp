#include "atow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    atow w;
    w.show();

    return a.exec();
}
