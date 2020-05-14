#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include <map>

// SDL Requierments:
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Reliant Classes
#include "Events.hpp"
#include "Text.hpp"
#include "AI.hpp"

using namespace std;

class Game 
{

    public:
        Game(string title, int width, int height);
        ~Game();
        void loop();
        void update();
        void render();
        void input();

    private:
        SDL_Renderer* ren;
        SDL_Window* win;

        // Game Management Variables:
        bool game_running;
        int count;

        int frame_count, timer_fps, last_frame;

        int sc_wdth, sc_hth;
        bool full;

        // Image Management Variables:
        Events ev;
        AI ai;


        int ball_x, ball_y;
        int paddle_speed, speed;

        // Game Play Management Variables:
        bool team;
        int event, selection;
        int bee_score, wasp_score;
        vector<int> score;

        int bee_paddle_y, wasp_paddle_y;
        int player_paddle_y, tmp_player_paddle_y;
        vector<int> paddle_ball;
};

#endif // GAME_H