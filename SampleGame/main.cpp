#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <SDL/SDL_render.h>

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
		m_texture = Alchemist::GetRenderEngine()->Load("lettuce", IMG_INIT_PNG);
	}

	void EndPlay() override {}

private:
	SDL_Texture* m_texture;

};

int main(int argC, char* argV[])
{
	Application::Run<Game>("Sample", 1080, 720);

	return EXIT_SUCCESS;
}