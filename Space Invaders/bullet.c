#include "bullet.h"

bool initBullet(t_bullet* bullet, t_display* display)
{
    if (bullet == NULL) return false;
	
	bullet->rect.x = 0;
    bullet->rect.y = 420;
	bullet->rect.h = 5;
    bullet->rect.w = 5;

    return (loadBulletImg(bullet, display));
}

bool loadBulletImg(t_bullet* bullet, t_display* display)
{
	if (bullet == NULL || display == NULL) return false;

    bullet->texture = IMG_LoadTexture(display->renderer, 
									  "bullet.png");

    if (bullet->texture == NULL)
    {
        SDL_Log("Unable to load bullet image: %s\n", 
				SDL_GetError());
        return false;
    }
    return true;
}

void drawBullet(t_bullet* bullet, t_display* display)
{
    if (bullet == NULL || display == NULL) return;

    SDL_RenderCopy(display->renderer, 
				   bullet->texture, NULL, 
				   &bullet->rect);
}

void destroy_bullet(t_bullet* bullet)
{
	if (bullet == NULL) return;

    SDL_DestroyTexture(bullet->texture);
	free(bullet);
	bullet = NULL;
}
