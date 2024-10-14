#ifndef WINDOW_SDL_H__
#define WINDOW_SDL_H__

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Window.h"

class WindowSDL : public Window {
private:
    SDL_Window* m_sdlWindow = nullptr;
    SDL_Renderer* m_sdlRenderer = nullptr;
    bool m_isRunning;

public:
    WindowSDL();
    ~WindowSDL();
    void createWindow(int width, int height) override;
    void clear() override;
    void display() override;
    void pollEvents() override;
    bool isRunning() override;
    void close() override;
    SDL_Renderer* getRenderer();
};

#endif // WINDOW_SDL_H__
