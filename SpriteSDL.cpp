#include "SpriteSDL.h"
#include <cmath>

SpriteSDL::SpriteSDL(SDL_Renderer* renderer) : m_sdlRenderer(renderer)
{
}

void SpriteSDL::drawCircle(int x, int y, int radius)
{
    SDL_SetRenderDrawColor(m_sdlRenderer, 255, 0, 0, 255);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(m_sdlRenderer, x + dx, y + dy);
            }
        }
    }
}