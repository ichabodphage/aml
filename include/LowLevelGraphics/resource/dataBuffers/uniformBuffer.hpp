#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../../../lib.hpp"

namespace aml{

    class UniformBuffer{
        private:
            /// @brief id of the UBO on the graphics card
            GLuint bufferID;

            /// @brief length of the buffer object
            size_t bufferSize;
        public:

        /**
         * @brief creates the UniformBuffer on the GPU
         * 
         */
        UniformBuffer(){
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
         * @brief Destroy the Uniform Buffer object
         * 
         */
        ~UniformBuffer(){
            glDeleteBuffers(1,&bufferID);
        };
        
        /**
         * @brief binds the buffer onto the GPU
         * 
         */
        void bindResource(){
            glBindBuffer(GL_UNIFORM_BUFFER, bufferID);
        };

    };
}