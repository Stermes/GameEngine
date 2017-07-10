#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <thread>

class Game;

class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	bool InitWindow(const char* windowName, int width, int height, int versionMajor, int versionMinor, bool resizableWindow, Game* game);
	void Loop();
	void Render();
	void Update();
	void FixedUpdate();

	GLFWwindow* GetWindow();
	int GetWidth();
	int GetHeight();

private:
	void InitGLFW(int versionMajor, int versionMinor, bool resizableWindow);
	void ShutdownWindow();

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void MaximizeCallBack(GLFWwindow* window, int width, int height);


	GLFWwindow* m_window;

	static int m_screenWidth;
	static int m_screenHeight;

	Game* game;

	std::thread update;
	bool gameRunning;
};

#endif


