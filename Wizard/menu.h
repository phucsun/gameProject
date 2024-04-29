#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include "logic.h"
#include "button.h"
#include "GameObject.h"

struct menu {
    SDL_Texture* menuTexture;
    SDL_Texture* buttonTexture;
    SDL_Event event;

    int Mx;
    int My;

    Button playButton;
    Button exitButton;
    Button optionsButton;
    Button mixerONButton;
    Button mixerOFFButton;

    menu() : playButton(200, 0 , SCREEN_WIDTH /2 - 50 , 250),optionsButton(200,90,SCREEN_WIDTH/2 - 50 , 350),exitButton(200, 185, SCREEN_WIDTH / 2 - 50, 450 ) , mixerONButton(200 , 550 , 1000 , 380) , mixerOFFButton(200,640 , 1000 , 380){}

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
                    mixerONButton.checkSelected(Mx , My);
                    mixerOFFButton.checkSelected(Mx,My);

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
                    else if(mixerONButton.isSelected or mixerOFFButton.isSelected){
                        if(game.mixer == false) game.mixer = true;
                        else game.mixer = false;
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


    void drawMenu(Graphics& graphics , GameLoop& game) {
        SDL_RenderCopy(graphics.renderer, menuTexture, NULL, NULL);
        playButton.renderButton(graphics, buttonTexture);
        exitButton.renderButton(graphics, buttonTexture);
        optionsButton.renderButton(graphics , buttonTexture);
        if(game.mixer) mixerONButton.renderButton(graphics , buttonTexture);
        if(!game.mixer) mixerOFFButton.renderButton(graphics , buttonTexture);
        SDL_RenderPresent(graphics.renderer);
    }
};

#endif // _MENU__H
