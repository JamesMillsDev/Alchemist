#include <Alchemist/Application.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <Alchemist/Rendering/Texture.h>

class Game : public GameInstance
{
public:
	Game() = default;

protected:
	void Tick() override {}
	void Render() override
	{
		Alchemist::GetRenderEngine()->DrawTexture(m_texture, 0, 0, 410, 300, 45, WHITE);
		//Alchemist::GetRenderEngine()->DrawCircleLines(100.f, 100.f, 50.f, { 255, 0, 0, 255 });
	}

	void BeginPlay() override
	{
		m_texture = new Texture("lettuce", PNG);
		m_texture->Load();
		m_texture2 = new Texture("lettuce", PNG);
		m_texture2->Load();
	}

	void EndPlay() override {}

private:
	Texture* m_texture;
	Texture* m_texture2;

};

int main(int argC, char* argV[])
{
	Application::Run<Game>("Sample", 1080, 720);

	return EXIT_SUCCESS;
}