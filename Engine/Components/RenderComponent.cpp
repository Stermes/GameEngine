#include "RenderComponent.h"
#include "../Resources/ShaderProgram.h"
#include "../Managers/RenderingManager.h"
#include "../Game.h"
#include "../GameObjects/GameObject.h"

RenderComponent::RenderComponent() : Component()
{
}

RenderComponent::RenderComponent(ShaderProgram * shader) : Component()
{
	SetShader(shader);
}

RenderComponent::RenderComponent(ShaderProgram * shader, unsigned int VAO) : Component()
{
	SetShader(shader);
	SetVAO(VAO);
}

void RenderComponent::SetShader(ShaderProgram * shader)
{
	m_shader = shader;
}

ShaderProgram * RenderComponent::GetShader()
{
	return m_shader;
}

void RenderComponent::SetVAO(unsigned int VAO)
{
	m_VAO_ID = VAO;
}

unsigned int RenderComponent::GetVAO()
{
	return m_VAO_ID;
}


void RenderComponent::Render()
{
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::Init()
{
	Component::Init();
	m_renderManager = gameObject->GetGame()->GetRenderingManager();
	m_renderManager->AddRenderComp(this);
}
