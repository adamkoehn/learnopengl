#ifndef INCLUDE_CUBE_H
#define INCLUDE_CUBE_H

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <iostream>

namespace Graphics
{

    class TexturedCube
    {
    public:
        void texture(const char *texture, const char *specular);
        void buffer();
        void draw();
        unsigned int getVbo() { return vbo_; }

    private:
        unsigned int vao_;
        unsigned int vbo_;
        unsigned int texture_;
        unsigned int specular_;
    };

}

#endif