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
#include "Win.hpp"

using namespace std;

class Events
{
    public:
        Events();
        ~Events();

        // Image Management Public:
        Pics p;
        Text txt;
        Win w;

        void getScreenParameters(int sc_hth, int sc_wdth);

        // Major game Events:    
        void callText(SDL_Renderer& render, int event);
        void showPoint(SDL_Renderer& render, int event, int bee_score, int wasp_score);
        vector<int> callPoint(int bee_score, int wasp_score, int ball_x, SDL_Renderer& render);
        int callEndGame(int bee_score, int wasp_score, int event);


        private:
            int sc_hth, sc_wdth;

            bool winer;
            bool win_team;


};

#endif // EVENTS_H