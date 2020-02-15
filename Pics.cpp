#include "Pics.hpp"

Pics::Pics()
{   
    IMG_Init(IMG_INIT_PNG);


    path1 = "Images/Drawn/"; // Correct Address!
    images = {"Title.png", "Bee1.png", "Bee2.png", "Bee3.png", "Grub.png", "Tulip1.png", "Wasp.png", "Wasp2.png", "Wasp3.png", "Top_Flowers.png", "Bottom_Flowers.png"};

    int index = 0;

    for(string i: images)
    {
        string im_val = path1 + i;
        files[index] = im_val;
        index++;
    }

    IMG_Init(IMG_INIT_JPG);

    path2 = "Images/Additional/";
    addons = {"Background.jpg"};

    for(string j: addons)
    {
        string add_vals = path2 + j;
        files[index] = add_vals;
        index++;
    }
    
}

Pics::~Pics()
{
    IMG_Quit();
}

void Pics::installTulips(int sc_wdth, int sc_hth, SDL_Renderer& render)
{

    int h_quater = sc_hth / 8;

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

}

void Pics::renderTitle(int sc_wdth, int sc_hth, SDL_Renderer& render)
{

    int mid_hth = sc_hth / 8;
    int mid_sec = sc_hth - (2 * mid_hth);

    SDL_Rect title;
    title.x = 0;
    title.y = mid_hth;
    title.w = sc_wdth;
    title.h = mid_sec;

    SDL_Surface* title_surf = IMG_Load(files[0].c_str());
    SDL_Texture* title_text = SDL_CreateTextureFromSurface(&render, title_surf);
    SDL_RenderCopy(&render, title_text, NULL, &title);
}

void Pics::addNormalCharacters(int sc_wdth, int sc_hth, SDL_Renderer& render)
{
    int lft_thrd = sc_wdth / 6;
    int rgt_thrd = sc_wdth - lft_thrd;

    int top = sc_hth / 8;
    int fill_hth = sc_hth - (2 * top);

    SDL_Rect bee_rect;
    bee_rect.x = 0;
    bee_rect.y = top;
    bee_rect.h = fill_hth;
    bee_rect.w = lft_thrd;

    SDL_Rect wasp_rect;
    wasp_rect.w = lft_thrd;
    wasp_rect.h = fill_hth;
    wasp_rect.x = rgt_thrd;
    wasp_rect.y = top;

    SDL_Surface* bee_surface = IMG_Load(files[3].c_str());
    SDL_Surface* wasp_surface = IMG_Load(files[8].c_str());

    SDL_Texture* bee_text = SDL_CreateTextureFromSurface(&render, bee_surface);
    SDL_Texture* wasp_text = SDL_CreateTextureFromSurface(&render, wasp_surface);

    SDL_RenderCopy(&render, bee_text, NULL, &bee_rect);
    SDL_RenderCopy(&render, wasp_text, NULL, &wasp_rect);
}

void Pics::Victory(int sc_wdth, int sc_hth, SDL_Renderer& render, bool victor)
{
    int lft_thrd = sc_wdth / 6;
    int rgt_thrd = sc_wdth - lft_thrd;

    int top = sc_hth / 8;
    int fill_hth = (6 * (sc_hth / 8));

    SDL_Rect bee_rect;
    bee_rect.x = 0;
    bee_rect.y = top;
    bee_rect.h = fill_hth;
    bee_rect.w = lft_thrd;

    SDL_Rect wasp_rect;
    wasp_rect.w = lft_thrd;
    wasp_rect.h = fill_hth;
    wasp_rect.x = rgt_thrd;
    wasp_rect.y = top;

    int b, w;

    if(victor)
    {
        b = 1;
        w = 7;
    } else {
        b = 2;
        w = 6;
    }

    SDL_Surface* bee_surface = IMG_Load(files[b].c_str());
    SDL_Surface* wasp_surface = IMG_Load(files[w].c_str());

    SDL_Texture* bee_text = SDL_CreateTextureFromSurface(&render, bee_surface);
    SDL_Texture* wasp_text = SDL_CreateTextureFromSurface(&render, wasp_surface);

    SDL_RenderCopy(&render, bee_text, NULL, &bee_rect);
    SDL_RenderCopy(&render, wasp_text, NULL, &wasp_rect);
}

void Pics::createBackground(SDL_Renderer& render)
{
    SDL_Surface* back_surf = IMG_Load(files[11].c_str());
    SDL_Texture* back_text = SDL_CreateTextureFromSurface(&render, back_surf);
    SDL_RenderCopy(&render, back_text, NULL, NULL); 
}

void Pics::addBall(int ball_x, int ball_y, SDL_Renderer& render, int sc_wdth, int sc_hth)
{
    int ratio = 20;
    int size_w = sc_wdth / ratio;
    int size_h = sc_hth / ratio;

    SDL_Rect ball;
    ball.x = ball_x;
    ball.y = ball_y;
    ball.w = size_w;
    ball.h = size_h;

    SDL_Surface* ball_surface = IMG_Load(files[5].c_str());
    SDL_Texture* ball_text = SDL_CreateTextureFromSurface(&render, ball_surface);
    SDL_RenderCopy(&render, ball_text, NULL, &ball);
}