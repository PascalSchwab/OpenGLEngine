#include <iostream>

#include <GLFW/glfw3.h>
#include "window.h"
#include "main.h"
#include "inputManager.h"

int main(){
    StatusCode status = OK;

    Window window(800, 600, "Engine");

    if(window.Init() == ERROR){
        window.Destroy();
        return status;
    }

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        // Clear Frame
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        // Render

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    window.Destroy();
    return status;
}