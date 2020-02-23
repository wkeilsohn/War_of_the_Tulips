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
    selection = 0;

    // Set Starting values
    team = true;
    event = 0;
    bee_score = 0;
    wasp_score = 0;

    ball_x = sc_wdth / 2; // These will need to be moved later.
    ball_y = sc_hth / 2;


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
        }
        

        render();
        input();
        update();

        if(event > 3)
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


    // /// Decides what to show:
    ev.callText(sc_wdth, sc_hth, *ren, event);
    ev.showPoint(sc_wdth, sc_hth, *ren, event, bee_score, wasp_score);

    // /// Push images to screen:
    SDL_RenderPresent(ren);

    // Determins Rendering Operation
    frame_count++;
    int timer_fps = SDL_GetTicks() - last_frame;

    if (timer_fps < (1000 / 60)) // Counts/Measures time.
    {
        SDL_Delay((1000 / 60) - timer_fps); // Determines frame rate...in a round about sort of way.
    }

    SDL_RenderClear(ren);
   
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
                if(event == 3)
                {
                    event = 0; // Reset game
                    bee_score = 0;
                    wasp_score = 0;
                    selection = 0;
                    team = false;
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



void Game::update()
{
    int ev_dif = event - selection;

    if(ev_dif >= 2)
    {
        event = event - 1;
    }else
    {
        event = event;
    }

    selection = event;

    score = ev.callPoint(sc_wdth, bee_score, wasp_score, ball_x, sc_hth, *ren);
    bee_score = score[0];
    wasp_score = score[1];

    event = ev.callEndGame(bee_score, wasp_score, event);
}
