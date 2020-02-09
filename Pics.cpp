#include "Pics.hpp"

Pics::Pics()
{   
    IMG_Init(IMG_INIT_PNG);

    path = "Images/Final/"; // Correct Address!
    images = {"Title.png", "Bee1.png", "Bee2.png", "Bee3.png", "Grub.png", "Tulip1.png", "Wasp.png", "Wasp2.png", "Wasp3.png", "Top_Flowers.png", "Bottom_Flowers.png"};

    int index = 0;

    for(string i: images)
    {
        string im_val = path + i;
        files[index] = im_val;
        index++;
    }
}

Pics::~Pics()
{
    IMG_Quit();
}

void Pics::installTulips(int sc_wdth, int sc_hth, SDL_Renderer& render)
{
    int h_quater = sc_hth / 4;

    SDL_Rect top_flow;
    top_flow.x = 0;
    top_flow.y = 0;
    top_flow.h = h_quater;
    top_flow.w = sc_wdth;

    int y_quarter = sc_hth - h_quater;

    SDL_Rect bottom_flow;
    bottom_flow.w = sc_wdth;
    bottom_flow.h = h_quater;
    bottom_flow.x = 0;
    bottom_flow.y = y_quarter;

    SDL_Surface* bottom_tulips_surf = IMG_Load(files[10].c_str());
    SDL_Surface* top_tulips_surf = IMG_Load(files[9].c_str());

    SDL_Texture* bottom_tulips_text = SDL_CreateTextureFromSurface(&render, bottom_tulips_surf);
    SDL_Texture* top_tulips_text = SDL_CreateTextureFromSurface(&render, top_tulips_surf);
    
    SDL_RenderCopy(&render, bottom_tulips_text, NULL, &bottom_flow);
    SDL_RenderCopy(&render, top_tulips_text, NULL, &top_flow);

    SDL_RenderPresent(&render);
}