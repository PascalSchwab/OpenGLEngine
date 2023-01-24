#include "person.h"

Person::Person(int age, string name){
    this->age = age;
    this->name = name;
}

int Person::GetAge(){
    return this->age;
}

void Person::SetAge(int age){
    this->age = age;
}

string Person::GetName(){
    return this->name;
}

void Person::SetName(string name){
    this->name = name;
}