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
#include "Graphics/vertex.hpp"
#ifndef AML_CORE
#define AML_CORE

namespace aml
{
    // returns the nth element in
    template <int N, typename... Ts>
    using indexInTemplate =
        typename std::tuple_element<N, std::tuple<Ts...>>::type;
    // returns an array containing the size of all types in a paramete pack
    
    //returns the total size of a parameter pack
    template <typename... T>
    constexpr size_t packSize()
    {
        
        return (sizeof(T) + ...);
    }
    template<typename T, typename... Ts>
    constexpr bool contains()
    { return std::disjunction_v<std::is_same<T, Ts>...>; }
    // throws an std::runtime_exception if gl encounters any errors
    void checkForGLErrors(const char *file, int line);

    // initalizes AML 
    void startAml(int antialiasingLevel = 1, bool resize = false);

    //weaves an array of possitions with an array of colors
    std::vector<aml::Vert3> makeVertexArr(std::vector<glm::vec3> &posArray,std::vector<glm::vec3> &colorArray);
    // terminates AML
    void stopAml();
    // creates a GLFW window
    GLFWwindow *makeGLWindow(size_t width, size_t height, const char *name);

}

#endif