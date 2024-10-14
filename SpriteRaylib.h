#ifndef SPRITE_RAYLIB_H__
#define SPRITE_RAYLIB_H__

#include "Sprite.h"

class SpriteRaylib : public Sprite {
public:
    SpriteRaylib();
    void drawCircle(int x, int y, int radius) override;
};

#endif // SPRITE_RAYLIB_H__
