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
    IOManager ioManager;
    InputManager inputManager;

    Window window(800, 600, "Engine");
    ShaderProgram shaderProgram(&ioManager, "shaders/shader.vert", "shaders/shader.frag");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f
    };

    // VAO / VBO
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // How to interpret the data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        // Clear Frame
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Render
        glUseProgram(shaderProgram.id);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // End
        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    shaderProgram.Delete();

    window.Delete();
    return 0;
}