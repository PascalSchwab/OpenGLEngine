#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "glad.h"
#include "shaderProgram.h"

enum GameObjectType{
    StaticObject = GL_STATIC_DRAW,
    DynamicObject = GL_DYNAMIC_DRAW
};

class GameObject{
    public:
        GameObject(unsigned int id, GameObjectType type, float* vertices, unsigned int verticeCount, unsigned int* indices, unsigned int indiceCount, ShaderProgram* shaderProgram = NULL);
        ~GameObject();
        float* GetVertices();
        virtual void Draw();
        unsigned int GetId();
    protected:
        unsigned int vertexBufferObject;
        unsigned int vertexArrayObject;
        unsigned int elementBufferObject;
        float* vertices;
        unsigned int* indices;
        unsigned int indiceCount;
        unsigned int verticeCount;
    private:
        unsigned int id;
        GameObjectType gameObjectType;
        ShaderProgram* shaderProgram;
};

#endif