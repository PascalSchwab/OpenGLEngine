#include <iostream>
#include "add.h"
#include "person.h"

int main(){
    Person p1(10, "Pascal");
    std::cout << p1.GetAge() << std::endl;
    return 0;
}