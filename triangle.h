#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "vector3.h"

class Triangle{
    public:
        Triangle(Vector3<float> v1, Vector3<float> v2, Vector3<float> v3);
        float* ExtractVerticeData(float* vertices);
    private:
        Vector3<float> vertices[3];
};

#endif