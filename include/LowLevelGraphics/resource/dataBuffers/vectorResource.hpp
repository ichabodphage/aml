#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#include "../../../lib.hpp"


#ifndef AML_VBO
#define AML_VBO
namespace aml
{
    /**
     * @brief template class that manages a VBO consisting of only one type of vector
     * 
     * @details 
     * VectorResource is like Vertex resource, in the sense that both manage a vertex buffer object on the graphics card
     * unlike VertexResource, it only manages one kind of vector within the VBO
     * not as space efficent as VertexResource, but its easier to implement
     * another difference from VertexResource is the size of each vector is not bound by the size of the datatype
     * VectorResource can interpret an array of raw floats the same way VertexResource would with specific vector structs 
     * 
     * @tparam datatype passed into the VBO
     */
    template<typename vType>
    class VectorResource{
    private:
        
        /// @brief location of the Resource in the Vector buffer
        size_t layout;

        /// @brief amount of values in each section of data passed into the shader
        size_t valueCount;

        /// @brief Vector buffer object
        GLuint vbo;

    public:

        /**
         * @brief Construct a new Vector Resource object
         * 
         * @param layoutLocation vector atribute position 
         * @param VectorSize size of each vector to pass to the GPU
         * @param glDatatype opengl datatype enum that will be bound to the driver. defaults to GL_FLOAT
         */
        VectorResource(size_t layoutLocation,size_t VectorSize = 3,size_t glDatatype = GL_FLOAT);

        /**
         * @brief Destroy the Vector Resource object
         * 
         */
        ~VectorResource();

        /**
         * @brief tells the grapics card to write to this vector resource 
         * 
         */
        void bindResource();

        /**
         * @brief establishes how vector data is positioned on the GPU
         * 
         * @param glDatatype opengl datatype enum that will be bound to the driver
         */
        void bindAtributes(size_t glDatatype);

        /**
         * @brief pushes a C style array into the vector buffer
         * 
         * @param VectorArray pointer to the C style array
         * @param size length of the array
         */
        void pushToGPU(vType* VectorArray, size_t size);

        /**
         * @brief pushes a standard vector to the vector buffer
         * 
         * @param VectorArray standard vector
         */
        void pushToGPU(std::vector<vType> &VectorArray);

        
        
        
    };
}
#include "../../../../src/vectorResource.ipp"
#endif