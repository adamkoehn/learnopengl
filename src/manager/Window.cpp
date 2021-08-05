#include "Window.h"

namespace Manager
{

    static void keyPress(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    static void sizeChange(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Window *Window::inst_ = NULL;

    Window::Window()
    {
        glfwInit_ = glfwInit();
        if (glfwInit_ == GLFW_TRUE)
        {
            glfwWindowHint(GLFW_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_VERSION_MINOR, 6);
            // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwSwapInterval(1);
            window_ = glfwCreateWindow(800, 600, "tutorial", NULL, NULL);
            if (window_)
            {
                glfwMakeContextCurrent(window_);

                glewInit_ = glewInit();
                if (glewInit_ == GLEW_OK)
                {
                    glfwSetKeyCallback(window_, keyPress);
                    glfwSetFramebufferSizeCallback(window_, sizeChange);
                    glViewport(0, 0, 800, 600);
                }
                else
                {
                    Log::error((const char *)glewGetErrorString(glewInit_));
                }
            }
            else
            {
                Log::error("could not create window");
            }
        }
        else
        {
            Log::error("could not init glfw");
        }
    }

    Window::~Window()
    {
        if (window_)
        {
            glfwDestroyWindow(window_);
        }

        if (glfwInit_ == GLFW_TRUE)
        {
            glfwTerminate();
        }
    }

    Window *Window::instance()
    {
        if (inst_ == NULL)
        {
            inst_ = new Window();
        }

        return inst_;
    }

    void Window::loop()
    {
        glClearColor(0.2, 0.3, 0.3, 1.0);
        while (!glfwWindowShouldClose(window_))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

}