#include "Text.hpp"

Text::Text()
{
    end_game = "Game Over.\nPlay Again?";
    character_selection = "Please Select A Character:\nPress 'B' for Bee and 'W' for Wasp.";

    TTF_Init();
    color = {0, 0, 0};
    font = TTF_OpenFont("corsiva.ttf", 12);
}

Text::~Text()
{
    TTF_Quit();
}

void Text::gameOver(int again_val)
{

}