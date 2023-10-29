#include "settings.h"
#include "head/bool.h"
#include "head/stdfuncdef.h"
#include "head/update.h"
#include "head/input.h"
#include "head/draw.h"

#define INCLUDE_PUTS

SDL_Window *window;
SDL_Renderer *renderer;

bool isRunning = true, Fullscreen = false;

int main(int argc, char *argv[]) {

	/*Initialize SDL*/
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		puts("Error occured at SDL_Init:");
		puts(SDL_GetError());
		exit(-1);
	}
	
	window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	
	if(NULL == window) {
		puts("Error occured at SDL_CreateWindow:");
		puts(SDL_GetError());
		exit(-1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(NULL == renderer) {
		puts("Error occured at SDL_CreateRenderer:");
		puts(SDL_GetError());
		exit(-1);
	}
	SDL_ShowCursor(1);
	
	SDL_SetWindowMinimumSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

	/*Game loop*/
	while(isRunning) {
		
		Update();
		
		Input();
		
		Draw();
		
	}

	/*Quit*/
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);
	
	SDL_Quit();

	return 0;
}
