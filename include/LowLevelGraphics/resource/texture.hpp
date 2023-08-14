#include <vector>
#include <string>
#include <fstream>


#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../../lib.hpp"

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

            /// @brief width of the texture
            int width;
            
            /// @brief height of the texture
            int height;

            /// @brief amount of data in each pixel
            int pixelSize;

            /// @brief flag to generate mipmaps for texture in question
            bool mipmap;

            /// @brief integer that stores the location within the shader to bind the texure too
            unsigned int bindLocation;
            /// @brief char pointer that points to the textures data
            unsigned char* textureData;
        public:
            
            /**
             * @brief Construct a new Texture object
             * 
             * @param path file path of texture data
             * 
             * @param mipmap flag to generate mipmaps
             * 
             * @param bindLocation location in gpu to bind texture too
             * 
             */
            Texture(const std::string& path,unsigned int bindLocation = 0, bool mipmap = false);

            /**
             * @brief binds the texture to openGL
             * 
             */
            void bindTexture();

            /**
             * @brief initalizes the texture as an opengl object and as an object that can be utilized by the shader
             * 
             */
            void createGLTexture();
            /**
             * @brief deconstructs the texture object
             * 
             */
            ~Texture();

            /**
             * @brief deletes the texture as an opengl object
             * 
             */
            void deleteGLTexture();
            /**
             * @brief gets the id of the texture 
             * 
             * @return GLuint 
             */
            GLuint getId();

            /**
             * @brief Get the Width of the image
             * 
             * @return int image width (x)
             */
            int getWidth();

            /**
             * @brief Sets the bind index within the texture
             * 
             * @param newIndex new location to bind the texture to within the shader 
             */
            void setBindIndex(unsigned int newIndex);
            /**
             * @brief Get the Height of the image
             * 
             * @return int image height (y)
             */
            int getHeight();
    };
}



#endif