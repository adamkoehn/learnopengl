#ifndef INCLUDE_RECTANGLE_H
#define INCLUDE_RECTANGLE_H

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <iostream>

namespace Graphics
{

    class Rectangle
    {
    public:
        void texture(const char *path);
        void buffer();
        void draw();

    private:
        unsigned int vao_;
        unsigned int ebo_;
        unsigned int texture_;
    };

}

#endif