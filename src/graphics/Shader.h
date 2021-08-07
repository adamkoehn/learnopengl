#ifndef INCLUDE_SHADER_H
#define INCLUDE_SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <iostream>

namespace Graphics
{

    class Shader
    {
    public:
        Shader(const char *vert, const char *frag);
        ~Shader();
        void use() { glUseProgram(id_); }

    private:
        unsigned int id_;
        unsigned int vertex_;
        unsigned int fragment_;
    };

}

#endif