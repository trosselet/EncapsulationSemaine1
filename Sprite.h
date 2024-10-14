#ifndef SPRITE_H__
#define SPRITE_H__

class Sprite {
public:
    virtual ~Sprite() = default;
    virtual void drawCircle(int x, int y, int radius) = 0;
};

#endif // SPRITE_H__