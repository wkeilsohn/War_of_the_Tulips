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

        // Adjust images
        map<int, string> files;

    private:
        vector<string> images;
        string path;


};




#endif // PICS_H