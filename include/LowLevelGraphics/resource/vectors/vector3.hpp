#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef AML_VECTOR3
#define AML_VECTOR3
#pragma pack(push, 1)

namespace aml
{

    /**
     * @brief Vector3 template, used to represent a 3 dimensional vector
     *
     * @details all data values within Vector3 are tightly packed, meaning no padding exists between the data values in memory
     *
     * @tparam Primitive primitive data type that will be held in the vector
     */
    template <typename Primitive>
    struct Vector3
    {
        Primitive x;
        Primitive y;
        Primitive z;
        /**
         * @brief Construct a new Vector 3 object
         *
         * @param x x value of the vector
         * @param y y value of the vector
         * @param z z value of the vector
         */
        Vector3(Primitive x, Primitive y, Primitive z) : x(x), y(y), z(z){};

        /**
         * @brief adds another Vector3 to the current one
         *
         * @param additionVector3 vector to add from
         */
        void operator+=(const Vector3 &additionVector3)
        {
            x += additionVector3.x;
            y += additionVector3.y;
            z += additionVector3.z;
        }

        /**
         * @brief returns a new vector3 by adding a vector to the current one
         *
         * @param additionVector3 vector to add from
         * 
         * @return Vector3 
         */
        Vector3 operator+(const Vector3 &additionVector3)
        {
            return Vector3(x + additionVector3.x, y + additionVector3.y, z + additionVector3.z);
        }

        /**
         * @brief subtracts another Vector3 to the current one
         *
         * @param subtractionVector3 vector to subtract from
         */
        void operator-=(const Vector3 &subtractionVector3)
        {
            x -= subtractionVector3.x;
            y -= subtractionVector3.y;
            z -= subtractionVector3.z;
        }

        /**
         * @brief returns a new vector3 by subtracting a vector to the current one
         *
         * @param subtractionVector3 vector to subtract from
         * 
         * @return Vector3 
         */
        Vector3 operator-(const Vector3 &subtractionVector3)
        {
            return Vector3(x - subtractionVector3.x, y - subtractionVector3.y, z - subtractionVector3.z);
        }

        /**
         * @brief multiplies another vector with the current one
         *
         * @param multiplicationVector3 vector to multiply from
         */
        void operator*=(const Vector3 &multiplicationVector3)
        {
            x *= multiplicationVector3.x;
            y *= multiplicationVector3.y;
            z *= multiplicationVector3.z;
        }

        /**
         * @brief returns a new vector3 by multiplying a vector to the current one
         * 
         * @param multiplicationVector3 
         * @return Vector3 
         */
         Vector3 operator*(const Vector3 &multiplicationVector3)
        {
            return Vector3(x *multiplicationVector3.x, y * multiplicationVector3.y, z * multiplicationVector3.z);
        }
    };
    //signed Vector3s
    typedef Vector3<char> Vector3char;
    typedef Vector3<short> Vector3short;
    typedef Vector3<int> Vector3int;
    typedef Vector3<long> Vector3long;
    typedef Vector3<float> Vector3float;
    typedef Vector3<double> Vector3double;

    //unsigned Vector3s
    typedef Vector3<unsigned char> Vector3uchar;
    typedef Vector3<unsigned short> Vector3ushort;
    typedef Vector3<unsigned int> Vector3uint;
    typedef Vector3<unsigned long> Vector3ulong;
}

#pragma pack(pop)
#endif // VECTOR3_H