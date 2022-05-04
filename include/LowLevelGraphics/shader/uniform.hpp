#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "../../lib.hpp"



#ifndef AML_UNIFORM
#define AML_UNIFORM

namespace aml{
    //forward declaration
    class ShaderProgram;
    
    /**
     * avoid working on this class at all costs, litterally all its member functions are just the same openGL
     * function but with exactly 1 character difference in each of them
     * 
     */

    /**
     * @brief class that manages interfacing with uniforms within shaders
     * 
     * @details uniforms are used as way to pass data into shaders without
     * reseting the data within vertex buffers, they are meant for passing 
     * small amounts of data into the GPU, and not the large amounts of data 
     * vertex buffers handle
     */
    class Uniform{
        private:
            /// @brief pointer to a compiled shader program
            aml::ShaderProgram* program;

            /// @brief id of the uniform in the GPU
            GLuint uniformId;

            /// @brief name of the uniform in the shader
            std::string paramName;

        public:
            /// @brief this only exists to remove a compiler error regrarding std::map
            Uniform() = default;
            
            /**
             * @brief Construct a new Uniform object
             * 
             * @param shaderProgram  pointer back to compiled shader program
             * @param shaderParameter name of the uniform in the shader
             */
            Uniform(aml::ShaderProgram* shaderProgram,std::string shaderParameter);

            // matrix functions

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 4x4 matrix
             */
            void setMatrix(glm::mat4 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 4x3 matrix
             */
            void setMatrix(glm::mat4x3 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 4x2 matrix
             */
            void setMatrix(glm::mat4x2 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 3x4 matrix
             */
            void setMatrix(glm::mat3x4 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 3x3 matrix
             */
            void setMatrix(glm::mat3 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 3x2 matrix
             */
            void setMatrix(glm::mat3x2 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 2x4 matrix
             */
            void setMatrix(glm::mat2x4 &matrix);

            
            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 2x3 matrix
             */
            void setMatrix(glm::mat2x3 &matrix);

            /**
             * @brief sets the uniform to the speficied matrix
             * 
             * @param matrix 2x2 matrix
             */
            void setMatrix(glm::mat2 &matrix);



            ///////////////////////////////////////////////////////////////////////////

            //vector functions

            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 4 elements
             */
            void setVector4(glm::vec4 &vector);

            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 3 elementsar(float scalarOne, float scalarTwo,float scalarThree);
             */
            void setVector3(glm::vec3 &vector);


            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 2 elements
             */
            void setVector2(glm::vec2 &vector);

        


            ///////////////////////////////////////////////////////////////////////////

            //// float setters

            /**
             * @brief Set the uniform to the specified scalar
             * 
             * @param scalar float value
             */
            void setScalarFloat(float scalar);
        

            ///////////////////////////////////////////////////////////////////////////

            // int setters
            
            /**
             * @brief Set the uniform to the specified scalar
             * 
             * @param scalar integer value
             */
            void setScalarInt(int scalar);



            ///////////////////////////////////////////////////////////////////////////

            // array setters

            /**
             * @brief Sets the uniform to an array of floats
             * 
             * @param array pointer to raw array
             * @param size lenght of the array
             */

            void setFloatArr(float * array, size_t size);


            /**
             * @brief Sets the uniform to an array of floats
             * 
             * @param array standard vector of floats
             */

            void setFloatArr(std::vector<float> &array);


            /**
             * @brief Sets the uniform to an array of integers
             * 
             * @param array pointer to raw array
             * @param size lenght of the array
             */

            void setIntArr(int * array, size_t size);


            /**                         
             * @brief Sets the uniform to an array of integers
             *  
             * @param array standard vector of integers
             */

            void setIntArr(std::vector<int> &array);


            // vector array setters

            /**
             * @brief Set the uniform to an array of 2d vectors
             * 
             * @param array raw pointer to vector array
             * @param size size of the array
             */
            void setVector2Arr(glm::vec2 * array,size_t size);

            /**
             * @brief Set the uniform to an array of 2d vectors
             * 
             * @param array standard vector of 2d vectors
             */
            void setVector2Arr(std::vector<glm::vec2> &array);

            /**
             * @brief Set the uniform to an array of 3d vectors
             * 
             * @param array raw pointer to vector array
             * @param size size of the array
             */
            void setVector3Arr(glm::vec3 * array, size_t size);


            /**
             * @brief Set the uniform to an array of 3d vectors
             * 
             * @param array standard vector of 3d vectors
             */
            void setVector3Arr(std::vector<glm::vec3> &array);

            /**
             * @brief Set the uniform to an array of 4d vectors
             * 
             * @param array raw pointer to vector array
             * @param size size of the array
             */
            void setVector4Arr(glm::vec4 * array, size_t size);


            /**
             * @brief Set the uniform to an array of 4d vectors
             * 
             * @param array standard vector of 4d vectors
             */
            void setVector4Arr(std::vector<glm::vec4> &array);
    };


}




#endif