#pragma once

#include "tile.h"
#include <list>
#include <memory>
#include <SDL2/SDL.h>


class Game
{
public:
    Game(int window_width, int window_height);
    void run(); // main loop is in here
    
    ~Game();
    
    Game(const Game& game) = delete;
    const Game& operator=(const Game&) = delete;
    Game(Game&& game) = delete;
    const Game& operator=(Game&&) = delete;
    
    std::list<Tile> createTiles(int tile_width, int tile_height, int num_rows);
private:
    
    int window_width_{};
    int window_height_{};
    SDL_Window* window_;
    SDL_Renderer* renderer_;
};