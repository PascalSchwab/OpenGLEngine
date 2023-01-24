#include "vector2.h"

template <typename Type>
Vector2<Type>::Vector2(Type x, Type y){
    this->x = x;
    this->y = y;
}

template <typename Type>
Type Vector2<Type>::GetX(){
    return this->x;
}

template <typename Type>
void Vector2<Type>::SetX(Type x){
    this->x = x;
}

template <typename Type>
Type Vector2<Type>::GetY(){
    return this->y;
}

template <typename Type>
void Vector2<Type>::SetY(Type y){
    this->y = y;
}