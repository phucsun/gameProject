#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Enemy.h"
#include "Egg.h"


void Enemy::update()
{
    rect.y += 1;

    if (rect.x <= 0 || rect.x + rect.w >= SCREEN_WIDTH) {
        moveDirection *= -1;
    }

    rect.x += moveDirection * 1;

    if (rect.y > SCREEN_HEIGHT) {
        rect.y = -rect.h;
        rect.x = rand() % (SCREEN_WIDTH - rect.w);
    }
}

void Enemy::decreaseHealth()
{
    --health;
}

Egg* Enemy::shootEgg(){return new Egg(rect.x + rect.w / 2 - 5, rect.y + rect.h, 13, 13);}

bool Enemy::isAlive() const{return health>0;}
















