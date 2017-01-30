#include <QtCore/QAbstractAnimation>
#include <Qt3DCore/QTransform>

#include "blockchainaxisshiftcontroller.h"
#include "axisvec3i.h"

namespace TMC {

BlockchainAxisShiftController::BlockchainAxisShiftController(QAbstractAnimation *parent, Blockchain chain)
    : QObject(parent)
    , m_translationAxis(DEFAULT_AXIS)
    , m_discreteShift(0)
    , m_translationMatrix()
    , m_chain(chain) {
}

BlockchainAxisShiftController::~BlockchainAxisShiftController() {
    qDebug() << "BlockchainController destroyed." << endl; // testing memory management
}

float BlockchainAxisShiftController::getDiscreteShift() const {
    return m_discreteShift;
}

void BlockchainAxisShiftController::setDiscreteShift(float newDiscreteShift) {
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

AxisIndex BlockchainAxisShiftController::getTranslationAxis() const {
    return m_translationAxis;
}

void BlockchainAxisShiftController::setTranslationAxis(AxisIndex newTranslationAxis) {
    if (m_translationAxis == newTranslationAxis) return;

    m_translationAxis = newTranslationAxis;
    emit translationAxisChanged();
}

void BlockchainAxisShiftController::updateBlockchainTranslations() {
    AxisVec3i range = m_chain.getRange();

    for (Vec3i it = m_chain.getBasePos();
         it != (it + range);
         it = it + range.getNormalized()) {

        // TODO: Implement blocks translation update here
    }
}

}

