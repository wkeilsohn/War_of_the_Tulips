#ifndef AI_H
#define AI_H

// General
#include <iostream>
#include <vector>

// Project Specific
#include "Pics.hpp"

using namespace std;

class AI
{
    public:
        AI();
        ~AI();

        // Player choice function:
        vector<int> movePaddles(SDL_Renderer& render, int player_paddle_y);

        // Gameplay Functions:
        vector<int> moveBall(int ball_x, int ball_y, SDL_Renderer& render);
        int moveEnemyPaddle(int y);
        int checkPaddle(int y);

        void checkCollision(int ball_x);
        
        void playBall(SDL_Renderer& render, int ball_x, int ball_y, int player_paddle_y);
        vector<int> paddle_ball_loc;

        // Additional Functions:
        void getParams(int sc_h, int sc_w, int speed, bool team, int event, int bee_y, int wasp_y, int ball_x, int ball_y);

    private:
        Pics p;

        int sc_hth, sc_wdth;
        int paddle_h;

        int max_y, min_y;

        int paddle_speed;
        bool paddle_dir;

        int ball_speed;
        vector<int> last_ball_pos;

        bool team;
        int event;

        int bee_y;
        int wasp_y;
};

#endif // AI_H