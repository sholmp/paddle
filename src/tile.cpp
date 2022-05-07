#include "tile.h"
#include <SDL2/SDL.h>

Tile::Tile(Position pos, int width, int height): pos_(pos), width_(width), height_(height)
{
    rect_.h = height_;
    rect_.w = width_;
    rect_.x = pos_.x_;
    rect_.y = pos_.y_; 
       
}

void Tile::draw(SDL_Renderer* renderer) const
{
     SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
     SDL_RenderDrawRect(renderer, &rect_);
}
