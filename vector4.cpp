#include "vector4.h"

template <typename Type>
Vector4<Type>::Vector4(Type x, Type y, Type z, Type a){
    this->x = x;
    this->y = y;
    this->z = z;
    this->a = a;
}

template <typename Type>
Type Vector4<Type>::GetX(){
    return this->x;
}

template <typename Type>
void Vector4<Type>::SetX(Type x){
    this->x = x;
}

template <typename Type>
Type Vector4<Type>::GetY(){
    return this->y;
}

template <typename Type>
void Vector4<Type>::SetY(Type y){
    this->y = y;
}

template <typename Type>
Type Vector4<Type>::GetZ(){
    return this->z;
}

template <typename Type>
void Vector4<Type>::SetZ(Type z){
    this->z = z;
}

template <typename Type>
Type Vector4<Type>::GetA(){
    return this->a;
}

template <typename Type>
void Vector4<Type>::SetA(Type a){
    this->a = a;
}