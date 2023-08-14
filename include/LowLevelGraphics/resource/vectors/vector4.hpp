#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_VECTOR4
#define AML_VECTOR4
#pragma pack(push, 1)

namespace aml
{

    /**
     * @brief Vector4 template, used to represent a 3 dimensional vector
     *
     * @details all data values within Vector4 are tightly packed, meaning no padding exists between the data values in memory
     *
     * @tparam Primitive primitive data type that will be held in the vector
     */
    template <typename Primitive>
    struct Vector4
    {
        Primitive x;
        Primitive y;
        Primitive z;
        Primitive w;
        /**
         * @brief Construct a new Vector 3 object
         *
         * @param x x value of the vector
         * @param y y value of the vector
         * @param z z value of the vector
         * @param w w value of the vector
         */
        Vector4(Primitive x, Primitive y, Primitive z, Primitive w) : x(x), y(y), z(z),w(w){};

        /**
         * @brief adds another Vector4 to the current one
         *
         * @param additionVector4 vector to add from
         */
        void operator+=(const Vector4 &additionVector4)
        {
            x += additionVector4.x;
            y += additionVector4.y;
            z += additionVector4.z;
            w += additionVector4.w;
        }

        /**
         * @brief returns a new vector3 by adding a vector to the current one
         *
         * @param additionVector4 vector to add from
         * 
         * @return Vector4 
         */
        Vector4 operator+(const Vector4 &additionVector4)
        {
            return Vector4(x + additionVector4.x, y + additionVector4.y, z + additionVector4.z, w+ additionVector4.w);
        }

        /**
         * @brief subtracts another Vector4 to the current one
         *
         * @param subtractionVector4 vector to subtract from
         */
        void operator-=(const Vector4 &subtractionVector4)
        {
            x -= subtractionVector4.x;
            y -= subtractionVector4.y;
            z -= subtractionVector4.z;
            w += subtractionVector4.w;
        }

        /**
         * @brief returns a new vector3 by subtracting a vector to the current one
         *
         * @param subtractionVector4 vector to subtract from
         * 
         * @return Vector4 
         */
        Vector4 operator-(const Vector4 &subtractionVector4)
        {
            return Vector4(x - subtractionVector4.x, y - subtractionVector4.y, z - subtractionVector4.z,w - subtractionVector4.w);
        }

        /**
         * @brief multiplies another vector with the current one
         *
         * @param multiplicationVector4 vector to multiply from
         */
        void operator*=(const Vector4 &multiplicationVector4)
        {
            x *= multiplicationVector4.x;
            y *= multiplicationVector4.y;
            z *= multiplicationVector4.z;
            w *= multiplicationVector4.w;
        }

        /**
         * @brief returns a new vector3 by multiplying a vector to the current one
         * 
         * @param multiplicationVector4 
         * @return Vector4 
         */
         Vector4 operator*(const Vector4 &multiplicationVector4)
        {
            return Vector4(x *multiplicationVector4.x, y * multiplicationVector4.y, z * multiplicationVector4.z,w * multiplicationVector4.w);
        }
    };
    //signed Vector4s
    typedef Vector4<char> Vector4char;
    typedef Vector4<short> Vector4short;
    typedef Vector4<int> Vector4int;
    typedef Vector4<long> Vector4long;
    typedef Vector4<float> Vector4float;
    typedef Vector4<double> Vector4double;

    //unsigned Vector4s
    typedef Vector4<unsigned char> Vector4uchar;
    typedef Vector4<unsigned short> Vector4ushort;
    typedef Vector4<unsigned int> Vector4uint;
    typedef Vector4<unsigned long> Vector4ulong;
}

#pragma pack(pop)
#endif // VECTOR3_H