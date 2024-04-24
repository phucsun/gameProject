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

    Sprite man;
    SDL_Texture* manTexture = graphics.loadTexture("SPRITE2.png");
    man.init(manTexture , MAN_FRAMES , MAN_CLIPS);

    Input input;
    input.initKeyBoard();

    GameLoop game;
    game.init(graphics);

    while (true)
	{
	    man.tick();
		graphics.prepareScene();


		input.getInput();

		game.playGame(input.keyboard , graphics);
        game.drawGame(graphics);
        graphics.render(100 , 500 , man);

		graphics.presentScene();

		SDL_Delay(15);
	}
    SDL_DestroyTexture( manTexture ); manTexture = nullptr;
    graphics.quit();
    return 0;
}
