#include "../include/Input/inputReciver.hpp"


using namespace aml;


void InputReciver::handleKeyInput(GLFWwindow* rawWindow, int key, int scancode, int action, int mods){
        
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    localInputReciver->keyPressTable[key-InputReciver::arrayOffset] = action;

    aml::Result result;
    result.type = aml::InputType::key;
    result.active = action;
    result.state.key = key;
    localInputReciver->resultQueue.push(result);

}
void InputReciver::handleMousePress(GLFWwindow* rawWindow, int button, int action, int mods){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    //set the activity of the index button to action
    localInputReciver->mousePressTable[button] = action;
    
    aml::Result result;
    result.type = aml::InputType::mousePress;
    result.active = action;
    result.state.mouseButton = button;
    localInputReciver->resultQueue.push(result);
};

void InputReciver::handleMouseMovement(GLFWwindow* rawWindow, double x, double y){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);

    //set the current cursor location on the window
    localInputReciver->mouseLocation.x = x;
    localInputReciver->mouseLocation.y = y;

    aml::Result result;
    result.type = aml::InputType::mouseMove;
    result.active = true;
    result.state.pos = glm::vec2(x,y);
    localInputReciver->resultQueue.push(result);
};


void InputReciver::handleScroll(GLFWwindow* rawWindow, double x, double y){
    InputReciver* localInputReciver = InputReciver::getInputReciver(rawWindow);
    //set the magnitude of the scroll event
    localInputReciver->scrollMagnitude.x = x;    
    localInputReciver->scrollMagnitude.y = y;

    aml::Result result;
    result.type = aml::InputType::scroll;
    result.active = true;
    result.state.magnitude = glm::vec2(x,y);
    localInputReciver->resultQueue.push(result);   
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

    //mouse input callbacks
    glfwSetMouseButtonCallback(window.renderWindow, InputReciver::handleMousePress);
    glfwSetCursorPosCallback(window.renderWindow, InputReciver::handleMouseMovement);
    glfwSetScrollCallback(window.renderWindow, InputReciver::handleScroll);

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
    return resultQueue.size();
}

aml::Result InputReciver::nextResult() 
{
    aml::Result next = resultQueue.front();
    resultQueue.pop();
    return next;
}