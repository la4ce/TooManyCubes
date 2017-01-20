#ifndef TMC_PLAYER_H
#define TMC_PLAYER_H

#include <Qt3DRender>
#include <Qt3DCore>

#include "cameracontroller.h"
#include "phantomblockcontroller.h"
#include "scene.h"

namespace TMC {

class Player
{
public:
    Player(Qt3DCore::QEntity *rootEntity, Qt3DRender::QCamera *viewCamera);

private:
    void initPlayerCamera();
    void initPlayerController();

    Qt3DRender::QCamera *m_playerCamera;
    CameraController *m_cameraContoller;
    PhantomBlockController *m_phantomBlockController;

};

}

#endif // TMC_PLAYER_H
