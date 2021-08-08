#ifndef INCLUDE_SCENE_H
#define INCLUDE_SCENE_H

namespace Scene
{

    class Scene
    {
    public:
        Scene() {}
        virtual ~Scene() {}
        virtual void update(float deltaTime) = 0;
        virtual void render() = 0;
    };

}

#endif