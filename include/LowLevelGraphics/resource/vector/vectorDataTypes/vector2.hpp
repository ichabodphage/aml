#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#ifndef AML_VECTOR2
#define AML_VECTOR2
#pragma pack(push, 1)

namespace aml
{

    /**
     * @brief Vector2 template, used to represent a 2 dimensional vector
     *
     * @details all data values within Vector2 are tightly packed, meaning no padding exists between the data values in memory
     *
     * @tparam Primitive primitive data type that will be held in the vector
     */
    template <typename Primitive>
    struct Vector2
    {
        Primitive x;
        Primitive y;
        /**
         * @brief Construct a new Vector 3 object
         *
         * @param x x value of the vector
         * @param y y value of the vector
         */
        Vector2(Primitive x, Primitive y) : x(x), y(y){};

        /**
         * @brief adds another Vector2 to the current one
         *
         * @param additionVector2 vector to add from
         */
        void operator+=(const Vector2 &additionVector2)
        {
            x += additionVector2.x;
            y += additionVector2.y;
        }

        /**
         * @brief returns a new Vector2 by adding a vector to the current one
         *
         * @param additionVector2 vector to add from
         * 
         * @return Vector2 
         */
        Vector2 operator+(const Vector2 &additionVector2)
        {
            return Vector2(x + additionVector2.x, y + additionVector2.y);
        }

        /**
         * @brief subtracts another Vector2 to the current one
         *
         * @param subtractionVector2 vector to subtract from
         */
        void operator-=(const Vector2 &subtractionVector2)
        {
            x -= subtractionVector2.x;
            y -= subtractionVector2.y;
        }

        /**
         * @brief returns a new Vector2 by subtracting a vector to the current one
         *
         * @param subtractionVector2 vector to subtract from
         * 
         * @return Vector2 
         */
        Vector2 operator-(const Vector2 &subtractionVector2)
        {
            return Vector2(x - subtractionVector2.x, y - subtractionVector2.y);
        }

        /**
         * @brief multiplies another vector with the current one
         *
         * @param multiplicationVector2 vector to multiply from
         */
        void operator*=(const Vector2 &multiplicationVector2)
        {
            x *= multiplicationVector2.x;
            y *= multiplicationVector2.y;
        }

        /**
         * @brief returns a new Vector2 by multiplying a vector to the current one
         * 
         * @param multiplicationVector3 
         * @return Vector2 
         */
         Vector2 operator*(const Vector2 &multiplicationVector2)
        {
            return Vector2(x *multiplicationVector2.x, y * multiplicationVector2.y);
        }
    };
    //signed Vector2s
    typedef Vector2<char> Vector2char;
    typedef Vector2<short> Vector2short;
    typedef Vector2<int> Vector2int;
    typedef Vector2<long> Vector2long;
    typedef Vector2<float> Vector2float;
    typedef Vector2<double> Vector2double;

    //unsigned Vector2s
    typedef Vector2<unsigned char> Vector2uchar;
    typedef Vector2<unsigned short> Vector2ushort;
    typedef Vector2<unsigned int> Vector2uint;
    typedef Vector2<unsigned long> Vector2ulong;
}

#pragma pack(pop)
#endif // VECTOR3_H