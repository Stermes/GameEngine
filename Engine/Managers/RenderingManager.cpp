#include "RenderingManager.h"
#include "../Components/RenderComponent.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Camera.h"
#include "../Resources/ShaderProgram.h"


unsigned int RenderingManager::m_currentVAO = -1;
ShaderProgram* RenderingManager::m_currentShader = NULL;
Camera* RenderingManager::m_currentCamera = NULL;

RenderingManager::RenderingManager()
{
	renderers.clear();
}

void RenderingManager::AddRenderComp(RenderComponent * renderer)
{
	renderers.push_back(renderer);
}

void RenderingManager::RemoveRenderComp(RenderComponent * renderer)
{
	for (std::list<RenderComponent*>::iterator it = renderers.begin(); it != renderers.end(); it++)
	{
		RenderComponent* found = (RenderComponent*)*it;
		if (found == renderer)
		{
			renderers.erase(it);
			break;
		}
	}
}

void RenderingManager::RenderScene(Camera* cam)
{
	m_currentCamera = cam;

	for (std::list<RenderComponent*>::iterator it = renderers.begin(); it != renderers.end(); it++)
	{
		RenderComponent* renderer = (RenderComponent*)*it;
	
		if (renderer->GetShader() != m_currentShader)
		{
			m_currentShader = renderer->GetShader();
			m_currentShader->Use();
			m_currentShader->SetMatrix("projection", m_currentCamera->GetProjection());
			m_currentShader->SetMatrix("view", m_currentCamera->GetView());
		}
		if (renderer->GetVAO() != m_currentVAO)
		{
			m_currentVAO = renderer->GetVAO();
			glBindVertexArray(m_currentVAO);
		}

		renderer->Render();

	}
	
	m_currentShader = nullptr;
}

ShaderProgram * RenderingManager::GetCurrentShader()
{
	return m_currentShader;
}

unsigned int RenderingManager::GetCurrentVAO()
{
	return m_currentVAO;
}

Camera * RenderingManager::GetCurrentCamera()
{
	return m_currentCamera;
}
