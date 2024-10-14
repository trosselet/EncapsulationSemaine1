#include "WindowSDL.h"
#include <iostream>

WindowSDL::WindowSDL()
{
}

WindowSDL::~WindowSDL()
{
}

void WindowSDL::createWindow(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error init video : " << SDL_GetError() << std::endl;
    }

    m_sdlWindow = SDL_CreateWindow("Ball Generator SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (m_sdlWindow == nullptr)
    {
        std::cout << "Error create window : " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (m_sdlRenderer == nullptr)
    {
        std::cout << "Error create renderer : " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    if (m_sdlRenderer && m_sdlWindow)
    {
        m_isRunning = true;
    }
    else
    {
        m_isRunning = false;
    }

}

void WindowSDL::clear()
{
    SDL_RenderClear(m_sdlRenderer);
}

void WindowSDL::display()
{
    SDL_SetRenderDrawColor(m_sdlRenderer, 255, 0, 0, 255);
    SDL_RenderPresent(m_sdlRenderer);
}

void WindowSDL::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_isRunning = false;
        }
    }
}

bool WindowSDL::isRunning()
{
    return m_isRunning;
}

void WindowSDL::close()
{
    SDL_DestroyRenderer(m_sdlRenderer);
    SDL_DestroyWindow(m_sdlWindow);
    SDL_Quit();
}
