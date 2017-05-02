#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace TMC {

class Scene;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(Scene *scene, QWidget *parent = 0);

private:
    Scene *mScene;
};

}

#endif // MAINWINDOW_H
