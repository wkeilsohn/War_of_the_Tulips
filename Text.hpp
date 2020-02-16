#ifndef TEX_H
#define TEX_H

#include <iostream>
#include <stdio.h>
#include <string.h>

// Include SDL Libraries:
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Text
{
    public:
        Text();
        ~Text();

        void teamSelection(int sc_wdth, int sc_hth, SDL_Renderer& render, int event);
        void gameOver(int again_val);
        void displayScore(int score, bool team);

    private:
        string end_game;
        string score;

        string keepScore(int score);

        SDL_Color color;
        TTF_Font* font;
};



#endif // TEX_H