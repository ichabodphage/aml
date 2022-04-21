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

#ifndef AML_WINDOW
#define AML_WINDOW

namespace aml{
    /*
        class that manages a window used to display graphics
    */

    
    class Window{
        private:
            //window vertex array object
            GLuint vao;
            //width and height of window
            size_t width,height;
            
            std::unordered_map<int,std::function<void(int)>> inputMap;
            //GLFW render target
            GLFWwindow* renderWindow;

            //private static function that handles openGl key input
            static void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
            //gets the AML window that holds rawWindow
            static aml::Window* getAmlWindow(GLFWwindow* rawWindow);
        public:
            

            //constructor using window width, height, and name
            Window(size_t width,size_t height, const char* name);

            ~Window();

            //clears the window 
            void clear();

            //returns if the window should be active or not
            bool isActive();

            //renders the current bound VBO
            void renderVBO(size_t index,size_t amount);

            //calls renderVBO and display
            void draw(size_t index, size_t amount);

            //swaps the video buffer and shows the next frame
            void display();

            //polls for user input
            void pollInput();
            //returns the width/height window dimensions
            glm::vec2 dimensions();

            //adds a key input into the windows input map
            void addKeyInput(int keyCode,std::function<void(int)> callback);
    };
}

#endif