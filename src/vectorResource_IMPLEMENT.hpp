#include "../include/LowLevelGraphics/vectorResource.hpp"

using namespace aml;
//set nextID to zero
template<typename vType>
size_t VectorResource<vType>::nextID = 0;


template<typename vType>
VectorResource<vType>::VectorResource(size_t layoutLocation,size_t VectorSize):
layout(layoutLocation),
valueCount(VectorSize){
    bindResource();
}

template<typename vType>
VectorResource<vType>::~VectorResource(){
    glDeleteBuffers(1, &vbo);
}

template<typename vType>
void VectorResource<vType>::bindResource(){
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

}


template<typename vType>
void VectorResource<vType>::addVerticies(vType* VectorArray, size_t size){
    for(size_t i = 0; i < size; i++){
        verticies.push_back(VectorArray[i]);
    }
}
template<typename vType>
void VectorResource<vType>::setVerticies(std::vector<vType> &VectorArray){
    verticies = VectorArray;
};


template<typename vType>
void VectorResource<vType>::pushToGPU(){
    //push the data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vType) * verticies.size(), verticies.data() , GL_STATIC_DRAW);
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

template<typename vType>
void VectorResource<vType>::pushAdd(vType* VectorArray, size_t size){
    addVerticies(VectorArray,size);
    pushToGPU();
}

template<typename vType>
void VectorResource<vType>::pushSet(std::vector<vType> &VectorArray){
    setVerticies(VectorArray);
    pushToGPU();
}