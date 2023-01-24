#ifndef __WINDOW__
#define __WINDOW__

#include <GLFW/glfw3.h>
#include <string>
#include "main.h"

using namespace std;

class Window{
    public:
        Window(int width, int height, string title);
        ~Window();
        StatusCode Init();
        StatusCode Destroy();
        GLFWwindow* GetWindow();
        int GetWidth();
        int GetHeight();
        string GetTitle();
    private:
        GLFWwindow* window;
        int width;
        int height;
        string title;
};

#endif