//#ifndef _MENU__H
//#define _MENU__H
//
//
//#include "graphics.h"
//#include "logic.h"
//#include "button.h"
//
//struct menu{
//    SDL_Texture* menuTexture;
//    SDL_Texture* buttonTexture;
//    SDL_Event event;
//    int Mx;
//    int My;
//
//    Button PLay_Button;
//
//    PLay_Button(400,0);
//
//    void initMenu(Graphics graphics) {
//        menuTexture = graphics.loadTexture("menu_game.jpg");
//        buttonTexture = graphics.loadTexture("button.png");
//    }
//
//    void handleMenuEvent(GameLoop& game) {
//        while (SDL_PollEvent(&event) != 0) {
//            if (event.type == SDL_MOUSEMOTION) {
//                SDL_GetMouseState(&Mx , &My);
//                PLay_Button.CheckSelected(Mx,My);
//
//            }
//            switch (event.type){
//                case SDL_MOUSEBUTTONDOWN:
//                    if(PLay_Button.isSelected){
//                        game.gameState = PLAY_STATE;
//                    }
//            }
//        }
//    }
//
//    void drawMenu(Graphics& graphics) {
//        SDL_RenderCopy(graphics.renderer , menuTexture , NULL , NULL);
////        PLay_Button.checkSelected(Mx , My);
//        PLay_Button.renderButton(graphics , buttonTexture);
//        SDL_RenderPresent();
//    }
//
//};
//#endif // _MENU__H
//
#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include "logic.h"
#include "button.h"

struct menu {
    SDL_Texture* menuTexture;
    SDL_Texture* buttonTexture;
    SDL_Event event;
    int Mx;
    int My;

    Button playButton;
    Button exitButton;
    Button optionsButton;

    menu() : playButton(200, 0 , SCREEN_WIDTH /2 - 50 , 250),optionsButton(200,90,SCREEN_WIDTH/2 - 50 , 350),exitButton(200, 185, SCREEN_WIDTH / 2 - 50, 450 ) {}

    void initMenu(Graphics graphics) {
        menuTexture = graphics.loadTexture("menu_game.jpg");
        buttonTexture = graphics.loadTexture("button.png");
    }

    void handleMenuEvent(GameLoop& game) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_MOUSEMOTION: {
                    SDL_GetMouseState(&Mx, &My);
                    playButton.checkSelected(Mx, My);
                    exitButton.checkSelected(Mx, My);
                    optionsButton.checkSelected(Mx, My);
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    if (playButton.isSelected) {
                        game.gameState = PLAY_STATE;
                    } else if (exitButton.isSelected) {
                        exit(0);
                    } else if (optionsButton.isSelected) {
                        game.gameState = HELP_STATE;
                    }
                    break;
                }
                case SDL_QUIT: {
                    exit(0);
                    break;
                }
            }
        }
    }


    void drawMenu(Graphics& graphics) {
        SDL_RenderCopy(graphics.renderer, menuTexture, NULL, NULL);
        playButton.renderButton(graphics, buttonTexture);
        exitButton.renderButton(graphics, buttonTexture);
        optionsButton.renderButton(graphics , buttonTexture);
        SDL_RenderPresent(graphics.renderer);
    }
};

#endif // _MENU__H
