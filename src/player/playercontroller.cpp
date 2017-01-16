#include <Qt3DRender>
#include <Qt3DInput>
#include <Qt3DLogic>

#include "playercontroller.h"

namespace TooManyCubes {

PlayerController::PlayerController(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity(parent)
    , m_camera(nullptr)
    , m_leftMouseButtonAction(new Qt3DInput::QAction())
    , m_fineMotionAction(new Qt3DInput::QAction())
    , m_rxAxis(new Qt3DInput::QAxis())
    , m_ryAxis(new Qt3DInput::QAxis())
    , m_txAxis(new Qt3DInput::QAxis())
    , m_tyAxis(new Qt3DInput::QAxis())
    , m_tzAxis(new Qt3DInput::QAxis())
    , m_leftMouseButtonInput(new Qt3DInput::QActionInput())
    , m_fineMotionKeyInput(new Qt3DInput::QActionInput())
    , m_mouseRxInput(new Qt3DInput::QAnalogAxisInput())
    , m_mouseRyInput(new Qt3DInput::QAnalogAxisInput())
    , m_keyboardTxPosInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardTyPosInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardTzPosInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardTxNegInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardTyNegInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardTzNegInput(new Qt3DInput::QButtonAxisInput())
    , m_keyboardDevice(new Qt3DInput::QKeyboardDevice())
    , m_mouseDevice(new Qt3DInput::QMouseDevice())
    , m_logicalDevice(new Qt3DInput::QLogicalDevice())
    , m_frameAction(new Qt3DLogic::QFrameAction())
    , m_linearSpeed(10.0f)
    , m_lookSpeed(180.0f)
    , m_firstPersonUp(QVector3D(0.0f, 1.0f, 0.0f)) {
    this->init();
}

void PlayerController::init() {
    // Left mouse button action
    m_leftMouseButtonInput->setButtons(QVector<int>() << Qt::LeftButton);
    m_leftMouseButtonInput->setSourceDevice(m_mouseDevice);
    m_leftMouseButtonAction->addInput(m_leftMouseButtonInput);

    // Fine motion action
    m_fineMotionKeyInput->setButtons(QVector<int>() << Qt::Key_Shift);
    m_fineMotionKeyInput->setSourceDevice(m_keyboardDevice);
    m_fineMotionAction->addInput(m_fineMotionKeyInput);

    // Mouse X
    m_mouseRxInput->setAxis(Qt3DInput::QMouseDevice::X);
    m_mouseRxInput->setSourceDevice(m_mouseDevice);
    m_rxAxis->addInput(m_mouseRxInput);

    // Mouse Y
    m_mouseRyInput->setAxis(Qt3DInput::QMouseDevice::Y);
    m_mouseRyInput->setSourceDevice(m_mouseDevice);
    m_ryAxis->addInput(m_mouseRyInput);

    // Keyboard Positive Tx
    m_keyboardTxPosInput->setButtons(QVector<int>() << Qt::Key_D);
    m_keyboardTxPosInput->setScale(1.0f);
    m_keyboardTxPosInput->setSourceDevice(m_keyboardDevice);
    m_txAxis->addInput(m_keyboardTxPosInput);

    // Keyboard Positive Ty
    m_keyboardTyPosInput->setButtons(QVector<int>() << Qt::Key_Q);
    m_keyboardTyPosInput->setScale(1.0f);
    m_keyboardTyPosInput->setSourceDevice(m_keyboardDevice);
    m_tyAxis->addInput(m_keyboardTyPosInput);

    // Keyboard Positive Tz
    m_keyboardTzPosInput->setButtons(QVector<int>() << Qt::Key_W);
    m_keyboardTzPosInput->setScale(1.0f);
    m_keyboardTzPosInput->setSourceDevice(m_keyboardDevice);
    m_tzAxis->addInput(m_keyboardTzPosInput);

    // Keyboard Negative Tx
    m_keyboardTxNegInput->setButtons(QVector<int>() << Qt::Key_A);
    m_keyboardTxNegInput->setScale(-1.0f);
    m_keyboardTxNegInput->setSourceDevice(m_keyboardDevice);
    m_txAxis->addInput(m_keyboardTxNegInput);

    // Keyboard Negative Ty
    m_keyboardTyNegInput->setButtons(QVector<int>() << Qt::Key_E);
    m_keyboardTyNegInput->setScale(-1.0f);
    m_keyboardTyNegInput->setSourceDevice(m_keyboardDevice);
    m_tyAxis->addInput(m_keyboardTyNegInput);

    // Keyboard Negative Tz
    m_keyboardTzNegInput->setButtons(QVector<int>() << Qt::Key_S);
    m_keyboardTzNegInput->setScale(-1.0f);
    m_keyboardTzNegInput->setSourceDevice(m_keyboardDevice);
    m_tzAxis->addInput(m_keyboardTzNegInput);


    m_logicalDevice->addAction(m_fineMotionAction);
    m_logicalDevice->addAction(m_leftMouseButtonAction);
    m_logicalDevice->addAxis(m_rxAxis);
    m_logicalDevice->addAxis(m_ryAxis);
    m_logicalDevice->addAxis(m_txAxis);
    m_logicalDevice->addAxis(m_tyAxis);
    m_logicalDevice->addAxis(m_tzAxis);


    QObject::connect(m_frameAction, SIGNAL(triggered(float)),
                     this, SLOT(onTriggered(float)));

    // Disable the logical device when the entity is disabled
    QObject::connect(this, &Qt3DCore::QEntity::enabledChanged,
                     m_logicalDevice, &Qt3DInput::QLogicalDevice::setEnabled);

    this->addComponent(m_frameAction);
    this->addComponent(m_logicalDevice);
}

void PlayerController::onTriggered(float dt) {
    if (m_camera != nullptr) {
        m_camera->translate(QVector3D(m_txAxis->value() * m_linearSpeed,
                                      m_tyAxis->value() * m_linearSpeed,
                                      m_tzAxis->value() * m_linearSpeed) * dt);
        float lookSpeed = m_lookSpeed;
        if (m_fineMotionAction->isActive())
            lookSpeed *= 0.2f;
        m_camera->pan(m_rxAxis->value() * lookSpeed * dt, m_firstPersonUp);
        m_camera->tilt(m_ryAxis->value() * lookSpeed * dt);

        QSizeF screenDimensions = QGuiApplication::primaryScreen()->size();
        QCursor::setPos(QPoint(screenDimensions.width() / 2.0, screenDimensions.height() / 2.0));
    }
}

PlayerController::~PlayerController() {
}

Qt3DRender::QCamera *PlayerController::camera() const {
    return this->m_camera;
}

float PlayerController::linearSpeed() const {
    return this->m_linearSpeed;
}

float PlayerController::lookSpeed() const {
    return this->m_lookSpeed;
}

// Note: this block had calls to QEntityPrivate, just in case
void PlayerController::setCamera(Qt3DRender::QCamera *camera) {
    if (this->m_camera != camera) {
        if (camera && !camera->parent())
            camera->setParent(this);

        this->m_camera = camera;

        emit cameraChanged();
    }
}

void PlayerController::setLinearSpeed(float linearSpeed) {
    if (this->m_linearSpeed != linearSpeed) {
        this->m_linearSpeed = linearSpeed;
        emit linearSpeedChanged();
    }
}

void PlayerController::setLookSpeed(float lookSpeed) {
    if (this->m_lookSpeed != lookSpeed) {
        this->m_lookSpeed = lookSpeed;
        emit lookSpeedChanged();
    }
}

}
