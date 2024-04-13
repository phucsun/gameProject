#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "graphics.h"
#include "defs.h"
#include "GameObject.h"
#include "SpaceShip.h"
#include "SpaceShip.h"
#include "Enemy.h"
#include "BackGround.h"
#include "BackGroundPart.h"
#include "Bullet.h"
#include "BrokenEgg.h"
#include "Egg.h"
#include "GameManager.h"
#include "GameObject.h"

using namespace std;

Player* player_=nullptr;
vector<Enemy*> enemies_;
Background* background_ = nullptr;


int main(int argc, char *argv[])
{
    srand(time(0));
    Graphics graphics;
    graphics.init();
   player_ = new Player(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT - 100, 60, 60);
   background_ = new Background("space2.png");


   for (int i = 0; i < NUM_ENEMY; ++i) {
       enemies_.push_back(new Enemy(rand() % (SCREEN_WIDTH - 50), -(rand() % SCREEN_HEIGHT), 55, 55));
   }

   while (true) {
//       GameManager::GetGame->handleEvents();
//       GameManager::GetGame->update();
//       GameManager::GetGame->render();
       SDL_Delay(50);

       if (!player_->isAlive()) {
            cout << "Game Over! Your Score: " << player_->getScore() << endl;
            break;
        }
   }

//   GameManager::GetGame->cleanup();
   return 0;


}
