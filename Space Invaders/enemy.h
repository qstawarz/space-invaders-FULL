#ifndef ENEMY_C
#define ENEMY_C

#include "display.h"
#include "bullet.h"

	typedef struct s_enemy
	{
		SDL_Texture *texture;
        SDL_Rect rect;
        t_bullet* bullet;
		bool down, left, rigth;
		int life;
	}t_enemy;

	bool initEnemy(t_enemy* enemy, t_display* display);
    bool loadEnemyImg(t_enemy* enemy, t_display* display);
    void moveEnemy(t_enemy* enemy);
    void shootEnemy(t_enemy* enemy, t_display* display);
    void drawEnemy(t_enemy* enemy, t_display* display);
    void destroy_enemy(t_enemy* enemy);

#endif 
