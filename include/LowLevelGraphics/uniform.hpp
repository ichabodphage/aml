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
            //this only exists to remove a compiler error
            Uniform() = default;
            
            Uniform(aml::ShaderProgram* shaderProgram,std::string shaderParameter);

            // matrix functions

            //sets the uniform parameter to a 4x4 matrix
            void setMatrix(glm::mat4 &matrix);

            //sets the uniform parameter to a 4x3 matrix
            void setMatrix(glm::mat4x3 &matrix);

            //sets the uniform parameter to a 4x2 matrix
            void setMatrix(glm::mat4x2 &matrix);

            //sets the uniform parameter to a 3x4 matrix
            void setMatrix(glm::mat3x4 &matrix);

            //sets the uniform parameter to a 3x3 matrix
            void setMatrix(glm::mat3 &matrix);

            //sets the uniform parameter to a 3x2 matrix
            void setMatrix(glm::mat3x2 &matrix);

            //sets the uniform parameter to a 2x4 matrix
            void setMatrix(glm::mat2x4 &matrix);

            //sets the uniform parameter to a 2x3 matrix
            void setMatrix(glm::mat2x3 &matrix);

            //sets the uniform parameter to a 2x2 matrix
            void setMatrix(glm::mat2 &matrix);


            //vector functions
            //sets the uniform parameter to a 4d vector
            void setVector(glm::vec4 &vector);

            //sets the uniform parameter to a 3d vector
            void setVector(glm::vec3 &vector);

            //sets the uniform parameter to a 2d vector
            void setVector(glm::vec2 &vector);

            //scalar functions
            //sets the uniform to a single scalar value
            void setScalar(float scalar);
            

    };


}




#endif