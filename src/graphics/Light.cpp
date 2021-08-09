#include "Light.h"

namespace Graphics
{

    Light::Light(Cube *cube) : cube_(cube)
    {
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);

        glBindBuffer(GL_ARRAY_BUFFER, cube->getVbo());

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void *)0);
        glEnableVertexAttribArray(0);
    }

    void Light::draw()
    {
    }

}