#ifndef PICS_H
#define PICS_H

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

// SDL Requierments:
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Pics 
{
    public:
        Pics();
        ~Pics();

        void installTulips(SDL_Renderer& render);

        // Opening:
        void renderTitle(SDL_Renderer& render);

        // Main Game:
        void addNormalCharacters(SDL_Renderer& render);
        void addBall(int ball_x, int ball_y, SDL_Renderer& render);
        void addPaddels(int bee_paddle_y, SDL_Renderer& render, int wasp_paddle_y, int paddle_h);


        // Event:
        void Victory(SDL_Renderer& render, bool victor);


        // Etc.:
        void createBackground(SDL_Renderer& render);

        map<int, string> files;

        void getScreenSize(int sc_hth, int sc_wdth);

        int correctHeight(int ht);

        int ball_l, ball_w;

        int sc_hth, sc_wdth;

    private:
        vector<string> images;
        string path1;

        vector<string> addons;
        string path2;

        

};

#endif // PICS_H