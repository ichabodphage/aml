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
    typedef GLFWwindow *&GLWindowRefrence;
    /// @brief class that manages the style of a window
    class StyleManager
    {
    private:
        /**
         * will only ever be instansiated by the window class,
         * so needs to be friend to access private constructor
         */
        friend class Window;

        ///@brief width and height of the window
        size_t width, height;

        ///@brief local window
        GLWindowRefrence localWindow;
        /**
         * @brief Construct a new Style Manager object
         *
         * @param rawWindow refrence to an openGL window pointer
         * @param width width of the window
         * @param height height of the window
         */
        StyleManager(GLWindowRefrence rawWindow, size_t width, size_t height);


    public:
        /**
         * @brief delete constructor that prevents a current instance of StyleManager to be coppied
         * 
         * @param copySource the StyleManager instance that wont be coppied
         */
        StyleManager(StyleManager& copySource) = delete;
        /**
         *   @brief minimizes the window on the desktop
         *   @return none
         */
        void minimize();

        /**
         *   @brief brief description unminimizes a minimized window
         *   @return none
         */
        void unMinimize();

        /**
         *   @brief brief description sets the window to the size of the entire screen
         *   @return none
         */
        void maximize();

        /**
         *   @brief returns the width/height window dimensions
         *   @return glm::vec2 holding current width and height of the window
         */
        glm::vec2 dimensions();

        // methods to controll the position of the window
    };
};

#endif
