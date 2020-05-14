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
    if(y >= max_y)
    {
        if((y + paddle_h) <= min_y)
        {
            return y;
        }else
        {
            y = min_y - paddle_h;
            return y;
        }
    }else
    {
        y = max_y;
        return y;
    }
    
}

void AI::getParams(int sc_h, int sc_w, int spd, bool tm, int evt, int b_y, int w_y)
{
    sc_hth = sc_h;
    sc_wdth = sc_w;

    paddle_h = sc_hth / 8;

    max_y = sc_hth / 4;
    min_y = (sc_hth / 4) * 3;

    paddle_speed = spd;

    team = tm;
    event = evt;

    wasp_y = w_y;
    bee_y = b_y;

    ball_speed = spd;
}

vector<int> AI::movePaddles(SDL_Renderer& render, int player_paddle_y)
{
    vector<int> paddle_values;
    int pp_y;

    if(team)
    {
        bee_y = checkPaddle(player_paddle_y);
        pp_y = bee_y;

        wasp_y = moveEnemyPaddle(wasp_y);
    }else
    {
        wasp_y = checkPaddle(player_paddle_y);
        pp_y = wasp_y;

        bee_y = moveEnemyPaddle(bee_y); 
    }

    p.addPaddels(bee_y, render, wasp_y, paddle_h);
    paddle_values = {bee_y, wasp_y, pp_y};

    return paddle_values;
}

int AI::moveEnemyPaddle(int y)
{
    if(paddle_dir)
    {
        y = y + paddle_speed;
        if(y == checkPaddle(y))
        {
            return y;
        }else
        {
            y = checkPaddle(y);
            paddle_dir = false;
            return y;
        }
    }else
    {
        y = y - paddle_speed;
        if(y == checkPaddle(y))
        {
            return y;
        }else
        {
            y = checkPaddle(y);
            paddle_dir = true;
            return y;
        }
    }
}

bool AI::checkCollision(int ball_x, int ball_y)
{
    int bee_bottom = bee_y + paddle_h;
    int wasp_bottom = wasp_y + paddle_h;
    
    int edge_w = sc_wdth / 6;
    int paddle_w = edge_w / 6;
    int spc = paddle_w / 2;
    int bee_x = edge_w + spc;
    int wasp_x = (sc_wdth - edge_w) - (paddle_w + spc);

    if(ball_x >= bee_x && ball_x <= (bee_x + paddle_w))
    {
        if(ball_y >= bee_y && ball_y <= bee_bottom)
        {
            return true;
        }else
        {
            return false;
        }     
    }else if(ball_x <= wasp_x && ball_x >= (wasp_x + paddle_w))
    {
        if(ball_y >= wasp_y && ball_y <= wasp_bottom)
        {
            return true;
        }else
        {
            return false;
        }
        
    }else
    {
        return false;
    }
}

vector<int> AI::moveBall(int ball_x, int ball_y, SDL_Renderer& render)
{
    vector<int> ball_pos;

    if(ball_y <= (sc_hth / 4))
    {
        ball_y = ball_y + ball_speed;
        ball_dir_y = true;
    }else if(ball_y >= (3 * (sc_hth / 4)))
    {
        ball_y = ball_y - ball_speed;
        ball_dir_y = false;
    }else if(ball_dir_y)
    {
        ball_y = ball_y + ball_speed;
    }else
    {
        ball_y = ball_y - ball_speed;
    }
    
    bool coll = checkCollision(ball_x, ball_y);

    if(coll)
    {
        if(ball_dir_x)
        {
            ball_x = ball_x - ball_speed;
            ball_dir_x = true;
        }else
        {
            ball_x = ball_x + ball_speed;
            ball_dir_x = false;
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

    p.getScreenSize(sc_hth, sc_wdth);

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
        int p_y = (sc_hth / 2) - (paddle_h / 2);
        vector<int> filler = {p_y, p_y, p_y, sc_wdth/2, sc_hth/2};
        paddle_ball_loc = filler;
    }
}
