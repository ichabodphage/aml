#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


#ifndef AML_VECTOR
#define AML_VECTOR
// struct needs densly packed datavalues to function properly
#pragma pack(push, 1)
namespace aml{
    /**
     * @brief Vertex template struct
     * 
     * @tparam PosType vector type containing vertex position
     * @tparam ColorType vector type containing vertex color
     */
    template<typename PosType,typename ColorType>
    struct Vertex{
        /// @brief position of the vertex
        PosType pos;

        /// @brief color of the vertex
        ColorType color;

        /**
         * @brief Construct a new Vertex object
         * 
         * @param position positon of the vertex
         * @param vertexColor color of the vertex
         */
        Vertex(PosType position,ColorType vertexColor):pos(position),color(vertexColor){};
    };
    
    /// @brief 2d vertex template declaration
    typedef aml::Vertex<glm::vec2,glm::vec3> Vert2;

    /// @brief 3d vertex template delcaration
    typedef aml::Vertex<glm::vec3,glm::vec3> Vert3;


}
#pragma pack(pop)

#endif