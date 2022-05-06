#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <cstdint>


#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "result.hpp"

#include "../lib.hpp"
#include "../LowLevelGraphics/window.hpp"

#ifndef AML_INPUT_RECIVER
#define AML_INPUT_RECIVER
namespace aml{
    /*
        class that manage polling of inputs
    */
    class InputReciver{
        private:
            //window is friend class as window holds a GLFWwindow thats needed to scan inputs from
            friend class aml::Window;

            
            static const size_t keyCount = 316;

            /// @brief array containing all key Inputs
            bool keyPressTable[InputReciver::keyCount];
            
            
            static const size_t mouseButtonCount = 8;

            /// @brief array containing all mouse button inputs
            bool mousePressTable[InputReciver::mouseButtonCount];

            /// @brief current location of the cursor of the window
            glm::vec2 mouseLocation;
            
            /// @brief magnitude of the current scroll
            glm::vec2 scrollMagnitude = glm::vec2(0,0);

            /// @brief constant that gets subtracted from each keycode to find its place in keyPresstable             
            static const size_t arrayOffset = 32;

            /*
                input callbacks used by the object to poll events from the window.
                all of them are friend functions as they need to access private variables
                of InputReciver to work
            */

            /*****************************************************************
             * @brief static function that acts as a keyboard event callback
             * 
             * @param window pointer to the window
             * @param key keycode of the key input
             * @param scancode platform specific keycode
             * @param action state of the keypress
             * @param mods modifiers of the keypress
             */
            static void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);

            /*****************************************************************
             * @brief static function that acts as a mouse button callback
             * 
             * @param window pointer to the window
             * @param button code of the mouse button that was pressed
             * @param action state of the button press
             * @param mods modifiers of the button press
             */
            static void handleMousePress(GLFWwindow* window,  int button, int action, int mods);
            friend void handleMousePress(GLFWwindow* window,  int button, int action, int mods);
            
            /*****************************************************************
             * @brief static function that acts as a cursor movement callback
             * 
             * @param window pointer to the window
             * @param x x cordinates of cursor
             * @param y y cordinates of cursor
             */
            static void handleMouseMovement(GLFWwindow* window, double x, double y);
            friend void handleMouseMovement(GLFWwindow* window, double x, double y);
            
            /*****************************************************************
             * @brief static function that acts as scrollwheel callback
             * 
             * @param window pointer to the window
             * @param x x magnitide of the scroll
             * @param y y magnitude of the scroll
             */
            static void handleScroll(GLFWwindow* window, double x, double y);
            friend void handleScroll(GLFWwindow* window, double x, double y);

            /**
             * @brief gets a windows InputReciver
             * 
             * @param window pointer to raw window
             * @return InputReciver* pointer to the windows InputReciver
             */
            static InputReciver* getInputReciver(GLFWwindow* window);
        public:

            /**
             * @brief creates an InputReciver for the selected window
             * 
             * @param window window to poll inputs from
             */
            InputReciver(aml::Window &window);

            //methods for polling inputs

            /**
             * @brief checks if a key is pressed down or not
             * 
             * @param keycode keycode to check for input 
             * @return true key is currently pressed
             * @return false key is not pressed
             */
            bool keyPressed(int16_t keycode);

            /**
             * @brief checks if a key was pressed only once
             * 
             * @param keycode keycode to check for input
             * @return true key was pressed once
             * @return false key is either held or not pressed
             */
            bool keyTriggered(int16_t keycode);

            //checks if a mouse button is pressed
            bool mousePressed(int16_t button);

            //returns the position of the cursor on the window
            glm::vec2 mousePosition();

            //gets mouses scroll
            glm::vec2 scrollAmount();

            //polls for input and fills the inputBuffer
            void pollInput();

    };


}
#endif