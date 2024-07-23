#include "Alchemist/Rendering/Texture.h"

#include <iostream>
#include <sstream>
#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_render.h>

using std::stringstream;

Texture::Texture(const char* name, ETextureType type)
	: m_name{ new char[strlen(name)] }, m_texture{ nullptr }, m_type{ type }
{
	strcpy_s(m_name, strlen(name) + 1, name);
}

Texture::~Texture()
{
	if (m_texture != nullptr)
		Unload();
}

void Texture::Load()
{
	stringstream path;
	path << "Content\\Textures\\";
	path << m_name;

	switch (m_type)  // NOLINT(clang-diagnostic-switch-enum)
	{
	case JPG:
		path << ".jpg";
		break;

	case PNG:
		path << ".png";
		break;

	case TIFF:
		path << ".tif";
		break;
	}

	SDL_Surface* surface = IMG_Load(path.str().c_str());
	if (surface == nullptr)
	{
		std::cout << "Error loading image: " << IMG_GetError() << "\n";
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(Alchemist::GetRenderEngine()->m_renderer, surface);
	if (m_texture == nullptr)
	{
		std::cout << "Error creating texture\n";
		return;
	}

	SDL_FreeSurface(surface);
}

void Texture::Unload()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
}

Texture::operator SDL_Texture* () const
{
	return m_texture;
}

void Texture::Tint(Color tint) const
{
	SDL_SetTextureColorMod(m_texture, tint.red, tint.green, tint.blue);
	SDL_SetTextureAlphaMod(m_texture, tint.alpha);
}

void Texture::ResetTint() const
{
	SDL_SetTextureColorMod(m_texture, 255, 255, 255);
	SDL_SetTextureAlphaMod(m_texture, 255);
}
