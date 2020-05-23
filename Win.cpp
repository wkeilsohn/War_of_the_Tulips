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
    p.Victory(render, vic);
}