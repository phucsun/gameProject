#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Egg.h"

void Egg::update()
{
    rect.y+=EGG_SPEED;
}
