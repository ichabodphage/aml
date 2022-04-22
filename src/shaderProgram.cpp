#include "../include/LowLevelGraphics/shaderProgram.hpp"

using namespace aml;


ShaderProgram::ShaderProgram(aml::ShaderResource &fragmentShader,aml::ShaderResource &vertexShader){
    programId = glCreateProgram();
    glAttachShader(programId, vertexShader.shader);
    glAttachShader(programId, fragmentShader.shader);
    glBindFragDataLocation(programId, 0, "outColor");
    
    glBindAttribLocation(programId,0,"vertexPosition");
    glLinkProgram(programId);
    glUseProgram(programId);    
    
    aml::checkForGLErrors(__FILE__,__LINE__);
    
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