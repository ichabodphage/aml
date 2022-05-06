
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_SHADER_TYPES
#define AML_SHADER_TYPES
namespace aml{

    /**
     * @brief enumerator for different shader types
     * 
     */
    enum ShaderType{
        FRAGMENT = GL_FRAGMENT_SHADER,
        VERTEX = GL_VERTEX_SHADER ,
        GEOMETRY = GL_GEOMETRY_SHADER
    };
}
#endif