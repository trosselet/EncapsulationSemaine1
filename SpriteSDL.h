#ifndef SPRITE_SDL_H__
#define SPRITE_SDL_H__

#include "Sprite.h"

class SpriteSDL : public Sprite {

public:
    SpriteSDL();
    void drawCircle(int x, int y, int radius) override;
};

#endif // SPRITE_SDL_H__