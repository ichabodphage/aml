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

    //insert verticies of the shape
    aml::VertexResource<glm::vec2,glm::vec3> multiBuffer;
    std::vector<aml::Vert2> verticies = make2dVertexArr(aml::squareVertices,aml::squareColors);
    multiBuffer.pushToGPU<aml::Vert2>(verticies);
    
    aml::ElementBuffer elementIndecies;
    std::vector<unsigned int> indecies = {
        0,1,3,
        1,2,3
    };

    elementIndecies.pushToGPU(indecies);
    
    // define shape texture cordinates
    aml::VectorResource<glm::vec2> texCords(2,2);
    std::vector<glm::vec2> cords = {
        glm::vec2(1,0),glm::vec2(1,1),glm::vec2(0,1),glm::vec2(0,0)
    };
    texCords.pushToGPU(cords);

    aml::Texture localTexture("test/w3c_home.bmp");
    //default shaders
    aml::ShaderResource defaultVertexShader(aml::defaultVert(),aml::ShaderType::VERTEX);
    aml::ShaderResource defaultFragmentShader(aml::defaultFrag(),aml::ShaderType::FRAGMENT);

    //initalize shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader,defaultVertexShader);
    
    shaderProgram["textureId"].setScalarInt(localTexture.getId());
    shaderProgram["BLEND_FLAG"].setScalarInt(true);
    while (window.isActive())
    {
        double time = glfwGetTime();
        
        window.clear();
        shaderProgram.run();
        elementIndecies.bindResource();
        window.renderElementBuffer(indecies.size());
        
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