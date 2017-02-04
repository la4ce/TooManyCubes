#ifndef TMC_INPUTCONTROLLER_H
#define TMC_INPUTCONTROLLER_H

#include <QVector3D>
#include <Qt3DCore/QEntity>

namespace Qt3DInput {
    class QAction;
    class QAxis;
    class QAnalogAxisInput;
    class QLogicalDevice;
    class QKeyboardDevice;
    class QMouseDevice;
    class QActionInput;
    class QButtonAxisInput;
}

namespace Qt3DRender {
    class QCamera;
}

namespace Qt3DLogic {
    class QFrameAction;
}

namespace TMC {

class Scene;
class PhantomBlockController;

class InputController : public Qt3DCore::QEntity
{
    Q_OBJECT

    Q_PROPERTY(Qt3DRender::QCamera *camera READ camera WRITE setCamera NOTIFY cameraChanged)
    Q_PROPERTY(float linearSpeed READ linearSpeed WRITE setLinearSpeed NOTIFY linearSpeedChanged)
    Q_PROPERTY(float lookSpeed READ lookSpeed WRITE setLookSpeed NOTIFY lookSpeedChanged)

public:
    static constexpr float CLICK_DURATION = 400; // milliseconds

public:
    explicit InputController(Scene *scene, PhantomBlockController *phantomBlockController);
    ~InputController();

    Qt3DRender::QCamera *camera() const;
    float linearSpeed() const;
    float lookSpeed() const;

    void setCamera(Qt3DRender::QCamera *camera);
    void setLinearSpeed(float linearSpeed);
    void setLookSpeed(float lookSpeed);
    void init();

private:
    Scene *m_scene;
    PhantomBlockController *m_phantomBlockController;

    Qt3DRender::QCamera *m_camera;

    Qt3DInput::QAction *m_leftMouseButtonAction;
    Qt3DInput::QAction *m_fineMotionAction;

    Qt3DInput::QAxis *m_rxAxis;
    Qt3DInput::QAxis *m_ryAxis;
    Qt3DInput::QAxis *m_txAxis;
    Qt3DInput::QAxis *m_tyAxis;
    Qt3DInput::QAxis *m_tzAxis;

    Qt3DInput::QActionInput *m_leftMouseButtonInput;
    Qt3DInput::QActionInput *m_fineMotionKeyInput;

    Qt3DInput::QAnalogAxisInput *m_mouseRxInput;
    Qt3DInput::QAnalogAxisInput *m_mouseRyInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTxPosInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTyPosInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTzPosInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTxNegInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTyNegInput;
    Qt3DInput::QButtonAxisInput *m_keyboardTzNegInput;

    Qt3DInput::QKeyboardDevice *m_keyboardDevice;
    Qt3DInput::QMouseDevice *m_mouseDevice;

    Qt3DInput::QLogicalDevice *m_logicalDevice;
    Qt3DLogic::QFrameAction *m_frameAction;

    float m_linearSpeed;
    float m_lookSpeed;
    QVector3D m_firstPersonUp;

signals:
    void cameraChanged();
    void linearSpeedChanged();
    void lookSpeedChanged();

public slots:
    void onTriggered(float);

};

}

#endif // TMC_INPUTCONTROLLER_H
