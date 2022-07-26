#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <functional>
#include <cassert>
#include <unordered_map>
#include <cinttypes>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_STYLE_MANAGER
#define AML_STYLE_MANAGER


namespace aml
{
    typedef GLFWwindow*& GLWindowRefrence; 
    /// @brief class that manages the style of a window
    class StyleManager{
        private:

            /**
             * will only ever be instansiated by the window class, 
             * so needs to be friend to access private constructor
             */
            friend class Window;
            
            /**
             * @brief Construct a new Style Manager object
             * 
             * @param rawWindow refrence to an openGL window pointer
             * @param width width of the window
             * @param height height of the window
             */
            StyleManager(GLWindowRefrence rawWindow,size_t width,size_t height);
        public:
        
    };
};

#endif
