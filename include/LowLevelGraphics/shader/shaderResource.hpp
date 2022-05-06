#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "shaderType.hpp"
#include "defaultShaderResources.hpp"
#include "../../lib.hpp"

#ifndef AML_SHADER
#define AML_SHADER

namespace aml{
    /**
     * @brief class that manages an individual shader
     * 
     */
    class ShaderResource{
        private:
            friend class ShaderProgram;

            /// @brief id of the shader
            GLuint shader;

            
            /// @brief type of shader
            aml::ShaderType shaderType;
        public:
            /**
             * @brief Construct a new Shader Resource object, compiles the shader from path shaderFile
             * 
             * @param shaderFile file path holding the shader
             * @param type type of shader
             */
            ShaderResource(const std::string shaderFile,aml::ShaderType type);

            


            /**
             * @brief Destroys the Shader Resource object
             * 
             */
            ~ShaderResource();

            
    };
 
}

#endif