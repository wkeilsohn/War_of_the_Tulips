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

void AI::getParams(int sc_h, int sc_w, int speed)
{
    sc_hth = sc_h;
    sc_wdth = sc_w;

    paddle_h = sc_hth / 8;

    max_y = sc_hth / 8;
    min_y = (sc_hth / 8) * 7;

    paddle_speed = speed;

}

vector<int> AI::movePaddles(bool team, int bee_y, int wasp_y, SDL_Renderer& render)
{
    vector<int> paddle_values;

    if(team)
    {
        bee_y = checkPaddle(bee_y);
        wasp_y = moveEnemyPaddle(wasp_y);
        p.addPaddels(bee_y, render, wasp_y, paddle_h);
    }else
    {
        wasp_y = checkPaddle(wasp_y);
        bee_y = moveEnemyPaddle(bee_y);
        p.addPaddels(bee_y, render, wasp_y, paddle_h);
    }

    paddle_values = {bee_y, wasp_y};

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

