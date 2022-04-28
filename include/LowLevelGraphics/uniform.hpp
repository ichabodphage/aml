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

#include "../lib.hpp"


#ifndef AML_UNIFORM
#define AML_UNIFORM

namespace aml{
    //forward declaration
    class ShaderProgram;
    
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


            //vector functions

            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 4 elements
             */
            void setVector(glm::vec4 &vector);

            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 3 elements
             */
            void setVector(glm::vec3 &vector);

            /**
             * @brief Set the uniform to the specified vector
             * 
             * @param vector vector with 2 elements
             */
            void setVector(glm::vec2 &vector);

            //scalar functions

            /**
             * @brief Set the uniform to the specified scalar
             * 
             * @param scalar float value
             */
            void setScalar(float scalar);

            /**
             * @brief Set the uniform to the specified ID
             * 
             * @param scalar integer value
             */
            void setId(int scalar);

    };


}




#endif