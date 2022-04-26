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
        class that manages a vector used to represent many things
        meant to be used with an instance of vertexResource
    */
    template<typename PosType,typename ColorType>
    struct Vertex{
        //position of the vertex
        PosType pos;
        //color of the vertex
        ColorType color;
        //constructor using both color and type
        Vertex(PosType position,ColorType vertexColor):pos(position),color(vertexColor){};
    };
    //predefined template for 2d vertex
    typedef aml::Vertex<glm::vec2,glm::vec3> Vert2;
    //predefined template for 3d vertex
    typedef aml::Vertex<glm::vec3,glm::vec3> Vert3;

}


#endif