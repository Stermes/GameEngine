#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H
#include <list>

class RenderComponent;
class Camera;
class ShaderProgram;

class RenderingManager
{
public:
	RenderingManager();

	void AddRenderComp(RenderComponent* renderer);
	void RemoveRenderComp(RenderComponent* renderer);

	void RenderScene(Camera* cam);

	std::list<RenderComponent*> renderers;

	ShaderProgram* GetCurrentShader();
	unsigned int GetCurrentVAO();
	Camera* GetCurrentCamera();

protected:
	static Camera* m_currentCamera;
	static ShaderProgram* m_currentShader;
	static unsigned int m_currentVAO;
};
#endif

