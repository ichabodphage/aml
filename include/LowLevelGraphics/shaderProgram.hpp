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
   
    /**
     * @brief class that manages ShaderResources and shader uniforms
     * 
     */
    class ShaderProgram{
        private:
            /// @brief GLuint id of the shader program
            GLuint programId;

            /// @brief map holding uniforms for the shader program
            std::unordered_map<std::string,aml::Uniform> uniformMap;

            /// @brief flag for if the program has been linked
            bool compiled = false;
        public:
            /**
             * @brief Construct a new Shader Program object using one vertex shader and one fragment shader
             * 
             * @param fragmentShader programs fragment shader
             * @param vertexShader programs vertex shader
             */
            ShaderProgram(aml::ShaderResource &fragmentShader,aml::ShaderResource &vertexShader);

            /**
             * @brief constructor for shader program with multiple shaders
             * 
             * @return * constructor 
             */
            ShaderProgram();

            /**
             * @brief Destroy the Shader Program object
             * 
             */
            ~ShaderProgram();
            
            /**
             * @brief runs the shader program once
             * 
             */
            void run();

            /**
             * @brief gets the ID of the shader program
             * 
             * @return GLuint shader program id
             */
            GLuint getID();
            
            /**
             * @brief adds a shader resource to the shader program
             * @attention 
             * throws a runtime error if the shader program allready has been linked and compiled
             * 
             * @param shader ShaderResource to add to the program
             */
            void addShader(aml::ShaderResource &shader);

            /**
             * @brief compiles and links all shader resources added to the shade program
             * 
             */
            void compile();

            /**
             * @brief accesss uniforms within the shader program
             * 
             * @param uniformName string holding name of the uniform
             * @return aml::Uniform& uniform at the specified name
             */
            aml::Uniform& operator[](const std::string uniformName);

            

    };

}

#endif