#ifndef __WINDOW__
#define __WINDOW__

#include <GLFW/glfw3.h>
#include <string>
#include "inputManager.h"

using namespace std;

class Window{
    public:
        Window(int width, int height, string title);
        ~Window();
        void Delete();
        GLFWwindow* GetWindow();
        int GetWidth();
        int GetHeight();
        string GetTitle();
    private:
        GLFWwindow* window;
        int width;
        int height;
        string title;
        static void errorCallback(int error, const char* description);
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif