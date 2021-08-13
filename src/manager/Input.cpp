#include "Input.h"

namespace Manager
{

    Input::Input(Camera *camera) : camera_(camera)
    {
        mouseSens = 0.1f;
        mousex = 0.0f;
        mousey = 0.0f;
        firstMouse = true;
    }

    void Input::processInput(GLFWwindow *window, float deltaTime)
    {
        double xpos, ypos, xoff, yoff;

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera_->moveCameraForward(deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera_->moveCameraBack(deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera_->moveCameraLeft(deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera_->moveCameraRight(deltaTime);

        glfwGetCursorPos(window, &xpos, &ypos);
        if (firstMouse)
        {
            mousex = xpos;
            mousey = ypos;
            firstMouse = false;
        }

        if (xpos != mousex || ypos != mousey)
        {
            xoff = xpos - mousex;
            yoff = mousey - ypos;
            mousex = xpos;
            mousey = ypos;
            xoff *= mouseSens;
            yoff *= mouseSens;
            camera_->setDirection(camera_->getPitch() + yoff, camera_->getYaw() + xoff);
        }
    }

}