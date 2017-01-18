#ifndef TMC_PLAYER_H
#define TMC_PLAYER_H

#include <Qt3DRender>
#include <Qt3DCore>

#include "playercontroller.h"
#include "scene.h"

namespace TMC {

class Player
{
public:
    Player(Qt3DCore::QEntity* rootEntity, Qt3DRender::QCamera* viewCamera);

private:
    void initPlayerCamera();
    void initPlayerController();

    Qt3DRender::QCamera* m_playerCamera;
    PlayerController* m_playerController;
};

}

#endif // TMC_PLAYER_H
