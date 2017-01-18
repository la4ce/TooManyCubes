#include "player.h"

namespace TMC {

Player::Player(Qt3DCore::QEntity* rootEntity, Qt3DRender::QCamera* viewCamera)
    : m_playerCamera(viewCamera)
    , m_playerController(new PlayerController(rootEntity)) {

    initPlayerCamera();
    initPlayerController();
}

void Player::initPlayerCamera() {
    this->m_playerCamera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    this->m_playerCamera->setPosition(QVector3D(0, 0, 40.0f));
    this->m_playerCamera->setViewCenter(QVector3D(0, 0, 0));
}

void Player::initPlayerController() {
    this->m_playerController->setLinearSpeed(12.0f);
    this->m_playerController->setLookSpeed(180.0f);
    this->m_playerController->setCamera(m_playerCamera);
}

} // namespace TooManyCubes


