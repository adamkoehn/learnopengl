#ifndef INCLUDE_NORMAL_CUBE_H
#define INCLUDE_NORMAL_CUBE_H

#include <GL/glew.h>

namespace Graphics
{
     
    class NormalCube
    {
    public:
        void buffer();
        void draw();
        unsigned int getVbo() { return vbo_; }
    
    private:
        unsigned int vao_;
        unsigned int vbo_;
    };

}

#endif