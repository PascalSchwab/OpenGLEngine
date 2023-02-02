#include "rectangle.h"

Rectangle::Rectangle(unsigned int id, GameObjectType type, float* vertices, unsigned int* indices, ShaderProgram* shaderProgram) : GameObject(id, type, vertices, 12, indices, 6, shaderProgram){

}

void Rectangle::Draw(){
    GameObject::Draw();
    glDrawElements(GL_TRIANGLES, this->indiceCount, GL_UNSIGNED_INT, 0);
}