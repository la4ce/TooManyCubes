#ifndef TMC_PLAYER_H
#define TMC_PLAYER_H

#include <QObject>

namespace Qt3DRender {
    class QCamera;
}

namespace TMC {

class Scene;
class InputController;
class PhantomBlockController;

class Player : public QObject {
    Q_OBJECT

public:
    Player(Scene *scene, Qt3DRender::QCamera *viewCamera);

private:
    void initPlayerCamera();
    void initInputController();

    Qt3DRender::QCamera *m_playerCamera;
    PhantomBlockController *m_phantomBlockController;
    InputController *m_inputController;
};

}

#endif // TMC_PLAYER_H
