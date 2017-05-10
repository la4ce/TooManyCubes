#include <QApplication>
#include <QFile>

#include "mainwindow.h"
#include "scene.h"

using namespace TMC;

int main(int argc, char* argv[]) {
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QFile stylesFile(":/styles/app_styles.css");
    stylesFile.open(QFile::ReadOnly);
    QString appStylesheet = QLatin1String(stylesFile.readAll());

    app.setStyleSheet(appStylesheet);
    Scene scene;
    MainWindow window(&scene);

    window.show();
    window.resize(800, 600);
    return app.exec();
}
