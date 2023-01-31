#ifndef __SHADER__
#define __SHADER__

#include "glad.h"

enum ShaderType{
    VertexShaderType = GL_VERTEX_SHADER,
    FragmentShaderType = GL_FRAGMENT_SHADER
};

class Shader{
    public:
        unsigned int id;
        Shader(const char* code, ShaderType type);
        void Delete();
    private:
        const char* code;
        ShaderType type;
};

#endif