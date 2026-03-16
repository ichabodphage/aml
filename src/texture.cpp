#include "../include/LowLevelGraphics/resource/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION

#include "../include/stb_image.h"
using namespace aml;

Texture::Texture(const std::string &path, unsigned int bindLocation, bool mipmap, const bool manualSetupEnabled) : mipmap(mipmap), bindLocation(bindLocation), manualSetupEnabled(manualSetupEnabled)
{

    stbi_set_flip_vertically_on_load(true);

    // 0 = "Give me the actual number of channels in the file"
    textureData = stbi_load(path.c_str(), &width, &height, &pixelSize, 0);

    if (textureData == nullptr)
    {
        throw std::runtime_error("Failed to load texture at: " + path);
    }

    if (!manualSetupEnabled)
    {
        createGLTexture();
    }
}

void Texture::createGLTexture()
{
    glGenTextures(1, &textureId);
    bindTexture();

    // CRITICAL: This fixes the "slanted" look for 3-channel (RGB) images
    // It tells OpenGL to read pixels byte-by-byte without 4-byte padding.
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    GLenum internalFormat = GL_RGB;
    GLenum format = GL_RGB;

    // Map the stb_image channel count (pixelSize) to OpenGL formats
    switch (pixelSize)
    {
    case 4: // RGBA (PNGs)
        internalFormat = GL_RGBA8;
        format = GL_RGBA;
        break;
    case 3: // RGB (BMPs/JPGs)
        internalFormat = GL_RGB8;
        format = GL_RGB;
        break;
    case 2: // Red/Green (Luminance/Alpha)
        internalFormat = GL_RG8;
        format = GL_RG;
        break;
    case 1: // Grayscale
        internalFormat = GL_R8;
        format = GL_RED;
        break;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, textureData);

    if (mipmap)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    // Set wrapping and filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mipmap ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR);
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

void Texture::setTextureParameter(unsigned int textureType, unsigned int openGLParameterNameEnum, unsigned int openGlParameter)
{
    glTexParameteri(textureType, openGLParameterNameEnum, openGlParameter);
}

void Texture::setBindIndex(unsigned int newIndex)
{
    bindLocation = newIndex;
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