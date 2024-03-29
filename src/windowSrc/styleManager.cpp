#include "../../include/LowLevelGraphics/window/styleManager.hpp"

using namespace aml;



StyleManager::StyleManager(GLWindowRefrence rawWindow, size_t winWidth, size_t winHeight):width(winWidth),height(winHeight),localWindow(rawWindow) 
{

}


//window size

glm::vec2 StyleManager::dimensions(){

    return glm::vec2(width,height);
}

void StyleManager::minimize(){
    glfwIconifyWindow(localWindow);
};

void StyleManager::unMinimize(){
    glfwRestoreWindow(localWindow);
}

void StyleManager::maximize(){
    glfwMaximizeWindow(localWindow);
}

void StyleManager::setTitle(const char* title){
    glfwSetWindowTitle(localWindow,title);
}

glm::vec2 StyleManager::position(){
    int x,y;
    glfwGetWindowPos(localWindow,&x,&y);
    return glm::vec2(x,y);
}