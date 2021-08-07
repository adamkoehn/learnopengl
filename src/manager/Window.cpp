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
            window_ = glfwCreateWindow(800, 600, "tutorial", NULL, NULL);
            if (window_)
            {
                glfwMakeContextCurrent(window_);
                glfwSwapInterval(1);

                glewInit_ = glewInit();
                if (glewInit_ == GLEW_OK)
                {
                    glfwSetKeyCallback(window_, keyPress);
                    glfwSetFramebufferSizeCallback(window_, sizeChange);
                    glViewport(0, 0, 800, 600);
                }
                else
                {
                    std::cout << glewGetErrorString(glewInit_) << std::endl;
                }
            }
            else
            {
                std::cout << "could not create window" << std::endl;
            }
        }
        else
        {
            std::cout << "could not init glfw" << std::endl;
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
        Graphics::Shader shader("src/shaders/rectangle.vert.glsl", "src/shaders/rectangle.frag.glsl");
        Graphics::Rectangle rectangle;

        rectangle.buffer();
        rectangle.texture("textures/wall.jpg");
        shader.use();

        glUniform1i(glGetUniformLocation(shader.getId(), "texSampler"), 0);

        glClearColor(0.2, 0.3, 0.3, 1.0);
        while (!glfwWindowShouldClose(window_))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            rectangle.draw();
            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

}