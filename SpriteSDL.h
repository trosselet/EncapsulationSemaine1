#ifndef SPRITE_SDL_H__
#define SPRITE_SDL_H__

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Sprite.h"

class SpriteSDL : public Sprite {
private:
    SDL_Renderer* m_sdlRenderer = nullptr;

public:
    SpriteSDL();
    void drawCircle(int x, int y, int radius) override;
};

#endif // SPRITE_SDL_H__