
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_RESULT
#define AML_RESULT

namespace aml{
    /*
        struct that holds the result of polling an input
    */
   struct Result{
       //state of the input
       int inputState;
       //activity of input
       bool active;
       //position of input
       glm::vec2 position;
   };

}



#endif