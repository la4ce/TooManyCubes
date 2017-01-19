#include <Qt3DLogic>

#include "phantomblock.h"

namespace TMC {

PhantomBlockController::PhantomBlockController(Qt3DCore::QEntity *parent, const Qt3DRender::QCamera *playerCamera)
    : Qt3DCore::QEntity(parent)
    , m_phantomBlock(new Block(parent, PHANTOM_BLOCK))
    , m_camera(playerCamera)
    , m_frameAction(new Qt3DLogic::QFrameAction()) {

    QObject::connect(m_frameAction, SIGNAL(triggered(float)),
                     this, SLOT(onTriggered(float)));

    this->addComponent(m_frameAction);

}

PhantomBlockController::~PhantomBlockController() {
}

void PhantomBlockController::onTriggered(float) {
    // We can access camera's directionVector and update block's position accordingly
}

}
