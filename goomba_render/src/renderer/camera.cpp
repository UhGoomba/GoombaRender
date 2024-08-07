#include "camera.h"

namespace GoombaRender
{
    Camera::Camera(glm::vec3 position, float aspect, float pitch, float yaw, glm::vec3 worldUp)
        : m_Position(position), m_Aspect(aspect), m_Pitch(pitch), m_Yaw(yaw), m_WorldUp(worldUp), m_Sensitivity(12.0f), m_Speed(2.5f)
    {
        CalculateCameraVectors();
    }
    
    glm::mat4 Camera::GetViewMatrix() const
    {
        return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
    }
    
    void Camera::ProcessMovementInput(glm::vec3 amount, double delta)
    {
        amount *= delta;
        m_Position += m_Speed * ((m_Right * amount.x) + (m_Front * amount.z) + (m_Up * amount.y));
    }
    
    void Camera::ProcessRotationInput(glm::vec2 amount, double delta)
    {
        amount *= m_Sensitivity * delta;
        
        m_Yaw += amount.x;
        m_Pitch += amount.y;
        
        CalculateCameraVectors();
    }
    
    void Camera::CalculateCameraVectors()
    {
        glm::vec3 front;
        front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        front.y = sin(glm::radians(m_Pitch));
        front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        m_Front = glm::normalize(front);
        
        m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
        m_Up    = glm::normalize(glm::cross(m_Right, m_Front));
    }
} // GoombaRender