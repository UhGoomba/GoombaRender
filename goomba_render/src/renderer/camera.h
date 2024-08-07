#ifndef GOOMBARENDER_CAMERA_H
#define GOOMBARENDER_CAMERA_H

// the camera is responsible for the view and projection matrices
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GoombaRender
{
    class Camera // TODO - Camera view and projection matrices should be a part of a scene ubo
    {
    public:
        Camera(glm::vec3 position = {0.0f, 0.0f, 0.0f}, float aspect = 16/9, float pitch = 0.0f, float yaw = -90.0f, glm::vec3 worldUp = {0.0f, 1.0f, 0.0f});
        
        virtual glm::mat4 GetViewMatrix() const;
        virtual glm::mat4 GetProjectionMatrix() const = 0;
        
        void ProcessMovementInput(glm::vec3 amount, double delta);
        void ProcessRotationInput(glm::vec2 amount, double delta);
        
        inline void SetAspect(float aspect) { m_Aspect = aspect; }
        inline void SetSensitivity(float sensitivity) {m_Sensitivity = sensitivity; }
        inline void SetSpeed(float speed) { m_Speed = speed; }
        
        inline const glm::vec3& GetPosition() const { return m_Position; };
        inline const glm::vec3& GetForward() const { return m_Front; };
        inline const glm::vec3& GetRight() const { return m_Right; };
        inline const glm::vec3& GetUp() const { return m_Up; };
    protected:
        glm::vec3 m_Position, m_Front, m_Up, m_Right, m_WorldUp;
        float m_Pitch, m_Yaw;
        float m_Sensitivity, m_Speed;
        float m_Aspect;
        
        void CalculateCameraVectors();
    };
    
} // GoombaRender

#endif //GOOMBARENDER_CAMERA_H
