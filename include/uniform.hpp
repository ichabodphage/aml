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



#ifndef AML_UNIFORM
#define AML_UNIFORM

namespace aml{
    //forward declaration
    class ShaderProgram;
    /*
        class that manages shader uniforms or inputs
    */
    class Uniform{
        private:
            //pointer back to the uniforms shader program
            aml::ShaderProgram* program;

            GLuint uniformId;
            //name of the uniform in the shader
            std::string paramName;

        public:
            //this only exists to remove a compiler error
            Uniform() = default;
            
            Uniform(aml::ShaderProgram* shaderProgram,std::string shaderParameter);

            //sets the uniform parameter to a 4x4 matrix
            void setMatrix(glm::mat4 &matrix);
            //sets the uniform parameter to a 3x3 matrix
            void setMatrix(glm::mat3 &matrix);
            //sets the uniform parameter to a 2x2 matrix
            void setMatrix(glm::mat2 &matrix);

    };


}




#endif