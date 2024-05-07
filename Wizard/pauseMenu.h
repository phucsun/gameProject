#ifndef _PAUSEMENU__H
#define _PAUSEMENU__H


#include "button.h"
#include "graphics.h"

struct MenuP{
    SDL_Texture* buttonTexture,*pauseTexture;
    SDL_Event event;

    TTF_Font* font__;
    SDL_Color color__= {255,0,0,255};

    Button pauseButton;
    Button continueButton;
    int Mx;
    int My;
    bool paused;
    MenuP() : pauseButton(200, 780 , SCREEN_WIDTH - 100, 20 ) , continueButton(200, 1190 ,SCREEN_WIDTH - 100, 20) , paused(false) {}

    void initTexture(Graphics graphics){
        buttonTexture = graphics.loadTexture("button.png");
        font__ = graphics.loadFont("fontt.ttf" , 70);
    }

    void drawPauseButton(Graphics graphics){
        if(paused){
            string pauseText = "GAME IS PAUSED";
            pauseTexture = graphics.renderText(pauseText.c_str(), font__, color__);
            graphics.renderTexture(pauseTexture, SCREEN_WIDTH/2 - 250 , SCREEN_HEIGHT/2 - 220);

            continueButton.renderButton(graphics , buttonTexture);
        }
        if(!paused) pauseButton.renderButton(graphics , buttonTexture);
    }
};
#endif // _PAUSEMENU__H
