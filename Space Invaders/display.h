#ifndef DISPLAY_C
#define DISPLAY_C

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>

	typedef struct s_sdl_display
	{
		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* police;
	}t_display;

	bool initAll(t_display* display);
	bool initSDL();
	bool initSDLImg();
	bool initSDLWindow(t_display* display);
	bool initSDLRenderer(t_display* display);
	bool displayFont(t_display* display);
	void clean_display(t_display* display);	
	void clear_display(t_display* display);
	void update_display(t_display* display);

#endif
