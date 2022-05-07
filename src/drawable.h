#pragma once

class SDL_Renderer;

class Drawable
{
  virtual void draw(SDL_Renderer* renderer) const = 0;
};