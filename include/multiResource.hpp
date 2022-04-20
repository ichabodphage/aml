#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "lib.hpp"
#ifndef AML_MULTI_RESOURCE
#define AML_MULTI_RESOURCE

namespace aml
{
    /*
        template class that manages a vertex resource that holds multiple values



    */
    template <typename... T>
    class MultiResource
    {
    private:
        // vertex buffer object
        size_t atributeSize = sizeof...(T);
        size_t stride = 0;
        GLuint vbo;
        // dataLocation is to be stored in an array where each index corisponds the the shader layout location
        struct DataLocation
        {
            short numOfValues;
        };
        // allocated at compile time, no need for new opperator
        DataLocation locations[sizeof...(T)];

        // method that initalizes locations
        template <size_t argAmount, size_t offset = 0, size_t begin = 0>
        void dynamicPush_back()
        {
            if constexpr (begin < argAmount)
            {
                // get the size of the current template item
                const size_t sizeOfIndex = sizeof(aml::indexInTemplate<begin, T...>);

                // add that to the size of the number of values within the item
                locations[begin].numOfValues = sizeOfIndex / sizeof(float);
                stride += locations[begin].numOfValues;
                // start next itteration with the next index
                dynamicPush_back<argAmount, offset + sizeOfIndex, begin + 1>();
            }
        }
        float vertices[18] = {
            // positions         // colors
            0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 1.0f    // top
        };
        

    public:
        // default constructor
        MultiResource(int x)
        {
            bindResource();
            dynamicPush_back<sizeof...(T)>();
        }
        // binds the MultiResource
        void bindResource()
        {
            glGenBuffers(1, &vbo);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
        }

        void addData()
        {
            
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            size_t offSet = 0;
            for(size_t i = 0; i <atributeSize;i++){
                glVertexAttribPointer(
                    i, locations[i].numOfValues ,
                    GL_FLOAT, GL_FALSE,stride * sizeof(float),
                    (void*) ((i*offSet) * sizeof(float)));
                glEnableVertexAttribArray(i);
                offSet+= locations[i].numOfValues;
            }
            aml::checkForGLErrors(__FILE__,__LINE__);
        }
        ~MultiResource()
        {
            glDeleteBuffers(1, &vbo);
        }
    };

}

#endif