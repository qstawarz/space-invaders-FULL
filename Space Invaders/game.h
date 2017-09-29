#ifndef GAME_C
#define GAME_C

#include "string_safe_concatenate.h"
#include "int_to_alpha.h"

#include "display.h"
#include "player.h"
#include "enemy.h"

	typedef struct s_game
	{
		t_display display;
		t_player player;
		t_enemy enemy;
		bool run;
	}t_game;

	bool init_game(t_game* game);
	void game_run(t_game* game);
	void checkInput(t_game* game);
	void clean_game(t_game* game);
    void collision(t_game* game);
	void displayLife(t_game* game);

#endif
