#ifndef BULLET_C
#define BULLET_C

#include "display.h"

	typedef struct s_bullet
	{
		SDL_Texture* texture;
		SDL_Rect rect;
	}t_bullet;
		
	bool initBullet(t_bullet* bullet, t_display* display);
	bool loadBulletImg(t_bullet* bullet, t_display* display);
    void drawBullet(t_bullet* bullet, t_display* display);
	void destroy_bullet(t_bullet* bullet);

#endif
