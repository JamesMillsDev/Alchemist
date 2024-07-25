#include "Alchemist/Rendering/Texture.h"

#include <format>
#include <iostream>
#include <sstream>
#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <Alchemist/Utilities/Console.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
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
	path << ExtensionFor();

	SDL_Surface* surface = IMG_Load(path.str().c_str());
	if (surface == nullptr)
	{
		Console::LogError(std::format("Error loading image '{}': {}", m_name, IMG_GetError()));
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(Alchemist::GetRenderEngine()->m_renderer, surface);

	if (m_texture == nullptr)
	{
		Console::LogError(std::format("Error loading image: {}", IMG_GetError()));
		return;
	}

	Console::Log(std::format("Loaded texture '{}{}'", m_name, ExtensionFor()));

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

string Texture::ExtensionFor() const
{
	switch (m_type)  // NOLINT(clang-diagnostic-switch-enum)
	{
	case JPG:
		return ".jpg";

	case PNG:
		return ".png";

	case TIFF:
		return ".tif";

	default:
		return ".png";
	}
}
