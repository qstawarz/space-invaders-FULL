#include "enemy.h"

bool initEnemy(t_enemy* enemy, t_display* display)
{
    if (enemy == NULL) return false;

    enemy->rect.x = 590/2;
    enemy->rect.y = 10;
    enemy->rect.h = 50;
    enemy->rect.w = 50;
    enemy->bullet = NULL;
	enemy->down = false;
	enemy->left = true;
	enemy->rigth = false;
	enemy->life = 10;

    return (loadEnemyImg(enemy, display));
}

bool loadEnemyImg(t_enemy* enemy, t_display* display)
{
    if (enemy == NULL || display == NULL) return false;

    enemy->texture = IMG_LoadTexture(display->renderer,
									 "enemy.png");

    if (enemy->texture == NULL)
    {
        SDL_Log("Unable to load enemy image: %s\n", 
				SDL_GetError());
        return false;
    }
    return true;
}

void moveEnemy(t_enemy* enemy)
{
    if (enemy == NULL) return;	
    
	if (enemy->left == true && enemy->rect.x >= 10)
    {
        enemy->rect.x -= 2;
    }
	if (enemy->down == false && enemy->rect.x <=10)
	{
		enemy->rect.y += 10;
		enemy->down = true;
		enemy->left = false;
		enemy->rigth = true;
	}

    if (enemy->rigth == true && 
		enemy->down == true && 
		enemy->rect.x <= 580)
    {
        enemy->rect.x += 2;
    }
	if (enemy->down == true && enemy->rect.x >= 580)
	{
		enemy->rect.y += 10;
		enemy->down = false;
		enemy->left = true;
		enemy->rigth = false;
	}
}

void shootEnemy(t_enemy* enemy, t_display* display)
{
    if (enemy == NULL || display == NULL) return;

    if (enemy->bullet == NULL)
    {
        enemy->bullet = malloc(sizeof(t_bullet));
        if (enemy->bullet == NULL) return;

        initBullet(enemy->bullet, display);

        enemy->bullet->rect.x = enemy->rect.x + 22.5;
		enemy->bullet->rect.y = enemy->rect.y + 22.5;
    }
    if (enemy->bullet != NULL && enemy->bullet->rect.y <= 480)
    {
        enemy->bullet->rect.y += 7;
	}    
    if (enemy->bullet != NULL && enemy->bullet->rect.y >= 480)
    {
	    destroy_bullet(enemy->bullet);
        enemy->bullet = NULL;
    }
}

void drawEnemy(t_enemy* enemy, t_display* display)
{
    if (enemy == NULL || display == NULL) return;

    SDL_RenderCopy(display->renderer, 
				   enemy->texture, NULL, 
				   &enemy->rect);
}

void destroy_enemy(t_enemy* enemy)
{
    if (enemy == NULL) return;

    SDL_DestroyTexture(enemy->texture);
}
