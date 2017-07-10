#include "WindowManager.h"
#include "InputManager.h"
#include "../Utility/Time.h"
#include "../Game.h"

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);

int WindowManager::m_screenWidth = 0;
int WindowManager::m_screenHeight = 0;

WindowManager::WindowManager()
{
}


WindowManager::~WindowManager()
{
}

bool WindowManager::InitWindow(const char * windowName, int width, int height, int versionMajor, int versionMinor, bool resizableWindow, Game* game)
{
	InitGLFW(versionMajor, versionMinor, resizableWindow);

	m_screenHeight = height;
	m_screenWidth = width;

	m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, windowName, nullptr, nullptr);
	if (m_window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);
	//glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallBack);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	glfwSetKeyCallback(m_window, KeyCallback);
	glfwSetCursorPosCallback(m_window, MouseCallback);
	glfwSetScrollCallback(m_window, ScrollCallback);
	glfwSetMouseButtonCallback(m_window, MouseButtonCallback);
	glfwSetWindowSizeCallback(m_window, MaximizeCallBack);

	this->game = game;
	game->Init(this);

	gameRunning = true;
	update = std::thread(&WindowManager::Update, this);

	Loop();

	gameRunning = false;
	update.join();

	ShutdownWindow();


	return true;
}

void WindowManager::Loop()
{
	while (!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
		Render();
	}
}

void WindowManager::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	game->Render();
	glfwSwapBuffers(m_window);
}

void WindowManager::Update()
{
	while (gameRunning)
	{
		InputManager::Instance().JoyStickUpdate();
		Time::UpdateTime(glfwGetTime());

		game->Update();
		while (Time::m_fixedTime >= Time::fixedDeltaTime)
		{
			FixedUpdate();
			Time::m_fixedTime -= Time::fixedDeltaTime;
		}
		InputManager::Instance().EndFrame();
	}
}

void WindowManager::FixedUpdate()
{
	game->FixedUpdate();
}

GLFWwindow * WindowManager::GetWindow()
{
	return m_window;
}

int WindowManager::GetWidth()
{
	return m_screenWidth;
}

int WindowManager::GetHeight()
{
	return m_screenHeight;
}

void WindowManager::InitGLFW(int versionMajor, int versionMinor, bool resizableWindow)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, resizableWindow);
}

void WindowManager::ShutdownWindow()
{
	glfwTerminate();
}

void FrameBufferSizeCallBack(GLFWwindow * window, int width, int height)
{
		glViewport(0, 0, width, height);
}


void WindowManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (action == GLFW_PRESS)
	{
		InputManager::Instance().keys[key].pressed = true;
	}
	else if (action == GLFW_RELEASE)
	{
		InputManager::Instance().keys[key].released = true;
	}

}

void WindowManager::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{

	InputManager::Instance().MouseX = xpos;
	InputManager::Instance().MouseY = ypos;

}

void WindowManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		InputManager::Instance().MouseClick[button].pressed = true;
	}
	else if (action == GLFW_RELEASE)
	{
		InputManager::Instance().MouseClick[button].released = true;
	}
}

void WindowManager::MaximizeCallBack(GLFWwindow *window, int width, int height)
{
	m_screenWidth = width;
	m_screenHeight = height;

	glViewport(0, 0, m_screenWidth, m_screenHeight);
}

void WindowManager::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{

}