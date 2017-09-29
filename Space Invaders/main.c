#include "game.h"

int main()
{
	t_game game;

	init_game(&game);

	game_run(&game);

	clean_game(&game);
		
	return 0;
}
