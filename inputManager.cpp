#include "inputManager.h"
#include <iostream>
using namespace std;

InputManager::InputManager(){

}

void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    cout << "Key Pressed" << endl;
}