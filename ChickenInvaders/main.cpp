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

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
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

    while(game.gameState == MENU_STATE){
        Menu.handleMenuEvent(game);
        Menu.drawMenu(graphics);
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

    graphics.quit();
    return 0;
}
