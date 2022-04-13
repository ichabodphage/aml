#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#ifndef AML_VECTOR
#define AML_VECTOR

namespace aml{
    /*
        class that manages a vector used to represent many things, has a ton of instance methods to help determine its functionality
    */
    template<typename primitive>
    struct Vec{

        primitive x;
        primitive y;
        primitive z;

        //constructor for 3d vector
        Vec(primitive x, primitive y, primitive z):
        x(x),
        y(y),
        z(z){};


        //constructor for 2d vector, sets Z to 1 
        Vec(primitive x, primitive y):
        x(x),
        y(y),
        z(1){}
    };

    typedef Vec<float> Vecf;


}


#endif