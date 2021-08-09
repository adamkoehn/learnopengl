#include "Window.h"

namespace Manager
{

    static void sizeChange(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Window *Window::inst_ = NULL;

    Window::Window()
    {
        camera_ = new Camera();
        input_ = new Input(camera_);

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

                glewInit_ = glewInit();
                if (glewInit_ == GLEW_OK)
                {
                    glViewport(0, 0, 800, 600);
                    glfwSetFramebufferSizeCallback(window_, sizeChange);
                    glfwSwapInterval(1);
                    glEnable(GL_DEPTH_TEST);
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
        delete input_;
        delete camera_;

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

    void Window::destroy()
    {
        if (inst_)
        {
            delete inst_;
            inst_ = NULL;
        }
    }

    void Window::loop()
    {
        glm::mat4 projection;

        float deltaTime;
        float lastFrame;
        float currentFrame;

        lastFrame = 0.0f;
        glClearColor(0.2, 0.3, 0.3, 1.0);
        while (!glfwWindowShouldClose(window_))
        {
            currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            input_->processInput(window_, deltaTime);
            scene_->update(deltaTime);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            scene_->render(camera_);

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

}