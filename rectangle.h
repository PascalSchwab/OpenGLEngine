#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "gameObject.h"

class Rectangle : GameObject{
    public:
        Rectangle(unsigned int id, GameObjectType type, float* vertices, unsigned int* indices, ShaderProgram* shaderProgram = NULL);
        void Draw() override;
};

#endif