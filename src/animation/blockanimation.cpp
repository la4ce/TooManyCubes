#include "blockanimation.h"
#include "blockchainanimationcontroller.h"

namespace TMC {

BlockAnimation::BlockAnimation(QObject *parent, Blockchain blocks, AxisVec3i animatedShift, float animationLengthUnit)
    : QPropertyAnimation(parent)
    , m_blocks(blocks)
    , m_shift(animatedShift)
    , m_controller(new BlockchainAxisShiftController(this, blocks, animatedShift.getAxis())){

    m_controller->setProperty("translationAxis", animatedShift.getAxis());
    this->setTargetObject(m_controller);
    this->setPropertyName("discreteShift");
    this->setStartValue(QVariant::fromValue(0.0f));
    this->setEndValue(QVariant::fromValue(static_cast<float>(animatedShift.getValue())));
    this->setDuration(animationLengthUnit * abs(animatedShift.getValue()));
    //this->setEasingCurve(QEasingCurve::InCubic);
    this->setLoopCount(1);

    QObject::connect(this, SIGNAL(finished()), SLOT(finishedWrapper()));

    // TODO: add couple different animation easings (Hint: ->setEasingCurve())
}

BlockAnimation::~BlockAnimation() {
    qDebug() << "BlockAnimation destroyed.";
}

void BlockAnimation::animate() {
    this->start(QAbstractAnimation::DeleteWhenStopped);
}

void BlockAnimation::finishedWrapper() {
    emit cleanupTrigger(m_blocks, m_shift);
}

}
