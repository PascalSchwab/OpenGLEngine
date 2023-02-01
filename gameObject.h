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
        GameObject(unsigned int id, GameObjectType type, float* vertices, unsigned int verticeCount, ShaderProgram* shaderProgram = NULL);
        ~GameObject();
        float* GetVertices();
        virtual void Draw();
        unsigned int GetId();
    protected:
        unsigned int vertexBufferObject;
        unsigned int vertexArrayObject;
        float* vertices;
    private:
        unsigned int id;
        GameObjectType gameObjectType;
        unsigned int verticeCount;
        ShaderProgram* shaderProgram;
};

#endif