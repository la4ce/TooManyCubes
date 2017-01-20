#ifndef TMC_PHANTOMBLOCKCONTROLLER_H
#define TMC_PHANTOMBLOCKCONTROLLER_H

#include <Qt3DLogic>
#include <Qt3DRender>

#include "phantomblock.h"

namespace TMC {

class PhantomBlockController : public Qt3DCore::QEntity {

    Q_OBJECT

public:
    explicit PhantomBlockController(Qt3DCore::QEntity *parent, const Qt3DRender::QCamera *playerCamera);
    ~PhantomBlockController();

private:
    PhantomBlock *m_phantomBlock;
    const Qt3DRender::QCamera *m_camera;
    Qt3DLogic::QFrameAction *m_frameAction;

public slots:
    void onTriggered(float);

};

}

#endif // TMC_PHANTOMBLOCKCONTROLLER_H


