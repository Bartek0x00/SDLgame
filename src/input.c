#include <SDL2/SDL.h>
#include "../head/bool.h"

extern bool isRunning;
extern bool Fullscreen;

void Input() {
	SDL_Event event;
	
	while(SDL_PollEvent(&event)) {

		if(event.type == SDL_QUIT) {
			isRunning = false;
		}
		
		const uint8_t *keystate = SDL_GetKeyboardState(NULL);

		if(keystate[SDL_SCANCODE_F10]) {
			Fullscreen = !Fullscreen;
			SDL_Delay(50);
		}
	}
}
