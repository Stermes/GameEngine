#include "Game.h"
#include "Managers/WindowManager.h"
#include "Managers/RenderingManager.h"
#include "GameObjects/SceneGraph.h"


#include "Resources/Shader.h"
#include "Resources/ShaderProgram.h"
#include "Resources/Texture.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Camera.h"
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "Components/SpriteRenderer.h"

Camera* camera = new Camera();

Game::Game()
{
}

void Game::Init(WindowManager * windowManager)
{
	this->m_windowManager = windowManager;
	this->m_sceneGraph = new SceneGraph(this);
	this->m_renderManager = new RenderingManager();

	Shader* vShader = new Shader("Shaders/Vertex/BasicVertex.VS", GL_VERTEX_SHADER);
	Shader* fShader = new Shader("Shaders/Fragment/BasicFragment.FS", GL_FRAGMENT_SHADER);
	ShaderProgram* shaderProgram = new ShaderProgram(vShader, fShader);

	float vertices[] = 
	{
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,   // top left 
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	};
		
	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
		
	glBindVertexArray(VAO);
		
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
		
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	Texture* tex = new Texture();
	tex->LoadTexture2D("container.jpg");

	glm::mat4 projection;
	float width = (GetWindowWidth())/200;
	float height = (GetWindowHeight())/200;
	projection = glm::ortho(-width, width, -height, height, 0.1f, 100.0f);
	camera->SetProjection(projection);
	camera->transform.position.z = -1.0f;

	GameObject* obj = new GameObject();
	m_sceneGraph->root->AddChild(obj);
	obj->AddComponent(new SpriteRenderer(shaderProgram, VAO, tex));
	m_sceneGraph->root->AddChild(camera);
	
}

void Game::Update()
{
	m_sceneGraph->Update();
}

void Game::FixedUpdate()
{
	m_sceneGraph->FixedUpdate();
}

void Game::Render()
{
	m_renderManager->RenderScene(camera);
}

int Game::GetWindowHeight()
{
	return m_windowManager->GetHeight();
}

int Game::GetWindowWidth()
{
	return m_windowManager->GetWidth();
}

WindowManager * Game::GetWindowManager()
{
	return m_windowManager;
}

RenderingManager * Game::GetRenderingManager()
{
	return m_renderManager;
}


void Game::Shutdown()
{
}

Game::~Game()
{
}
