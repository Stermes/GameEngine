#include "ShaderProgram.h"
#include "Shader.h"

ShaderProgram::ShaderProgram(Shader * vertexShader, Shader * fragmentShader, Shader * geometryShader)
{
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader->GetShader());
	glAttachShader(m_ID, fragmentShader->GetShader());
	if(geometryShader != NULL)
		glAttachShader(m_ID, geometryShader->GetShader());

	glLinkProgram(m_ID);
	CheckCompileErrors();

}

ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::Use()
{
	glUseProgram(m_ID);
}

unsigned int ShaderProgram::GetID()
{
	return m_ID;
}

void ShaderProgram::SetBool(const std::string & name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void ShaderProgram::SetInt(const std::string & name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void ShaderProgram::SetFloat(const std::string & name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void ShaderProgram::SetMatrix(const std::string & name, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::CheckCompileErrors()
{
	int success;
	char infoLog[1024];

	glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_ID, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type:  PROGRAM \n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
	}
}
