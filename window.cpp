#include "glad.h"
#include "window.h"
#include <iostream>
using namespace std;

Window::Window(int width, int height, string title){
    this->width = width;
    this->height = height;
    this->title = title;

    // GLFW Initialisation
    if(!glfwInit()){
        cerr << "Failed to init GLFW" << endl;
        exit(1);
    }

    glfwSetErrorCallback(Window::errorCallback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(this->width, this->height, this->title.data(), NULL, NULL);

    if (this->window == NULL){
        cerr << "Failed to create GLFW window" << endl;
        exit(1);
    }

    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cerr << "Failed to init GLAD" << endl;
        exit(1);
    }

    glfwSetKeyCallback(this->window, InputManager::KeyCallback);
    glfwSwapInterval(1);

    glViewport(0, 0, this->width, this->height);
    glfwSetFramebufferSizeCallback(this->window, Window::framebufferSizeCallback);

    cout << "Window was created" << endl;
}

Window::~Window(){
    glfwDestroyWindow(this->window);
    glfwTerminate();
    cout << "Window was destroyed" << endl;
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
    cerr << stderr << "Error: %s\n" << description << endl;
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}