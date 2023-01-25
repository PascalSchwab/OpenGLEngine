#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"
#include "main.h"
#include "inputManager.h"
#include "vector2.h"

using namespace std;

int main(){
    StatusCode status = OK;

    Window window(800, 600, "Engine");

    if(window.Init() == ERROR){
        window.Destroy();
        return status;
    }

    Vector2<int> v(10,10);
    Vector2<int> v2(10,10);

    if(v == v2){
        cout << "Yeah" << endl;
    }


    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        // Clear Frame
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Render

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    window.Destroy();
    return status;
}