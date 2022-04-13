#include <iostream>
#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#include "points.hpp"
#include "include/lib.hpp"
#include "include/vertexResource.hpp"
#include "include/window.hpp"
#include "include/shaderResource.hpp"
#include "include/shaderProgram.hpp"
#include "include/vector3.hpp"
#include "include/renderMatrix.hpp"
/*
 compile with 
 cmake --build . -j 2
*/


int main()
{
    //initAML and make AML window
    aml::initAml();
    aml::Window window(800,600,"TEST");
    
    
    //establish vertex buffer
    aml::VertexResource<glm::vec3> vertexBuffer;

    vertexBuffer.pushAdd(aml::cubeVertices.data(),aml::cubeVertices.size());


    //color buffer

 
    
    // does not work for some reason
    aml::VertexResource<glm::vec3> colorBuffer;
    

    colorBuffer.addVerticies(cubeColors.data(),cubeColors.size());
    
  
    colorBuffer.pushToGPU();
    
    
    //initalize shader resources
    aml::ShaderResource vertexShader("src/basicShaders/basicVert.vert",aml::ShaderType::VERTEX);
    aml::ShaderResource fragmentShader("src/basicShaders/basicFrag.frag",aml::ShaderType::FRAGMENT);

    // Link the vertex and fragment shader into a shader program
    aml::ShaderProgram shaderProgram(fragmentShader,vertexShader);

    aml::RenderMatrix viewMatrix(
        glm::lookAt(glm::vec3(0.0f, 0.0f, 20.0f), // Eye position
        glm::vec3(0.0f, 0.0f, 0.0f),  // Viewpoint position
        glm::vec3(0.0f, 1.0f, 0.0f)),shaderProgram.programId,"matrices.viewMatrix");

    aml::RenderMatrix modelMatrix( glm::scale(glm::mat4(1), glm::vec3(5,5,5)),shaderProgram.programId,"matrices.modelMatrix");

    aml::RenderMatrix projectionMatrix(glm::perspective(
    45.0f, // field of view angle (in degrees)
    window.dimensions().x/window.dimensions().y, // aspect ratio
    0.5f, // near plane distance
    1000.0f), shaderProgram.programId,"matrices.projectionMatrix");
    // ---------------------------- RENDERING ------------------------------ //

    float rot = 0;
    while(window.isActive())
    {
        window.clear();

        shaderProgram.run();
        viewMatrix.pushToGPU();
        projectionMatrix.pushToGPU();
            
        modelMatrix.matrix = glm::scale(glm::rotate(glm::mat4(1), rot, glm::vec3(1.0f, 0.0f, 0.0f)),glm::vec3(5,5,5));
        modelMatrix.matrix = glm::rotate(modelMatrix.matrix, rot, glm::vec3(0, 1.0f, 0.0f));
        modelMatrix.matrix = glm::rotate(modelMatrix.matrix, rot, glm::vec3(0, 0, 1.0f));
        modelMatrix.pushToGPU();
        
        //call windows draw function
        window.draw(0,cubeVertices.size()*3);


        glfwPollEvents();
        rot += 0.01f;
    }
    
    // ---------------------------- TERMINATE ----------------------------- //

    // Terminate GLFW
    glfwTerminate();
}