#include "../include/LowLevelGraphics/texture.hpp"

#include "../include/stb_image.h"
using namespace aml;

Texture::Texture(const std::string& path, bool mipmap){
    stbi_set_flip_vertically_on_load(1);

    //load image
    unsigned char * imageData = stbi_load(path.c_str(), &width, &height, &pixelSize, 0);


    
    if (imageData == nullptr)
	{
		throw std::runtime_error( "Failed to load image " + path + "!\n");
	}

    glGenTextures(1, &textureId);
	bindTexture();

	GLenum internalFormat = 0;
	GLenum format = 0;

    //get pixel depth
    switch (pixelSize)
    {
        case 4:
            internalFormat = format = GL_RGBA;
        break;
        case 3:
            internalFormat = format = GL_RGB;
        break;
    
        default:
            internalFormat = format = GL_ALPHA;
        break;
    }


    
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
    
    if(mipmap){
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    
    stbi_image_free(imageData);
}

void Texture::bindTexture(){
    glBindTexture(GL_TEXTURE_2D, textureId);
}

Texture::~Texture(){
    glDeleteTextures(1,&textureId);
}

GLuint Texture::getId() 
{
    return textureId;
}

int Texture::getWidth() 
{
    return width;
}

int Texture::getHeight() 
{
    return height;
};