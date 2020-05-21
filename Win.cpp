#include "Win.hpp"

Win::Win()
{
    Pics p;
}

Win::~Win()
{
    // Dealocate Space
}

void Win::showWiner(bool vic, SDL_Renderer& render)
{
/*
    int start_tic = SDL_GetTicks();
    int end_tic = SDL_GetTicks();

    while(start_tic < (end_tic + 10))
    {
        p.Victory(render, vic);
        end_tic = SDL_GetTicks();  
    }
*/
    p.Victory(render, vic);

}