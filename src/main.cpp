#include <QApplication>

#include "mainwindow.h"
#include "scene.h"

using namespace TMC;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Scene scene;
    MainWindow window(&scene);

    window.show();
    window.resize(800, 600);
    return app.exec();
}
