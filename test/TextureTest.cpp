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

int main()
{
    // initAML and make AML window
    aml::startAml();
    aml::Window window(800, 600, "TEST");

    //input reciver for the window
    aml::InputReciver localInput(window);

    aml::VertexResource2d multiBuffer;
    std::vector<aml::Vert3> verticies = aml::makeVertexArr(aml::cubeVertices,aml::cubeColors);
    multiBuffer.pushToGPU<aml::Vert2>(verticies.data(),verticies.size());

    // default vertex shader, uses color and vertex data
    aml::ShaderResource defaultVertexShader(aml::defaultVert(),aml::ShaderType::VERTEX);
    // default fragment shader, uses vertex color data
    aml::ShaderResource defaultFragmentShader(aml::defaultFrag(),aml::ShaderType::FRAGMENT);
    // Link the vertex and fragment shader into a shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader,defaultVertexShader);
 
    float rotx = 0;

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