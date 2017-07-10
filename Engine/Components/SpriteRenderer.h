#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "RenderComponent.h"

class Texture;

class SpriteRenderer :	public RenderComponent
{
public:
	SpriteRenderer();
	SpriteRenderer(ShaderProgram* shader);
	SpriteRenderer(ShaderProgram* shader, unsigned int VAO);
	SpriteRenderer(ShaderProgram* shader, unsigned int VAO, Texture* texture);

	virtual void Render() override;

	~SpriteRenderer();

	Texture* texture;
};


#endif // 