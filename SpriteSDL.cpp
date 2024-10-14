#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(SDL_Renderer* renderer) : m_sdlRenderer(renderer)
{
}

void SpriteSDL::drawCircle(int x, int y, int radius)
{

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(m_sdlRenderer, x + dx, y + dy);
            }
        }
    }
}
