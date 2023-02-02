#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"
#include "inputManager.h"
#include "triangle.h"
#include "shaderProgram.h"
#include "ioManager.h"

using namespace std;

int main(){
    InputManager inputManager;
    Window window(800, 600, "Engine");

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int indices[3] = {
        0,1,2
    };

    Triangle triangle(0, StaticObject, vertices, indices);

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        // Clear Frame
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Render
        triangle.Draw();
        // End
        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }
    return 0;
}