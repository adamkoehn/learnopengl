#include "Cubes.h"

namespace Scene
{

    Cubes::Cubes(unsigned int numCubes) : numCubes_(numCubes)
    {
        glm::mat4 projection;
        unsigned int i;

        shader_ = new Graphics::Shader("src/shaders/cubes.vert.glsl", "src/shaders/cubes.frag.glsl");
        model_ = glGetUniformLocation(shader_->getId(), "model");
        view_ = glGetUniformLocation(shader_->getId(), "view");
        projection_ = glGetUniformLocation(shader_->getId(), "projection");

        shader_->use();
        glUniform1i(glGetUniformLocation(shader_->getId(), "texSampler"), 0);

        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glUniformMatrix4fv(projection_, 1, GL_FALSE, glm::value_ptr(projection));

        cube_ = new Graphics::TexturedCube();
        cube_->buffer();
        cube_->texture("textures/wall.jpg");

        transforms_ = new glm::mat4[numCubes];
        for (i = 0; i < numCubes; i++)
        {
            transforms_[i] = glm::mat4(1.0f);
            transforms_[i] = glm::translate(transforms_[i], glm::ballRand(5.0f));
        }
    }

    Cubes::~Cubes()
    {
        delete[] transforms_;
        delete cube_;
    }

    void Cubes::update(float deltaTime)
    {
        unsigned int i;

        for (i = 0; i < numCubes_; i++)
        {
            transforms_[i] = glm::rotate(transforms_[i], deltaTime * glm::radians(50.0f), glm::vec3(0.7f, 0.9f, 0.2f));
        }
    }

    void Cubes::render(Manager::Camera *camera)
    {
        unsigned int i;

        shader_->use();
        glUniformMatrix4fv(view_, 1, GL_FALSE, glm::value_ptr(camera->getView()));

        for (i = 0; i < numCubes_; i++)
        {
            glUniformMatrix4fv(model_, 1, GL_FALSE, glm::value_ptr(transforms_[i]));
            cube_->draw();
        }
    }

}