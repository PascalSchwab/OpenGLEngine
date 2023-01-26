#ifndef __VECTORTHREE__
#define __VECTORTHREE__

template <typename Type>
class Vector3{
    public:
        Vector3(){
            
        }
        Vector3(Type x, Type y, Type z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        static Type ScalarProduct(Vector3<Type> const &v1, Vector3<Type> const &v2){
            Type result = 0;
            result += v1.x*v2.x;
            result += v1.y*v2.y;
            result += v1.z*v2.z;
            return result;
        }
        Vector3 operator+(Vector3 const &v){
            Vector3<Type> result;
            result.x = this->x + v.x;
            result.y = this->y + v.y;
            result.z = this->z + v.z;
            return result;
        }
        Vector3 operator-(Vector3 const &v){
            Vector3<Type> result;
            result.x = this->x - v.x;
            result.y = this->y - v.y;
            result.z = this->z - v.z;
            return result;
        }
        bool operator==(Vector3 const &v){
            bool result = false;
            if(this->x == v.x){
                if(this->y == v.y){
                    if(this->z == v.z){
                        result = true;
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
    private:
        Type x;
        Type y;
        Type z;
};

#endif