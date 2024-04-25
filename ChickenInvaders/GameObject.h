#ifndef _APP__H
#define _APP__H

#include<iostream>
#include<list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"

using namespace std;

struct GameObject {
	int x , y , w , h;
    float dx , dy;
	int side;
	int health;
	int reload;
	int state;
	int moveDirection;
	SDL_Texture *texture;

	bool checkCollision(GameObject* other);

    void player_move();
	void move();

    void AI_move(list<GameObject*>& bullets);

	bool offScreen();

	void initObject(int pos_x , int pos_y , int health_ , int reload_ , int side_);

};


#endif // _APP__H
