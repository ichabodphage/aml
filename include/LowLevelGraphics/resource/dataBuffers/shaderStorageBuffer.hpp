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

#ifndef __SHADERSTORAGEBUFFER_H__
#define __SHADERSTORAGEBUFFER_H__
namespace aml
{
    template <typename T>
    class ShaderStorageBuffer
    {
    private:
        /// @brief id of the SSBO on the graphics card
        GLuint bufferID;

        /// @brief length of the buffer object
        size_t bufferSize;

    public:
        /**
         * @brief creates the ShaderStorageBuffer on the GPU
         *
         */
        ShaderStorageBuffer()
        {
            glGenBuffers(1, &bufferID);
            bindResource();
        };

        /**
         * @brief returns the size of the buffer
         *
         * @return size_t size of the buffer
         */
        size_t size()
        {
            return bufferSize;
        }
        /**
         * @brief pushes data to the GPU
         *
         * @param data pointer to the data to push
         * @param size size of the data to push
         */
        void pushToGPU(T *data, size_t size)
        {
            bindResource();
            glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(T) * size, data, GL_STATIC_DRAW);
            bufferSize = size;
        }
        /**
         * @brief pushes data to the GPU
         *
         * @param data vector of the data to push
         *
         */
        void pushToGPU(std::vector<T> &data)
        {
            bindResource();
            glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(T) * data.size(), data.data(), GL_STATIC_DRAW);
            bufferSize = data.size();
        };
        /**
         * @brief links the buffer to a specific slot on the GPU
         * * @param slot slot to link the buffer to
         * 
         */
        void bindSlot(GLuint slot)
        {
            // This connects our buffer ID to the target slot
            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, slot, bufferID);
        }
        /**
         * @brief pushes an update to the GPU
         * * @param data pointer to the data to push
         * @param size size of the data to push
         * @param index index in the buffer to begin writing to
         *
         */

        void pushUpdateToGPU(T *data, size_t size, size_t index)
        {
            bindResource();
            glBufferSubData(GL_SHADER_STORAGE_BUFFER, index * sizeof(T), size * sizeof(T), data);
        };
        /**
         * @brief pushes an update to the GPU
         *
         * @param data vector of the data to push
         * @param index index in the buffer to begin writing to
         */
        void pushUpdateToGPU(std::vector<T> &data, size_t index)
        {
            bindResource();
            glBufferSubData(GL_SHADER_STORAGE_BUFFER, index * sizeof(T), data.size() * sizeof(T), data.data());
        };
        /**
         * @brief Destroy the Shader Storage Buffer object
         *
         */
        ~ShaderStorageBuffer()
        {
            glDeleteBuffers(1, &bufferID);
        };

        /**
         * @brief binds the buffer onto the GPU
         *
         */
        void bindResource()
        {
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID);
        };
    };
}
#endif