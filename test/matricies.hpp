#include <vector>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GLFW/glfw3.h>


namespace aml{
    glm::mat4 viewMatrix =
        glm::lookAt(glm::vec3(0.0f, 0.0f, 20.0f), // Eye position
        glm::vec3(0.0f, 0.0f, 0.0f),  // Viewpoint position
        glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 modelMatrix = glm::scale(glm::mat4(1), glm::vec3(5,5,5));

    
}