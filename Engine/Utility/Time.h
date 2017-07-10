static class Time
{
	friend class WindowManager;
public:
	static float deltaTime;
	static float elapsedTime;
	static int FPS;
	static float fixedDeltaTime;

private:
	static void UpdateTime(float time);
	static int frameCount;
	static float frameTime;
	static float m_lastFrameTime;
	static float m_fixedTime;
};
