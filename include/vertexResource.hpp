#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_VBO
#define AML_VBO
namespace aml
{
    //class that holds a vertex Resource, template so holds many vertex types
    template<typename vType>
    class VertexResource{
    private:
        static size_t nextID;
        size_t id;
        //vertex buffer object
        GLuint vbo;
    public:
        std::vector<vType> verticies;
        ~VertexResource();

        //binds the vertex resources
        void bindResource();

        //adds the verticies of a vertex array into verticeis
        void addVerticies(vType* vertexArray, size_t size);

        //pushes verticies data into the gpu
        void pushToGPU();
    };
}
#include "../src/vertexResource_IMPLEMENT.hpp"
#endif