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
std::vector<aml::Vector2float> cords = {
    aml::Vector2float(0, 0), aml::Vector2float(0, 1), aml::Vector2float(1, 0)};
std::vector<aml::Vert3> make2dVertexArr(std::vector<aml::Vector3float> &posArray, std::vector<aml::Vector3float> &colorArray, std::vector<aml::Vector2float> &textureCordinates)
{
    if (posArray.size() != colorArray.size())
    {
        throw std::runtime_error("array of position vectors must be the same size of the array of color vectors");
    }

    std::vector<aml::Vert3> vertices;

    for (size_t i = 0; i < posArray.size(); i++)
    {
        vertices.push_back(aml::Vert3(posArray[i], colorArray[i], textureCordinates[i]));
    }

    return vertices;
};
int main()
{
    // initAML and make AML window
    aml::startAml();
    aml::Window window(800, 600, "TEST");

    // input reciver for the window
    aml::InputReciver localInput(window, 10);

    // insert verticies of the shape
    std::vector<aml::Vert3> vertArray = make2dVertexArr(aml::squareVertices, aml::squareColors, cords);
    aml::VertexResource3d vertexBuffer;
    
    
        glEnableVertexAttribArray(2);
    vertexBuffer.pushToGPU(vertArray);
    /*
    aml::VectorResource<aml::Vector3float> posBuffer(0);
    posBuffer.pushToGPU(aml::squareVertices);
    aml::VectorResource<aml::Vector3float> colorBuffer(1);
    colorBuffer.pushToGPU(aml::squareColors);
    aml::VectorResource<aml::Vector2float> cordBuffer(2,2);
    cordBuffer.pushToGPU(cords);
    */

    // define shape texture cordinates
    aml::Texture localTexture("test/blackbuck.bmp", 0);

    // default shaders
    aml::ShaderResource defaultVertexShader(aml::defaultVert(), aml::ShaderType::VERTEX);
    aml::ShaderResource defaultFragmentShader(aml::defaultFrag(), aml::ShaderType::FRAGMENT);

    // initalize shader program
    aml::ShaderProgram shaderProgram(defaultFragmentShader, defaultVertexShader);

    std::vector<int> textureArr(16);
    textureArr[0] = localTexture.getId();

    shaderProgram["textureId"].setIntArr(textureArr);
    while (window.isActive())
    {
        window.clear();
        shaderProgram.run();
        shaderProgram.renderVertexBuffer(0, 3);

        // check for all inputs
        localInput.pollInput();
        if (localInput.keyTriggered('W'))
        {

            std::cout << window.upTime() << "\n";
        }
        window.display();
    }

    aml::stopAml();
}