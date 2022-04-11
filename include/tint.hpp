#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#ifndef AML_TINT
#define AML_TINT

namespace aml{
    /*
        class that manages RGBA tint values for shader programs
    */
    struct Tint{

        GLfloat colors[3];
        //constructor using RGB values
        Tint(float red, float green,float blue);

        //constructor using RGBA values


        //constructor using greyscale float value
        Tint(float lightness);

        float normalize(float value);

    };

}


#endif