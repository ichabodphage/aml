#include "../include/lib.hpp"

using namespace aml;

void aml::initAml(bool resize){
    //init glfw
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW\n");
    }
    
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, resize);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

}

GLFWwindow* aml::makeGLWindow(size_t width,size_t height,const char* name){
    GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
    glfwMakeContextCurrent(window);
    
    if (glewInit()!= 0) {
        throw std::runtime_error("Failed to initialize GLEW\n");
    }
    return window;
}

