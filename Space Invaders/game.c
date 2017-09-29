#include "game.h"


bool init_game(t_game* game)
{
	if (game == NULL) return false;
	
	game->run = true;
	
	return initAll(&game->display) & 
		   initPlayer(&game->player, &game->display) & 
		   initEnemy(&game->enemy, &game->display);
}

void game_run(t_game* game)
{
	if (game == NULL) return;

	while (game->run)
	{
		clear_display(&game->display);

		checkInput(game);

		SDL_PumpEvents();
	
		movePlayer(SDL_GetKeyboardState(NULL), &game->player);
		drawPlayer(&game->player, &game->display);
		shootPlayer(SDL_GetKeyboardState(NULL), 
					&game->player, &game->display);
		if (game->player.bullet != NULL) 
		{
			drawBullet(game->player.bullet, &game->display);		
		}
		
		moveEnemy(&game->enemy);
		drawEnemy(&game->enemy, &game->display);
		shootEnemy(&game->enemy, &game->display);
		if (game->enemy.bullet != NULL) 
		{
			drawBullet(game->enemy.bullet, &game->display);		
		}
		
		collision(game);	

		displayLife(game);
			
		update_display(&game->display);
	}
}

void checkInput(t_game* game)
{
	if (game == NULL) return;

	SDL_Event event;

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            game->run = false;
            break;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    game->run = false;
                    break;
                default:
                    break;
            }
        }
    }

}

void clean_game(t_game* game)
{
	if (game == NULL) return;
	
	destroy_bullet(game->player.bullet);
	destroy_enemy(&game->enemy);
	destroy_player(&game->player);
	clean_display(&game->display);
}

void collision(t_game* game)
{
	if (game == NULL) return;

	if (game->player.bullet != NULL)
	{
		if ((game->player.bullet->rect.x < game->enemy.rect.x + 50 && 
			game->player.bullet->rect.x > game->enemy.rect.x - 5) && 
			(game->player.bullet->rect.y < game->enemy.rect.y + 50 && 
			game->player.bullet->rect.y > game->enemy.rect.y))
		{
			destroy_bullet(game->player.bullet);
			game->player.bullet = NULL;
			game->enemy.life--;
	
			if (game->enemy.life == 0)
			{
				destroy_enemy(&game->enemy);
				game->run = false;
			}
		}
	}

	if (game->enemy.bullet != NULL)
	{
		if ((game->enemy.bullet->rect.x < game->player.rect.x + 50 && 
			game->enemy.bullet->rect.x > game->player.rect.x - 5) && 
			(game->enemy.bullet->rect.y < game->player.rect.y + 50 && 
			game->enemy.bullet->rect.y > game->player.rect.y))
		{
			destroy_bullet(game->enemy.bullet);
			game->enemy.bullet = NULL;
			game->player.life--;

			if (game->player.life == 0)
			{
				destroy_player(&game->player);
				game->run = false;
			}
		}
	}
	if (game->enemy.rect.y >= 380)
	{
		game->run = false;
	}
	if (game->enemy.bullet != NULL && game->player.bullet != NULL)
	{
		if ((game->enemy.bullet->rect.x < game->player.bullet->rect.x + 5 && 
			game->enemy.bullet->rect.x > game->player.bullet->rect.x - 5) && 
			(game->enemy.bullet->rect.y < game->player.bullet->rect.y + 5 && 
			game->enemy.bullet->rect.y > game->player.bullet->rect.y - 5))
		{
			destroy_bullet(game->enemy.bullet);
			game->enemy.bullet = NULL;
			destroy_bullet(game->player.bullet);
			game->player.bullet = NULL;

		}
	}
}

void displayLife(t_game* game)
{
    SDL_Color white = {255, 255, 255};

    char playerLife[20] = "Player Life : ";
    char* lifeNb = int_to_alpha(game->player.life);
    string_safe_concatenate(playerLife, lifeNb, 20);

    SDL_Surface* life = TTF_RenderUTF8_Solid(game->display.police, playerLife, white);
    SDL_Texture* lifeTex = SDL_CreateTextureFromSurface(game->display.renderer, life);

    int life_w, life_h;
    SDL_QueryTexture(lifeTex, NULL, NULL, &life_w, &life_h);

    SDL_Rect lifePos = {0, 480 - life_h, life_w, life_h};

    SDL_RenderCopy(game->display.renderer, lifeTex, NULL, &lifePos);

    free(lifeNb);
    SDL_FreeSurface(life);
    SDL_DestroyTexture(lifeTex);

}
