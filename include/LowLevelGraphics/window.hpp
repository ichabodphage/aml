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

    typedef std::function<void(int,int)> KeyCallback;
    class Window{
        private:
            /*
                input reciver needs access to private variables 
                to properly scan inputs from the window
            */
            friend class InputReciver;

            //window vertex array object
            GLuint vao;

            //width and height of window
            size_t width,height;
        
            //GLFW render target
            GLFWwindow* renderWindow;
        public:
            

            //constructor using window width, height, and name
            Window(size_t width,size_t height, const char* name);

            //window deconstructor
            ~Window();


            // methods that controll what is displayed on the window

            //sets the window as the current target to draw to
            void makeDrawTarget();

            //clears the window 
            void clear();

            //renders the VBO to the current window
            void render(size_t index,size_t amount);
            
            //swaps the video buffer and shows the next frame
            void display();


            // methods to controll the size of the window

            //minimizes the window in the OS
            void minimize();

            //unminimizes a minimized window
            void unMinimize();

            //sets the window to the size of the entire screen
            void maximize();

            //returns the width/height window dimensions
            glm::vec2 dimensions();

            
            //methods to controll the activity of the window

            //returns if the window should be active or not
            bool isActive();

            //closes the window
            void close(); 

    };
}

#endif