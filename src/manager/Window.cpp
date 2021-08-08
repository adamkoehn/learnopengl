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
        camera = new Camera();
        input = new Input(camera);

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

                    shader = new Graphics::Shader("src/shaders/rectangle.vert.glsl", "src/shaders/rectangle.frag.glsl");
                    uModel = glGetUniformLocation(shader->getId(), "model");
                    uView = glGetUniformLocation(shader->getId(), "view");
                    uProjection = glGetUniformLocation(shader->getId(), "projection");
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
        delete input;
        delete camera;

        if (window_)
        {
            glfwDestroyWindow(window_);
        }

        if (glfwInit_ == GLFW_TRUE)
        {
            glfwTerminate();
        }

        if (shader)
        {
            delete shader;
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
        glm::mat4 projection;

        float deltaTime;
        float lastFrame;
        float currentFrame;

        shader->use();
        glUniform1i(glGetUniformLocation(shader->getId(), "texSampler"), 0);

        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glUniformMatrix4fv(uProjection, 1, GL_FALSE, glm::value_ptr(projection));

        lastFrame = 0.0f;
        glClearColor(0.2, 0.3, 0.3, 1.0);
        while (!glfwWindowShouldClose(window_))
        {
            currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            input->processInput(window_, deltaTime);
            scene->update(deltaTime);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(camera->getView()));
            scene->render();

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

}