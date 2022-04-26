#include "../include/Input/inputReciver.hpp"


using namespace aml;

void InputReciver::handleKeyInput(GLFWwindow* rawWindow, int key, int scancode, int action, int mods){
        
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->keyPressTable[key-InputReciver::arrayOffset] = action;

}
void InputReciver::handleMousePress(GLFWwindow* rawWindow, int button, int action, int mods){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->mousePressTable[button] = action;
};

void InputReciver::handleMouseMovement(GLFWwindow* rawWindow, double x, double y){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->mouseLocation.x = x;
    localInputReciver->mouseLocation.y = y;
};
void InputReciver::handleScroll(GLFWwindow* rawWindow, double x, double y){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->scrollMagnitude.x = x;
    localInputReciver->scrollMagnitude.y = y;
};

InputReciver* InputReciver::getInputReciver(GLFWwindow* rawWindow){
    //retrieve the aml::window object pointer that is stored within the raw GLFW window
    return reinterpret_cast<InputReciver*>(glfwGetWindowUserPointer(rawWindow));
};


InputReciver::InputReciver(aml::Window &window){
    //set up window input
    glfwSetWindowUserPointer(window.renderWindow,this);
    //set up InputReciver callbacks
    glfwSetKeyCallback(window.renderWindow, InputReciver::handleKeyInput);
    glfwSetMouseButtonCallback(window.renderWindow, InputReciver::handleMousePress);
    glfwSetCursorPosCallback(window.renderWindow, InputReciver::handleMouseMovement);
    glfwSetScrollCallback(window.renderWindow, InputReciver::handleScroll);
    for(int i = 0; i < 8; i++){
        mousePressTable[i] = false;
    }
};

bool InputReciver::keyPressed(int16_t keycode){
    return keyPressTable[keycode-InputReciver::arrayOffset];
};


bool InputReciver::keyTriggered(int16_t keycode){
    //get the press status of the key
    bool pressStatus = keyPressTable[keycode-InputReciver::arrayOffset];
    //set the pressed status to false to check for a keypress only once
    keyPressTable[keycode-InputReciver::arrayOffset] = false;
    return pressStatus;
};
bool InputReciver::mousePressed(int16_t keycode){
    return mousePressTable[keycode];
};


glm::vec2 InputReciver::mousePosition(){
    return mouseLocation;
};


glm::vec2 InputReciver::scrollAmount(){
    return scrollMagnitude;
};
void InputReciver::pollInput(){
    glfwPollEvents();
}