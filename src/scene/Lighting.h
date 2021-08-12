#ifndef INCLUDE_LIGHTING_H
#define INCLUDE_LIGHTING_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include "../graphics/Shader.h"
#include "../graphics/NormalCube.h"
#include "../graphics/Light.h"

namespace Scene
{

    class Lighting : public Scene
    {
    public:
        Lighting();
        ~Lighting();
        void update(float deltaTime);
        void render(Manager::Camera *camera);
    
    private:
        unsigned int lightModel_;
        unsigned int cubeModel_;
        unsigned int lightView_;
        unsigned int cubeView_;
        unsigned int lightProjection_;
        unsigned int cubeProjection_;
        unsigned int lightColor_;
        unsigned int objectColor_;
        unsigned int lightPos_;
        float lightAngle_;
        Graphics::Shader *lightShader_;
        Graphics::Shader *cubeShader_;
        glm::mat4 cubeTransform_;
        glm::mat4 lightTransform_;
        glm::vec3 lightLocation_;
        Graphics::NormalCube *cube_;
        Graphics::Light *light_;
    };

}

#endif