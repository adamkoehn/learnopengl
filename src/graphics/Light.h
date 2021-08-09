#ifndef INCLUDE_LIGHT_H
#define INCLUDE_LIGHT_H

#include "Cube.h"

namespace Graphics
{

    class Light
    {
    public:
        Light(Cube *cube);
        void draw();

    private:
        Cube *cube_;
        unsigned int vao_;
    };

}

#endif