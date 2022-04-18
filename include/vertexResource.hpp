#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#include "lib.hpp"


#ifndef AML_VBO
#define AML_VBO
namespace aml
{
    //class that holds a vertex Resource, template so holds many vertex types
    template<typename vType>
    class VertexResource{
    private:
        static size_t nextID;
        //location of the Resource in the vertex buffer
        size_t layout;
        //amount of values in each section of data passed into the shader
        size_t valueCount;
        //vertex buffer object
        GLuint vbo;
    public:
        std::vector<vType> verticies;

        VertexResource(size_t layoutLocation,size_t vertexSize = 3);
        ~VertexResource();

        //binds the vertex resources
        void bindResource();

        //adds the verticies of a vertex array into verticies
        void addVerticies(vType* vertexArray, size_t size);

        //adds the verticies of a vertex array into verticies and pushes them to the GPU
        void pushAdd(vType* vertexArray, size_t size);

        
        //pushes verticies data into the gpu
        void pushToGPU();
    };
}
#include "../src/vertexResource_IMPLEMENT.hpp"
#endif