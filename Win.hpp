#ifndef WIN_H
#define WIN_H

#include <iostream>
#include <string.h>
#include <vector>

// SDL Requierments:
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Reliant Classes
#include "Pics.hpp"

using namespace std;

class Win // Currently unused class.
{
    public:
        Win();
        ~Win();

        void showWiner(bool vic, SDL_Renderer& render);

        Pics p;

};

#endif // WIN_H