#ifndef TMC_PHANTOMBLOCKCONTROLLER_H
#define TMC_PHANTOMBLOCKCONTROLLER_H

#include <Qt3DLogic>
#include <Qt3DRender>

#include "scene.h"
#include "phantomblock.h"

namespace TMC {

class PhantomBlockController : public Qt3DCore::QEntity {

    Q_OBJECT

public:
    static constexpr float PHANTOM_BLOCK_DISTANCE = 4.0f;

public:
    explicit PhantomBlockController(Scene *scene, const Qt3DRender::QCamera *playerCamera);
    ~PhantomBlockController();

private:
    Scene *m_scene;
    PhantomBlock *m_phantomBlock;
    const Qt3DRender::QCamera *m_camera;
    Qt3DLogic::QFrameAction *m_frameAction;

public slots:
    void onTriggered(float);

};

}

#endif // TMC_PHANTOMBLOCKCONTROLLER_H


