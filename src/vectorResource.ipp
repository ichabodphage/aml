#include "../include/LowLevelGraphics/resource/vectorResource.hpp"

using namespace aml;



template<typename vType>
VectorResource<vType>::VectorResource(size_t layoutLocation,size_t VectorSize):
layout(layoutLocation),
valueCount(VectorSize){
    glGenBuffers(1, &vbo);
    bindResource();
    bindAtributes();
}

template<typename vType>
VectorResource<vType>::~VectorResource(){
    
    glDeleteBuffers(1, &vbo);
}

template<typename vType>
void VectorResource<vType>::bindResource(){
    //bind the vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

}


template<typename vType>
void VectorResource<vType>::pushToGPU(vType* VectorArray, size_t size){
    bindResource();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vType) * size, VectorArray , GL_STATIC_DRAW);
}

template<typename vType>
void VectorResource<vType>::pushToGPU(std::vector<vType> &VectorArray){
    bindResource();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vType) * VectorArray.size(), VectorArray.data() , GL_STATIC_DRAW);
};


template<typename vType>
void VectorResource<vType>::bindAtributes(){
    
    //get the length of the Vector atribute
    size_t atributeLength = sizeof(vType) /sizeof(float);
    //set the current data pointer to the objects ID
    glVertexAttribPointer(
        layout, valueCount, 
        GL_FLOAT, GL_FALSE, 
        0, 
        (void*)0);
    glEnableVertexAttribArray(layout);
    aml::checkForGLErrors(__FILE__,__LINE__);
	
}
