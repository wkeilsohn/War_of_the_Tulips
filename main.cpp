#include <iostream>
#include <stdio.h>
#include <string.h>

// Import SDL
#include <SDL2/SDL.h>

// Include Game Files
#include "Game.hpp"

using namespace std;

// To run test: g++ *.cpp -g -pedantic -o Test -lSDL2
// ./Test
int main()
{
    Game g("War of the Tulips", 950, 1000);
    return 0;
}