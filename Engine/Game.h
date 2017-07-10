#ifndef GAME_H
#define GAME_H

class RenderingManager;
class SceneGraph;

class Game
{
	friend class WindowManager;

public:
	Game();

	virtual void Init(class WindowManager* wondowManager);

	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render();

	int GetWindowHeight();
	int GetWindowWidth();

	WindowManager* GetWindowManager();
	RenderingManager* GetRenderingManager();

protected:
	WindowManager* m_windowManager;
	RenderingManager* m_renderManager;
	SceneGraph* m_sceneGraph;
	virtual void Shutdown();
	virtual ~Game();
};

#endif // 