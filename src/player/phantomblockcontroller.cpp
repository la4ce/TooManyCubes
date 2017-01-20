#include <Qt3DLogic>

#include "phantomblockcontroller.h"

namespace TMC {

PhantomBlockController::PhantomBlockController(Qt3DCore::QEntity *parent, const Qt3DRender::QCamera *playerCamera)
    : Qt3DCore::QEntity(parent)
    , m_phantomBlock(new PhantomBlock(parent))
    , m_camera(playerCamera)
    , m_frameAction(new Qt3DLogic::QFrameAction()) {

    QObject::connect(m_frameAction, SIGNAL(triggered(float)),
                     this, SLOT(onTriggered(float)));

    this->addComponent(m_frameAction);

}

PhantomBlockController::~PhantomBlockController() {
}

void PhantomBlockController::onTriggered(float) {
    if (m_camera != nullptr) {
        m_phantomBlock->setHided(BLOCK_VISIBLE);
        QVector3D newWorldPos = m_camera->position() + m_camera->viewVector() / m_camera->viewVector().length() * PHANTOM_BLOCK_DISTANCE;
        m_phantomBlock->setPos(Scene::worldToDiscreteCoordinates(newWorldPos));
    }
}

}
