#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include "GameObject.h"
#include "BackGroundPart.h"


class Background : public GameObject {
private:
   std::vector<BackgroundPart*> parts;

public:
   Background(const char* imagePath) : GameObject(imagePath, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) {
       for (int i = 0; i < 2; ++i) {
           parts.push_back(new BackgroundPart(imagePath, 0, i * SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT));
       }
   }

   void update(){
       for (auto& part : parts) {
           part->update();
       }
   }

   void render(){
       for (auto& part : parts) {
           part->render();
       }
   }

   ~Background() {
       for (auto& part : parts) {
           delete part;
       }
   }
};
#endif // _BACKGROUND_H

