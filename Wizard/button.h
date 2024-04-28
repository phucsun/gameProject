#ifndef _BUTTON__H
#define _BUTTON__H

#include "SDL.h"
#include "graphics.h"

struct Button {
    SDL_Rect src;
    SDL_Rect dest;
    bool isSelected;

    Button(int x, int y , int x_, int y_) : isSelected(false) {
        src = { x, y, 190, 80 };
        dest = { x_, y_, 390, 80 };
    }

    void checkSelected(int Mx, int My) {
        if (dest.x <= Mx && Mx <= (dest.x + src.w) && dest.y <= My && My <= (dest.y + src.h)) {
            isSelected = true;
            src.x = 200;
        }
        else {
            isSelected = false;
            src.x = 0;
        }
    }

    void renderButton(Graphics graphics, SDL_Texture* texture) {
        graphics.blitRect(texture, &src, dest.x, dest.y);
    }
};

#endif // _BUTTON__H
