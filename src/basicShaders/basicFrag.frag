#version 330 core

layout(location = 0) out vec4 outputColor;

smooth in vec3 ioVertexColor;
smooth in vec2 TexCoord;


uniform sampler2D[16] textureId;
uniform int BLEND_FLAG = 0;


void main()
{	if(BLEND_FLAG == 1){
		outputColor = texture(textureId[0], TexCoord) * vec4(ioVertexColor, 1.0);	
	}else{
		outputColor = texture(textureId[0], TexCoord) + vec4(ioVertexColor, 1.0);
	}
	
} 