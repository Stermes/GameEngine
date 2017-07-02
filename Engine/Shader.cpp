#include "Shader.h"

Shader::Shader(const char * filePath, GLenum shaderType)
{
	std::string code;
	std::ifstream shaderFile;

	// ensure we can throw exceptions 
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		// open the file
		shaderFile.open(filePath);
		std::stringstream shaderStream;
		// Read the file into the stream
		shaderStream << shaderFile.rdbuf();
		//close file handler
		shaderFile.close();
		//convert into string
		code = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* shaderCode = code.c_str();
	int success;
	char infoLog[512];

	m_Shader = glCreateShader(shaderType);
	glShaderSource(m_Shader, 1, &shaderCode, NULL);
	glCompileShader(m_Shader);
	CheckCompileErrors(m_Shader, shaderType);
}

Shader::~Shader()
{
	DeleteShader();
}

unsigned int Shader::GetShader()
{
	return m_Shader;
}

void Shader::DeleteShader()
{
	glDeleteShader(m_Shader);
}

void Shader::CheckCompileErrors(unsigned int shader, GLenum shaderType)
{
	int success;
	char infoLog[1024];

	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader, 1024, NULL, infoLog);
		std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << shaderType << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
	}
}
