#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager;

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
};

#endif // CAMERAMANAGER_H
