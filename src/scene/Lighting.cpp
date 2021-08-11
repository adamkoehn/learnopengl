#include "Lighting.h"

namespace Scene
{

    Lighting::Lighting()
    {
        lightShader_ = new Graphics::Shader("src/shaders/lighting_light.vert.glsl", "src/shaders/lighting_light.frag.glsl");
        cubeShader_ = new Graphics::Shader("src/shaders/lighting_cube.vert.glsl", "src/shaders/lighting_cube.frag.glsl");
        cube_ = new Graphics::NormalCube();
        cube_->buffer();
        light_ = new Graphics::Light(cube_);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


        lightShader_->use();
        lightProjection_ = glGetUniformLocation(lightShader_->getId(), "projection");
        lightView_ = glGetUniformLocation(lightShader_->getId(), "view");
        lightModel_ = glGetUniformLocation(lightShader_->getId(), "model");
        glUniformMatrix4fv(lightProjection_, 1, GL_FALSE, glm::value_ptr(projection));

        lightTransform_ = glm::mat4(1.0f);
        lightTransform_ = glm::translate(lightTransform_, glm::vec3(1.2f, 1.0f, 2.0f));
        lightTransform_ = glm::scale(lightTransform_, glm::vec3(0.2f));
        glUniformMatrix4fv(lightModel_, 1, GL_FALSE, glm::value_ptr(lightTransform_));

        cubeShader_->use();
        cubeProjection_ = glGetUniformLocation(cubeShader_->getId(), "projection");
        cubeView_ = glGetUniformLocation(cubeShader_->getId(), "view");
        cubeModel_ = glGetUniformLocation(cubeShader_->getId(), "model");
        lightColor_ = glGetUniformLocation(cubeShader_->getId(), "lightColor");
        objectColor_ = glGetUniformLocation(cubeShader_->getId(), "objectColor");
        glUniformMatrix4fv(cubeProjection_, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform3fv(lightColor_, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
        glUniform3fv(objectColor_, 1, glm::value_ptr(glm::vec3(1.0f, 0.5f, 0.31f)));

        cubeTransform_ = glm::mat4(1.0f);
        cubeTransform_ = glm::translate(cubeTransform_, glm::vec3(0.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(cubeModel_, 1, GL_FALSE, glm::value_ptr(cubeTransform_));
    }

    Lighting::~Lighting()
    {
        delete lightShader_;
        delete cubeShader_;
        delete light_;
        delete cube_;
    }

    void Lighting::update(float deltaTime)
    {
        cubeTransform_ = glm::rotate(cubeTransform_, deltaTime * glm::radians(50.0f), glm::vec3(0.7f, 0.9f, 0.2f));
    }

    void Lighting::render(Manager::Camera *camera)
    {
        glm::mat4 view = camera->getView();

        lightShader_->use();
        glUniformMatrix4fv(lightView_, 1, GL_FALSE, glm::value_ptr(view));
        light_->draw();

        cubeShader_->use();
        glUniformMatrix4fv(cubeView_, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(cubeModel_, 1, GL_FALSE, glm::value_ptr(cubeTransform_));
        cube_->draw();
    }

}