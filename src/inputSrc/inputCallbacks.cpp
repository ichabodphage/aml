#include "../../include/Input/inputCallbacks.hpp"


aml::InputReciver* aml::getInputReciver(GLFWwindow* rawWindow){
    //retrieve the aml::window object pointer that is stored within the raw GLFW window
    return reinterpret_cast<aml::InputReciver*>(glfwGetWindowUserPointer(rawWindow));
};

void aml::handleKeyInput(GLFWwindow* rawWindow, int key, int scancode, int action, int mods){
        
    aml::InputReciver* localInputReciver = aml::getInputReciver(rawWindow);
    localInputReciver->keyPressTable[key-InputReciver::arrayOffset] = action;
    //return if queue is full
    if(localInputReciver->resultQueue.size() > localInputReciver->maxBufferSize){
        return;
    }
    //push result to input recivers event queue
    aml::Result result;
    result.type = aml::InputType::key;
    result.active = action;
    result.modifiers = mods;
    result.state.key = key;
    localInputReciver->resultQueue.push(result);

}
void aml::handleMousePress(GLFWwindow* rawWindow, int button, int action, int mods){
    aml::InputReciver* localInputReciver = aml::getInputReciver(rawWindow);
    //set the activity of the index button to action
    localInputReciver->mousePressTable[button] = action;

    //return if queue is full
    if(localInputReciver->resultQueue.size() > localInputReciver->maxBufferSize){
        return;
    }

    //push result to input recivers event queue
    aml::Result result;
    result.type = aml::InputType::mousePress;
    result.active = action;
    result.modifiers = mods;
    result.state.mouseButton = button;
    localInputReciver->resultQueue.push(result);
};

void aml::handleMouseMovement(GLFWwindow* rawWindow, double x, double y){
    aml::InputReciver* localInputReciver = aml::getInputReciver(rawWindow);

    //set the current cursor location on the window
    localInputReciver->mouseLocation.x = x;
    localInputReciver->mouseLocation.y = y;

    //return if queue is full
    if(localInputReciver->resultQueue.size() > localInputReciver->maxBufferSize){
        return;
    }

    //push result to input recivers event queue
    aml::Result result;
    result.type = aml::InputType::mouseMove;
    result.active = true;
    result.state.pos = glm::vec2(x,y);
    localInputReciver->resultQueue.push(result);
};


void aml::handleScroll(GLFWwindow* rawWindow, double x, double y){
    aml::InputReciver* localInputReciver = aml::getInputReciver(rawWindow);
    //set the magnitude of the scroll event
    localInputReciver->scrollMagnitude.x = x;    
    localInputReciver->scrollMagnitude.y = y;

    //return if queue is full
    if(localInputReciver->resultQueue.size() > localInputReciver->maxBufferSize){
        return;
    }
    //push result to input recivers event queue
    aml::Result result;
    result.type = aml::InputType::scroll;
    result.active = true;
    result.state.magnitude = glm::vec2(x,y);
    localInputReciver->resultQueue.push(result);   
};