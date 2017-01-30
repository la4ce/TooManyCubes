#ifndef BLOCKANIMATION_H
#define BLOCKANIMATION_H

#include <Qt3DCore>

namespace TMC {

class AxisVec3i;
class Blockchain;
class BlockchainAxisShiftController;

// Friend of TMC::Block
class BlockAnimation : public QPropertyAnimation {
public:
    BlockAnimation(QObject *parent, Blockchain blocks, AxisVec3i animatedShift, float animationLengthUnit);
    ~BlockAnimation();

    void animate();

private:
    BlockchainAxisShiftController *m_controller;
};

}

#endif // BLOCKANIMATION_H
