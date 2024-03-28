#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameObject.h"
#include "defs.h"
#include "graphics.h"
#include "Egg.h"



extern std::vector<GameObject*> eggs;

class Enemy : public GameObject {
private:
   int health;
   int moveCounter;
   int moveDirection;

public:
   Enemy(int x, int y, int w, int h) : GameObject("chickenwater.png", x, y, w, h), health(ENEMY_HEALTH), moveCounter(0), moveDirection(1) {}

   void update() override ;

   void decreaseHealth() ;

   Egg* shootEgg() ;

   bool isAlive() const ;
};





#endif // _ENEMY_H
