#include "mainwindow.h"
#include "qt3dwindow.h"
#include "scene.h"
#include "player.h"

namespace TMC {

MainWindow::MainWindow(Scene *scene, QWidget *parent)
    : QMainWindow(parent)
    , mScene(scene) {
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    Player *player = new Player(scene, view->camera()); // tied to scene

    view->setRootEntity(scene->getRootEntity());

    QWidget *container = QWidget::createWindowContainer(view, this);
    this->setCentralWidget(container); // took ownership over Qt3DWindow
}

}
