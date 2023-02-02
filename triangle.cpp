#include "triangle.h"

Triangle::Triangle(unsigned int id, GameObjectType type, float* vertices, unsigned int* indices, ShaderProgram* shaderProgram) : GameObject(id, type, vertices, 9, indices, 3, shaderProgram){
    
}

void Triangle::Draw(){
    GameObject::Draw();
    glDrawElements(GL_TRIANGLES, this->indiceCount, GL_UNSIGNED_INT, 0);
}