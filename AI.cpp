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

void AI::getParams(int sc_h, int sc_w, int speed, bool team, int event, int bee_y, int wasp_y, int ball_x, int ball_y)
{
    sc_hth = sc_h;
    sc_wdth = sc_w;

    paddle_h = sc_hth / 8;

    max_y = sc_hth / 8;
    min_y = (sc_hth / 8) * 7;

    paddle_speed = speed;

    team = team;
    event = event;

    wasp_y = wasp_y;
    bee_y = bee_y;

    ball_speed = speed * (sc_wdth / sc_hth);

    last_ball_pos = {ball_x, ball_y};

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
        p.addPaddels(bee_y, render, wasp_y, paddle_h);
    }else
    {
        wasp_y = player_paddle_y;
        wasp_y = checkPaddle(wasp_y);
        player_paddle_y = wasp_y;

        bee_y = moveEnemyPaddle(bee_y);
        p.addPaddels(bee_y, render, wasp_y, paddle_h);
    }

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

    int vert_dis = last_ball_pos[1] - ball_y;
    int horz_dis = last_ball_pos[0] - ball_x;

    if((vert_dis > 0) && (ball_y - ball_speed <= (sc_hth / 8)))
    {
        ball_y = ball_y - ball_speed;
    }else if(vert_dis > 0)
    {
        ball_y = ball_y + ball_speed;
    }else if((vert_dis < 0) && (ball_y + ball_speed >= (sc_hth / 8)))
    {
        ball_y = ball_y + ball_speed;
    }else
    {
        ball_y = ball_y - ball_speed;
    }

    bool coll = checkCollision(ball_x);

    if(coll)
    {
        if(horz_dis > 0)
        {
            ball_x = ball_x - ball_speed;
        }else
        {
            ball_x = ball_x + ball_speed;
        }
    }else
    {
        if(horz_dis > 0)
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

    if(event == 2)
    {
        paddle_loc = movePaddles(render, player_paddle_y);
        ball_loc = moveBall(ball_x, ball_y, render);

        paddle_ball_l.insert(paddle_ball_l.end(), paddle_loc.begin(), paddle_loc.end());
        paddle_ball_l.insert(paddle_ball_l.end(), ball_loc.begin(), ball_loc.end());

        paddle_ball_loc = paddle_ball_l;
    }else
    {
        vector<int> filler(5, 0);
        paddle_ball_loc = filler;
    }
    

}
