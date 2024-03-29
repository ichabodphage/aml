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
#include "../../../templateUtilities/templateLib.hpp"
#ifndef AML_MULTI_RESOURCE
#define AML_MULTI_RESOURCE

namespace aml
{
    /** @brief manages a vertex buffer that lives on the GPU
    * 
    *   @details 
    *   data is ordered in the vertex buffer in the order the data is declared within the template. 
    *   the order of the data also determines the atribute location within shaders.
    *
    *   @attention in order for the template to work properly, all template arguments must meet these requirements
    *   all dataTypes must contain no private members or pointers
    *   they must only contain float values
    *   the datatypes must be indicative of the amount of values within said atribute 
    *   (ie a single float will be indicative of one value while a struct holding 2 floats will atribute to 2 values)
    *
    *   @tparam 
    *   template pack, parameters must meet requirements in details section
    */
    template <typename VertexType,typename... T>
    class VertexResource
    {
    private:
        
        ///@brief constant value that dictates the total size of the verticies
        const size_t stride = aml::packSize<T...>()/sizeof(float);

        ///@brief openGL vertex buffer 
        GLuint vbo;
 
        /** 
        *   @brief 
        *   array holding the amount of floats in each template parameter
        *   @details 
        *   openGL needs to know how much floats are in each vector atribute
        *   this array stores the float count of each atribute in the order used in the template
        */
        const short floatCountArr[sizeof...(T)] = {(sizeof(T) / sizeof(float))...};

        /// @brief size of floatCountArr
        const size_t atributeSize = sizeof...(T);

        /// @brief constant value for the offset to add to the layout of the vertex elements
        const size_t layout;

        size_t bufferSize;
    public:
        /**
        *   @brief constructor for vertex resource
        *   @details creates the vertex buffer on the GPU and 
        *   establishes how that data is layed out within the buffer
        * 
        *   @param layoutOffset offset of the data atribute pointers. defaults to no offset (0)
        */
        VertexResource(size_t layoutOffset = 0) noexcept :layout(layoutOffset){
            glGenBuffers(1, &vbo);
            bindResource();
            bindAtributes();    
        };

        /** 
        *   @brief tells the graphics card to opperate on this specific vertex resource
        *  
        */
        void bindResource()
        {
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
        }

        /**
        *   @brief establishes how vertex data is positioned on the GPU
        *   
        */ 
        void bindAtributes(){
            size_t offSet = 0;
            for(size_t i = 0; i <atributeSize;i++){
                glVertexAttribPointer(
                    //set the atribute location and its size
                    i+layout, floatCountArr[i] , 
                    //tell openGl that this is atribute is a series of floats
                    GL_FLOAT, GL_FALSE,
                    //establish the distance inbetween verticies
                    stride * sizeof(float), 
                    //tell openGL where the atribute is located within the vertex
                    (void*) (offSet * sizeof(float)));
                  
                glEnableVertexAttribArray(i+layout);
                offSet+= floatCountArr[i];
            } 
            aml::checkForGLErrors(__FILE__,__LINE__);
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
        /**
        *   @brief pushes an array of verticies into the vertex buffer
        *
        *   @param rawData pointer to an array of verticies
        *   @param size size of the vertex array
        *   
        */
        void pushToGPU(VertexType * rawData, size_t size)
        {   
            //tell opengl to write data to this VBO
            bindResource();

            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, aml::packSize<T...>() *size, rawData, GL_STATIC_DRAW);
            bufferSize = size;
            aml::checkForGLErrors(__FILE__,__LINE__);
        }

        /**
         * @brief pushes an array of verticies into the vertex buffer
         * 
         * 
         * @param vertexArray std::vector holding verticies
         */
       
        void pushToGPU(std::vector<VertexType>& vertexArray)
        {
            //tell opengl to write data to this VBO
            bindResource();

            //set the buffer data to vertexArr
            glBufferData(GL_ARRAY_BUFFER, aml::packSize<T...>() * vertexArray.size(), vertexArray.data(), GL_STATIC_DRAW);   
            bufferSize = vertexArray.size();         
            aml::checkForGLErrors(__FILE__,__LINE__);
        }
        
        /**
         * @brief writes a data from a raw array of VertexType begining at a specific index in the buffer
         * 
         * @param rawData pointer to raw vertex data
         * @param size amount of verticies
         * @param index index in the buffer to write to
         */
        void write(VertexType * rawData, size_t size, size_t index){

            bindResource();
            glBufferSubData(GL_ARRAY_BUFFER, index, aml::packSize<T...>() * size, rawData);
            aml::checkForGLErrors(__FILE__,__LINE__);
        }

        /**
         * @brief writes a standard vector of vertexType begining at a specific index in the buffer
         * 
         * @param vertexArray standard vector of vertexType
         * @param index index to begin writing
         */
        void write(std::vector<VertexType>& vertexArray, size_t index){

            bindResource();
            glBufferSubData(GL_ARRAY_BUFFER, index, aml::packSize<T...>() * vertexArray.size(), vertexArray.data());
            aml::checkForGLErrors(__FILE__,__LINE__);
        }


        /**
         * @brief returns the size of the buffer in the GPU
         * 
         * @return size_t size of the buffer
         */
        size_t size(){
            return bufferSize;
        }
        /**
         * @brief Destroy the Vertex Resource object
         * 
         */
        ~VertexResource()
        {
            glDeleteBuffers(1, &vbo);
        }

        
    };
    /// @brief vertex buffer for 2d vertices
    typedef aml::VertexResource<aml::Vert2,
                                aml::Vector2float, //position
                                aml::Vector3float, //color
                                aml::Vector2float  //textcords
                                > VertexResource2d;
    /// @brief vertex buffer for 3d verticies
    typedef aml::VertexResource<aml::Vert3,
                                aml::Vector3float, //position
                                aml::Vector3float, //color
                                aml::Vector2float  //textcords
                                > VertexResource3d; 
}

#endif