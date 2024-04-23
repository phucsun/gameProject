#ifndef _APP__H
#define _APP__H

#include<iostream>
#include<list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"

using namespace std;

struct Entity {
	int x;
	int y;
	int w;
	int h;
    float dx;
	float dy;
	int side;
	int health;
	int reload;
	int moveDirection;
	SDL_Texture *texture;

	bool collides(Entity* other) {
	    return (max(x, other->x) < min(x + w, other->x + other->w))
	        && (max(y, other->y) < min(y + h, other->y + other->h));
	}

	void move() {
	    x += dx;
	    y += dy;
	}

    void move_(list<Entity*>& bullets) {
        for(auto bullet : bullets) {
            if(bullet->side == 0){
                float distanceX = bullet->x - x;
                float distanceY = bullet->y - y;
                if(0<= distanceX and distanceX <= w and x-10>0 and x+w+10<SCREEN_WIDTH ){
                        x+= (rand()%3-2)*15;
                }
            }
        }
        x += moveDirection * 2;

        if (x <= 0 || x + w >= SCREEN_WIDTH){
            moveDirection *= -1;
        }

        y += 1;

        if (rand() % 100 < 2) {
            moveDirection *= -1;
        }

        if (y > SCREEN_HEIGHT || y < -h) {
            y = -h;
            x = rand() % (SCREEN_WIDTH - w);
            moveDirection = (rand() % 2 == 0) ? 1 : -1;
        }
    }

	bool offScreen() {
	     return x < -w || y < -h || x > SCREEN_WIDTH || y > SCREEN_HEIGHT;
	}
};


struct Star {
	int x;
	int y;
	int speed;
};
#endif // _APP__H
