#include <iostream>
#include <stdio.h>
#include <string.h>

// Import SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Include Game Files
#include "Pics.hpp"
#include "Game.hpp"

using namespace std;

// To run test: g++ *.cpp -g -pedantic -o Test -lSDL2
// ./Test
int main()
{
    Game g("War of the Tulips", 1000, 1000);
    return 0;
}