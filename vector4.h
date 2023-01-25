#ifndef __VECTORFOUR__
#define __VECTORFOUR__

template <typename Type>
class Vector4{
    public:
        Vector4(Type x, Type y, Type z, Type a){
            this->x = x;
            this->y = y;
            this->z = z;
            this->a = a;
        }
        static Type ScalarProduct(Vector4<Type> const &v1, Vector4<Type> const &v2){
            Type result = 0;
            result += v1.x*v2.x;
            result += v1.y*v2.y;
            result += v1.z*v2.z;
            result += v1.a*v2.a;
            return result;
        }
        Vector4 operator+(Vector4 const &v){
            Vector4<Type> result;
            result.x = this->x + v.x;
            result.y = this->y + v.y;
            result.z = this->z + v.z;
            result.a = this->a + v.a;
            return result;
        }
        Vector4 operator-(Vector4 const &v){
            Vector4<Type> result;
            result.x = this->x - v.x;
            result.y = this->y - v.y;
            result.z = this->z - v.z;
            result.a = this->a - v.a;
            return result;
        }
        bool operator==(Vector4 const &v){
            bool result = false;
            if(this->x == v.x){
                if(this->y == v.y){
                    if(this->z == v.z){
                        if(this->a == v.a){
                            result = true;
                        }
                    }
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
        Type GetZ(){
            return this->z;
        }
        void SetZ(Type z){
            this->z = z;
        }
        Type GetA(){
            return this->a;
        }
        void SetA(Type a){
            this->z = z;
        }
    private:
        Type x;
        Type y;
        Type z;
        Type a;
};

#endif