#include "game.h"
#include "logger.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std::chrono_literals;

Game::Game(int window_width, int window_height) : window_width_(window_width), window_height_(window_height)
{
    SDL_CreateWindowAndRenderer(window_width_, window_height_, 0, &window_, &renderer_);
    //    SDL_Window
}

bool Game::init()
{

    // Initialize SDL_ttf
    if (TTF_Init() < 0)
    {
        std::cout << "Error intializing SDL_ttf: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void Game::run()
{
    init();

    auto tiles = createTiles(50, 20, 5);
    std::cout << tiles.size() << std::endl;

    SDL_Event event;
    while (event.type != SDL_QUIT)
    {
        auto frame_start = std::chrono::system_clock::now();

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer_);

        auto new_end = tiles.remove_if([](Tile t)
                                       { return t.pos().x_ > 300; });
        for (const Tile &t : tiles)
            t.draw(renderer_);

        // display fps
        SDL_Rect rect;
        TTF_Font *font = TTF_OpenFont((std::string(FONTS_DIR) + "/OpenSans-Light.ttf").c_str(), 14);
        if (!font)
        {
            Logger::log("could not open font...");
            exit(-1);
        }

        SDL_Texture *fps_text;
        SDL_Surface *text_surf = TTF_RenderText_Solid(font, "foobarbaz", {255, 0, 0});

        fps_text = SDL_CreateTextureFromSurface(renderer_, text_surf);
        rect.w = text_surf->w;
        rect.h = text_surf->h;
        rect.x = 100;
        rect.y = 400;
        SDL_RenderCopy(renderer_, fps_text, &rect, nullptr);

        SDL_RenderPresent(renderer_);
        while (SDL_PollEvent(&event))
        {
        }
        SDL_DestroyTexture(fps_text);

        auto frame_end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);
        auto desired_frame_period = 1s;
        auto sleep_time = desired_frame_period - duration;
        std::cout << "sleeping for " << sleep_time.count() << std::endl;
        std::this_thread::sleep_for(sleep_time);
        auto time_after_sleep = std::chrono::system_clock::now();
        auto actual_period = time_after_sleep - frame_start;
        std::cout << "actual period: " << actual_period.count() << std::endl;

        SDL_Delay(100);

        SDL_FreeSurface(text_surf);
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
    for (int j = 0; j < num_cols; j++)
    {
        for (int i = 0; i < num_rows; i++)
        {
            Tile t(Position(j * adjusted_tile_width, i * tile_height), adjusted_tile_width, tile_height);
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
