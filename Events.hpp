#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

// SDL Requierments:
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Reliant Classes
#include "Pics.hpp"

using namespace std;

class Events
{
    public:
        Events();
        ~Events();
//        bool determineScreen(int sc_wdth, int sc_hth, SDL_Renderer& render, int ball_x, int ball_y, int bee_paddle_x, int bee_paddle_y, int wasp_paddle_x, int wasp_paddle_y, int team, int bee_score, int wasp_score);

        // Image Management Public:
        Pics p;

        // Major game Events:    
        void callTitle(int sc_wdth, int sc_hth, SDL_Renderer& render, int event);
//        void callPlayerChoice();
        void callPoint();
        void callEndGame(int bee_score, int wasp_score);


};

#endif // EVENTS_H