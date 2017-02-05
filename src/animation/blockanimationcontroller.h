#ifndef BLOCKANIMATIONCONTROLLER_H
#define BLOCKANIMATIONCONTROLLER_H

#include <QObject>
#include <QMatrix4x4>

#include "blockchain.h"

class QAbstractAnimation;

namespace Qt3DCore {
    class QTransform;
}

namespace TMC {

class Vec3i;
class AxisVec3i;
class Scene;

class BlockAnimationController : public QObject {
    Q_OBJECT
    Q_PROPERTY(float discreteShift READ getDiscreteShift WRITE setDiscreteShift NOTIFY discreteShiftChanged)
    Q_PROPERTY(AxisIndex translationAxis READ getTranslationAxis WRITE setTranslationAxis NOTIFY translationAxisChanged)

public:
    /* We want parent to be QAbstractAnimation so BlockchainController always deleted
     * automatically when animation deletes. */
    BlockAnimationController(QAbstractAnimation *parent, Scene *scene, Blockchain chain, AxisIndex axis);
    ~BlockAnimationController();

    float getDiscreteShift() const;
    void setDiscreteShift(float newShift);

    AxisIndex getTranslationAxis() const;
    void setTranslationAxis(AxisIndex newTranslationAxis);

signals:
    void discreteShiftChanged();
    void translationAxisChanged();

private:
    void updateBlockchainTranslations();

    Scene *m_scene;
    AxisIndex m_translationAxis;
    float m_discreteShift;

    QMatrix4x4 m_translationMatrix;
    Blockchain m_chain;
};

}

#endif // BLOCKANIMATIONCONTROLLER_H
