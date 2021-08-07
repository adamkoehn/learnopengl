#ifndef INCLUDE_WINDOW_H
#define INCLUDE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include "../graphics/Cube.h"
#include "../graphics/Shader.h"

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
        void processInput(float deltaTime);

        static Window *inst_;
        GLFWwindow *window_ = NULL;
        int glfwInit_;
        GLenum glewInit_;
        float cameraSpeed;
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;
    };

}

#endif