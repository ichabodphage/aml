#include "../include/LowLevelGraphics/resource/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION

#include "../include/stb_image.h"
using namespace aml;

Texture::Texture(const std::string &path, unsigned int bindLocation, bool mipmap):mipmap(mipmap), bindLocation(bindLocation)
{

    // load image
    textureData = stbi_load(path.c_str(), &width, &height, &pixelSize, 0);

    if (textureData == nullptr)
    {
        throw std::runtime_error("Failed to load texture " + path + "!\n");
    }

    createGLTexture()
    
}


void Texture::createGLTexture() 
{
    glGenTextures(1, &textureId);
    bindTexture();

    GLenum internalFormat = 0;
    GLenum format = 0;

    // get pixel depth
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

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, textureData);

    if (mipmap)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::bindTexture()
{   
    glActiveTexture(GL_TEXTURE0 + bindLocation);
    glBindTexture(GL_TEXTURE_2D, textureId);
}

Texture::~Texture()
{
    stbi_image_free(textureData);
    deleteGLTexture();
}

void Texture::deleteGLTexture() 
{
    glDeleteTextures(1, &textureId);
}

void Texture::setBindIndex(unsigned int newIndex) 
{
    bindLocation = newIndex;
}


GLuint Texture::getId()
{
    return textureId - 1;
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
};