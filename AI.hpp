#ifndef AI_H
#define AI_H

// General
#include <iostream>
#include <vector>

// Project Specific
#include "Pics.hpp"
//#include "Events.hpp"

using namespace std;

class AI
{
    public:
        AI();
        ~AI();

        // Player choice function:
        vector<int> movePaddles(bool team, int bee_y, int wasp_y, SDL_Renderer& render);

        // Gameplay Functions:
        vector<int> moveBall(int ball_x, int ball_y, int score, SDL_Renderer& render, int bee_y, int wasp_y);
        int moveEnemyPaddle(int y);
        int checkPaddle(int y);

        // Additional Functions:
        void getParams(int sc_h, int sc_w, int speed);

    private:
        Pics p;

        int sc_hth, sc_wdth;
        int paddle_h;

        int max_y, min_y;

        int paddle_speed;
        bool paddle_dir;
};

#endif // AI_H