#include "../include/shaderProgram.hpp"

using namespace aml;


ShaderProgram::ShaderProgram(aml::ShaderResource &fragmentShader,aml::ShaderResource &vertexShader){
    programId = glCreateProgram();
    glAttachShader(programId, vertexShader.shader);
    glAttachShader(programId, fragmentShader.shader);
    glBindFragDataLocation(programId, 0, "outColor");
    
    glLinkProgram(programId);
    glUseProgram(programId);
    
    //define position of shader data
    posAttrib = glGetAttribLocation(programId, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

ShaderProgram::~ShaderProgram(){
    glDeleteProgram(programId);
}
void ShaderProgram::run(){
    glUseProgram(programId);
}

GLuint ShaderProgram::getID(){
    return programId;
};


Uniform& ShaderProgram::operator[](const std::string uniformName){
    if(uniformMap.count(uniformName) == 0){
        uniformMap[uniformName] = aml::Uniform(this,uniformName);
    }
    return uniformMap[uniformName];
}