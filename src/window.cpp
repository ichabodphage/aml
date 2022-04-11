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