#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <tuple>

#ifndef AML_CORE

#define AML_CORE

namespace aml{
    //returns the nth element in 
    template<int N, typename... Ts> using indexInTemplate =
        typename std::tuple_element<N, std::tuple<Ts...>>::type;
        
  
    //throws an std::runtime_exception if gl encounters any errors
    void checkForGLErrors(const char *file, int line);
    
    //runs all basic opengl init functions
    void startAml(int antialiasingLevel,bool resize = false);

    //terminates AML
    void stopAml();
    //creates a GLFW window
    GLFWwindow* makeGLWindow(size_t width,size_t height, const char* name);


}



#endif