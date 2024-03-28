#ifndef _GAMEOBJECT__H
#define _GAMEOBJECT__H


#include<vector>

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"

class GameObject {
protected:
   SDL_Rect rect;
   SDL_Texture* texture;
   SDL_Renderer* renderer;
   Graphics graphics;
public:
   GameObject(const char* imagePath, int x, int y, int w, int h) : rect({ x, y, w, h }) {
       texture = graphics.loadTexture(imagePath);
   }

   virtual ~GameObject() {
       SDL_DestroyTexture(texture);
   }

   virtual void update() {}
   virtual void render() {
       SDL_RenderCopy(renderer, texture, nullptr, &rect);
   }
   SDL_Rect getRect() {
       return rect;
   }
   SDL_Texture* getTexture(){
       return texture;
   }
   int getX() const { return rect.x; }
   int getY() const { return rect.y; }
   int getWidth() const { return rect.w; }
   int getHeight() const { return rect.h; }

   void setPosition(int x, int y) { rect.x = x; rect.y = y; }
   virtual bool getIsAlive(){}

};
#endif

