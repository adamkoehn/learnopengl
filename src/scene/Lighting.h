#ifndef INCLUDE_LIGHTING_H
#define INCLUDE_LIGHTING_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include "../graphics/Shader.h"
#include "../graphics/TexturedCube.h"
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
        unsigned int viewPos_;
        struct {
            unsigned int specular_;
            unsigned int shininess_;
        } material_;
        struct {
            unsigned int position_;
            unsigned int ambient_;
            unsigned int diffuse_;
            unsigned int specular_;
        } light_;
        float lightAngle_;
        Graphics::Shader *lightShader_;
        Graphics::Shader *cubeShader_;
        glm::mat4 cubeTransform_;
        glm::mat4 lightTransform_;
        glm::vec3 lightLocation_;
        Graphics::TexturedCube *cube_;
        Graphics::Light *lightCube_;
    };

}

#endif