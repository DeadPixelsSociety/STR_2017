
///                                                        ///
/// \file cameramanager.cpp                                ///
/// \brief Implémentation de la classe CameraManager       ///
///                                                        ///

#include "cameramanager.h"
#include "inputmanager.h"

CameraManager::CameraManager()
{
}

void CameraManager::Initialize(sf::View *pCamera, InputManager *pInputManager, float cameraSpeed)
{
    m_pCamera = pCamera;
    m_pInputManager = pInputManager;
    m_fCameraSpeed = cameraSpeed;
}

///
/// \brief Met à jour la caméra
/// \param dt Le delta temps
///

void CameraManager::Update(float dt)
{
    if (m_pInputManager->IsCameraLeft())
    {
        m_pCamera->move(-m_fCameraSpeed * 60 * dt, 0.0f);
    }
    else if (m_pInputManager->IsCameraRight())
    {
        m_pCamera->move(m_fCameraSpeed * 60 * dt, 0.0f);
    }

    if (m_pInputManager->IsCameraTop())
    {
        m_pCamera->move(0.0f, m_fCameraSpeed * 60 * dt);
    }
    else if (m_pInputManager->IsCameraDown())
    {
        m_pCamera->move(0.0f, -m_fCameraSpeed * 60 * dt);
    }
}

///
/// \brief Renvoi la caméra
/// \return Pointeur sur l'instance de sf::View
///

sf::View * CameraManager::GetCamera(void)
{
    return(m_pCamera);
}
