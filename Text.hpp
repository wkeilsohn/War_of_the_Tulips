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

        void teamSelection(SDL_Renderer& render);
        void gameOver(SDL_Renderer& render);
        void displayScore(SDL_Renderer& render,  int bee_score, int wasp_score);

        void getScreenArea(int sc_hth, int sc_wdth);

    private:
        SDL_Color color;
        TTF_Font* font;
        TTF_Font* score_font;

        int sc_hth, sc_wdth;
};



#endif // TEX_H