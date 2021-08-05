#ifndef INCLUDE_WINDOW_H
#define INCLUDE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "../util/Log.h"

namespace Manager
{

    class Window
    {
    public:
        static Window *instance();
        void loop();
        bool isReady() { return glfwInit_ == GLFW_TRUE && glewInit_ == GLEW_OK && window_ != NULL; }

    private:
        Window();
        ~Window();

        static Window *inst_;
        GLFWwindow *window_ = NULL;
        int glfwInit_;
        GLenum glewInit_;
    };

}

#endif