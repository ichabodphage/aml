#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <algorithm>
#include <type_traits>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "points.hpp"
#include "matricies.hpp"

#include "../include/graphics.hpp"

#include "../include/input.hpp"

/*
 compile with
 cmake --build . -j 4
*/
std::vector<aml::Vert2> make2dVertexArr(std::vector<glm::vec2> &posArray,std::vector<glm::vec3> &colorArray){
    if(posArray.size() != colorArray.size()){
        throw std::runtime_error("array of position vectors must be the same size of the array of color vectors");
    }

    std::vector<aml::Vert2> vertices;

    for(size_t i = 0; i <posArray.size();i++){
        vertices.push_back(aml::Vert2(posArray[i],colorArray[i]));
    }

    return vertices;

};
int main()
{
    // initAML and make AML window
    aml::startAml();
    aml::Window window(800, 600, "TEST");

    //input reciver for the window
    aml::InputReciver localInput(window);

    aml::VertexResource<glm::vec2,glm::vec3> multiBuffer;
    std::vector<aml::Vert2> verticies = make2dVertexArr(aml::squareVertices,aml::squareColors);
    multiBuffer.pushToGPU<aml::Vert2>(verticies.data(),verticies.size());

    aml::Texture localTexture;

    //default shaders
    aml::ShaderResource defaultVertexShader(aml::defaultVert(),aml::ShaderType::VERTEX);
    aml::ShaderResource defaultFragmentShader(aml::defaultFrag(),aml::ShaderType::FRAGMENT);

    //initalize shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader,defaultVertexShader);
    
    shaderProgram["textureId"].setScalarInt(localTexture.getId());
    while (window.isActive())
    {
        double time = glfwGetTime();
        
        window.clear();
        shaderProgram.run();
        window.render(0,verticies.size());
        
        //check for all inputs
        localInput.pollInput();
        if(localInput.keyTriggered('W')){
            
            std::cout << std::to_string(localInput.mousePosition().x) << " "
            << std::to_string(localInput.mousePosition().y) << "\n";
            
        }
        
        window.display();
        
    }

    aml::stopAml();
}