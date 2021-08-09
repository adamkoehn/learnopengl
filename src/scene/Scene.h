#ifndef INCLUDE_SCENE_H
#define INCLUDE_SCENE_H

#include "../manager/Camera.h"

namespace Scene
{

    class Scene
    {
    public:
        Scene() {}
        virtual ~Scene() {}
        virtual void update(float deltaTime) = 0;
        virtual void render(Manager::Camera *camera) = 0;
    };

}

#endif