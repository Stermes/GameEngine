#include "Managers/WindowManager.h"
#include "Game.h"

int main()
{
	WindowManager* windowManager = new WindowManager();
	windowManager->InitWindow("Game", 1920, 1080, 4, 0, true, new Game());
	return 0;
}
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//#include "Resources/Shader.h"
//#include "Resources/ShaderProgram.h"
//#include "Resources/Texture.h"
//
//#include <glm/glm/glm.hpp>
//#include <glm/glm/gtc/matrix_transform.hpp>
//#include <glm/glm/gtc/type_ptr.hpp>
//
//#include "GameObjects/Camera.h"
//void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
//void HandleInput(GLFWwindow* window);
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//Camera* camera = new Camera();
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Engine", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);
//
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader* vShader = new Shader("Shaders/Vertex/BasicVertex.VS", GL_VERTEX_SHADER);
//	Shader* fShader = new Shader("Shaders/Fragment/BasicFragment.FS", GL_FRAGMENT_SHADER);
//
//	ShaderProgram* shaderProgram = new ShaderProgram(vShader, fShader);
//
//	float vertices[] = {
//		// positions          // colors           // texture coords
//		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,   // top left 
//		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//	};
//
//	unsigned int VBO, VAO;
//	glGenBuffers(1, &VBO);
//	glGenVertexArrays(1, &VAO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// color attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	// texture coord attribute
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	Texture* tex = new Texture();
//	tex->LoadTexture2D("container.jpg");
//
//	//glEnable(GL_DEPTH_TEST);
//
//	shaderProgram->Use();
//	glm::mat4 projection;
//	//projection = glm::perspective(glm::radians(45.0f), (float)(SCR_WIDTH /SCR_HEIGHT), 0.1f, 100.0f);
//	projection = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, 0.1f, 100.0f);
//
//	glm::mat4 model;
//	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0));
//
//	shaderProgram->SetMatrix("model", model);
//
//	camera->SetProjection(projection);
//	camera->transform.position.z = -1.0f;
//
//	while (!glfwWindowShouldClose(window))
//	{
//		HandleInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);		
//
//		camera->Update(0.166f);
//
//		shaderProgram->Use();
//		shaderProgram->SetMatrix("projection", camera->GetProjection());
//		shaderProgram->SetMatrix("view", camera->GetView());
//		shaderProgram->SetMatrix("model", model);
//		tex->BindTexture();
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//	
//	delete tex;
//	delete vShader;
//	delete fShader;
//	glfwTerminate();
//	return 0;
//}
//
//void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void HandleInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//}