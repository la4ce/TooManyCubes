#include <QGuiApplication>

#include "qt3dwindow.h"
#include "scene.h"
#include "player.h"

using namespace TMC;

// TODO: add some beautiful demo presets (for block generation, animations, gravity, liquids, explosions)
// TODO: use exceptions for block adding, removing, movement and animation instead of qDebug. Write your own ones.
// TODO: add ping-pong animations for nice demo scenes

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    //QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    Qt3DExtras::Qt3DWindow view;
    Scene scene;
    Player player(&scene, view.camera());

    view.setRootEntity(scene.getRootEntity());

    //view.showFullScreen();
    view.show();

    return app.exec();
}
