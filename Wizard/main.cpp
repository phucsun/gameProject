#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "input.h"
#include "graphics.h"
#include "logic.h"
#include "menu.h"
#include "highscore.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));

    Graphics graphics;
    graphics.init();
    HighScore high_score;
    high_score.init(graphics);

    Input input;
    input.initKeyBoard();
    input.initMouseButtons();

    GameLoop game;

    game.init(graphics);

    menu Menu;
    Menu.initMenu(graphics);

    bool quit = false;
    while(!quit){
        while(game.gameState == MENU_STATE){
            Menu.handleMenuEvent(game);
            Menu.drawMenu(graphics , game);
        }
        while(game.gameState == HELP_STATE){
            SDL_RenderCopy(graphics.renderer , game.helpTexture , NULL , NULL);
            SDL_RenderPresent(graphics.renderer);
            SDL_Event e;
            while(SDL_PollEvent(&e)){
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT) {
                        game.gameState = MENU_STATE;
                }
                if(e.type ==  SDL_QUIT) {
                    exit(0);
                    break;
                }
            }
        }
        while(game.gameState == PLAY_STATE){
            graphics.prepareScene();
            input.getInput();
            game.playGame(graphics , input);
            game.drawGame(graphics);
            graphics.presentScene();
            SDL_Delay(20);
        }
        while(game.gameState == DIE_STATE){
            high_score.handleEventMouse(game, graphics);
            high_score.drawEndGame(graphics , game);
        }
    }

    graphics.quit();
    return 0;
}
