#include "player.h"

bool initPlayer(t_player* player, t_display* display)
{
	if (player == NULL) return false;

	player->rect.x = 590/2;
	player->rect.y = 425;
	player->rect.h = 50;
	player->rect.w = 50;
	player->bullet = NULL;
	player->life = 3;
	
	return (loadPlayerImg(player, display));
}

bool loadPlayerImg(t_player* player, t_display* display)
{
	if (player == NULL || display == NULL) return false;

    player->texture = IMG_LoadTexture(display->renderer,
									  "player.png");

    if (player->texture == NULL)
    {
        SDL_Log("Unable to load player image: %s\n",
				SDL_GetError());
        return false;
    }
    return true;
}

void movePlayer(const Uint8* state, t_player* player)
{
	if (state == NULL || player == NULL) return;

	if (state[SDL_SCANCODE_LEFT] && player->rect.x >= 10)
	{
		player->rect.x -= 5;
	}
	if (state[SDL_SCANCODE_RIGHT] && player->rect.x <= 580)
	{
		player->rect.x += 5;
	}
}	

void shootPlayer(const Uint8* state, t_player* player, t_display* display)
{
	if (state == NULL || player == NULL || display == NULL)
		return;
		
	if (state[SDL_SCANCODE_SPACE] && player->bullet == NULL)
	{
		player->bullet = malloc(sizeof(t_bullet));
    	if (player->bullet == NULL) return;

	   	initBullet(player->bullet, display);

		player->bullet->rect.x = player->rect.x + 22.5;	
	}
	if (player->bullet != NULL && player->bullet->rect.y >= 0)
	{
		player->bullet->rect.y -= 10;
	}
	if (player->bullet != NULL && player->bullet->rect.y <= 0)
	{
		destroy_bullet(player->bullet);
		player->bullet = NULL;	
	}
}

void drawPlayer(t_player* player, t_display* display)
{
	if (player == NULL || display == NULL) return;

	SDL_RenderCopy(display->renderer, 
				   player->texture, NULL, 
				   &player->rect);
}

void destroy_player(t_player* player)
{
	if (player == NULL) return;

	SDL_DestroyTexture(player->texture);
}
