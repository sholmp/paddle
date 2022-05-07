#include "game.h"
#include "logger.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game(int window_width, int window_height) : window_width_(window_width), window_height_(window_height)
{
    SDL_CreateWindowAndRenderer(window_width_, window_height_, 0, &window_, &renderer_);
}

void Game::run()
{
    SDL_Event event;

    auto tiles = createTiles(50, 20, 5);
    std::cout << tiles.size() << std::endl;

    while (event.type != SDL_QUIT)
    {
        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer_);

        for (const Tile &t : tiles)
            t.draw(renderer_);

        SDL_RenderPresent(renderer_);
        while (SDL_PollEvent(&event))
        {
        }

        SDL_Delay(100);
    }
}

std::list<Tile> Game::createTiles(int tile_width, int tile_height, int num_rows)
{
    // ensure tiles fill out the entire width by squeezing extra tile in, if window width is not
    // evenly divisible width desired tile_width
    int num_cols = std::ceil(window_width_ / (double)tile_width);
    int adjusted_tile_width = window_width_ / num_cols;

    Logger::log("w {}, h {}, l {} --> num_rows {}, adjusted width {}", tile_width, tile_height, num_rows, num_cols, adjusted_tile_width);

    std::list<Tile> tiles;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            Tile t(Position(i * tile_height, j * tile_width), adjusted_tile_width, tile_height);
            tiles.push_back(t);
        }
    }

    return tiles;
}

Game::~Game()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    // delete window_;
    // delete renderer_;
}
