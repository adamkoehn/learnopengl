#include "Camera.h"

namespace Manager
{

    Camera::Camera()
    {
        this->reset();
    }

    void Camera::reset()
    {
        position_ = glm::vec3(0.0f, 0.0f, 5.0f);
        front_ = glm::vec3(0.0f, 0.0f, -1.0f);
        up_ = glm::vec3(0.0f, 1.0f, 0.0f);
        speed_ = 2.5f;
        pitch_ = 0.0f;
        yaw_ = -90.0;
    }

    void Camera::moveCameraForward(float deltaTime)
    {
        position_ += (speed_ * deltaTime) * front_;
    }

    void Camera::moveCameraBack(float deltaTime)
    {
        position_ -= (speed_ * deltaTime) * front_;
    }

    void Camera::moveCameraLeft(float deltaTime)
    {
        position_ -= glm::normalize(glm::cross(front_, up_)) * (speed_ * deltaTime);
    }

    void Camera::moveCameraRight(float deltaTime)
    {
        position_ += glm::normalize(glm::cross(front_, up_)) * (speed_ * deltaTime);
    }

    void Camera::setDirection(float pitch, float yaw)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        pitch_ = pitch;
        yaw_ = yaw;

        front_ = glm::normalize(
            glm::vec3(
                cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
                sin(glm::radians(pitch)),
                sin(glm::radians(yaw)) * cos(glm::radians(pitch))));
    }

    glm::mat4 Camera::getView()
    {
        return glm::lookAt(position_, position_ + front_, up_);
    }

}