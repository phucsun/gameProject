#ifndef _MENU__H
#define _MENU__H


#include "graphics.h"
#include "logic.h"

struct menu{
    SDL_Texture* menuTexture;
    SDL_Texture* buttonTexture;
    SDL_Event event;
    int Mx;
    int My;
    bool isSelected;

    void initMenu(Graphics graphics) {
        menuTexture = graphics.loadTexture("menu_game.jpg");
        buttonTexture = graphics.loadTexture("button.png");
        isSelected = false;
    }

    void handleMenuEvent(GameLoop& game) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&Mx , &My);
                if(Mx>= SCREEN_WIDTH/2 - 190 and My>=SCREEN_HEIGHT/2 -90) isSelected = true;
                else isSelected = false;
            }
            switch (event.type){
                case SDL_MOUSEBUTTONDOWN:
                    if(Mx>= SCREEN_WIDTH/2 - 190 and My>=SCREEN_HEIGHT/2 -90){
                        game.gameState = PLAY_STATE;
                    }
            }
        }
    }

    void drawMenu(Graphics& graphics) {
        SDL_RenderCopy(graphics.renderer , menuTexture , NULL , NULL);
        SDL_Rect src;
        src.x = 400;
        src.y = 0;
        src.w = 380;
        src.h = 180;
        if(isSelected) src.x = 400;

        else src.x = 0;
        graphics.blitRect(buttonTexture , &src , SCREEN_WIDTH/2 - 190 , SCREEN_HEIGHT/2 -90 );
        SDL_RenderPresent(graphics.renderer);
    }

};
#endif // _MENU__H
