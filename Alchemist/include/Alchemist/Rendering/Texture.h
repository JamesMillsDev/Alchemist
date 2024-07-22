#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Texture;

enum ETextureFormat
{
	Jpg,
	Png,
	Tiff
};

class DLL Texture
{
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

};