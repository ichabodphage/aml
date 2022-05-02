#include "../include/LowLevelGraphics/texture.hpp"

using namespace aml;

Texture::Texture(){
    glGenTextures(1,&textureId);
    bindTexture();
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
};