#include "SpriteRenderer.h"
#include "../Resources/ShaderProgram.h"
#include "../Managers/RenderingManager.h"
#include "../Game.h"
#include "../GameObjects/GameObject.h"
#include "../Resources/Texture.h"



SpriteRenderer::SpriteRenderer()
{
}

SpriteRenderer::SpriteRenderer(ShaderProgram * shader) : RenderComponent(shader)
{
}

SpriteRenderer::SpriteRenderer(ShaderProgram * shader, unsigned int VAO) : RenderComponent(shader, VAO)
{
}

SpriteRenderer::SpriteRenderer(ShaderProgram * shader, unsigned int VAO, Texture * texture) : RenderComponent(shader, VAO)
{
	this->texture = texture;
}

void SpriteRenderer::Render()
{
	gameObject->GetGame()->GetRenderingManager()->GetCurrentShader()->SetMatrix("model", gameObject->transform.model);
	texture->BindTexture();
	glBindVertexArray(m_VAO_ID);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


SpriteRenderer::~SpriteRenderer()
{
}
