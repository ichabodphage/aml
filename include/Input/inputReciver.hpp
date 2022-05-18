#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <cstdint>
#include <queue>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "result.hpp"

#include "../lib.hpp"
#include "../LowLevelGraphics/window.hpp"
#ifndef AML_INPUT_RECIVER
#define AML_INPUT_RECIVER
namespace aml
{
    // forward declaration
    void handleKeyInput(GLFWwindow *window, int key, int scancode, int action, int mods);
    void handleMousePress(GLFWwindow *window, int button, int action, int mods);
    void handleMouseMovement(GLFWwindow *window, double x, double y);
    void handleScroll(GLFWwindow *window, double x, double y);
    /*
        class that manage polling of inputs
    */

    class InputReciver
    {
    private:
        // window is friend class as window holds a GLFWwindow thats needed to scan inputs from
        friend class aml::Window;

        /// @brief standard queue of input results
        std::queue<aml::Result> resultQueue;
        /// @brief number of keys to track
        static const size_t keyCount = 316;

        /// @brief array containing all key Inputs
        bool keyPressTable[InputReciver::keyCount];

        /// @brief number of mouse buttons to track
        static const size_t mouseButtonCount = 8;

        /// @brief array containing all mouse button inputs
        bool mousePressTable[InputReciver::mouseButtonCount];

        /// @brief current location of the cursor of the window
        glm::vec2 mouseLocation;

        /// @brief magnitude of the current scroll
        glm::vec2 scrollMagnitude = glm::vec2(0, 0);

        /// @brief constant that gets subtracted from each keycode to find its place in keyPresstable
        static const size_t arrayOffset = 32;

        /// @brief constant max size of the input buffer
        const size_t maxBufferSize;
        /*
            input callbacks used by the object to poll events from the window.
            all of them are friend functions as they need to access private variables
            of InputReciver to work
        */

        friend void aml::handleMouseMovement(GLFWwindow *window, double x, double y); 
        friend void aml::handleScroll(GLFWwindow *window, double x, double y); 
        friend void aml::handleMousePress(GLFWwindow *window, int button, int action, int mods); 
        friend void aml::handleKeyInput(GLFWwindow *window, int key, int scancode, int action, int mods);

    public:
        /**
         * @brief creates an InputReciver for the selected window
         *
         * @param window window to poll inputs from
         * @param maxLength max length of the input buffer
         */
        InputReciver(aml::Window &window, const size_t maxLength);

        // methods for polling inputs

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

        /**
         * @brief checks if a mouse button is pressed
         *
         * @param button code of the mouse button to check
         * @return true mouse button is pressed
         * @return false mouse button is not pressed
         */
        bool mousePressed(int16_t button);

        /**
         * @brief gets the position of the cursor on the window
         *
         * @return glm::vec2 cursor positon
         */
        glm::vec2 mousePosition();

        /**
         * @brief gets the current magnitude of the scrollwheel
         *
         * @return glm::vec2 scroll magnitude
         */
        glm::vec2 scrollAmount();

        /**
         * @brief polls the window for input
         *
         */
        void pollInput();

        /**
         * @brief checks if the input queue has pending results
         *
         * @return true queue has pending results
         * @return false queue has no results
         */
        bool pendingResults();

        /**
         * @brief returns the next input result in the queue
         *
         * @return aml::Result& next result
         */
        aml::Result nextResult();
    };
    

}
#endif