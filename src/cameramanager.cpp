///
/// \file cameramanager.cpp
/// \brief Implémentation de la classe CameraManager
///

#include "cameramanager.h"
#include "inputmanager.h"

///
/// \brief Constructeur
///
CameraManager::CameraManager()
{
}

///
/// \brief Initialisation
/// \param Pointeur sur la View
/// \param Pointeur sur l'input manager
/// \param Vitesse de la caméra
///
void CameraManager::Initialize(sf::View *pCamera, InputManager *pInputManager, float cameraSpeed)
{
    m_pCamera = pCamera;
    m_pInputManager = pInputManager;
    m_fCameraSpeed = cameraSpeed;

    m_fCameraZoom = 1.0f;
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
        m_pCamera->move(0.0f, -m_fCameraSpeed * 60 * dt);
    }
    else if (m_pInputManager->IsCameraDown())
    {
        m_pCamera->move(0.0f, m_fCameraSpeed * 60 * dt);
    }

    int zoomStatus = m_pInputManager->GetCameraZoom();
    if (1 == zoomStatus)
    {
        m_pCamera->zoom(0.9f);
    }
    else if (-1 == zoomStatus)
    {
        m_pCamera->zoom(1.1f);
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
