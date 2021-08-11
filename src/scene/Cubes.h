#ifndef INCLUDE_CUBES_H
#define INCLUDE_CUBES_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/random.hpp>
#include <GL/glew.h>

#include "../graphics/TexturedCube.h"
#include "../graphics/Shader.h"
#include "../manager/Camera.h"
#include "Scene.h"

namespace Scene
{

    class Cubes : public Scene
    {
    public:
        Cubes(unsigned int numCubes);
        ~Cubes();
        void update(float deltaTime);
        void render(Manager::Camera *camera);

    private:
        Graphics::TexturedCube *cube_;
        Graphics::Shader *shader_;
        unsigned int model_;
        unsigned int view_;
        unsigned int projection_;
        unsigned int numCubes_;
        glm::mat4 *transforms_;
    };

}

#endif