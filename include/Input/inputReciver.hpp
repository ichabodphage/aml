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
            friend class aml::Window;
            //map containing all key Inputs
            bool keyPressTable[316];

            //private static function that handles openGl key input
            static void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
            //gets the input reciver
            static InputReciver* getInputReciver(GLFWwindow* window);
        public:
            InputReciver(aml::Window &window);
            //checks a key in the keyPressTable
            bool checkKey(int16_t keycode);

            //polls for input and fills the inputBuffer
            void pollInput();
    };


}



#endif