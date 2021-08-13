#include "Light.h"

namespace Graphics
{

    Light::Light(TexturedCube *cube) : cube_(cube)
    {
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);

        glBindBuffer(GL_ARRAY_BUFFER, cube_->getVbo());

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *)0);
        glEnableVertexAttribArray(0);
    }

    void Light::draw()
    {
        glBindVertexArray(vao_);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }

}