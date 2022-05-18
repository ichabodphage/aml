#include "../include/Input/inputReciver.hpp"
#include "../include/Input/inputCallbacks.hpp"

using namespace aml;


InputReciver::InputReciver(aml::Window &window, const size_t bufferLength):maxBufferSize(bufferLength){
    //set up window input
    glfwSetWindowUserPointer(window.renderWindow,this);
    //set up InputReciver callbacks
    glfwSetKeyCallback(window.renderWindow, aml::handleKeyInput);

    //mouse input callbacks
    glfwSetMouseButtonCallback(window.renderWindow, aml::handleMousePress);
    glfwSetCursorPosCallback(window.renderWindow, aml::handleMouseMovement);
    glfwSetScrollCallback(window.renderWindow,  aml::handleScroll);

    //set all values in the mousePressTable to false
    for(int i = 0; i < InputReciver::mouseButtonCount; i++){
        mousePressTable[i] = false;
    }
    //set all values in keyPressTable to false
    for(int i = 0; i < InputReciver::keyCount; i++){
        keyPressTable[i] = false;
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

bool InputReciver::pendingResults() 
{
    pollInput();
    return !resultQueue.empty();
}

aml::Result InputReciver::nextResult() 
{
    aml::Result next = resultQueue.front();
    resultQueue.pop();
    return next;
}