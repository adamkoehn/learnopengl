#include "Shader.h"

namespace Graphics
{

    Shader::Shader(const char *vert, const char *frag)
    {
        unsigned int vertex;
        unsigned int fragment;
        int success;
        char *code;
        std::streampos size;
        std::ifstream glsl;
        char log[512];

        glsl.open(vert, std::ios::in | std::ios::ate);
        if (glsl.is_open())
        {
            size = glsl.tellg();
            code = new char[size];
            glsl.seekg(0, std::ios::beg);
            glsl.read(code, size);
            glsl.close();
        }
        else
        {
            std::cout << "could not open vertex glsl: " << vert << std::endl;
        }

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &code, (int*)&size);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, log);
            std::cout << "vertex shader: " << log << std::endl;
        }

        delete[] code;

        glsl.open(frag, std::ios::in | std::ios::ate);
        if (glsl.is_open())
        {
            size = glsl.tellg();
            code = new char[size];
            glsl.seekg(0, std::ios::beg);
            glsl.read(code, size);
            glsl.close();
        }
        else
        {
            std::cout << "could not open fragment glsl: " << frag << std::endl;
        }

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &code, (int*)&size);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, log);
            std::cout << "fragment shader: " << log << std::endl;
        }

        delete[] code;

        id_ = glCreateProgram();
        glAttachShader(id_, vertex);
        glAttachShader(id_, fragment);
        glLinkProgram(id_);
        glGetProgramiv(id_, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(id_, 512, NULL, log);
            std::cout << "shader linker: " << log << std::endl;
        }

        glDeleteShader(fragment);
        glDeleteShader(vertex);
    }

    Shader::~Shader()
    {
        if (id_)
        {
            glDeleteProgram(id_);
        }
    }

}