#include "../include/LowLevelGraphics/shaderResource.hpp"

using namespace aml;

ShaderResource::ShaderResource(const std::string shaderFile,aml::ShaderType type):shaderType(type){
    //ifstream to read the shader file
    std::ifstream resourceFile(shaderFile,std::ios::in);
    //vector holding all the lines of the resource file
    std::vector<std::string> fileLines;


    
    //throw runtime error if the file fails to open
    if(!resourceFile.is_open()){
        throw std::runtime_error("file resource \"" + shaderFile  + "\" failed to open"); 
    }

    //read the file lines into the vector
    std::string line;
    while(std::getline(resourceFile,line)){
        fileLines.push_back(line + "\n");
    }

    //allocate memory equal to the size of the file
    const char** rawLines = new const char*[fileLines.size()];

    //read raw file data into rawLines
    for(size_t i = 0; i < fileLines.size();i++){
        rawLines[i] = fileLines[i].c_str();
    }

    //compile the shader program
    shader = glCreateShader(shaderType);
    glShaderSource(shader, (GLsizei)fileLines.size(), rawLines, NULL);
    glCompileShader(shader);

    delete[] rawLines;
    //handle compiler exceptions
    int compilationStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationStatus);

    //throw runtime error if shader failed to compile
	if(!compilationStatus)
	{
		char infoLogBuffer[2048];
		int logLength;
		glGetShaderInfoLog(shader, 2048, &logLength, infoLogBuffer);
		throw std::runtime_error(infoLogBuffer);
		
	}
    

}

ShaderResource::~ShaderResource(){
    glDeleteShader(shader);
}