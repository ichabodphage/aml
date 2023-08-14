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

#include "../../lib.hpp"


#include "styleManager.hpp"
#ifndef AML_WINDOW
#define AML_WINDOW

namespace aml
{

    /**
     *
     * @brief class that manages a window that displays graphics
     * @details contains mostly low level methods to interface with openGl window functions
     */
    class Window
    {
    private:
        // shader program needs to acess the raw window
        friend class ShaderProgram;
        /*
            input reciver needs access to private variables
            to properly scan inputs from the window
        */
        friend class InputReciver;

        ///@brief openGl vertex array object
        GLuint vao;



        ///@brief raw openGL render window
        GLFWwindow *renderWindow;

        ///@brief system time in seconds when the window was opened
        double windowStartTime;

    public:

        /// @brief windows' style manager
        aml::StyleManager style;

        /**
         *   @brief window constuctor, creates a window and sets the window as the current draw target
         *   @param width width of the window
         *   @param height height of the window
         *   @param name name of the window
         */
        Window(size_t width, size_t height, const char *name);

        ///@brief deletes the windows vertex array and its raw openGL window
        ~Window();

        // methods that controll what is displayed on the window
        /**
         *   @brief tells openGL to render to this window instance
         *   @return none
         */
        void makeDrawTarget();

        /**
         *   @brief clears the current draw target
         *   @return none
         */
        void clear();

        
        /**
         *   @brief displays to the current draw target
         *   @return none
         */
        void display();


        // methods to controll the activity of the window

        /**
         *   @brief gets the current activity status of the window
         *   @return boolean value, false means the window is inactive, true means the window is active
         */
        bool isActive();

        /**
         *   @brief closes the window and sets its activity to false
         *   @return none
         */
        void close();

        
        /**
         * @brief returns how long the window has been active
         * 
         * @return double current time in seconds
         */
        double upTime();
    };
}

#endif