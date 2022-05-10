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

#include "../lib.hpp"

#include "resource/elementBuffer.hpp"
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
        //shader program needs to acess the raw window
        friend class ShaderProgram;
        /*
            input reciver needs access to private variables
            to properly scan inputs from the window
        */
        friend class InputReciver;

        ///@brief openGl vertex array object
        GLuint vao;

        ///@brief width and height of the windo
        size_t width, height;

        ///@brief raw openGL render window
        GLFWwindow *renderWindow;

    public:
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
        *   @brief renders current VBO from the starting vertex index and the amount of verticies to draw
        *   @param index index to start drawing from
        *   @param amount amount of verticies to draw
        *   @return none
        */ 
        void renderVertexBuffer(size_t index, size_t amount);
        
        /**
        *   @brief renders a bound EBO using the size of the EBO
        *   @param amount amount of verticies to draw
        *   @return none
        */ 
        void renderBoundEBO(size_t amount);

        /**
         * @brief binds an EBO and draws its elements
         * 
         * @param ebo ebo to draw
         */
        void renderEBO(aml::ElementBuffer& ebo);
        /**
        *   @brief displays to the current draw target
        *   @return none
        */
        void display();

        // methods to controll the size of the window

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
        
        /**
        *   @brief returns the position of the window on the monitor
        *   @return glm::vec2 holding current position of the window
        */
        glm::vec2 position();

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
        *   @brief changes the title of the window
        *   @param title new title of the window
        *   @return none
        */ 
        void setTitle(const char *title);
    };
}

#endif