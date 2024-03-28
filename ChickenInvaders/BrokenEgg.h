#ifndef _BROKENEGG_H
#define _BROKENEGG_H

#include "GameObject.h"


class BrokenEgg : public GameObject {
private:
   int lifeTime;
   bool isAlive;
public:
   BrokenEgg(int x, int y, int w, int h) : GameObject("egg2.png", x, y, w, h), lifeTime(1000) , isAlive(true){}
   void update();
   bool getIsAlive();
};

#endif // _BROKENEGG_H
