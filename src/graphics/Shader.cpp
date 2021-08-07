#include "Shader.h"

namespace Graphics
{

    Shader::Shader(const char *vert, const char *frag)
    {
        int success;
        char *vertexCode;
        char *fragmentCode;
        std::streampos size;
        std::ifstream vertexFile;
        std::ifstream fragmentFile;
        char log[512];

        vertexFile.open(vert, std::ios::in | std::ios::ate);
        if (vertexFile.is_open())
        {
            size = vertexFile.tellg();
            vertexCode = new char[size];
            vertexFile.seekg(0, std::ios::beg);
            vertexFile.read(vertexCode, size);
            vertexFile.close();
        }
        else
        {
            std::cout << "could not open vertex glsl: " << vert << std::endl;
        }

        fragmentFile.open(frag, std::ios::in | std::ios::ate);
        if (fragmentFile.is_open())
        {
            size = fragmentFile.tellg();
            fragmentCode = new char[size];
            fragmentFile.seekg(0, std::ios::beg);
            fragmentFile.read(fragmentCode, size);
            fragmentFile.close();
        }
        else
        {
            std::cout << "could not open fragment glsl: " << frag << std::endl;
        }

        vertex_ = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_, 1, &vertexCode, NULL);
        glCompileShader(vertex_);
        glGetShaderiv(vertex_, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex_, 512, NULL, log);
            std::cout << "vertex shader: " << log << std::endl;
        }

        fragment_ = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_, 1, &fragmentCode, NULL);
        glCompileShader(fragment_);
        glGetShaderiv(fragment_, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment_, 512, NULL, log);
            std::cout << "fragment shader: " << log << std::endl;
        }

        id_ = glCreateProgram();
        glAttachShader(id_, vertex_);
        glAttachShader(id_, fragment_);
        glLinkProgram(id_);
        glGetProgramiv(id_, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(id_, 512, NULL, log);
            std::cout << "shader linker: " << log << std::endl;
        }

        glDeleteShader(vertex_);
        glDeleteShader(fragment_);
        delete[] vertexCode;
        delete[] fragmentCode;
    }

    Shader::~Shader()
    {
        if (id_)
        {
            glDeleteProgram(id_);
        }
    }

}