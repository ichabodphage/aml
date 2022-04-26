#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#include "../lib.hpp"


#ifndef AML_VBO
#define AML_VBO
namespace aml
{
    //class that holds a vector Resource, template so holds many Vector types
    template<typename vType>
    class VectorResource{
    private:
        static size_t nextID;
        //location of the Resource in the Vector buffer
        size_t layout;
        //amount of values in each section of data passed into the shader
        size_t valueCount;
        //Vector buffer object
        GLuint vbo;
    public:
        std::vector<vType> verticies;

        VectorResource(size_t layoutLocation,size_t VectorSize = 3);
        ~VectorResource();

        //binds the Vector resources
        void bindResource();

        //adds the verticies of a Vector array into verticies
        void addVerticies(vType* VectorArray, size_t size);

        void setVerticies(std::vector<vType> &VectorArray);
        //adds the verticies of a Vector array into verticies and pushes them to the GPU
        void pushAdd(vType* VectorArray, size_t size);
        void pushSet(std::vector<vType> &VectorArray);
        
        //pushes verticies data into the gpu
        void pushToGPU();
    };
}

#endif