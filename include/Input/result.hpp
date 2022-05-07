
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "inputType.hpp"
#ifndef AML_RESULT
#define AML_RESULT

namespace aml{
    /**
     * @brief class that represents the result of an input
     * 
     */
    class Result{
    private:
        /// @brief type of the input
        aml::InputType type;
        
        /// @brief activity of input
        bool active;

        /**
         * @brief union that holds relavant information per type of input
         * 
         */
        union {
            /// @brief keycode of a keyboard input
            int key;
            
            /// @brief magnitude of a scroll input
            glm::vec2 magnitude;

            /// @brief position of a mouse click or move input
            glm::vec2 pos;
        } state;

        
   };

}



#endif