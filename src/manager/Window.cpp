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
        glm::mat4 model;
        glm::mat4 projection;

        float deltaTime;
        float lastFrame;
        float currentFrame;
        unsigned int i;
        unsigned int uModel;
        unsigned int uView;
        unsigned int uProjection;

        Graphics::Shader shader("src/shaders/rectangle.vert.glsl", "src/shaders/rectangle.frag.glsl");
        Graphics::Cube cube;

        cube.buffer();
        cube.texture("textures/wall.jpg");
        shader.use();

        uModel = glGetUniformLocation(shader.getId(), "model");
        uView = glGetUniformLocation(shader.getId(), "view");
        uProjection = glGetUniformLocation(shader.getId(), "projection");
        glUniform1i(glGetUniformLocation(shader.getId(), "texSampler"), 0);

        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glUniformMatrix4fv(uProjection, 1, GL_FALSE, glm::value_ptr(projection));

        glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, -4.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f),
        };

        lastFrame = 0.0f;
        glClearColor(0.2, 0.3, 0.3, 1.0);
        while (!glfwWindowShouldClose(window_))
        {
            currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            input->processInput(window_, deltaTime);;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(camera->getView()));

            for (i = 0; i < 10; i++)
            {
                model = glm::mat4(1.0f);
                model = glm::translate(model, cubePositions[i]);
                model = glm::rotate(model, currentFrame * glm::radians(50.0f), glm::vec3(0.7f, 0.9f, 0.2f));
                glUniformMatrix4fv(uModel, 1, GL_FALSE, glm::value_ptr(model));
                cube.draw();
            }

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }
    }

}