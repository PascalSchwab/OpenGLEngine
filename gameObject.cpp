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

    // Generate VAO / VBOs
    glGenVertexArrays(1, &this->vertexArrayObject);
    glGenBuffers(1, &this->vertexBufferObject);

    // Bind VAO / VBOs
    glBindVertexArray(this->vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);

    // Set VBO Data and how to interpret it
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices)*this->verticeCount, this->vertices, this->gameObjectType);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind Buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GameObject::~GameObject(){
    glDeleteVertexArrays(1, &this->vertexArrayObject);
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
    glBindVertexArray(this->vertexArrayObject);
}