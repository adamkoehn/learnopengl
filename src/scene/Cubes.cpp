#include "Cubes.h"

namespace Scene
{

    Cubes::Cubes(unsigned int uModel, unsigned int numCubes) : u(uModel), n(numCubes)
    {
        unsigned int i;

        cube = new Graphics::Cube();
        cube->buffer();
        cube->texture("textures/wall.jpg");

        cubes = new glm::mat4[numCubes];
        for (i = 0; i < numCubes; i++)
        {
            cubes[i] = glm::mat4(1.0f);
            cubes[i] = glm::translate(cubes[i], glm::ballRand(5.0f));
        }
    }

    Cubes::~Cubes()
    {
        delete[] cubes;
        delete cube;
    }

    void Cubes::update(float deltaTime)
    {
        unsigned int i;
        for (i = 0; i < n; i++)
        {
            cubes[i] = glm::rotate(cubes[i], deltaTime * glm::radians(50.0f), glm::vec3(0.7f, 0.9f, 0.2f));
        }
    }

    void Cubes::render()
    {
        unsigned int i;
        for (i = 0; i < n; i++)
        {
            glUniformMatrix4fv(u, 1, GL_FALSE, glm::value_ptr(cubes[i]));
            cube->draw();
        }
    }

}