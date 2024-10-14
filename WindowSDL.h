#ifndef WINDOW_SDL_H__
#define WINDOW_SDL_H__

#include "Window.h"

class WindowSDL : public Window {

public:
    WindowSDL();
    ~WindowSDL();
    void createWindow(int width, int height) override;
    void clear() override;
    void display() override;
    void pollEvents() override;
    bool isRunning() override;
    void close() override;
};

#endif // WINDOW_SDL_H__
