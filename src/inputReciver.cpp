#include "../include/Input/inputReciver.hpp"


using namespace aml;

void InputReciver::handleKeyInput(GLFWwindow* rawWindow, int key, int scancode, int action, int mods){
        
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->keyPressTable[key-32] = action;

}

InputReciver* InputReciver::getInputReciver(GLFWwindow* rawWindow){
    //retrieve the aml::window object pointer that is stored within the raw GLFW window
    return reinterpret_cast<InputReciver*>(glfwGetWindowUserPointer(rawWindow));
}
InputReciver::InputReciver(aml::Window &window){
    //set up window input
    glfwSetWindowUserPointer(window.renderWindow,this);
    glfwSetKeyCallback(window.renderWindow, InputReciver::handleKeyInput);
};

bool InputReciver::keyPressed(int16_t keycode){
    return keyPressTable[keycode-32];
};

void InputReciver::pollInput(){
    glfwPollEvents();
}