#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../../lib.hpp"



#ifndef __ELEMENTBUFFER_H__
#define __ELEMENTBUFFER_H__

namespace aml{
    /**
     * @brief class that manages an element buffer object on the GPU
     * 
     * @details ElementBuffer manages an element buffer object that lives on the GPU
     * ElementBuffer's main job is to hold information about how the shader should interpret vertex data from
     * VectorResource or VertexResource. unlike VectorResource or VertexResource, Element buffer does not manage 
     * individual verticies, rather holds indecies for which the GPU can use to draw individual triangles from points
     * that otherwise wouldnt make a complete triangle (like in quaderaterals)
     * 
     */
    class ElementBuffer{
        private:
            /// @brief id of the EBO on the graphics card
            GLuint bufferID;

            /// @brief length of the buffer object
            size_t bufferSize;
        public:

        /**
         * @brief creates the ElementBuffer on the GPU
         * 
         */
        ElementBuffer(){
            glGenBuffers(1,&bufferID);
            bindResource();
        };

        /**
         * @brief returns the size of the buffer
         * 
         * @return size_t size of the buffer
         */
        size_t size(){
            return bufferSize;
        }

        /**
         * @brief Destroy the Element Buffer object
         * 
         */
        ~ElementBuffer(){
            glDeleteBuffers(1,&bufferID);
        };
        
        /**
         * @brief binds the buffer onto the GPU
         * 
         */
        void bindResource(){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
        };

        /**
         * @brief pushes an array of a type that is equivalent to a pack of integers into the buffer 
         * 
         * @tparam IntType type of integer to push into the buffer 
         * @param indexArray standard vector of IntType filled with indexes to interpret vertex data
         */
        template<typename IntType>
        void pushToGPU(std::vector<IntType>& indexArray)
        {      
            //guard clause to prevent any datatype that isnt an integer from being used
            static_assert(std::is_same<IntType,unsigned int>(),
            "type of standard vector used in element buffer object must be equivalent to unsigned int");
            //tell opengl to write data to this EBO
            bindResource();
            bufferSize = indexArray.size();
            //set the buffer data to vertexArr
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IntType) * indexArray.size(), indexArray.data(), GL_STATIC_DRAW);            
            aml::checkForGLErrors(__FILE__,__LINE__);
        }

        /**
         * @brief pushes an array of a type that is equivalent to a pack of integers into the buffer 
         * 
         * @tparam IntType type of integer to push into the buffer 
         * @param indexArray raw pointer to array of IntType filled with indexes to interpret vertex data
         * @param size length of indexArray
         */

        template<typename IntType>
        void pushToGPU(IntType * indexArray , size_t size)
        {
            //guard clause to prevent any datatype that isnt an integer from being used
            static_assert(std::is_same<IntType,unsigned int>(),
            "type of raw pointer used in element buffer object must be equivalent to unsigned int");
            
            //tell opengl to write data to this EBO
            bindResource();
            bufferSize = size;
            //set the buffer data to vertexArr
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IntType) * size, indexArray, GL_STATIC_DRAW);            
            aml::checkForGLErrors(__FILE__,__LINE__);
        }
        
    };
}



#endif // __ELEMENTBUFFER_H__