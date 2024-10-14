#include <iostream>
#include "WindowSDL.h"
#include "SpriteSDL.h"

struct Circle {
	int x;
	int y;
	int radius;
};

int main(int argc, char* argv[])
{
	WindowSDL win;
	SpriteSDL sprite;

	win.createWindow(800, 600);

	while (win.isRunning())
	{
		win.pollEvents();
		win.clear();
		win.display();
	}
	return 0;
}