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
        const size_t stride = aml::packSize<T...>()/sizeof(float);
        // vertex buffer object
        GLuint vbo;
 
        //floatCountArr is equal to the amount of floats in each vector type
        const short floatCountArr[sizeof...(T)] = {(sizeof(T) / sizeof(float))...};
        //size of numFloats
        const size_t atributeSize = sizeof...(T);
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
        
        /* unsafe implementation of pushToGPU, does not do any typechecking
        void pushToGPU(void * rawData, size_t size)
        {
            
            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, aml::packSize<T...>() *size, rawData, GL_STATIC_DRAW);

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
        */
        
        //typesafe version of pushToGPU
        template<typename vertexType>
        void pushToGPU(vertexType * rawData, size_t size)
        {
            //check if the vertexType is the same size as the pack size
            if constexpr (sizeof(vertexType) != aml::packSize<T...>()){
                throw std::runtime_error("vertex template paramerter is not compatable with the type of vertex resource");
            }
            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, aml::packSize<T...>() *size, rawData, GL_STATIC_DRAW);

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

        
    };
    typedef aml::VertexResource<glm::vec2,glm::vec3> VertexResource2d; 
    typedef aml::VertexResource<glm::vec3,glm::vec3> VertexResource3d; 
}

#endif