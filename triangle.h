#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "gameObject.h"

class Triangle : GameObject{
    public:
        Triangle(unsigned int id, GameObjectType type, float* vertices, unsigned int* indices, ShaderProgram* shaderProgram = NULL);
        void Draw() override;
};

#endif