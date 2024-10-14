#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "WindowSDL.h"
#include "SpriteSDL.h"

struct Circle {
	int x;
	int y;
	int radius;
};

int main(int argc, char* argv[])
{
	Window* window = nullptr;
	Sprite* sprite = nullptr;
	Circle circle{ 100, 100, 100 };

	window = new WindowSDL();
	window->createWindow(800, 600);

	while (window->isRunning())
	{
		window->pollEvents();
		window->clear();
		sprite->drawCircle(circle.x, circle.y, circle.radius);
		window->display();
	}
	window->close();
	delete window;
	delete sprite;
	return 0;
}