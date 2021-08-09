#ifndef INCLUDE_CUBE_H
#define INCLUDE_CUBE_H

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <iostream>

namespace Graphics
{

    class Cube
    {
    public:
        Cube() : textured(false), buffered(false) {}
        void texture(const char *path);
        void buffer();
        void draw();
        unsigned int getVbo() { return vbo_; }

    private:
        unsigned int vao_;
        unsigned int vbo_;
        unsigned int ebo_;
        unsigned int texture_;
        bool textured;
        bool buffered;
    };

}

#endif