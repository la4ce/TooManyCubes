#ifndef TMC_PHANTOMBLOCK_H
#define TMC_PHANTOMBLOCK_H

#include "scene.h"

namespace TMC {

class PhantomBlockController : public Qt3DCore::QEntity {

    Q_OBJECT

public:
    explicit PhantomBlockController(Qt3DCore::QEntity *parent, const Qt3DRender::QCamera *playerCamera);
    ~PhantomBlockController();

private:
    Block *m_phantomBlock;
    const Qt3DRender::QCamera *m_camera;
    Qt3DLogic::QFrameAction *m_frameAction;

public slots:
    void onTriggered(float);

};

}

#endif // TMC_PHANTOMBLOCK_H


