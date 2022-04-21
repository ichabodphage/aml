#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../lib.hpp"
#ifndef AML_MULTI_RESOURCE
#define AML_MULTI_RESOURCE

namespace aml
{
    /*
        template class that manages a vertex resource that holds multiple values
        VertexResouce manages verticies with multiple vector components, 
        unlike vector resource which only manages one compnent of a vertex
    */
    template <typename... T>
    class VertexResource
    {
    private:
        
        //stride will be equal too the number of floats in all the vectors
        size_t stride = aml::packSize<T...>()/sizeof(float);
        // vertex buffer object
        GLuint vbo;
 
        //floatCountArr is equal to the amount of floats in each vector type
        short floatCountArr[sizeof...(T)] = {(sizeof(T) / sizeof(float))...};
        //size of numFloats
        size_t atributeSize = sizeof...(T);

        //array of floats from the verticies
        std::vector<float> vertexArr;
        

    public:
        // default constructor
        VertexResource(){
            bindResource();       
        };
        // binds the MultiResource
        void bindResource()
        {
            glGenBuffers(1, &vbo);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
        }
        //takes a raw pointer to a vertex array and adds it into the vertex arr
        void addRawVerticies(void* verticies,size_t vertexSize){
            //cast verticies into an array of floats 
            float * vertexBuff = reinterpret_cast<float*>(verticies);
            size_t size = stride * vertexSize;

            //push all the verticies into vertexArr
            for(size_t i = 0; i < size;i++){
                vertexArr.push_back(vertexBuff[i]);
            }
        }
        //pushes vertex data to the GPU
        void pushToGPU()
        {
            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexArr.size(), vertexArr.data(), GL_STATIC_DRAW);

            //offset of vertex atributes in vertexArr
            size_t offSet = 0;

            //establish all the proper atribute locations
            for(size_t i = 0; i <atributeSize;i++){
                glVertexAttribPointer(
                    //set the atribute location and its size
                    i, floatCountArr[i] , 
                    //tell openGl that this is atribute is a series of floats
                    GL_FLOAT, GL_FALSE,
                    //establish the distance inbetween verticies
                    stride * sizeof(float), 
                    //tell openGL where the atribute is located within the vertex
                    (void*) ((i*offSet) * sizeof(float)));
                glEnableVertexAttribArray(i);
                offSet+= floatCountArr[i];
            }
            aml::checkForGLErrors(__FILE__,__LINE__);
        }
        void pushToGPU(void * rawData, size_t size)
        {
            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) *stride *size, rawData, GL_STATIC_DRAW);

            //offset of vertex atributes in vertexArr
            size_t offSet = 0;

            //establish all the proper atribute locations
            for(size_t i = 0; i <atributeSize;i++){
                glVertexAttribPointer(
                    //set the atribute location and its size
                    i, floatCountArr[i] , 
                    //tell openGl that this is atribute is a series of floats
                    GL_FLOAT, GL_FALSE,
                    //establish the distance inbetween verticies
                    stride * sizeof(float), 
                    //tell openGL where the atribute is located within the vertex
                    (void*) ((i*offSet) * sizeof(float)));
                glEnableVertexAttribArray(i);
                offSet+= floatCountArr[i];
            }
            aml::checkForGLErrors(__FILE__,__LINE__);
        }
        ~VertexResource()
        {
            glDeleteBuffers(1, &vbo);
        }

        //clears the resources' vertex array
        void clear(){
            vertexArr.reserve(0);
        };
    };
    typedef aml::VertexResource<glm::vec2,glm::vec3> VertexResource2d; 
    typedef aml::VertexResource<glm::vec3,glm::vec3> VertexResource3d; 
}

#endif