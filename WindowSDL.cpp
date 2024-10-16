#include "WindowSDL.h"
#include <iostream>

WindowSDL::WindowSDL() : m_sdlWindow(nullptr), m_sdlRenderer(nullptr), m_isRunning(false)
{
}

WindowSDL::~WindowSDL()
{
    close();
}

void WindowSDL::createWindow(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error init video : " << SDL_GetError() << std::endl;
    }

    m_sdlWindow = SDL_CreateWindow("Ball Generator SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!m_sdlWindow)
    {
        std::cout << "Error create window : " << SDL_GetError() << std::endl;
    }

    m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!m_sdlRenderer)
    {
        std::cout << "Error create renderer : " << SDL_GetError() << std::endl;
    }

    m_isRunning = true;
    
}

void WindowSDL::clear()
{
    SDL_SetRenderDrawColor(m_sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_sdlRenderer);
}

void WindowSDL::display()
{
    
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
    if(m_sdlRenderer)
        SDL_DestroyRenderer(m_sdlRenderer);
    if(m_sdlWindow)
        SDL_DestroyWindow(m_sdlWindow);
    SDL_Quit();
}

SDL_Renderer* WindowSDL::getRenderer()
{
    return m_sdlRenderer;
}
