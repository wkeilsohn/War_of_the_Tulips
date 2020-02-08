#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>

// SDL Requierments:
#include <SDL2/SDL.h>

using namespace std;

class Game {

    public:
        Game(string title, int width, int height);
        ~Game();
        void loop();
//        void update();
        void render();
        void input();
    private:
        SDL_Renderer* ren;
        SDL_Window* win;

        bool game_running;
        int count;
        
        int frame_count, timer_fps, last_frame;

        int sc_wdth, sc_hth;
        bool full;
};

#endif // GAME_H