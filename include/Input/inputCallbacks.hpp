#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "inputReciver.hpp"

#ifndef AML_INPUT_CALLBACKS
#define AML_INPUT_CALLBACKS
/**
 * @brief series of functions that act as window input callbacks
 *
 */
namespace aml
{
    /**
     * @brief function that acts as a keyboard event callback
     *
     * @param window pointer to the window
     * @param key keycode of the key input
     * @param scancode platform specific keycode
     * @param action state of the keypress
     * @param mods modifiers of the keypress
     */
    void handleKeyInput(GLFWwindow *window, int key, int scancode, int action, int mods);
    

    /**
     * @brief unction that acts as a mouse button callback
     *
     * @param window pointer to the window
     * @param button code of the mouse button that was pressed
     * @param action state of the button press
     * @param mods modifiers of the button press
     */
    void handleMousePress(GLFWwindow *window, int button, int action, int mods);
    

    /**
     * @brief function that acts as a cursor movement callback
     *
     * @param window pointer to the window
     * @param x x cordinates of cursor
     * @param y y cordinates of cursor
     */
    void handleMouseMovement(GLFWwindow *window, double x, double y);

    /**
     * @brief function that acts as scrollwheel callback
     *
     * @param window pointer to the window
     * @param x x magnitide of the scroll
     * @param y y magnitude of the scroll
     */
    void handleScroll(GLFWwindow *window, double x, double y);
    
    /**
     * @brief gets a windows InputReciver
     *
     * @param window pointer to raw window
     * @return InputReciver* pointer to the windows InputReciver
     */
    InputReciver *getInputReciver(GLFWwindow *window);
}

#endif