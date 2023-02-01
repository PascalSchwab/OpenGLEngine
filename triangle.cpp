#include "triangle.h"
#include <iostream>

Triangle::Triangle(unsigned int id, GameObjectType type, float* vertices, ShaderProgram* shaderProgram) : GameObject(id, type, vertices, 9, shaderProgram){
    
}

void Triangle::Draw(){
    GameObject::Draw();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}