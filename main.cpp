#include <iostream>
#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "include/lib.hpp"
#include "include/vertexResource.hpp"
#include "include/window.hpp"
#include "include/shaderResource.hpp"
#include "include/shaderProgram.hpp"
#include "include/tint.hpp"
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
    vertexBuffer.bindResource();
    
    glm::vec3 vertices[] = {
        // Front face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f),
        // Back face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, -0.5f),
        // Left face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, 0.5f),
    };


    //add verticies to vertex buffer and push them to the GPU
    vertexBuffer.addVerticies(vertices,9);
    vertexBuffer.pushToGPU();


    //color buffer
    aml::VertexResource<glm::vec3> colorBuffer;
    //aml::VertexResource<aml::Tint> colorBuffer;
    colorBuffer.bindResource();

    glm::vec3 triangleColors[] = { 
        glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)
    };
    
    /*aml::Tint triangleColors[] = { 
        aml::Tint(255,0,0),aml::Tint(0,255,0),aml::Tint(0,0,255)
    };*/
    colorBuffer.addVerticies(triangleColors,6);
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
    float(800) / float(600), // aspect ratio
    0.5f, // near plane distance
    1000.0f), shaderProgram.programId,"matrices.projectionMatrix");
    // ---------------------------- RENDERING ------------------------------ //

    float rot = 0;
    while(!glfwWindowShouldClose(window.renderWindow))
    {

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.run();
        viewMatrix.pushToGPU();
        projectionMatrix.pushToGPU();
            
        modelMatrix.matrix = glm::scale(glm::rotate(glm::mat4(1), rot, glm::vec3(1.0f, 0.0f, 0.0f)),glm::vec3(5,5,5));
        modelMatrix.matrix = glm::rotate(modelMatrix.matrix, rot, glm::vec3(0, 1.0f, 0.0f));

        
        modelMatrix.pushToGPU();
        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Swap buffers and poll window events
        glfwSwapBuffers(window.renderWindow);
        glfwPollEvents();
        rot += 0.01f;
    }
    
    // ---------------------------- TERMINATE ----------------------------- //

    // Terminate GLFW
    glfwTerminate();
}