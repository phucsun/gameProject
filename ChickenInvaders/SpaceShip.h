#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "GameObject.h"

class Player : public GameObject {
private:
   int health;
   int score;
public:
   Player(int x, int y, int w, int h) : GameObject("rocket4.png", x, y, w, h),health(TURN) {}

   void moveLeft();

   void moveUp();

   void moveDown();

   void moveRight();
   void decreaseHealth();
   bool isAlive() const ;
   int getScore() const ;
   void increaseScore(int points);

};
#endif


