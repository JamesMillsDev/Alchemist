#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>

#include "Alchemist/Rendering/Texture.h"

class Game : public GameInstance
{
public:
	Game() = default;

protected:
	void Tick() override {}
	void Render() override
	{
		Alchemist::GetRenderEngine()->RenderTexture(m_texture);
	}

	void BeginPlay() override
	{
		m_texture = new Texture("lettuce", Png);
		m_texture->Load();
	}

	void EndPlay() override {}

private:
	Texture* m_texture;

};

int main(int argC, char* argV[])
{
	Application::Run<Game>("Sample", 1080, 720);

	return EXIT_SUCCESS;
}