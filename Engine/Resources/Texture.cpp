#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "..\stb_image.h"

Texture::Texture()
{
}

bool Texture::LoadTexture2D(char * path, bool bGenerateMipMaps)
{
	m_filePath = path;
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	m_minFilter = TFT_LINEAR;
	m_magFilter = TFT_LINEAR;

	unsigned char *data = stbi_load(path, &m_width, &m_height, &m_nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
		stbi_image_free(data);
		return false;
	}
	stbi_image_free(data);
	return true;
}

void Texture::SetFiltering(TextureFilter filter, TextureFilterType filterType)
{
	glTexParameteri(m_textureID, filter, filterType);
}

void Texture::BindTexture(int textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}


TextureFilterType Texture::GetMinificationFilter()
{
	return m_minFilter;
}

TextureFilterType Texture::GetMagnificationFilter()
{
	return m_magFilter;
}

void Texture::ReleaseTexture()
{
	glDeleteTextures(1, &m_textureID);
}

unsigned int Texture::GetTextureID()
{
	return m_textureID;
}

char * Texture::GetPath()
{
	return m_filePath;
}


Texture::~Texture()
{
	ReleaseTexture();
}
