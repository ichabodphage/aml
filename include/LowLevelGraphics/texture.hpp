#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../lib.hpp"

#ifndef AML_TEXTURE
#define AML_TEXTURE

namespace aml{
    /**
     * @brief class that manages an openGL texture
     * 
     * 
     */
    class Texture{
        private:
            /// @brief openGL id of the texture
            GLuint textureId;

            /// @brief raw texture data            
            unsigned char * textureData;

            /// @brief width of the texture
            size_t width;
            
            /// @brief height of the texture
            size_t height;

            /// @brief number of color channels in the texture;
            size_t colorChanelCount;

        public:
            
            /**
             * @brief deconstructs the texture object
             * 
             */
            ~Texture();
    }
}



#endif