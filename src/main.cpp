#include <iostream>
#include "game.h"
#include "logger.h"


int main(int argc, char *argv[])
{
    Game game(800, 600);
    game.run();

    return 0;
}