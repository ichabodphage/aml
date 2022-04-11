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

#include "shaderProgram.hpp"
#ifndef AML_VIEW
#define AML_VIEW

namespace aml{

    /*
        class that manages matricies for rendering
    */

    class RenderMatrix{
    public:
        glm::mat4 matrix;
        GLuint boundProgramID;
        GLuint matrixID;
        std::string shaderLoc;
        RenderMatrix(glm::mat4 initMatrix,GLuint program,std::string matrixType){
            matrix = initMatrix;
            boundProgramID = program;
            shaderLoc = matrixType;
        }

        void pushToGPU(){
            matrixID= glGetUniformLocation(boundProgramID, shaderLoc.c_str());

            glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);
        }
    };
}


#endif