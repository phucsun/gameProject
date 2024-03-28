#ifndef _BACKGROUNDPATH_H
#define _BACKGROUNDPATH_H

#include "GameObject.h"

class BackgroundPart : public GameObject {
public:
   BackgroundPart(const char* imagePath, int x, int y, int w, int h) : GameObject(imagePath, x, y, w, h) {}

   void update(){
       rect.y += SPEED_CROLL;
       if (rect.y >= SCREEN_HEIGHT) {
           rect.y = -rect.h + 5;
       }
   }
};
#endif // __BACKGROUNDPATH_H

