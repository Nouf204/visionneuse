#include "visionneuse.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Visionneuse w;
    w.show();

    return a.exec();
}
