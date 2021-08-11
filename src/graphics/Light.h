#ifndef INCLUDE_LIGHT_H
#define INCLUDE_LIGHT_H

#include "NormalCube.h"

namespace Graphics
{

    class Light
    {
    public:
        Light(NormalCube *cube);
        void draw();

    private:
        NormalCube *cube_;
        unsigned int vao_;
    };

}

#endif