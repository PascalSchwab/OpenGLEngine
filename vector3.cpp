#include "vector3.h"

template <typename Type>
Vector3<Type>::Vector3(Type x, Type y, Type z){
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename Type>
Type Vector3<Type>::GetX(){
    return this->x;
}

template <typename Type>
void Vector3<Type>::SetX(Type x){
    this->x = x;
}

template <typename Type>
Type Vector3<Type>::GetY(){
    return this->y;
}

template <typename Type>
void Vector3<Type>::SetY(Type y){
    this->y = y;
}

template <typename Type>
Type Vector3<Type>::GetZ(){
    return this->z;
}

template <typename Type>
void Vector3<Type>::SetZ(Type z){
    this->z = z;
}

