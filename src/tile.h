#pragma once

#include "drawable.h"
#include "position.h"
#include "SDL2/SDL_rect.h"

class Tile : public Drawable
{
public:
    Tile(Position pos, int width, int height);
    virtual void draw(SDL_Renderer *renderer) const;
    
    Position pos();
    
private:
    Position pos_;
    int width_{};
    int height_{};
    SDL_Rect rect_;
};
