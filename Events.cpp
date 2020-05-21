#include "Events.hpp"

Events::Events()
{
    Pics p;
    Text txt;

    winer = false;
}

Events::~Events()
{
    // End Game.
}

void Events::callText(SDL_Renderer& render, int event)
{
    if(event != 0)
    {
        switch (event)
        {
        case 1:
            p.addNormalCharacters(render);
            txt.teamSelection(render);
            break;
        case 2:
            p.addNormalCharacters(render);
/*        
            if(!winer)
            {
                p.addNormalCharacters(render); // Puts them in shadows.
            }else
            {
                p.Victory(render, true); // Overlays them.
            }
*/ 
            break;                     
        case 3:
            p.addNormalCharacters(render);
            txt.gameOver(render); 
        default:
            break;
        }
    }else
    {
        p.renderTitle(render);
    }
    
}

vector<int> Events::callPoint(int bee_score, int wasp_score, int ball_x, SDL_Renderer& render)
{

    int side_1 = sc_wdth / 8;
    int side_2 = side_1 * 6;

    vector<int> score_vec;
    bool victor = false;

    if(ball_x <= side_1)
    {
        bee_score++;
        victor = true;
        p.Victory(render, victor);
        winer = true;
    }else if(ball_x >= side_2)
    {
        wasp_score++;
        p.Victory(render, victor);
        winer = true;
    }else
    {
        bee_score = bee_score;
        wasp_score = wasp_score;
        winer = false;
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

void Events::showPoint(SDL_Renderer& render, int event, int bee_score, int wasp_score)
{
    if(event >= 2)
    {
        txt.displayScore(render, bee_score, wasp_score);
    }
}

void Events::getScreenParameters(int sc_h, int sc_w)
{
    sc_wdth = sc_w;
    sc_hth = sc_h;

    txt.getScreenArea(sc_hth, sc_wdth);
    p.getScreenSize(sc_hth, sc_wdth);
}