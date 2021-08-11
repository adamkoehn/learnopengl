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
#include "../graphics/TexturedCube.h"
#include "../graphics/Shader.h"
#include "../scene/Scene.h"

namespace Manager
{

    class Window
    {
    public:
        Window();
        ~Window();
        void setScene(Scene::Scene *scene) { scene_ = scene; }
        void loop();
        bool isReady() { return glfwInit_ == GLFW_TRUE && glewInit_ == GLEW_OK && window_ != NULL; }

    private:
        GLFWwindow *window_ = NULL;
        Input *input_;
        Camera *camera_;
        int glfwInit_;
        GLenum glewInit_;
        Scene::Scene *scene_;
    };

}

#endif