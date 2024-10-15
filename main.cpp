#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "WindowSDL.h"
#include "SpriteSDL.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600


struct Circle {
	int x, y;
	int radius;
	int dx, dy;
};

int main(int argc, char* argv[])
{
	Window* window = nullptr;
	Sprite* sprite = nullptr;

	window = new WindowSDL();
	window->createWindow(WIDTH, HEIGHT);
	sprite = new SpriteSDL(((WindowSDL*)window)->getRenderer());

	std::srand(std::time(nullptr));
	std::vector<Circle> circles;

#define FPS_INTERVAL 1.0 //seconds.

	Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
	Uint32 fps_current; //the current FPS.
	Uint32 fps_frames = 0; //frames passed since the last recorded fps.


	for (int i = 0; i < 5; ++i) {
		Circle circle;
		circle.radius = 10;
		circle.x = (std::rand() % (WIDTH - 2 - circle.radius - 10)) + (circle.radius + 10);
		circle.y = (std::rand() % (HEIGHT - 2 - circle.radius - 10)) + (circle.radius + 10);
		circle.dx = (std::rand() % 2) + 1;
		circle.dy = (std::rand() % 2) + 1;
		circles.push_back(circle);
	}

	while (window->isRunning())
	{
		fps_frames++;
		if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL * 1000)
		{
			fps_lasttime = SDL_GetTicks();
			fps_current = fps_frames;
			fps_frames = 0;
			std::cout << fps_current << std::endl;
		}

		window->pollEvents();
		window->clear();

		for (auto& circle : circles) {
			circle.x += circle.dx;
			circle.y += circle.dy;

			if (circle.x - circle.radius <= 1 || circle.x + circle.radius >= WIDTH - 1) {
				circle.dx = -circle.dx;
			}
			if (circle.y - circle.radius <= 1 || circle.y + circle.radius >= HEIGHT - 1) {
				circle.dy = -circle.dy;
			}

			
			sprite->drawCircle(circle.x, circle.y, circle.radius);
		}

		window->display();

		

		
	}
	window->close();
	delete window;
	delete sprite;
	return 0;
}