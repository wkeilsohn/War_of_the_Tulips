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
#include "Text.hpp"

using namespace std;

class Events
{
    public:
        Events();
        ~Events();

        // Image Management Public:
        Pics p;
        Text txt;

        // Major game Events:    
        void callText(int sc_wdth, int sc_hth, SDL_Renderer& render, int event);
        void showPoint(int sc_wdth, int sc_hth, SDL_Renderer& render, int event, int bee_score, int wasp_score);
        void callPoint();
        int callEndGame(int bee_score, int wasp_score, int event);


};

#endif // EVENTS_H