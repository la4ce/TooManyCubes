#include <QToolBar>

#include "mainwindow.h"
#include "qt3dwindow.h"
#include "scene.h"
#include "player.h"
#include "quickactionspanel.h"

namespace TMC {

MainWindow::MainWindow(Scene *scene, QWidget *parent)
    : QMainWindow(parent)
    , mScene(scene) {
    auto *qt3DWindow = new Qt3DExtras::Qt3DWindow();
    qt3DWindow->setRootEntity(scene->getRootEntity());

    // TODO: not a good place for Player creation, move when refactoring
    Player *player = new Player(scene, qt3DWindow->camera()); // tied to scene

    QWidget *container = QWidget::createWindowContainer(qt3DWindow, this);
    this->setCentralWidget(container);

//    auto qToolBar = new QToolBar();
//    addToolBar(Qt::RightToolBarArea, qToolBar);

    auto quickActionsPanel = new QuickActionsPanel();
    addDockWidget(Qt::TopDockWidgetArea, quickActionsPanel);
}

} // namespace TMC
