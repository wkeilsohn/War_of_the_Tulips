#include "Text.hpp"

Text::Text()
{
    TTF_Init();

    color = {0, 0, 0};
    font = TTF_OpenFont("Fonts/mayqueen.ttf", 72); // Possible update would be to make this more dynamic.
    score_font = TTF_OpenFont("Fonts/SCRIPTIN.ttf", 16);
}

Text::~Text()
{
    TTF_CloseFont(font);
    TTF_Quit();
}

void Text::gameOver(SDL_Renderer& render)
{
        int siding = sc_wdth / 6;
        int flooring = sc_hth / 8;

        int mid_w = sc_wdth - (2 * siding);
        int mid_l = sc_hth - (2 * flooring);

        int top_y_1 = flooring * 2;
        int top_x = mid_w / 3;

        int top_y_2 = top_y_1 * 2;

        string game_pt1 = "Game Over!";
        string game_pt2 = "Play Again?";


        SDL_Surface* game_pt1_surf = TTF_RenderText_Solid(font, game_pt1.c_str(), color);
        SDL_Surface* game_pt2_surf = TTF_RenderText_Solid(font, game_pt2.c_str(), color);

        SDL_Texture* game_pt1_text = SDL_CreateTextureFromSurface(&render, game_pt1_surf);
        SDL_Texture* game_pt2_text = SDL_CreateTextureFromSurface(&render, game_pt2_surf);

        SDL_QueryTexture(game_pt1_text, NULL, NULL, &mid_w, &mid_l);
        SDL_QueryTexture(game_pt2_text, NULL, NULL, &mid_w, &mid_l);

        SDL_Rect game_pt1_rect;
        game_pt1_rect.h = mid_l;
        game_pt1_rect.w = mid_w;
        game_pt1_rect.x = top_x;
        game_pt1_rect.y = top_y_1;

        SDL_Rect game_pt2_rect;
        game_pt2_rect.h = mid_l;
        game_pt2_rect.w = mid_w;
        game_pt2_rect.x = top_x;
        game_pt2_rect.y = top_y_2;


        SDL_RenderCopy(&render, game_pt1_text, NULL, &game_pt1_rect);
        SDL_RenderCopy(&render, game_pt2_text, NULL, &game_pt2_rect);

        SDL_DestroyTexture(game_pt1_text);
        SDL_DestroyTexture(game_pt2_text);
}

void Text::teamSelection(SDL_Renderer& render)
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

void Text::displayScore(SDL_Renderer& render, int bee_score, int wasp_score)
{

        int siding = sc_wdth / 6;
        int flooring = sc_hth / 8;

        int mid_w = siding;
        int mid_l = flooring;

        int w_len = mid_w  / 2;
        int top_x = siding / 2;
             

        string score_pt1 = "Score: ";
        string bee_score_pt2 = to_string(bee_score);
        string wasp_score_pt2 = to_string(wasp_score);

        SDL_Surface* score_pt1_surf = TTF_RenderText_Solid(font, score_pt1.c_str(), color);
        SDL_Surface* bee_score_pt2_surf = TTF_RenderText_Solid(score_font, bee_score_pt2.c_str(), color);
        SDL_Surface* wasp_score_pt2_surf = TTF_RenderText_Solid(score_font, wasp_score_pt2.c_str(), color);

        SDL_Texture* score_pt1_text = SDL_CreateTextureFromSurface(&render, score_pt1_surf);
        SDL_Texture* bee_score_pt2_text = SDL_CreateTextureFromSurface(&render, bee_score_pt2_surf);
        SDL_Texture* wasp_score_pt2_text = SDL_CreateTextureFromSurface(&render, wasp_score_pt2_surf);

        SDL_QueryTexture(score_pt1_text, NULL, NULL, &w_len, &mid_l);
        SDL_QueryTexture(bee_score_pt2_text, NULL, NULL, &mid_w, &mid_l);
        SDL_QueryTexture(wasp_score_pt2_text, NULL, NULL, &mid_w, &mid_l);

        SDL_Rect bee_score_pt1_rect;
        bee_score_pt1_rect.h = mid_l;
        bee_score_pt1_rect.w = w_len;
        bee_score_pt1_rect.x = siding;
        bee_score_pt1_rect.y = flooring;

        SDL_Rect wasp_score_pt1_rect;
        wasp_score_pt1_rect.h = mid_l;
        wasp_score_pt1_rect.w = w_len;
        wasp_score_pt1_rect.x = siding * 4;
        wasp_score_pt1_rect.y = flooring;

        SDL_Rect bee_score_pt2_rect;
        bee_score_pt2_rect.h = mid_l;
        bee_score_pt2_rect.w = w_len / 4;
        bee_score_pt2_rect.x = siding + top_x;
        bee_score_pt2_rect.y = flooring;

        SDL_Rect wasp_score_pt2_rect;
        wasp_score_pt2_rect.h = mid_l;
        wasp_score_pt2_rect.w = w_len / 4;
        wasp_score_pt2_rect.x = top_x + (siding * 4);
        wasp_score_pt2_rect.y = flooring;


        SDL_RenderCopy(&render, score_pt1_text, NULL, &bee_score_pt1_rect);
        SDL_RenderCopy(&render, bee_score_pt2_text, NULL, &bee_score_pt2_rect);
        SDL_RenderCopy(&render, score_pt1_text, NULL, &wasp_score_pt1_rect);
        SDL_RenderCopy(&render, wasp_score_pt2_text, NULL, &wasp_score_pt2_rect);

        SDL_DestroyTexture(score_pt1_text);
        SDL_DestroyTexture(bee_score_pt2_text);
        SDL_DestroyTexture(wasp_score_pt2_text);
}

void Text::getScreenArea(int sc_h, int sc_w)
{
        sc_hth = sc_h;
        sc_wdth = sc_w;
}