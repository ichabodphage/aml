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

            //sets the window as the current target to draw to
            void makeDrawTarget();

            //clears the window 
            void clear();

            //clear that forces openGL to clear the current window
            void clear(bool forceRenderTarget);

            //returns if the window should be active or not
            bool isActive();

            //renders the VBO to the current window
            void render(size_t index,size_t amount);
            
            //swaps the video buffer and shows the next frame
            void display();


            //returns the width/height window dimensions
            glm::vec2 dimensions();

    };
}

#endif