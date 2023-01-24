#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

#include <GLFW/glfw3.h>

class InputManager{
    public:
        InputManager();
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif