#include "Game.hpp"

Game::Game()
{
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(360, 240, 0, &win, &ren);
    SDL_SetWindowTitle(win, "War of the Tulips");
    game_running = true;
    count = 0;
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
//        input();
//        update();

        if (count > 10)
        {
            game_running = false;
        }
        
    }
    
}

void Game::render()
{

    SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
    SDL_Rect rect;
    rect.x = rect.y=0;
    rect.w = 360;
    rect.h = 240;
    SDL_RenderFillRect(ren, &rect);

    frame_count++;
    int timer_fps = SDL_GetTicks() - last_frame;

    if (timer_fps < (1000 / 60))
    {
        SDL_Delay((1000 / 60) - timer_fps);
    }

    SDL_RenderPresent(ren);
    
}