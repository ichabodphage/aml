#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <algorithm>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#include "points.hpp"
#include "matricies.hpp"

#include "include/graphics.hpp"


/*
 compile with 
 cmake --build . -j 2
*/


int main()
{
    //initAML and make AML window
    aml::startAml();
    aml::Window window(800,600,"TEST");
    
    //establish vertex buffer and push vertex data into the GPU
    aml::VertexResource<float> vertexBuffer(0);
    vertexBuffer.pushAdd(aml::cubeVerticesFloat.data(),aml::cubeVerticesFloat.size());

    //like the vertexBuffer, but for the color of the verticies
    aml::VertexResource<glm::vec3> colorBuffer(1);
    
    colorBuffer.pushAdd(aml::cubeColors.data(),aml::cubeColors.size());

    //default vertex shader, uses color and vertex data
    aml::ShaderResource defaultVertexShader("src/basicShaders/basicVert.vert",aml::ShaderType::VERTEX);

    //default fragment shader, uses vertex color data
    aml::ShaderResource defaultFragmentShader("src/basicShaders/basicFrag.frag",aml::ShaderType::FRAGMENT);
    // Link the vertex and fragment shader into a shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader,defaultVertexShader);


    //initalize shader program uniforms
    shaderProgram["matrices.modelMatrix"].setMatrix(aml::modelMatrix);
    shaderProgram["matrices.viewMatrix"].setMatrix(aml::viewMatrix);
  
    glm::mat4 projectionMatrix =glm::perspective(
    45.0f, // field of view angle (in degrees)
    window.dimensions().x/window.dimensions().y, // aspect ratio
    0.5f, // near plane distance
    1000.0f);

    shaderProgram["matrices.projectionMatrix"].setMatrix(projectionMatrix);
    // ---------------------------- RENDERING ------------------------------ //

    float rot = 0;
    while(window.isActive())
    {
        window.clear();
        shaderProgram.run();
    
        aml::modelMatrix = glm::scale(glm::rotate(glm::mat4(1), rot, glm::vec3(0.0f, 1.0f, 0.0f)),glm::vec3(5,5,5));
        aml::modelMatrix = glm::rotate(modelMatrix, rot, glm::vec3(0, 1.0f, 0.0f));
        aml::modelMatrix = glm::rotate(modelMatrix, rot, glm::vec3(0, 0, 1.0f));
        shaderProgram["matrices.modelMatrix"].setMatrix(aml::modelMatrix);
        
        //call windows draw function
        window.draw(0,cubeVerticesFloat.size());
        window.pollInput();
        
        rot += 0.01f;
    }
    
    aml::stopAml();
}