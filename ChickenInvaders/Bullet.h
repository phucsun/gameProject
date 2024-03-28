#ifndef _BULLET_H
#define _BULLET_H

#include "GameObject.h"
#include "defs.h"
#include "graphics.h"

class Bullet : public GameObject {
public:
   Bullet(int x, int y, int w, int h) : GameObject("arrow.png", x, y, w, h) {}

   void update();
};






#endif // _BULLET_H
