#ifndef INCLUDE_LIGHTING_H
#define INCLUDE_LIGHTING_H

#include "Scene.h"

namespace Scene
{

    class Lighting : public Scene
    {
    public:
        void update(float deltaTime);
        void render();
    };

}

#endif