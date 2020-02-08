#include "Game.hpp"

Game::Game(string title, int width, int height)
{

    sc_wdth = width;
    sc_hth = height;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(sc_wdth, sc_hth, 0, &win, &ren);
    SDL_SetWindowTitle(win, title.c_str());
    game_running = true;
    count = 0; // In-game Clock
    loop();
}

Game::~Game() 
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop()
{
    while (game_running)
    {
        last_frame = SDL_GetTicks();
        static int last_time;

        if (last_frame >= (last_time + 1000))
        {
            last_time = last_frame;
            frame_count = 0;
            count++;
        }
        

        render();
        input();
//        update();
        
    }
    
}

void Game::render()
{

    SDL_SetRenderDrawColor(ren, 0, 0, sc_wdth, sc_hth);
    SDL_Rect rect;
    rect.x = rect.y=0;
    rect.w = sc_wdth;
    rect.h = sc_hth;
    SDL_RenderFillRect(ren, &rect);

    frame_count++;
    int timer_fps = SDL_GetTicks() - last_frame;

    if (timer_fps < (1000 / 60))
    {
        SDL_Delay((1000 / 60) - timer_fps);
    }

    SDL_RenderPresent(ren);
    
}

void Game::input()
{
    SDL_Event e;

    while(SDL_PollEvent( &e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            game_running = false;
        }
        else
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game_running = false;
                break;
            case SDLK_f:
                SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
                SDL_DisplayMode D;
                SDL_GetCurrentDisplayMode(0, &D);
                sc_wdth = D.w;
                sc_hth = D.h;
            default:
                break;
            }
        }
    }
}


/*
void Game::update()
{
    // Add items to screen.
}
*/