#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "../vector/vectorInclude.hpp"

#ifndef AML_VERTEX
#define AML_VERTEX
// struct needs densly packed datavalues to function properly
//#pragma pack(push, 1)
namespace aml{
    /**
     * @brief Vertex template struct
     * 
     * @tparam PositionVecorType vector type containing vertex position
     * @tparam ColorVectorType vector type containing vertex color
     * @tparam TextureCordinateVectorType vector type of the texture cordinates, defaults to aml::Vector2fload
     */

    template<typename PositionVecorType,typename ColorVectorType,typename TextureCordinateVectorType = aml::Vector2float>
    struct Vertex{
        /// @brief position of the vertex
        PositionVecorType positon;

        /// @brief color of the vertex
        ColorVectorType color;

        TextureCordinateVectorType textCords;
        /**
         * @brief Construct a new Vertex object
         * 
         * @param position positon of the vertex
         * @param vertexColor color of the vertex
         */
        Vertex(PositionVecorType position,ColorVectorType color,TextureCordinateVectorType textCords):positon(position),color(color),textCords(textCords){};
    };
    
    /// @brief 2d vertex template declaration
    typedef aml::Vertex<aml::Vector2float,aml::Vector3float> Vert2;

    /// @brief 3d vertex template delcaration
    typedef aml::Vertex<aml::Vector3float,aml::Vector3float> Vert3;


}
//#pragma pack(pop)

#endif