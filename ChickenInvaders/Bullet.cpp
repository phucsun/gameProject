#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Bullet.h"
#include "defs.h"
#include "GameObject.h"

void Bullet::update()
{
    rect.y -= BULLET_SPEED;
}
