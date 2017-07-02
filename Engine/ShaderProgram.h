#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glad/glad.h>
#include <string>

class Shader;

class ShaderProgram
{
public:
	ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Shader* geometryShader = NULL);
	~ShaderProgram();

	// Sets this shader program to be used
	void Use();
	unsigned int GetID();

	// Sets the uniforms for the shader program
	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;

private:
	unsigned int m_ID;
	// compile error check
	void CheckCompileErrors();
};

#endif 