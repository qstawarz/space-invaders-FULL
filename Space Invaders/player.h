#ifndef PLAYER_C
#define PLAYER_C

#include "display.h"
#include "bullet.h"

	typedef struct s_player
	{
		SDL_Texture *texture;
		SDL_Rect rect;
		t_bullet* bullet;
		int life;
	}t_player;

	bool initPlayer(t_player* player, t_display* display);
	bool loadPlayerImg(t_player* player, t_display* display);
	void movePlayer(const Uint8* state, t_player* player);
	void shootPlayer(const Uint8 * state, 
					 t_player* player, 
					 t_display* display);
	void drawPlayer(t_player* player, t_display* display);
	void destroy_player(t_player* player);

#endif
