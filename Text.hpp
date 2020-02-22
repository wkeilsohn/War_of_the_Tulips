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

        void teamSelection(int sc_wdth, int sc_hth, SDL_Renderer& render);
        void gameOver(int sc_wdth, int sc_hth, SDL_Renderer& render);
        void displayScore(int sc_wdth, int sc_hth, SDL_Renderer& render,  int bee_score, int wasp_score);

    private:
        SDL_Color color;
        TTF_Font* font;
        TTF_Font* score_font;
};



#endif // TEX_H