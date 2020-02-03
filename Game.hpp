#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Game {

    public:
        Game();
        ~Game();
        void loop();
//        void update();
        void render();
//       void input();
    private:
        SDL_Renderer* ren;
        SDL_Window* win;

        bool game_running;
        int count;
        
        int frame_count, timer_fps, last_frame;
};

#endif // GAME_H