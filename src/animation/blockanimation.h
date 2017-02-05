#ifndef BLOCKANIMATION_H
#define BLOCKANIMATION_H

#include <QPropertyAnimation>

#include "blockchain.h"
#include "axisvec3i.h"

namespace TMC {

class Scene;
class BlockAnimationController;

// Friend of TMC::Block
class BlockAnimation : public QPropertyAnimation {
    Q_OBJECT

public:
    BlockAnimation(Scene *scene, Blockchain blocks, AxisVec3i animatedShift, float animationLengthUnit);
    ~BlockAnimation();

    void animate();

private slots:
    void finishedWrapper();

signals:
    void cleanupTrigger(Blockchain movedBlocks, AxisVec3i shift);

private:
    Blockchain m_blocks;
    AxisVec3i m_shift;
    BlockAnimationController *m_controller;
};

}

#endif // BLOCKANIMATION_H
