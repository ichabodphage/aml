#include "../include/uniform.hpp"
#include "../include/shaderProgram.hpp"

using namespace aml;

Uniform::Uniform(aml::ShaderProgram* shaderProgram,std::string shaderParameter):
    program(shaderProgram),paramName(shaderParameter){
    uniformId = glGetUniformLocation(program->getID(), paramName.c_str());
};


void Uniform::setMatrix(glm::mat4 &matrix){
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat3 &matrix){
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat2 &matrix){
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}