#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

///
/// \file cameramanager.h
/// \brief Header de la classe CameraManager
///

#include <SFML/Graphics.hpp>

class InputManager;

///
/// \class CameraManager
/// \brief Gestion de la vue
///
/// Gestion de la vue en utilisant la classe sf::View de la SFML ainsi
/// que la classe InputManager pour les intéractions utilisateur.
///
class CameraManager
{
public:
    CameraManager();

    void        Initialize(sf::View * pCamera, InputManager * pInputManager, float cameraSpeed);

    void        Update(float dt);

    sf::View *  GetCamera(void);

private:

    sf::View *      m_pCamera;
    InputManager *  m_pInputManager;

    float           m_fCameraSpeed;
    float           m_fCameraZoom;
};

#endif // CAMERAMANAGER_H
