#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <tuple>
#include <type_traits>

#include "LowLevelGraphics/resource/vertex/vertex.hpp"
#include "LowLevelGraphics/resource/vector/vectorInclude.hpp"
#ifndef AML_CORE
#define AML_CORE
/**
 * @brief generic AML namespace holding all functions and classes
 * 
 */
namespace aml
{

    /**
     * @brief checks for any openGL errors, throws a runtime error if any errors are caught
     *
     *
     * @param file path to the file to check errors (should be _FILE_)
     * @param line line to alert error from (should be _LINE_)
     */
    void checkForGLErrors(const char *file, int line);

    /**
     * @brief starts aml within the program on a global scale
     *
     * @param antialiasingLevel level of antialiasing, defaults to 1
     * @param resize flag for if windows should be resizable or not, defaults to false
     */
    void startAml(int antialiasingLevel = 1, bool resize = false);

    /**
     * @brief template function that interweaves 2 standard vectors holding vectors into a single vertex array
     *
     * @details
     * used to provide compatibility between arrays of raw vectors and arrays of verticies
     *
     *
     * @param posArray array of position vectors
     * @param colorArray array of color vectors
     * @return std::vector<vertType> standard vector of vertTyoe vertices
     */
    
    std::vector<aml::Vert3> makeVertexArr(std::vector<aml::Vector3float> &posArray, std::vector<aml::Vector3float> &colorArray,std::vector<aml::Vector2float>& textureCordinates);

    /**
     * @brief terminates AML
     *
     */
    void stopAml();

    /**
     * @brief creates a raw openGL window
     *
     * @param width width of the window
     * @param height height of the window
     * @param name display name of the window
     * @return GLFWwindow* pointer to the raw openGL window
     */
    GLFWwindow *makeGLWindow(size_t width, size_t height, const char *name);


    /**
     * @brief gets the current system time in seconds
     * 
     * @return double, system time
     */
    double systemTime();
}

#endif