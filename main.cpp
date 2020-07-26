#include <QApplication>

#include "morketiewindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MorketieWindow w;
    w.show();

    return app.exec();
}