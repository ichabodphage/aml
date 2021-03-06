#include "../include/lib.hpp"

using namespace aml;

void aml::checkForGLErrors( const char *file, int line){
    GLenum errorCode;
    std::string totalError = "";
    //get all openGL errors
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error = "Gl error : ";
        switch (errorCode){
            case GL_INVALID_ENUM:                  error += "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 error += "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             error += "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                error += "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               error += "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 error += "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error += "INVALID_FRAMEBUFFER_OPERATION"; break;
        }
        if(error.size() > 0){
            totalError += error + " in : "+ file +" on line " + std::to_string(line) +"\n";
        }
    }

    if(totalError.size() > 0){
        throw std::runtime_error(totalError);
    }
};

void aml::startAml(int antialiasingLevel,bool resize){
    //init glfw
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW\n");
    }
    
    //establish openGL version hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //establish if resizing is allowed or not
    glfwWindowHint(GLFW_RESIZABLE, resize);
    glfwWindowHint(GLFW_SAMPLES, antialiasingLevel);

    glEnable(GL_MULTISAMPLE);  
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glfwSwapInterval(0);
    aml::checkForGLErrors(__FILE__,__LINE__);
  

}

GLFWwindow* aml::makeGLWindow(size_t width,size_t height,const char* name){
    GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit()!= 0) {
        throw std::runtime_error("Failed to initialize GLEW\n");
    }
    return window;
}

void aml::stopAml(){
    glfwTerminate();
}

std::vector<aml::Vert3> aml::makeVertexArr(std::vector<glm::vec3> &posArray,std::vector<glm::vec3> &colorArray){
    if(posArray.size() != colorArray.size()){
        throw std::runtime_error("array of position vectors must be the same size of the array of color vectors");
    }

    std::vector<aml::Vert3> vertices;

    for(size_t i = 0; i <posArray.size();i++){
        vertices.push_back(aml::Vert3(posArray[i],colorArray[i]));
    }

    return vertices;

};