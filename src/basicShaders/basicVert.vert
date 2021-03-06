#version 330 core

#define IDENTITY_MATRIX 


struct MatrixPack
{
	mat4 projectionMatrix;
	mat4 viewMatrix;
	mat4 modelMatrix;
};


uniform MatrixPack matrices = MatrixPack(mat4(1),mat4(1),mat4(1));


layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 aTexCoord;

smooth out vec3 ioVertexColor;
smooth out vec2 TexCoord;




void main()
{
	mat4 mvpMatrix = matrices.projectionMatrix * matrices.viewMatrix * matrices.modelMatrix;
	gl_Position = mvpMatrix * vec4(vertexPosition, 1.0);
	ioVertexColor = vertexColor;
	TexCoord = aTexCoord;
}