#include "Game.hpp"

Game::Game(string title, int width, int height)
{

    sc_wdth = width;
    sc_hth = height;

    Events ev;
    AI ai;

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

    paddle_speed = sc_hth / 8;

    player_paddle_y = (sc_hth / 2) - (sc_hth / 8);
    tmp_player_paddle_y = 0;

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
    /// Read Screen:
    ev.getScreenParameters(sc_hth, sc_wdth);
    ai.getParams(sc_hth, sc_wdth, paddle_speed, team, event, bee_paddle_y, wasp_paddle_y);

    // /// Adds the background color:
    SDL_RenderClear(ren);
    ev.p.createBackground(*ren);

    
    // /// Adds in the boarder Tulips:
    ev.p.installTulips(*ren);


    // /// Decides what to show:
    ev.callText(*ren, event);
    ev.showPoint(*ren, event, bee_score, wasp_score);

    // /// Add Paddels and Ball:
    ai.playBall(*ren, ball_x, ball_y, player_paddle_y);

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
                SDL_GetWindowSize(win, &sc_wdth, &sc_hth);
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
                tmp_player_paddle_y = 0 - paddle_speed; // Inverted axis.
                break;
            case SDLK_DOWN:
                tmp_player_paddle_y = 0 + paddle_speed;
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

    paddle_ball = ai.paddle_ball_loc;
    bee_paddle_y = paddle_ball[0];
    wasp_paddle_y = paddle_ball[1];
    player_paddle_y = paddle_ball[2] + tmp_player_paddle_y;
    ball_x = paddle_ball[3];
    ball_y = paddle_ball[4];

    selection = event;

    score = ev.callPoint(bee_score, wasp_score, ball_x, *ren);
    bee_score = score[0];
    wasp_score = score[1];

    event = ev.callEndGame(bee_score, wasp_score, event);
}
