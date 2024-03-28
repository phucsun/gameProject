#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "SpaceShip.h"

void Player::moveLeft()
{
    rect.x -= PLAYER_SPEED;
    if (rect.x < 0) rect.x = 0;
}

void Player::moveUp()
{
    rect.y -= PLAYER_SPEED;
    if (rect.y < 0) rect.y = 0;
}

void Player::moveDown()
{
    rect.y += PLAYER_SPEED;
    if (rect.y + rect.h > SCREEN_HEIGHT - 25 ) rect.y = SCREEN_HEIGHT - rect.h -25;
}

void Player::moveRight()
{
    rect.x += PLAYER_SPEED;
    if (rect.x + rect.w > SCREEN_WIDTH) rect.x = SCREEN_WIDTH - rect.w;
}

void Player::decreaseHealth()
{
    --health;
}

bool Player::isAlive () const
{
    return health>0;
}

int Player::getScore() const
{
    return score;
}

void Player::increaseScore(int points)
{
    score += points;
}
