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
	float dx, dy;
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

	for (int i = 0; i < 5; ++i) {
		Circle circle;
		circle.radius = 20;
		circle.x = (std::rand() % (WIDTH - 2 * circle.radius - 1)) + (circle.radius + 1);
		circle.y = (std::rand() % (HEIGHT - 2 * circle.radius - 1)) + (circle.radius + 1);
		circle.dx = (std::rand() % 5) + 0.5;
		circle.dy = (std::rand() % 5) + 0.5;
		circles.push_back(circle);
	}

	while (window->isRunning())
	{
		window->pollEvents();
		window->clear();

		for (auto& circle : circles) {
			circle.x += circle.dx;
			circle.y += circle.dy;

			if (circle.x - circle.radius < 1 || circle.x + circle.radius > WIDTH - 1) {
				circle.dx = -circle.dx;
			}
			if (circle.y - circle.radius < 1 || circle.y + circle.radius > HEIGHT - 1) {
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