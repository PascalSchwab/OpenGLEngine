#ifndef __VECTORTWO__
#define __VECTORTWO__

#include "vector.h"

template <typename Type>
class Vector2 : Vector{
    public:
        Vector2(Type x, Type y);
        Type GetX();
        void SetX(Type x);
        Type GetY();
        void SetY(Type y);
    private:
        Type x;
        Type y;
};

#endif