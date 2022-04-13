#include "../include/vertexResource.hpp"

using namespace aml;
//set nextID to zero
template<typename vType>
size_t VertexResource<vType>::nextID = 0;


template<typename vType>
VertexResource<vType>::VertexResource(){
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
    id = VertexResource::nextID;
    VertexResource::nextID++;
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
    std::cout << verticies.size() << "\n";
    glBufferData(GL_ARRAY_BUFFER, sizeof(vType) * verticies.size(), verticies.data() , GL_STATIC_DRAW);
    

    //set the current data pointer to the objects ID
    glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(id);
	
}

template<typename vType>
void VertexResource<vType>::pushAdd(vType* vertexArray, size_t size){
    addVerticies(vertexArray,size);
    pushToGPU();
}