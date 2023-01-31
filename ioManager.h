#ifndef __IOMANAGER__
#define __IOMANAGER__

#include <iostream>
#include <fstream>

using namespace std;

class IOManager{
    public:
        IOManager();
        string ReadFile(const char* filePath);
};

#endif