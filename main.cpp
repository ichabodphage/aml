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
    aml::VertexResource<glm::vec3> vertexBuffer(0,3);
    vertexBuffer.pushAdd(aml::cubeVertices.data(),aml::cubeVertices.size());

    //like the vertexBuffer, but for the color of the verticies
    aml::VertexResource<float> colorBuffer(1);
    
    colorBuffer.pushAdd(aml::cubeColorsFloat.data(),aml::cubeColorsFloat.size());

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

    float rotx = 0;
    float roty = 0;
    window.addKeyInput('D',[&rotx](int action){

        rotx += 0.05f;
    });
    window.addKeyInput('A',[&rotx](int action){

        rotx -= 0.05f;
    });
    window.addKeyInput('W',[&roty](int action){

        roty -= 0.05f;
    });
    window.addKeyInput('S',[&roty](int action){

        roty += 0.05f;
    });
    while(window.isActive())
    {
        window.clear();
        shaderProgram.run();
    
        aml::modelMatrix = glm::scale(glm::rotate(glm::mat4(1),rotx, glm::vec3(0.0f, 1.0f, 0.0f)),glm::vec3(5,5,5));
    
        aml::modelMatrix = glm::rotate(modelMatrix, roty, glm::vec3(1, 0, 0));
        shaderProgram["matrices.modelMatrix"].setMatrix(aml::modelMatrix);
        
        //call windows draw function
        window.draw(0,cubeVertices.size());
        window.pollInput();

    }
    
    aml::stopAml();
}