#ifndef SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader(const char* filePath, GLenum shaderType);
	~Shader();

	unsigned int GetShader();
	void DeleteShader();

private:

	void CheckCompileErrors(unsigned int shader, GLenum shaderType);
	unsigned int m_Shader;
};

#endif

