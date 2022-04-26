#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../lib.hpp"

#ifndef AML_SHADER
#define AML_SHADER

namespace aml{
    enum ShaderType{
        FRAGMENT = GL_FRAGMENT_SHADER,
        VERTEX = GL_VERTEX_SHADER ,
        GEOMETRY = GL_GEOMETRY_SHADER
    };
    /*
        class that manages compiling of shaders
    */
    class ShaderResource{
        public:
            //GLuint id of the shader program
            GLuint shader;

            //aml ShaderType of the shader
            aml::ShaderType shaderType;
            
            //constructor using the type of shader and file path
            ShaderResource(const std::string shaderFile,aml::ShaderType type);
            ~ShaderResource();

            
    };
#define AML_DEFAULT_FRAG "src/basicShaders/basicFrag.frag", aml::ShaderType::FRAGMENT
#define AML_DEFAULT_VERT "src/basicShaders/basicVert.vert", aml::ShaderType::VERTEX 
}

#endif