#ifndef _EGG_H
#define _EGG_H

#include "GameObject.h"
#include "defs.h"
#include "graphics.h"
#include<vector>




class Egg : public GameObject {
public:
   Egg(int x, int y, int w, int h) : GameObject("egg.png", x, y, w, h){}

   void update();
};


#endif // _EGG_H
