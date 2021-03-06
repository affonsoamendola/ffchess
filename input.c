#include <stdlib.h>

#include "stdio.h"
#include "SDL2/SDL.h"

#include "engine.h"
#include "cursor.h"

SDL_Event input_event;

char key_down[284];
char key_up[284];

int mouse_x_raw = 0;
int mouse_y_raw = 0;

void input_update()
{
	memset(key_down, 0, 284);
	memset(key_up, 0, 284);

	SDL_GetMouseState(&mouse_x_raw, &mouse_y_raw);

	while(SDL_PollEvent(&input_event))
	{
		if(	input_event.type == SDL_KEYDOWN)
		{
			if(input_event.key.repeat == 0) key_down[input_event.key.keysym.scancode] = true;

			switch(input_event.key.keysym.sym)
			{
				case SDLK_w:
					move_cursor(0, -1);
					break;
				case SDLK_s:
					move_cursor(0, 1);
					break;
				case SDLK_d:
					move_cursor(1, 0);
					break;
				case SDLK_a:
					move_cursor(-1, 0);
					break;
			}
		}

		if(	input_event.type == SDL_KEYUP)
		{
			if(input_event.key.repeat == 0) key_up[input_event.key.keysym.scancode] = true;
		}

		if( input_event.type == SDL_QUIT )
		{
			signal_quit();
			break;
		}
	}
}