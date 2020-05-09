#include "AI.hpp"

AI::AI()
{
    Pics p;

    paddle_dir = false;
}

AI::~AI()
{
    // Dealocate memory.
}

int AI::checkPaddle(int y)
{   
    if(y > max_y)
    {
        if((y + paddle_h) < min_y)
        {
            return y;
        }else
        {
            y = y - paddle_speed;
            y = checkPaddle(y);
        }
    }else if(y < max_y)
    {
        y = y + paddle_speed;
        y = checkPaddle(y);
    }else
    {
        return y;
    }
}

void AI::getParams(int sc_h, int sc_w, int spd, bool tm, int evt, int b_y, int w_y, int b_x, int bl_y)
{
    sc_hth = sc_h;
    sc_wdth = sc_w;

    paddle_h = sc_hth / 8;

    max_y = sc_hth / 8;
    min_y = (sc_hth / 8) * 7;

    paddle_speed = spd;

    team = tm;
    event = evt;

    wasp_y = w_y;
    bee_y = b_y;

    ball_speed = spd * (sc_wdth / sc_hth);

    last_ball_pos = {b_x, bl_y};

}

vector<int> AI::movePaddles(SDL_Renderer& render, int player_paddle_y)
{
    vector<int> paddle_values;

    if(team)
    {
        bee_y = player_paddle_y;
        bee_y = checkPaddle(bee_y);
        player_paddle_y = bee_y;

        wasp_y = moveEnemyPaddle(wasp_y);
    }else
    {
        wasp_y = player_paddle_y;
        wasp_y = checkPaddle(wasp_y);
        player_paddle_y = wasp_y;

        bee_y = moveEnemyPaddle(bee_y); 
    }

    p.addPaddels(bee_y, render, wasp_y, paddle_h);
    paddle_values = {bee_y, wasp_y, player_paddle_y};

    return paddle_values;
}

int AI::moveEnemyPaddle(int y)
{
    if(paddle_dir)
    {
        y = y + paddle_speed;
        if(y == checkPaddle(y))
        {
            paddle_dir = false;
            return y;
        }else
        {
            y = checkPaddle(y);
            return y;
        }
    }else
    {
        y = y - paddle_speed;
        if(y == checkPaddle(y))
        {
            paddle_dir = true;
            return y;
        }else
        {
            y = checkPaddle(y);
            return y;
        }
    }
}

bool AI::checkCollision(int ball_x)
{
    int bee_bottom = bee_y + paddle_h;
    int wasp_bottom = wasp_y + paddle_h;

    if((ball_x < bee_y) && (ball_x > bee_bottom))
    {
        return false;
    }else if((ball_x < wasp_y) && (ball_x > wasp_bottom))
    {
        return false;
    }else
    {
        return true;
    }  
}

vector<int> AI::moveBall(int ball_x, int ball_y, SDL_Renderer& render)
{
    vector<int> ball_pos;

    if(ball_y <= (2 * (sc_hth / 8)))
    {
        ball_y = ball_y + ball_speed;
        ball_dir_y = false;
    }else if((ball_y >= (7 * (sc_hth / 8))))
    {
        ball_y = ball_y - ball_speed;
        ball_dir_y = true;
    }else if(ball_dir_y)
    {
        ball_y = ball_y + ball_speed;
    }else
    {
        ball_y = ball_y - ball_speed;
    }
    
    bool coll = checkCollision(ball_x);

    if(coll)
    {
        if(ball_dir_x)
        {
            ball_x = ball_x - ball_speed;
            ball_dir_x = false;
        }else
        {
            ball_x = ball_x + ball_speed;
            ball_dir_x = true;
        }
    }else
    {
        if(ball_dir_x)
        {
            ball_x = ball_x + ball_speed;
        }else
        {
            ball_x = ball_x - ball_speed;
        }   
    }
    
    ball_pos = {ball_x, ball_y};

    return ball_pos;

}


void AI::playBall(SDL_Renderer& render, int ball_x, int ball_y, int player_paddle_y)
{
    vector<int> paddle_loc;
    vector<int> ball_loc;
    vector<int> paddle_ball_l;

    if(event == 1)
    {
        srand(time(0));
        int r_val = rand() % 2;

        if(r_val < 0.5)
        {
            ball_dir_x = true;
        }else
        {
            ball_dir_x = false;
        }
    }
    
    if(event == 2) 
    {
        paddle_loc = movePaddles(render, player_paddle_y);

        ball_loc = moveBall(ball_x, ball_y, render);
        p.addBall(ball_loc[0], ball_loc[1], render);

        paddle_ball_l.insert(paddle_ball_l.end(), paddle_loc.begin(), paddle_loc.end());
        paddle_ball_l.insert(paddle_ball_l.end(), ball_loc.begin(), ball_loc.end());

        paddle_ball_loc = paddle_ball_l;

    }else
    {
        int p_y = sc_hth - paddle_h;
        vector<int> filler = {p_y, p_y, p_y, sc_wdth/2, sc_hth/2};
        paddle_ball_loc = filler;
    }
    

}
