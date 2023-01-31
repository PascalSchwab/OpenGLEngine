#include "shader.h"
#include <iostream>

using namespace std;

Shader::Shader(const char* code, ShaderType type){
    this->code = code;
    this->type = type;
    this->id = glCreateShader(type);
    glShaderSource(this->id, 1, &code, NULL);
    glCompileShader(this->id);

    // Compilation Error
    int success;
    glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(this->id, 512, NULL, infoLog);
        cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << endl;
        exit(1);
    }
}

void Shader::Delete(){
    glDeleteShader(this->id);
}