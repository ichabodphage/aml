#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "shaderProgram.hpp"

#ifndef AML_UNIFORM
#define AML_UNIFORM

namespace aml{
    /*
        class that manages shader uniforms or inputs
    */
    class Uniform{
        private:
            aml::ShaderProgram* program;
    };


}




#endif