#include "ioManager.h"

IOManager::IOManager(){

}

string IOManager::ReadFile(const char* filePath){
    string content = "";
    ifstream fileStream(filePath, ios::in);

    if(!fileStream.is_open()){
        cerr << "Could not read file " << filePath << ". File doesn't exist." << endl;
        exit(1);
    }

    string line = "";
    while(!fileStream.eof()){
        getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}