#include "Game.hpp"

Game::Game(string title, int width, int height)
{

    sc_wdth = width;
    sc_hth = height;

    Events ev;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(sc_wdth, sc_hth, 0, &win, &ren);
    SDL_SetWindowTitle(win, title.c_str());
    game_running = true;
    count = 0; // In-game Clock

    // Set Starting values
    team = true;
    event = 0;
    bee_score = 0;
    wasp_score = 0;


    loop(); // Begin Game.
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
//            count++; // Not sure if this is worth keeping?
        }
        

        render();
        input();
//        update();

        if(event > 2)
        {
            game_running = false;
        }
        
    }
    
}

void Game::render()
{
    // Add images to the screen:

    // /// Adds the background color:
    SDL_RenderClear(ren);
    ev.p.createBackground(*ren);

    
    // /// Adds in the boarder Tulips:
    ev.p.installTulips(sc_wdth, sc_hth, *ren);


    // /// Decides what to show based on user input:
    ev.callTitle(sc_wdth, sc_hth, *ren, event);

    // /// Push images to screen:
    SDL_RenderPresent(ren);

    // Determins Rendering Operation
    frame_count++;
    int timer_fps = SDL_GetTicks() - last_frame;

    if (timer_fps < (1000 / 60)) // Counts/Measures time.
    {
        SDL_Delay((1000 / 60) - timer_fps); // Determines frame rate...in a round about sort of way.
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
                break;
            case SDLK_SPACE:
                event++; // You can quit the game (in addition to passing the title) by hitting the space bar.
                break;
            case SDLK_w:
                team = false;
                event++; // Cheating prevention.
                break;
            case SDLK_b:
                team = true;
                event++;
                break;
            case SDLK_y:
                if(event == 2)
                {
                    event = 0; // Reset game
                    bee_score = 0;
                    wasp_score = 0;
                }else
                {
                    event++;
                }
                break;
            case SDLK_n:
                game_running = false;
                break;
            case SDLK_UP:
                player_paddle_x = player_paddle_x + paddle_speed;
                break;
            case SDLK_DOWN:
                player_paddle_x = player_paddle_x - paddle_speed;
            default:
                break;
            }
        }
    }
}


/*
void Game::update()
{
    // Add points and update variables.
}
*/