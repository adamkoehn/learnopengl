#ifndef INCLUDE_INPUT_H
#define INCLUDE_INPUT_H

#include <GLFW/glfw3.h>

#include "Camera.h"

namespace Manager
{

    class Input
    {
    public:
        Input(Camera *camera);
        void processInput(GLFWwindow *window, float deltaTime);

    private:
        Camera *camera_;
        bool firstMouse;
        float mouseSens;
        float mousex;
        float mousey;

    };

}

#endif