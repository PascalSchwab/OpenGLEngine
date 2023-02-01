#include "gameObject.h"
#include <iostream>

GameObject::GameObject(unsigned int id, GameObjectType type, float* vertices, unsigned int verticeCount, ShaderProgram* shaderProgram){
    this->id = id;
    this->gameObjectType = type;
    this->verticeCount = verticeCount;

    // Set Vertices
    this->vertices = new float[this->verticeCount];
    for(unsigned int i = 0; i < this->verticeCount; i++){
        this->vertices[i] = vertices[i];
    }

    // Set Program
    if(shaderProgram == NULL){
        IOManager manager;
        this->shaderProgram = new ShaderProgram(&manager, "shaders/shader.vert", "shaders/shader.frag");
    }
    else{
        this->shaderProgram = shaderProgram;
    }

    glGenBuffers(1, &this->vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, this->gameObjectType);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GameObject::~GameObject(){
    glDeleteBuffers(1, &this->vertexBufferObject);
    this->shaderProgram->Delete();
}

float* GameObject::GetVertices(){
    return this->vertices;
}

unsigned int GameObject::GetId(){
    return this->id;
}

void GameObject::Draw(){
    glUseProgram(this->shaderProgram->id);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}