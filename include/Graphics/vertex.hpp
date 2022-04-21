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
    template<typename PosType,typename ColorType>
    struct Vertex{
        PosType pos;
        ColorType color;

        Vertex(PosType position,ColorType vertexColor):pos(position),color(vertexColor){};
    };
    typedef aml::Vertex<glm::vec2,glm::vec3> Vert2;
    typedef aml::Vertex<glm::vec3,glm::vec3> Vert3;

}


#endif