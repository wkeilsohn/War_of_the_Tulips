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

void Events::callPoint()
{
    // Add point and call point screen.
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