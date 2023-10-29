#include <SDL2/SDL.h>

extern SDL_Renderer *renderer;

int FrameCount = 0, LastFrame = 0, ScreenWidth = 0, ScreenHeight = 0;

void Draw(){
    
	SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    ScreenWidth = DM.w;
    ScreenHeight = DM.h;

	SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);

	SDL_Rect rect;

 	rect.x = 0;
 	rect.y = 0;
 	rect.w = ScreenWidth;
 	rect.h = ScreenHeight;

 	SDL_RenderFillRect(renderer, &rect);
    
	FrameCount ++;

	int TimerFPS = SDL_GetTicks() - LastFrame;

	if(TimerFPS < (1000/60))
 	{
 		SDL_Delay((1000/60) - TimerFPS);
 	}

 	SDL_RenderPresent(renderer);
}
