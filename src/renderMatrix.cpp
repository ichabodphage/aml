#include "../include/renderMatrix.hpp"

using namespace aml;

RenderMatrix::RenderMatrix(glm::mat4 initMatrix,GLuint program,std::string matrixType):
matrix(initMatrix),boundProgramID(program),shaderLoc(matrixType){};


void RenderMatrix::pushToGPU(){
    matrixID= glGetUniformLocation(boundProgramID, shaderLoc.c_str());
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);
}