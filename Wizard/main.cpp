#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "input.h"
#include "graphics.h"
#include "logic.h"
#include "menu.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));

    Graphics graphics;
    graphics.init();


    Input input;
    input.initKeyBoard();

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
            }
        }
        while(game.gameState == PLAY_STATE){
            while (true)
            {
                graphics.prepareScene();


                input.getInput();

                game.playGame(input.keyboard , graphics);
                game.drawGame(graphics);
                graphics.presentScene();

                SDL_Delay(20);
            }
        }
    }

    graphics.quit();
    return 0;
}
