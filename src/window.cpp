#include "../include/window.hpp"
#include "../include/lib.hpp"
using namespace aml;

Window::Window(size_t width,size_t height, const char* name){
    renderWindow = aml::makeGLWindow(width,height,name);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

Window::~Window(){
    glDeleteVertexArrays(1, &vao);
}

void Window::clear(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glFrontFace(GL_CW);
    glDisable(GL_CULL_FACE);
}