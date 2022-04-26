#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "shaderResource.hpp"
#include "uniform.hpp"
#include "../lib.hpp"

#ifndef AML_SHADER_PROGRAM
#define AML_SHADER_PROGRAM

namespace aml{
   
    /*
        class that manages linking shaders into one program
    */
    class ShaderProgram{
        private:
            //GLuint id of the shader program
            GLuint programId;
            //map holding uniforms for the shader program
            std::unordered_map<std::string,aml::Uniform> uniformMap;
        public:
            //constructor using vertex and fragment shader, compiles and links the fragment and vertex shader together
            ShaderProgram(aml::ShaderResource &fragmentShader,aml::ShaderResource &vertexShader);

            //deconstructor of shaderProgram
            ~ShaderProgram();
            
            //runs the programs shaders
            void run();

            //gets the ID of the compiled program
            GLuint getID();

            //opperator that allows access to uniforms within the shader
            aml::Uniform& operator[](const std::string uniformName);

            

    };

}

#endif