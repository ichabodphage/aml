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
        public:
            
            /**
             * @brief Construct a new Texture object
             * 
             * @param path file path of texture data
             * 
             * @param mipmap flag to generate mipmaps
             * 
             * @param bindLocation location in gpu to bind texture too
             */
            Texture(const std::string& path,unsigned int bindLocation = 0, bool mipmap = false);

            /**
             * @brief binds the texture to openGL
             * 
             * @param bindIndex index to bind the texture to
             */
            void bindTexture(int bindIndex);
            /**
             * @brief deconstructs the texture object
             * 
             */
            ~Texture();

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
             * @brief Get the Height of the image
             * 
             * @return int image height (y)
             */
            int getHeight();
    };
}



#endif