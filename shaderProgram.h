#ifndef __SHADERPROGRAM__
#define __SHADERPROGRAM__

#include "shader.h"
#include "ioManager.h"

class ShaderProgram{
    public:
        unsigned int id;
        ShaderProgram(IOManager* ioManager, const char* vertexShaderPath, const char* fragmentShaderPath);
        void Delete();
    private:
        Shader* vertexShader;
        Shader* fragmentShader;
};

#endif