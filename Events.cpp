#include "Events.hpp"

Events::Events()
{
    Pics p;
}

Events::~Events()
{
    // End Game.
}

void Events::callTitle(int sc_wdth, int sc_hth, SDL_Renderer& render, int event)
{
    if(event != 0)
    {
        p.addNormalCharacters(sc_wdth, sc_hth, render);
    }else
    {
        p.renderTitle(sc_wdth, sc_hth, render);
    }
    
}

//void Events::callPlayerChoice(){};

void Events::callPoint()
{
    // Add point and call point screen.
}

void Events::callEndGame(int bee_score, int wasp_score)
{
    //    
}