#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "vector3.h"
#include "gameObject.h"

class Triangle : GameObject{
    public:
        Triangle(unsigned int id, GameObjectType type, float* vertices, ShaderProgram* shaderProgram = NULL);
        void Draw() override;
};

#endif