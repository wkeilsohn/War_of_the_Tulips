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

        void installTulips(int sc_wdth, int sc_hth, SDL_Renderer& render);

        // Opening:
        void renderTitle(int sc_wdth, int sc_hth, SDL_Renderer& render);

        // Main Game:
        void addNormalCharacters(int sc_wdth, int sc_hth, SDL_Renderer& render);
//        void addBall(int sc_wdth, int sc_hth, SDL_Renderer& render);


        // Event:
        void Victory(int sc_wdth, int sc_hth, SDL_Renderer& render, bool victor);

//      void endGame(int sc_wdth, int sc_hth, SDL_Renderer& render);

        // Etc.:
        void createBackground(SDL_Renderer& render);

        map<int, string> files;

    private:
        vector<string> images;
        string path1;

        vector<string> addons;
        string path2;
};

#endif // PICS_H