#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"
#include "inputManager.h"
#include "rectangle.h"
#include "shaderProgram.h"
#include "ioManager.h"

using namespace std;

int main(){
    InputManager inputManager;
    Window window(800, 600, "Engine");

    float vertices[12] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    unsigned int indices[6] = {
        0,1,3,
        1,2,3
    };

    Rectangle rectangle(0, StaticObject, vertices, indices);

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        // Clear Frame
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Render
        rectangle.Draw();
        // End
        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }
    return 0;
}