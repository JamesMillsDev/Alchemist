#include <Alchemist/Application.h>

int main(int argC, char* argV[])
{
	Application* app = new Application("Sample", 1080, 720);

	app->Run();

	delete app;

	return EXIT_SUCCESS;
}