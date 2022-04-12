#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_WINDOW
#define AML_WINDOW

namespace aml{
    class Window{
        public:
            //window vertex array object
            GLuint vao;

            //GLFW render target
            GLFWwindow* renderWindow;

            //constructor using window width, height, and name
            Window(size_t width,size_t height, const char* name);

            ~Window();

            //clears the window 
            void clear();
    };
}

#endif