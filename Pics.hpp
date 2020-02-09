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


        map<int, string> files;

    private:
        vector<string> images;
        string path;


};




#endif // PICS_H