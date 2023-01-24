#ifndef __VECTORFOUR__
#define __VECTORFOUR__

#include "vector.h"

template <typename Type>
class Vector4 : Vector{
    public:
        Vector4(Type x, Type y, Type z, Type a);
        Type GetX();
        void SetX(Type x);
        Type GetY();
        void SetY(Type y);
        Type GetZ();
        void SetZ(Type z);
        Type GetA();
        void SetA(Type a);
    private:
        Type x;
        Type y;
        Type z;
        Type a;
};

#endif