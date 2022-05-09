#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#ifndef AML_INPUT_TYPE
#define AML_INPUT_TYPE
namespace aml{
    /**
     * @brief enumerator for different types of input
     * 
     */
    enum InputType{
        /// @brief mousewheel input
        scroll,
        /// @brief cursor movement input
        mouseMove,
        /// @brief mouse button press
        mousePress,
        /// @brief key input
        key,

    };
}


#endif