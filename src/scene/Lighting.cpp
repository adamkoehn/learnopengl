#include "Lighting.h"

namespace Scene
{

    Lighting::Lighting()
    {
        lightShader_ = new Graphics::Shader("src/shaders/lighting_light.vert.glsl", "src/shaders/lighting_light.frag.glsl");
        cubeShader_ = new Graphics::Shader("src/shaders/lighting_cube.vert.glsl", "src/shaders/lighting_cube.frag.glsl");
        cube_ = new Graphics::TexturedCube();
        cube_->buffer();
        cube_->texture("textures/crate.png", "textures/crate_specular.png");
        lightCube_ = new Graphics::Light(cube_);
        lightAngle_ = 0;
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


        lightShader_->use();
        lightProjection_ = glGetUniformLocation(lightShader_->getId(), "projection");
        lightView_ = glGetUniformLocation(lightShader_->getId(), "view");
        lightModel_ = glGetUniformLocation(lightShader_->getId(), "model");
        glUniformMatrix4fv(lightProjection_, 1, GL_FALSE, glm::value_ptr(projection));

        lightLocation_ = glm::vec3(1.2f, 1.0f, 2.0f);
        lightTransform_ = glm::mat4(1.0f);
        lightTransform_ = glm::translate(lightTransform_, lightLocation_);
        lightTransform_ = glm::scale(lightTransform_, glm::vec3(0.2f));
        glUniformMatrix4fv(lightModel_, 1, GL_FALSE, glm::value_ptr(lightTransform_));

        cubeShader_->use();
        cubeProjection_ = glGetUniformLocation(cubeShader_->getId(), "projection");
        cubeView_ = glGetUniformLocation(cubeShader_->getId(), "view");
        cubeModel_ = glGetUniformLocation(cubeShader_->getId(), "model");
        viewPos_ = glGetUniformLocation(cubeShader_->getId(), "viewPos");
        material_.specular_ = glGetUniformLocation(cubeShader_->getId(), "material.specular");
        material_.shininess_ = glGetUniformLocation(cubeShader_->getId(), "material.shininess");
        light_.position_ = glGetUniformLocation(cubeShader_->getId(), "light.position");
        light_.ambient_ = glGetUniformLocation(cubeShader_->getId(), "light.ambient");
        light_.diffuse_ = glGetUniformLocation(cubeShader_->getId(), "light.diffuse");
        light_.specular_ = glGetUniformLocation(cubeShader_->getId(), "light.specular");
        glUniformMatrix4fv(cubeProjection_, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform1i(glGetUniformLocation(cubeShader_->getId(), "material.diffuse"), 0);
        glUniform1i(glGetUniformLocation(cubeShader_->getId(), "material.specular"), 1);
        glUniform1f(material_.shininess_, 32.0f);
        glUniform3fv(light_.ambient_, 1, glm::value_ptr(glm::vec3(0.2f, 0.2f, 0.2f)));
        glUniform3fv(light_.diffuse_, 1, glm::value_ptr(glm::vec3(0.5f, 0.5f, 0.5f)));
        glUniform3fv(light_.specular_, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));

        cubeTransform_ = glm::mat4(1.0f);
        cubeTransform_ = glm::translate(cubeTransform_, glm::vec3(0.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(cubeModel_, 1, GL_FALSE, glm::value_ptr(cubeTransform_));
    }

    Lighting::~Lighting()
    {
        delete lightShader_;
        delete cubeShader_;
        delete lightCube_;
        delete cube_;
    }

    void Lighting::update(float deltaTime)
    {
        lightAngle_ -= deltaTime;
        if (lightAngle_ <= 0.0f) {
            lightAngle_ += 360.0f;
        }

        cubeTransform_ = glm::rotate(cubeTransform_, deltaTime * glm::radians(50.0f), glm::vec3(0.7f, 0.9f, 0.2f));
        lightLocation_ = glm::vec3(sin(lightAngle_) * 2.0f, 0.0, cos(lightAngle_) * 2.0f);

        lightTransform_ = glm::mat4(1.0f);
        lightTransform_ = glm::translate(lightTransform_, lightLocation_);
        lightTransform_ = glm::scale(lightTransform_, glm::vec3(0.2f));
    }

    void Lighting::render(Manager::Camera *camera)
    {
        glm::mat4 view = camera->getView();

        lightShader_->use();
        glUniformMatrix4fv(lightView_, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(lightModel_, 1, GL_FALSE, glm::value_ptr(lightTransform_));
        lightCube_->draw();

        cubeShader_->use();
        glUniformMatrix4fv(cubeView_, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(cubeModel_, 1, GL_FALSE, glm::value_ptr(cubeTransform_));
        glUniform3fv(light_.position_, 1, glm::value_ptr(lightLocation_));
        glUniform3fv(viewPos_, 1, glm::value_ptr(camera->getPosition()));
        cube_->draw();
    }

}