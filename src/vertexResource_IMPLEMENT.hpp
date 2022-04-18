#include "../include/vertexResource.hpp"

using namespace aml;
//set nextID to zero
template<typename vType>
size_t VertexResource<vType>::nextID = 0;


template<typename vType>
VertexResource<vType>::VertexResource(size_t layoutLocation,size_t vertexSize):
layout(layoutLocation),
valueCount(vertexSize){
    bindResource();
}

template<typename vType>
VertexResource<vType>::~VertexResource(){
    glDeleteBuffers(1, &vbo);
}

template<typename vType>
void VertexResource<vType>::bindResource(){
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

}


template<typename vType>
void VertexResource<vType>::addVerticies(vType* vertexArray, size_t size){
    for(size_t i = 0; i < size; i++){
        verticies.push_back(vertexArray[i]);
    }
}


template<typename vType>
void VertexResource<vType>::pushToGPU(){
    //push the data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vType) * verticies.size(), verticies.data() , GL_STATIC_DRAW);
    //get the length of the vertex atribute
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
void VertexResource<vType>::pushAdd(vType* vertexArray, size_t size){
    addVerticies(vertexArray,size);
    pushToGPU();
}