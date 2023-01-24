#ifndef __VECTORTHREE__
#define __VECTORTHREE__

#include "vector.h"

template <typename Type>
class Vector3 : Vector{
    public:
        Vector3(Type x, Type y, Type z);
        Type GetX();
        void SetX(Type x);
        Type GetY();
        void SetY(Type y);
        Type GetZ();
        void SetZ(Type z);
    private:
        Type x;
        Type y;
        Type z;
};

#endif