#include "Events.hpp"

Events::Events()
{
    Pics p;
    Text txt;
}

Events::~Events()
{
    // End Game.
}

void Events::callText(int sc_wdth, int sc_hth, SDL_Renderer& render, int event)
{
    if(event != 0)
    {
        p.addNormalCharacters(sc_wdth, sc_hth, render);
        switch (event)
        {
        case 1:
            txt.teamSelection(sc_wdth, sc_hth, render);
            break;
        case 3:
            txt.gameOver(sc_wdth, sc_hth, render); 
        default:
            break;
        }
    }else
    {
        p.renderTitle(sc_wdth, sc_hth, render);
    }
    
}

vector<int> Events::callPoint(int sc_wdth, int bee_score, int wasp_score, int ball_x)
{

    int side_1 = sc_wdth / 8;
    int side_2 = side_1 * 6;

    vector<int> score_vec;

    if(ball_x <= side_1)
    {
        bee_score++;
    }else if(ball_x >= side_2)
    {
        wasp_score++;
    }else
    {
        bee_score = bee_score;
        wasp_score = wasp_score;
    }

    score_vec = {bee_score, wasp_score};
    
    return score_vec;
}

int Events::callEndGame(int bee_score, int wasp_score, int event)
{
    if(bee_score == 5 || wasp_score == 5)
    {
        return 3;
    }else
    {
        return event;
    }
}

void Events::showPoint(int sc_wdth, int sc_hth, SDL_Renderer& render, int event, int bee_score, int wasp_score)
{
    if(event >= 2)
    {
        txt.displayScore(sc_wdth, sc_hth, render, bee_score, wasp_score);
    }
}