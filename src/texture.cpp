#include "../include/LowLevelGraphics/texture.hpp"

using namespace aml;

Texture::~Texture(){
    delete[] textureData;
};