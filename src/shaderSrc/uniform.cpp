#include "../../include/LowLevelGraphics/shader/uniform.hpp"
#include "../../include/LowLevelGraphics/shader/shaderProgram.hpp"

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

void Uniform::setVector4(glm::vec4 &vector){
    glUniform4f(uniformId,vector.x ,vector.y,vector.z,vector.w);
};

void Uniform::setVector4Arr(glm::vec4 * array, size_t size) 
{
    glUniform4fv(uniformId,size,
    reinterpret_cast<float*>(array));
}

void Uniform::setVector4Arr(std::vector<glm::vec4> &array) 
{
    glUniform4fv(uniformId,array.size(),
    reinterpret_cast<float*>(array.data()));   
};









void Uniform::setVector3(glm::vec3 &vector){
    glUniform3f(uniformId,vector.x ,vector.y,vector.z);
};


void Uniform::setVector3Arr(glm::vec3 * array, size_t size) 
{
    glUniform3fv(uniformId,size,
    reinterpret_cast<float*>(array));
}

void Uniform::setVector3Arr(std::vector<glm::vec3> &array) 
{
    glUniform3fv(uniformId,array.size(),
    reinterpret_cast<float*>(array.data()));   
}






void Uniform::setVector2(glm::vec2 &vector){
    glUniform2f(uniformId,vector.x ,vector.y);
};


void Uniform::setVector2Arr(glm::vec2 * array,size_t size){
    glUniform2fv(uniformId,size,
    reinterpret_cast<float*>(array)
    );
}

void Uniform::setVector2Arr(std::vector<glm::vec2> &array) 
{
    glUniform2fv(uniformId,array.size(),
    reinterpret_cast<float*>(array.data()));   
}





//scalar setters
void Uniform::setScalarFloat(float scalar){
    glUniform1f(uniformId,scalar);
};

//int scalar setters
void Uniform::setScalarInt(int scalar){
    glUniform1i (uniformId,scalar);
};

// array setters

void Uniform::setFloatArr(float * array, size_t size){
    glUniform1fv(uniformId,size,array);
}

void Uniform::setFloatArr(std::vector<float> &array){
    glUniform1fv(uniformId,array.size(),array.data());
}


void Uniform::setIntArr(int * array, size_t size){
    glUniform1iv(uniformId,size,array);
};


void Uniform::setIntArr(std::vector<int> &array){
    glUniform1iv(uniformId,array.size(),array.data());
};