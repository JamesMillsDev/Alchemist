#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Texture;
struct Color;

enum ETextureFormat
{
	Jpg,
	Png,
	Tiff
};

class DLL Texture
{
	friend class RenderEngine;

public:
	Texture(const char* name, ETextureFormat format);
	~Texture();

	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;

public:
	void Load();
	void Unload();

public:
	operator SDL_Texture* () const;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&&) = delete;

private:
	char* m_name;

	SDL_Texture* m_texture;
	ETextureFormat m_format;

private:
	void Tint(Color tint) const;
	void ResetTint() const;

};