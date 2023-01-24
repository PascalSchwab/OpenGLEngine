#include <iostream>

#include <GLFW/glfw3.h>
#include "window.h"
#include "main.h"

int main(){
    StatusCode status = OK;

    Window window(800, 600, "Engine");

    if(window.Init() == ERROR){
        window.Destroy();
        return status;
    }

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    window.Destroy();
    return status;
}