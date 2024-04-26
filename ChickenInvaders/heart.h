#ifndef _HEART__H
#define _HEART__H

#include "defs.h"
#include "graphics.h"
#include "GameObject.h"

struct Heart{
    int x , y, w ,h ;
    SDL_Rect rect;


    void initHeart(int x_ , int y_ , int w_ ,int h_){
        rect.x = x_;
        rect.y = y_;
        rect.w = w_;
        rect.h = h_;
    }

    void drawHp(Graphics graphics){
        SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
        SDL_SetRenderDrawColor(graphics.renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(graphics.renderer, &rect);
    }
};
#endif // _HEART__H
