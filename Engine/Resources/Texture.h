#ifndef TEXTURE_H

#include <string>
#include <iostream>
#include <glad/glad.h>

enum TextureFilter
{
	TF_MAG_FILTER = GL_TEXTURE_MAG_FILTER,
	TF_MIN_FILTER = GL_TEXTURE_MIN_FILTER
};

enum TextureFilterType
{
	TFT_NEAREST = GL_NEAREST,
	TFT_LINEAR = GL_LINEAR,
	TFT_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
	TFT_MIPMAP_LINEAR_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
	TFT_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR,
};
class Texture
{
public:
	Texture();

	bool LoadTexture2D(char* path, bool bGenerateMipMaps = false);
	void SetFiltering(TextureFilter filter, TextureFilterType filterType);
	void BindTexture(int textureUnit = 0);

	TextureFilterType GetMinificationFilter();
	TextureFilterType GetMagnificationFilter();

	void ReleaseTexture();

	unsigned int GetTextureID();
	char* GetPath();
	~Texture();

private:
	TextureFilterType m_minFilter, m_magFilter;
	unsigned int m_textureID;
	char* m_filePath;
	int m_width, m_height, m_nrChannels;
};

#endif
