#include "../include/LowLevelGraphics/window.hpp"
using namespace aml;


Window::Window(size_t winWidth,size_t winHeight, const char* name):width(winWidth),height(winHeight){
    //create the raw opengl render target
    renderWindow = aml::makeGLWindow(width,height,name);

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

void Window::renderVertexBuffer(size_t index, size_t amount){
    // Draw a triangle from the 3 vertices
    glDrawArrays(GL_TRIANGLES, index, amount);
    
}

void Window::renderElementBuffer(size_t amount){
    glDrawElements(GL_TRIANGLES,amount,GL_UNSIGNED_INT,0);
}

void Window::display(){
    glfwSwapBuffers(renderWindow);
}


//window size

glm::vec2 Window::dimensions(){

    return glm::vec2(width,height);
}

void Window::minimize(){
    glfwIconifyWindow(renderWindow);
};

void Window::unMinimize(){
    glfwRestoreWindow(renderWindow);
}

void Window::maximize(){
    glfwMaximizeWindow(renderWindow);
}


//window activity

bool Window::isActive(){
    return !glfwWindowShouldClose(renderWindow);
}

void Window::close(){
    glfwSetWindowShouldClose(renderWindow,true);
}


//window position

glm::vec2 Window::position(){
    int x,y;
    glfwGetWindowPos(renderWindow,&x,&y);
    return glm::vec2(x,y);
}


//window name

void Window::setTitle(const char* title){
    glfwSetWindowTitle(renderWindow,title);
}