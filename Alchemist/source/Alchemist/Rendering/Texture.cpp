#include "Alchemist/Rendering/Texture.h"

#include <iostream>
#include <sstream>
#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_render.h>

using std::stringstream;

Texture::Texture(const char* name, ETextureFormat format)
	: m_name{ new char[strlen(name)] }, m_texture{ nullptr }, m_format{ format }
{
	strcpy_s(m_name, strlen(name) + 1, name);
}

Texture::~Texture() = default;

void Texture::Load()
{
	stringstream path;
	path << "Content\\Textures\\";
	path << m_name;

	switch (m_format)  // NOLINT(clang-diagnostic-switch-enum)
	{
	case Jpg:
		path << ".jpg";
		break;

	case Png:
		path << ".png";
		break;

	case Tiff:
		path << ".tif";
		break;

	default:
		path << ".png";
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