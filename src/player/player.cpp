#include "player.h"

namespace TMC {

Player::Player(Scene *scene, Qt3DRender::QCamera *viewCamera)
    : m_playerCamera(viewCamera)
    , m_phantomBlockController(new PhantomBlockController(scene, viewCamera))
    , m_inputController(new InputController(scene, m_phantomBlockController)) { // TODO: check if it's okay to do like this

    initPlayerCamera();
    initInputController();
}

void Player::initPlayerCamera() {
    m_playerCamera->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    m_playerCamera->setPosition(QVector3D(20.0f, 20.0f, 20.0f));
    m_playerCamera->setViewCenter(QVector3D(0, 0, 0));
}

void Player::initInputController() {
    m_inputController->setLinearSpeed(12.0f);
    m_inputController->setLookSpeed(180.0f);
    m_inputController->setCamera(m_playerCamera);
}

} // namespace TooManyCubes


