#include "blockanimation.h"
#include "axisvec3i.h"
#include "blockchain.h"
#include "blockchainaxisshiftcontroller.h"

namespace TMC {

BlockAnimation::BlockAnimation(QObject *parent, Blockchain blocks, AxisVec3i animatedShift, float animationLengthUnit)
    : QPropertyAnimation(parent)
    , m_controller(new BlockchainAxisShiftController(this, blocks)){

    m_controller->setProperty("translationAxis", animatedShift.getAxis());
    this->setTargetObject(m_controller);
    this->setPropertyName("discreteShift");
    this->setStartValue(QVariant::fromValue(0.0f));
    this->setEndValue(QVariant::fromValue((float)animatedShift.getValue()));
    this->setDuration(animationLengthUnit * animatedShift.getValue() * 1000.0f);
    this->setLoopCount(1);
}

BlockAnimation::~BlockAnimation() {
    qDebug() << "BlockAnimation destroyed." << endl; // testing memory management
}

void BlockAnimation::animate() {
    this->start(QAbstractAnimation::DeleteWhenStopped);
}


}
