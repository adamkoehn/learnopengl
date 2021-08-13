#ifndef INCLUDE_CAMERA_H
#define INCLUDE_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Manager
{

    class Camera
    {
    public:
        Camera();
        void moveCameraForward(float deltaTime);
        void moveCameraBack(float deltaTime);
        void moveCameraLeft(float deltaTime);
        void moveCameraRight(float deltaTime);
        void setDirection(float pitch, float yaw);
        glm::mat4 getView();
        glm::vec3 getPosition() { return position_; }
        float getPitch() { return pitch_; }
        float getYaw() { return yaw_; }
    
    private:
        float speed_;
        float pitch_;
        float yaw_;
        glm::vec3 position_;
        glm::vec3 front_;
        glm::vec3 up_;
    };

}

#endif