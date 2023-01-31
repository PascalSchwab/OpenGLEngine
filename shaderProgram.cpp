#include "shaderProgram.h"
#include <iostream>

using namespace std;

ShaderProgram::ShaderProgram(IOManager* ioManager, const char* vertexShaderPath, const char* fragmentShaderPath){
    this->vertexShader = new Shader(ioManager->ReadFile(vertexShaderPath).c_str(), VertexShaderType);
    this->fragmentShader = new Shader(ioManager->ReadFile(fragmentShaderPath).c_str(), FragmentShaderType);

    this->id = glCreateProgram();
    glAttachShader(this->id, this->vertexShader->id);
    glAttachShader(this->id, this->fragmentShader->id);
    glLinkProgram(this->id);

    // Linking Error
    int success;
    glGetProgramiv(this->id, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(this->id, 512, NULL, infoLog);
        cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << endl;
        exit(1);
    }

    glDeleteShader(this->vertexShader->id);
    glDeleteShader(this->fragmentShader->id);
}

void ShaderProgram::Delete(){
    glDeleteProgram(this->id);
}