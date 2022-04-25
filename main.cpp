#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <algorithm>
#include<type_traits>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "points.hpp"
#include "matricies.hpp"

#include "include/graphics.hpp"

#include "include/input.hpp"

/*
 compile with
 cmake --build . -j 2
*/

struct k{
    glm::vec3 color;
    glm::vec2 pos;
};
int main()
{
    // initAML and make AML window
    aml::startAml();
    aml::Window window(800, 600, "TEST");

    //input reciver for the window
    aml::InputReciver localInput(window);


    aml::VertexResource3d multiBuffer;
    std::vector<aml::Vert3> verticies = aml::makeVertexArr(aml::cubeVertices,aml::cubeColors);

    multiBuffer.pushToGPU<aml::Vert3>(verticies.data(),verticies.size());

    // default vertex shader, uses color and vertex data
    aml::ShaderResource defaultVertexShader(AML_DEFAULT_VERT);
    // default fragment shader, uses vertex color data
    aml::ShaderResource defaultFragmentShader(AML_DEFAULT_FRAG);

    // Link the vertex and fragment shader into a shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader, defaultVertexShader);

    // initalize shader program uniforms
    shaderProgram["matrices.modelMatrix"].setMatrix(aml::modelMatrix);
    shaderProgram["matrices.viewMatrix"].setMatrix(aml::viewMatrix);

    glm::mat4 viewConst = aml::viewMatrix;
    glm::mat4 projectionMatrix = glm::perspective(
        45.0f,window.dimensions().x / window.dimensions().y,
        0.5f,1000.0f);

    shaderProgram["matrices.projectionMatrix"].setMatrix(projectionMatrix);
    
    float rotx = 0;
  
    
    while (window.isActive())
    {
        double time = glfwGetTime();
        window.clear();
        shaderProgram.run();
        if(localInput.checkKey('Q')){
            std::cout << "PRESSED Q\n";
        }
        if(localInput.checkKey('W')){
            std::cout << "PRESSED-W\n";
        }
        for (int k = -2; k < 2; k++)
        {
            for (int j = -1; j < 4; j++)
            {
                for (int i = -2; i < 4; i++)
                {
                    aml::modelMatrix = glm::scale(glm::mat4(1), glm::vec3(5, 5, 5));
                    
                    aml::modelMatrix = glm::translate(aml::modelMatrix, glm::vec3(3 * -i, 3 * -k, 3 * -j));
                    aml::modelMatrix = glm::translate(aml::modelMatrix, glm::vec3(std::sin(rotx)*2,std::cos(rotx)*2,0));

                    aml::modelMatrix = glm::rotate(aml::modelMatrix,rotx,glm::vec3(1,0,0));
                    shaderProgram["matrices.modelMatrix"].setMatrix(aml::modelMatrix);
                    shaderProgram["matrices.viewMatrix"].setMatrix(aml::viewMatrix);
                    // call windows draw function
                    window.renderVBO(0, verticies.size());
                }
            }
        }
        
        window.display();
        rotx += 0.01;
    }

    aml::stopAml();
}