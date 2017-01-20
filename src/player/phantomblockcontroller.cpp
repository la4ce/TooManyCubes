#include <Qt3DLogic>

#include "phantomblockcontroller.h"

namespace TMC {

PhantomBlockController::PhantomBlockController(Scene *scene, const Qt3DRender::QCamera *playerCamera)
    : Qt3DCore::QEntity(scene->getRootEntity())
    , m_scene(scene)
    , m_phantomBlock(new PhantomBlock(scene->getRootEntity()))
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
        Vec3i newDiscretePos = Scene::worldToDiscreteCoordinates(
                    m_camera->position() + m_camera->viewVector() / m_camera->viewVector().length() * PHANTOM_BLOCK_DISTANCE);

        HidedState hidedState = m_scene->blockCouldBePlaced(newDiscretePos) ? BLOCK_VISIBLE : BLOCK_HIDED;

        m_phantomBlock->setHided(hidedState);
        m_phantomBlock->setPos(newDiscretePos);
    }
}

}
