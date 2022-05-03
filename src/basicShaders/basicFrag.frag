#version 330 core

layout(location = 0) out vec4 outputColor;

smooth in vec3 ioVertexColor;
smooth in vec2 TexCoord;

uniform sampler2D textureId;

void main()
{
	outputColor = texture(textureId, TexCoord) * vec4(ioVertexColor, 1.0);
}