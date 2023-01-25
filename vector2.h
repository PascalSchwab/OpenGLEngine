#ifndef __VECTORTWO__
#define __VECTORTWO__

template <typename Type>
class Vector2{
    public:
        Vector2(Type x, Type y){
            this->x = x;
            this->y = y;
        }
        static Type ScalarProduct(Vector2<Type> const &v1, Vector2<Type> const &v2){
            Type result = 0;
            result += v1.x*v2.x;
            result += v1.y*v2.y;
            return result;
        }
        Vector2 operator+(Vector2 const &v){
            Vector2<Type> result;
            result.x = this->x + v.x;
            result.y = this->y + v.y;
            return result;
        }
        Vector2 operator-(Vector2 const &v){
            Vector2<Type> result;
            result.x = this->x - v.x;
            result.y = this->y - v.y;
            return result;
        }
        bool operator==(Vector2 const &v){
            bool result = false;
            if(this->x == v.x){
                if(this->y == v.y){
                    result = true;
                }
            }
            return result;
        }
        Type GetX(){
            return this->x;
        }
        void SetX(Type x){
            this->x = x;
        }
        Type GetY(){
            return this->y;
        }
        void SetY(Type y){
            this->y = y;
        }
    private:
        Type x;
        Type y;
};

#endif