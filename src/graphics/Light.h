#ifndef INCLUDE_LIGHT_H
#define INCLUDE_LIGHT_H

#include "TexturedCube.h"

namespace Graphics
{

    class Light
    {
    public:
        Light(TexturedCube *cube);
        void draw();

    private:
        TexturedCube *cube_;
        unsigned int vao_;
    };

}

#endif