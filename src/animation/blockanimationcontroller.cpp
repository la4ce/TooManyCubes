#include <QtCore/QAbstractAnimation>
#include <Qt3DCore/QTransform>

#include "blockanimationcontroller.h"
#include "axisvec3i.h"
#include "scene.h"

namespace TMC {

BlockAnimationController::BlockAnimationController(QAbstractAnimation *parent, Scene *scene, Blockchain chain, AxisIndex axis)
    : QObject(parent)
    , m_scene(scene)
    , m_translationAxis(axis)
    , m_discreteShift(0)
    , m_translationMatrix()
    , m_chain(chain) {
}

BlockAnimationController::~BlockAnimationController() {
    qDebug() << "BlockchainAnimationController destroyed.";
}

float BlockAnimationController::getDiscreteShift() const {
    return m_discreteShift;
}

void BlockAnimationController::setDiscreteShift(float newDiscreteShift) {
    if (qFuzzyCompare(m_discreteShift, newDiscreteShift)) return;

    m_discreteShift = newDiscreteShift;

    m_translationMatrix.setToIdentity();
    m_translationMatrix.translate(
                m_translationAxis == XAXIS ? m_discreteShift : 0.0f,
                m_translationAxis == YAXIS ? m_discreteShift : 0.0f,
                m_translationAxis == ZAXIS ? m_discreteShift : 0.0f
                );

    updateBlockchainTranslations();
    emit discreteShiftChanged();
}

AxisIndex BlockAnimationController::getTranslationAxis() const {
    return m_translationAxis;
}

void BlockAnimationController::setTranslationAxis(AxisIndex newTranslationAxis) {
    if (m_translationAxis == newTranslationAxis) return;

    m_translationAxis = newTranslationAxis;
    emit translationAxisChanged();
}

void BlockAnimationController::updateBlockchainTranslations() {

    for (Blockchain::const_iterator it = m_chain.begin(); it != m_chain.end(); ++it) {
        m_scene->getBlock(*it)->translateFromBasePos(m_translationMatrix);
    }
}

}

