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


#ifndef AML_VIEW
#define AML_VIEW

namespace aml{

    /*
        class that manages matricies for rendering
    */

    class RenderMatrix{
    public:
        glm::mat4 matrix;
        GLuint matrixID;
        GLuint boundProgramID;
        std::string shaderLoc;
        RenderMatrix(glm::mat4 initMatrix,GLuint program,std::string matrixType);
        

        void pushToGPU();

    };
}


#endif