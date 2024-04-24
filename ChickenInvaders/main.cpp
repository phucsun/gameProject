#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "input.h"
#include "graphics.h"
#include "logic.h"
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

    while (true)
	{
		graphics.prepareScene();


		input.getInput();

		game.playGame(input.keyboard , graphics);
        game.drawGame(graphics);
		graphics.presentScene();

		SDL_Delay(15);
	}

    graphics.quit();
    return 0;
}
