#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

class ShaderProgram;
class RenderingManager;

#include "Component.h"
class RenderComponent :	public Component
{
public:
	RenderComponent();
	RenderComponent(ShaderProgram* shader);
	RenderComponent(ShaderProgram* shader, unsigned int VAO);

	void SetShader(ShaderProgram* shader);
	ShaderProgram* GetShader();

	void SetVAO(unsigned int VAO);
	unsigned int GetVAO();

	virtual void Render();
	virtual ~RenderComponent();

	void Init() override;

	bool bAlwaysDraw = false;

protected:
	ShaderProgram* m_shader;
	unsigned int m_VAO_ID;

	RenderingManager* m_renderManager;
};


#endif