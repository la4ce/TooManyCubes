#include <Qt3DLogic>

#include "phantomblockcontroller.h"

namespace TMC {

PhantomBlockController::PhantomBlockController(Qt3DCore::QEntity *parent, const Qt3DRender::QCamera *playerCamera)
    : Qt3DCore::QEntity(parent)
    , m_phantomBlock(new Block(parent, PHANTOM_BLOCK))
    , m_camera(playerCamera)
    , m_frameAction(new Qt3DLogic::QFrameAction()) {

    QObject::connect(m_frameAction, SIGNAL(triggered(float)),
                     this, SLOT(onTriggered(float)));

    this->addComponent(m_frameAction);
    m_phantomBlock->setHided(BLOCK_VISIBLE);
    m_phantomBlock->setPos(Vec3i(2.0));

}

PhantomBlockController::~PhantomBlockController() {
}

void PhantomBlockController::onTriggered(float) {
    if (m_camera != nullptr) {
        //m_phantomBlock->setHided(BLOCK_VISIBLE);
        //m_phantomBlock->setPos(Vec3i(2.0));
    }
}

}
