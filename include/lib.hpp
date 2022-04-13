#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#ifndef AML_CORE

#define AML_CORE

namespace aml{

    
    //runs all basic opengl init functions
    void startAml(bool resize = false);

    //terminates AML
    void stopAml();
    //creates a GLFW window
    GLFWwindow* makeGLWindow(size_t width,size_t height, const char* name);
}



#endif