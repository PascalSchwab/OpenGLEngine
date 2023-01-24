#include <string>

using namespace std;

#ifndef __PERSON__
#define __PERSON__

class Person{
    public:
        Person(int age, string name);
        int GetAge();
        void SetAge(int age);
        string GetName();
        void SetName(string name);
    private:
        int age;
        string name;
};

#endif