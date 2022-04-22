#include "../include/LowLevelGraphics/uniform.hpp"
#include "../include/LowLevelGraphics/shaderProgram.hpp"

using namespace aml;

Uniform::Uniform(aml::ShaderProgram* shaderProgram,std::string shaderParameter):
    program(shaderProgram),paramName(shaderParameter){
    uniformId = glGetUniformLocation(program->getID(), paramName.c_str());
};


//4xN matricies
void Uniform::setMatrix(glm::mat4 &matrix){
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat4x3 &matrix){
    glUniformMatrix4x3fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat4x2 &matrix){
    glUniformMatrix4x2fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}


//3xN matricies
void Uniform::setMatrix(glm::mat3x4 &matrix){
    glUniformMatrix3x4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat3 &matrix){
    glUniformMatrix3fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat3x2 &matrix){
    glUniformMatrix3x2fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}


//2xN matricies
void Uniform::setMatrix(glm::mat2x4 &matrix){
    glUniformMatrix2x4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat2x3 &matrix){
    glUniformMatrix2x3fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

void Uniform::setMatrix(glm::mat2 &matrix){
    glUniformMatrix2fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

//vector setters

void Uniform::setVector(glm::vec4 &vector){
    glUniform4f(uniformId,vector.x ,vector.y,vector.z,vector.w);
};

void Uniform::setVector(glm::vec3 &vector){
    glUniform3f(uniformId,vector.x ,vector.y,vector.z);
};

void Uniform::setVector(glm::vec2 &vector){
    glUniform2f(uniformId,vector.x ,vector.y);
};

//scalar setters
void Uniform::setScalar(float scalar){
    glUniform1f(uniformId,scalar);
};