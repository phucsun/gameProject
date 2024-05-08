#ifndef _HIGHSCORE__H
#define _HIGHSCORE__H

#include "graphics.h"
#include "logic.h"
#include "button.h"
#include "GameObject.h"
#include <fstream>
#include <string>
#include <iostream>


struct HighScore{
    SDL_Texture* bgETexture;
    SDL_Texture* buttonTexture;
    SDL_Texture* highestScoreTexture;
    SDL_Texture* gameOver;
    SDL_Texture* frame;
    SDL_Event event;
    SDL_Color color = {255 , 0 , 0 ,255};
    TTF_Font* font;
    TTF_Font* font_;
    int Mx;
    int My;

    Button rePlayButton;
    Button quitButton;
    Button backButton;


    HighScore() : rePlayButton(200, 360 , 250 , 400 ),quitButton(200, 460, 250 , 500 ) , backButton(200,275 , 250 , 300) {}

    void init(Graphics graphics) {
        bgETexture = graphics.loadTexture("end_pic.png");
        buttonTexture = graphics.loadTexture("button.png");
        font = graphics.loadFont("Space Nation.ttf" , 50);
        frame = graphics.loadTexture("hg.png");
        font_ = graphics.loadFont("Mario-Party-Hudson-Font.ttf" , 150);
    }

    void handleEventMouse(GameLoop& game , Graphics graphics) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_MOUSEMOTION: {
                    SDL_GetMouseState(&Mx, &My);
                    rePlayButton.checkSelected(Mx, My);
                    quitButton.checkSelected(Mx, My);
                    backButton.checkSelected(Mx,My);
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    if (rePlayButton.isSelected) {
                        game.gameState = PLAY_STATE;
                        game.newGame(graphics);
                    } else if (quitButton.isSelected) {
                        exit(0);
                    } else if(backButton.isSelected){
                        game.gameState = MENU_STATE;
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
    void drawEndGame(Graphics& graphics , GameLoop& game) {
        std::ifstream highscoreFile("highscore.txt");
        int highestScore = 0;
        if (highscoreFile.is_open()) {
            std::string scoreStr;
            if (std::getline(highscoreFile, scoreStr)) {
                highestScore = std::stoi(scoreStr);
            }
            highscoreFile.close();
        }
        SDL_RenderCopy(graphics.renderer, bgETexture, NULL, NULL);
        rePlayButton.renderButton(graphics, buttonTexture);
        quitButton.renderButton(graphics, buttonTexture);
        backButton.renderButton(graphics , buttonTexture);
        graphics.renderTexture(frame , SCREEN_WIDTH - 500 , SCREEN_HEIGHT/2 - 200);
        std::string highestScoreText = std::to_string(highestScore);
        highestScoreTexture = graphics.renderText(highestScoreText.c_str(), font, color);
        graphics.renderTexture(highestScoreTexture , SCREEN_WIDTH - 290  , SCREEN_HEIGHT/2 - 10);

        std::string gameOverText = "GAME OVER";
        gameOver = graphics.renderText(gameOverText.c_str(), font_, color);
        graphics.renderTexture(gameOver , 10  , 100);

        SDL_RenderPresent(graphics.renderer);

        SDL_DestroyTexture(highestScoreTexture);
        SDL_DestroyTexture(gameOver);
    }

};
#endif // _HIGHSCORE__H
