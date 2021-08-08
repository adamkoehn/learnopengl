#ifndef INCLUDE_CUBES_H
#define INCLUDE_CUBES_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/random.hpp>
#include <GL/glew.h>

#include "../graphics/Cube.h"
#include "Scene.h"

namespace Scene
{

    class Cubes : public Scene
    {
    public:
        Cubes(unsigned int uModel, unsigned int numCubes);
        ~Cubes();
        void update(float deltaTime);
        void render();

    private:
        Graphics::Cube *cube;
        unsigned int u;
        unsigned int n;
        glm::mat4 *cubes;
    };

}

#endif