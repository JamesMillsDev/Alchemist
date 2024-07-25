#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Texture;
struct Color;

enum ETextureType
{
	JPG,
	PNG,
	TIFF
};

class DLL Texture
{
	friend class RenderEngine;

public:
	Texture(const char* name, ETextureType type);
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
	ETextureType m_type;

private:
	void Tint(Color tint) const;
	void ResetTint() const;

	string ExtensionFor() const;

};