#ifndef INCLUDE_TRIANGLE_H
#define INCLUDE_TRIANGLE_H

#include <GL/glew.h>

namespace Graphics
{

    class Triangle
    {
    public:
        void buffer();
        void draw();

    private:
        unsigned int vao_;
    };

}

#endif