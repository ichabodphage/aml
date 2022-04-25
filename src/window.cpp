#include "../include/LowLevelGraphics/window.hpp"
using namespace aml;


Window::Window(size_t winWidth,size_t winHeight, const char* name):width(winWidth),height(winHeight){
    renderWindow = aml::makeGLWindow(width,height,name);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

Window::~Window(){
    glDeleteVertexArrays(1, &vao);
}

void Window::clear(){

    //enable 3d depth testing
    glEnable(GL_DEPTH_TEST);

    //clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //cull any verticies that are obstructed by other verticies
    glFrontFace(GL_CW);
    glDisable(GL_CULL_FACE);
    
}

bool Window::isActive(){
    return !glfwWindowShouldClose(renderWindow);
}

void Window::renderVBO(size_t index, size_t amount){
    // Draw a triangle from the 3 vertices
    glDrawArrays(GL_TRIANGLES, index, amount);
    
}


void Window::draw(size_t index, size_t amount){
    glDrawArrays(GL_TRIANGLES, index, amount);
    display();
}

void Window::display(){
    glfwSwapBuffers(renderWindow);
}

glm::vec2 Window::dimensions(){

    return glm::vec2(width,height);
}
