/*Libraries*/
#include <SDL2/SDL.h>
#include <stdio.h>
#define WIDTH 1280
#define HEIGHT 720

/*Var*/
SDL_Renderer* renderer;
SDL_Window* window;

int IsRunning = 0, FrameCount = 0, Fullscreen = 0, TimerFPS = 0, LastFrame = 0, FPS = 0, Windowscreen = 0; 

/*Functions*/
void Update()
{
    if(Fullscreen)
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    }

    if(Windowscreen)
    {
        SDL_SetWindowFullscreen(window, 0);
    }
}

void Input()
{
   SDL_Event event;
   while(SDL_PollEvent(&event))
   {
        if(event.type == SDL_QUIT)
        {
            IsRunning = 0;
        }
        
        const uint8_t *keystates = SDL_GetKeyboardState(NULL);

        if(keystates[SDL_SCANCODE_ESCAPE])
        {
            IsRunning = 0;
        }

        if(keystates[SDL_SCANCODE_F11])
        {
            Fullscreen = 0;
            Windowscreen = 1;
        }

        if(keystates[SDL_SCANCODE_F12])
        {
            Fullscreen = 1;
            Windowscreen = 0;
        }

   } 
}

void Draw()
{
    SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);
    
    SDL_Rect rect;
    
    rect.x = 0;
    rect.y = 0;
    rect.w = WIDTH;
    rect.h = HEIGHT;

    SDL_RenderFillRect(renderer, &rect);
    FrameCount ++;
    
    int TimerFPS = SDL_GetTicks() - LastFrame;
    
    if(TimerFPS < (1000/60))
    {
        SDL_Delay((1000/60) - TimerFPS);
    }

    SDL_RenderPresent(renderer);
}

/*Main function*/
int main(int argc, char* args[]) 
{
    IsRunning = 1;

    Fullscreen = 0;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Error occurred at SDL_Init():\n%s", SDL_GetError());
        exit(-1);
    }

    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0)
    {
        printf("Error ocurred at SDL_CreateWindowAndRenderer():\n%s", SDL_GetError());
        exit(-1);
    } 

    SDL_SetWindowTitle(window, "Game");

    SDL_ShowCursor(1);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    while(IsRunning) 
    {
        Update();

        Input();
        
        Draw();
    }

    /*Exit*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
