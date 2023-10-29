#include "../head/bool.h"
#include <SDL2/SDL.h>

extern bool Fullscreen;
extern SDL_Window *window;

void Update() {
	switch((int)Fullscreen) {		
		case 1:
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			break;

		case 0:
			SDL_SetWindowFullscreen(window, 0);
			break;
	}
}
