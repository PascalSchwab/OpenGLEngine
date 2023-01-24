#include "window.h"
#include <iostream>
using namespace std;

Window::Window(int width, int height, string title){
    this->width = width;
    this->height = height;
    this->title = title;
}

Window::~Window(){

}

StatusCode Window::Init(){
    // GLFW Initialisation
    if(!glfwInit()){
        cout << "Failed to init GLFW" << endl;
        return ERROR;
    }

    glfwSetErrorCallback(Window::errorCallback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(this->width, this->height, this->title.data(), NULL, NULL);

    if (this->window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        return ERROR;
    }

    glfwSetKeyCallback(this->window, InputManager::KeyCallback);
    glfwMakeContextCurrent(this->window);
    glfwSwapInterval(1);

    glViewport(0, 0, this->width, this->height);
    glfwSetFramebufferSizeCallback(this->window, Window::framebufferSizeCallback);

    cout << "Window was created" << endl;
    return OK;
}

StatusCode Window::Destroy(){
    glfwDestroyWindow(this->window);
    glfwTerminate();
    cout << "Window was destroyed" << endl;
    return OK;
}

GLFWwindow* Window::GetWindow(){
    return this->window;
}

int Window::GetWidth(){
    return this->width;
}

int Window::GetHeight(){
    return this->height;
}

string Window::GetTitle(){
    return this->title;
}

void Window::errorCallback(int error, const char* description){
    cout << stderr << "Error: %s\n" << description << endl;
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}