#include "Text.hpp"

Text::Text()
{
    end_game = "Game Over.\nPlay Again?";

    TTF_Init();

    color = {0, 0, 0};
    font = TTF_OpenFont("Fonts/mayqueen.ttf", 72); // Possible "Update" would be to make this more dynamic.
}

Text::~Text()
{
    TTF_CloseFont(font);
    TTF_Quit();
}

void Text::gameOver(int again_val)
{

}

void Text::teamSelection(int sc_wdth, int sc_hth, SDL_Renderer& render, int event)
{   
    if(event == 1)
    {
        int siding = sc_wdth / 6;
        int flooring = sc_hth / 8;

        int mid_w = sc_wdth - (2 * siding);
        int mid_l = sc_hth - (2 * flooring);

        int top_y_1 = flooring * 2;
        int top_x = mid_w / 3;

        int top_y_2 = top_y_1 * 2;

        string character_pt1 = "Please Select A Character:";
        string character_pt2 = "Press 'B' for Bee and 'W' for Wasp.";


        SDL_Surface* character_pt1_surf = TTF_RenderText_Solid(font, character_pt1.c_str(), color);
        SDL_Surface* character_pt2_surf = TTF_RenderText_Solid(font, character_pt2.c_str(), color);

        SDL_Texture* character_pt1_text = SDL_CreateTextureFromSurface(&render, character_pt1_surf);
        SDL_Texture* character_pt2_text = SDL_CreateTextureFromSurface(&render, character_pt2_surf);

        SDL_QueryTexture(character_pt1_text, NULL, NULL, &mid_w, &mid_l);
        SDL_QueryTexture(character_pt2_text, NULL, NULL, &mid_w, &mid_l);

        SDL_Rect character_pt1_rect;
        character_pt1_rect.h = mid_l;
        character_pt1_rect.w = mid_w;
        character_pt1_rect.x = top_x;
        character_pt1_rect.y = top_y_1;

        SDL_Rect character_pt2_rect;
        character_pt2_rect.h = mid_l;
        character_pt2_rect.w = mid_w;
        character_pt2_rect.x = top_x;
        character_pt2_rect.y = top_y_2;


        SDL_RenderCopy(&render, character_pt1_text, NULL, &character_pt1_rect);
        SDL_RenderCopy(&render, character_pt2_text, NULL, &character_pt2_rect);

        SDL_DestroyTexture(character_pt1_text);
        SDL_DestroyTexture(character_pt2_text);

    }
}