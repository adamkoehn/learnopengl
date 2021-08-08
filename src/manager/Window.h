#ifndef INCLUDE_WINDOW_H
#define INCLUDE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <string>

#include "Input.h"
#include "Camera.h"
#include "../graphics/Cube.h"
#include "../graphics/Shader.h"
#include "../scene/Scene.h"

namespace Manager
{

    class Window
    {
    public:
        static Window *instance();
        void setScene(Scene::Scene *s) { scene = s; }
        unsigned int getUModel() { return uModel; }
        void loop();
        bool isReady() { return glfwInit_ == GLFW_TRUE && glewInit_ == GLEW_OK && window_ != NULL; }

        bool firstMouse;
        float cameraSpeed;
        float mouseX;
        float mouseY;
        float yaw;
        float pitch;
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraRight;
        glm::vec3 cameraUp;

    private:
        Window();
        ~Window();

        static Window *inst_;
        GLFWwindow *window_ = NULL;
        Camera *camera;
        Input *input;
        int glfwInit_;
        GLenum glewInit_;
        Scene::Scene *scene;
        Graphics::Shader *shader;
        unsigned int uModel;
        unsigned int uView;
        unsigned int uProjection;
    };

}

#endif