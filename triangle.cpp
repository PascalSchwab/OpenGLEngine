#include "triangle.h"

Triangle::Triangle(Vector3<float> v1, Vector3<float> v2, Vector3<float> v3){
    this->vertices[0] = v1;
    this->vertices[1] = v2;
    this->vertices[3] = v3;
}

float* Triangle::ExtractVerticeData(float* vertices){
    for(int i = 0; i < 3; i++){
        vertices[i*3+0] = this->vertices[i].GetX();
        vertices[i*3+1] = this->vertices[i].GetY();
        vertices[i*3+2] = this->vertices[i].GetZ();
    }
    return vertices;
}