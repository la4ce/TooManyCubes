

















































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

using namespace TooManyCubes;

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow view;

    Scene scene;
    scene.addBlock(QVector3D(0.0, 0.0, 0.0));
    scene.addBlock(QVector3D(1.0, 0.0, 0.0));
    scene.addBlock(QVector3D(2.0, 0.0, 0.0));
    scene.addBlock(QVector3D(1.0, 0.0, 1.0));
    scene.addBlock(QVector3D(1.0, 0.0, -1.0));

    scene.addBlock(QVector3D(1.0, 1.0, 0.0));

    // Camera and CameraContoller
    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(scene.getRootEntity());
    camController->setLinearSpeed(15.0f);
    camController->setLookSpeed(360.0f);
    camController->setCamera(camera);

    view.setRootEntity(scene.getRootEntity());
    view.show();

    return app.exec();
}
