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
    SDL_Texture* gameOverTexture;
    SDL_Event event;
    SDL_Color color = {255 , 255 , 255,255};
    TTF_Font* font;
    int Mx;
    int My;

    Button rePlayButton;
    Button quitButton;


    HighScore() : rePlayButton(200, 360 , SCREEN_WIDTH /2 - 50 , 400 ),quitButton(200, 460, SCREEN_WIDTH / 2 - 50, 500 ) {}

    void init(Graphics graphics) {
        bgETexture = graphics.loadTexture("end_pic.png");
        buttonTexture = graphics.loadTexture("button.png");
        font = graphics.loadFont("CottonCloud.ttf" , 50);
    }

    void handleEventMouse(GameLoop& game , Graphics graphics) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_MOUSEMOTION: {
                    SDL_GetMouseState(&Mx, &My);
                    rePlayButton.checkSelected(Mx, My);
                    quitButton.checkSelected(Mx, My);

                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    if (rePlayButton.isSelected) {
                        game.gameState = PLAY_STATE;
                        game.newGame(graphics);
                    } else if (quitButton.isSelected) {
                        exit(0);
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
        std::string highestScoreText = "Highest Score: " + std::to_string(highestScore);
        highestScoreTexture = graphics.renderText(highestScoreText.c_str(), font, color);
        graphics.renderTexture(highestScoreTexture , 30 , 15);

        std::string gameOverText = "GAME OVER !";
        gameOverTexture = graphics.renderText(gameOverText.c_str() , font , color);
        graphics.renderTexture(gameOverTexture , SCREEN_WIDTH/2 - 300  , SCREEN_HEIGHT/2 - 500);

        SDL_RenderPresent(graphics.renderer);

        SDL_DestroyTexture(highestScoreTexture);
        SDL_DestroyTexture(gameOverTexture);
    }

};
#endif // _HIGHSCORE__H
