#include "../../include/LowLevelGraphics/window/window.hpp"
using namespace aml;


Window::Window(size_t winWidth,size_t winHeight, const char* name):
    renderWindow(aml::makeGLWindow(winWidth,winHeight,name)),
    windowStartTime(aml::systemTime()),
    style(renderWindow,winWidth,winHeight)
{
    style.setTitle(name);
    //initalize the vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    makeDrawTarget();
}

Window::~Window(){
    glDeleteVertexArrays(1, &vao);
    glfwDestroyWindow(renderWindow);
}

void Window::makeDrawTarget(){
    glfwMakeContextCurrent(renderWindow);
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



void Window::display(){
    glfwSwapBuffers(renderWindow);
}

bool Window::isActive(){
    return !glfwWindowShouldClose(renderWindow);
}

void Window::close(){
    glfwSetWindowShouldClose(renderWindow,true);
}

double Window::upTime(){
    return aml::systemTime() - windowStartTime;
}
