

















































#include <QGuiApplication>

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DCore/QTransform>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras//QForwardRenderer>
#include <Qt3DExtras//QPhongMaterial>
#include <Qt3DExtras/QFirstPersonCameraController>

#include <Qt3DExtras/QTorusMesh>

#include "qt3dwindow.h"
#include "scene.h"
#include "player.h"

using namespace TMC;

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    //QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    Qt3DExtras::Qt3DWindow view;

    Scene &scene = Scene::getInstance();

    Player player(&scene, view.camera());

    view.setRootEntity(scene.getRootEntity());

    //view.showFullScreen();
    view.show();

    return app.exec();
}
