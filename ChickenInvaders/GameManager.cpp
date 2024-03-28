#include "SDL.h"
#include "SDL_image.h"


#include<bits/stdc++.h>

#include "GameManager.h"
#include "Egg.h"
#include "Enemy.h"
#include "BrokenEgg.h"
#include "SpaceShip.h"
#include "Bullet.h"
#include "graphics.h"
#include "BackGround.h"

using namespace std;

Player* player = nullptr;
Graphics graphics;
Background* background = nullptr;



vector<GameObject*> eggs;
vector<Bullet*> bullets;
vector<Enemy*> enemies;
vector<GameObject*> BrokenEggs;



void GameManager::handleEvents()
{
    SDL_Event event;
   while (SDL_PollEvent(&event)) {
       switch (event.type) {
       case SDL_QUIT:
           exit(0);
           break;
       case SDL_KEYDOWN:
           if (player) {
               switch (event.key.keysym.sym) {
               case SDLK_LEFT:
                   player->moveLeft();
                   break;
               case SDLK_RIGHT:
                   player->moveRight();
                   break;
               case SDLK_UP:
                   player->moveUp();
                   break;
               case SDLK_DOWN:
                   player->moveDown();
                   break;
               case SDLK_SPACE:
                   bullets.push_back(new Bullet(player->getX() + player->getWidth() / 2 - 5, player->getY(), 13, 13));
                   break;
               }
           }
           break;
       }
   }
}

bool GameManager::checkCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    return SDL_HasIntersection(&a, &b);
}

void GameManager::update()
{
    vector<Bullet*> bulletsToRemove;
   vector<GameObject*> eggsToRemove;
   vector<GameObject*> BrokenEggsToRemove;
   vector<Enemy*> enemiesToRemove;
   for (auto& bullet : bullets) {
       bullet->update();
       if (bullet->getRect().y < 0) {
            bulletsToRemove.push_back(bullet);
        }
   }
   for (auto& egg : eggs) {
       egg->update();
       if (checkCollision(player->getRect(), egg->getRect())) {
           eggsToRemove.push_back(egg);
       }
   }
   for (auto& egg : eggs) {
       egg->update();
       if(checkCollision(player->getRect() , egg->getRect())){
           player->decreaseHealth();
       }
       if (egg->getY() >= SCREEN_HEIGHT - 30) {
           eggsToRemove.push_back(egg);
           BrokenEggs.push_back(new BrokenEgg(egg->getX(), egg->getY(), 30, 30));
       }
   }
   for(auto& BrokenEgg : BrokenEggs){
       BrokenEgg->update();
       if(!BrokenEgg->getIsAlive()){
           BrokenEggsToRemove.push_back(BrokenEgg);
       }
   }
   for (auto& enemy : enemies) {
       enemy->update();
       if(enemy->getRect().y > SCREEN_HEIGHT || !enemy->isAlive()){
            enemiesToRemove.push_back(enemy);
       }
       if(checkCollision(enemy->getRect() , player->getRect())){

       }
       for (auto& bullet : bullets) {
           if (checkCollision(bullet->getRect(), enemy->getRect())) {
               enemy->decreaseHealth();
               bulletsToRemove.push_back(bullet);
               if(!enemy->isAlive()){
                    player->increaseScore(10);
               }
               break;
           }
       }
       if (rand() % 100 == 0) {
           eggs.push_back(enemy->shootEgg());
       }
   }

   for (auto& bullet : bulletsToRemove) {
       bullets.erase(remove(bullets.begin(), bullets.end(), bullet), bullets.end());
       delete bullet;
   }

   for (auto& egg : eggsToRemove) {
       eggs.erase(remove(eggs.begin(), eggs.end(), egg), eggs.end());
       delete egg;
   }
   for (auto& BrokenEgg : BrokenEggsToRemove) {
       BrokenEggs.erase(remove(BrokenEggs.begin(), BrokenEggs.end(), BrokenEgg), BrokenEggs.end());
       delete BrokenEgg;
   }
   for (auto& enemy : enemiesToRemove) {
        enemies.erase(remove(enemies.begin(), enemies.end(), enemy), enemies.end());
        delete enemy;
    }
}

void GameManager::render()
{
    SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);
   SDL_RenderClear(graphics.renderer);

   background->update();
   background->render();
   if(player->isAlive()){
       player->render();
   }
   for (auto& bullet : bullets) {
       bullet->render();
   }
   for(auto&BrokenEgg : BrokenEggs){
       if(BrokenEgg->getIsAlive()){
           BrokenEgg->render();
       }
   }
   for (auto& egg : eggs) {
       egg->render();
   }

   for (auto& enemy : enemies) {
       if (enemy->isAlive()) {
           enemy->render();
       }
   }

   SDL_RenderPresent(graphics.renderer);
}

void GameManager::cleanup()
{
    for (auto& bullet : bullets) {
       delete bullet;
   }
   bullets.clear();

   for (auto& egg : eggs) {
       delete egg;
   }
   eggs.clear();
   for(auto& BrokenEgg : BrokenEggs){
       delete BrokenEgg;
   }
   BrokenEggs.clear();
   for (auto& enemy : enemies) {
       delete enemy;
   }
   enemies.clear();

   delete player;
   delete background;

   SDL_DestroyRenderer(graphics.renderer);
   SDL_DestroyWindow(graphics.window);
   IMG_Quit();
   SDL_Quit();
}
