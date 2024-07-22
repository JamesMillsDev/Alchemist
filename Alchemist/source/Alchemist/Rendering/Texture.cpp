#include "Alchemist/Rendering/Texture.h"

#include "Alchemist/Application.h"
#include "Alchemist/Rendering/RenderEngine.h"

Texture::Texture(const char* name, ETextureFormat format)
	: m_name{ new char[strlen(name)] }, m_texture{ nullptr }, m_format{ format }
{
	strcpy_s(m_name, strlen(name) + 1, name);
}

Texture::~Texture() = default;

void Texture::Load()
{
	m_texture = Alchemist::GetRenderEngine()->Load(m_name, m_format, this);
}

void Texture::Unload()
{
	Alchemist::GetRenderEngine()->Unload(this);
	m_texture = nullptr;
}

Texture::operator SDL_Texture* () const
{
	return m_texture;
}