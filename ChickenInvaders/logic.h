#ifndef _LOGIC__H
#define _LOGIC__H
#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "graphics.h"
#include "GameObject.h"
#include "Function.h"

struct GameLoop {

    GameObject player;
    list<GameObject*> bullets;
	list<GameObject*> fighters;

    SDL_Texture *bulletTexture, *enemyTexture, *enemyBulletTexture, *background;
    Mix_Chunk *gJump;

    int enemySpawnTimer;
    int stageResetTimer;

    int backgroundX = 0;

    void clean(list<GameObject*>& entities) {
        while (!entities.empty()) {
            GameObject* e = entities.front();
            entities.pop_front();
            if (e != &player) delete e;
        }
    }
    void newGame()
    {
        clean(fighters);
        clean(bullets);
        fighters.push_back(&player);
	    player.initObject(POS_X , POS_Y , 1 , 0 , SIDE_PLAYER);
        enemySpawnTimer = 0;
        stageResetTimer = FRAME_PER_SECOND * 3;
	}

    void init(Graphics& graphics)
    {
        player.texture = graphics.loadTexture("rocket4.png");
        SDL_QueryTexture(player.texture, NULL, NULL, &player.w, &player.h);

        bulletTexture = graphics.loadTexture("arrow.png");
        enemyTexture = graphics.loadTexture("chickenwater.png");
        enemyBulletTexture = graphics.loadTexture("egg.png");
        background = graphics.loadTexture("hallo.jpg");
        gJump = graphics.loadSound("jump.wav");
        newGame();
    }

    void PLAYER_ATTACK()
    {
        GameObject *bullet = new GameObject();
        bullets.push_back(bullet);
        bullet->texture = bulletTexture;
        SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

        bullet->initObject(player.x +40,player.y +88 - (player.h / 2) - (bullet->h / 2),1,0,SIDE_PLAYER);
        bullet->dx = PLAYER_BULLET_SPEED;
        player.reload = PLAYER_RELOAD;
    }

    void ENEMY_ATTACK(GameObject* enemy)
    {
        GameObject *bullet = new GameObject();
        bullets.push_back(bullet);
        bullet->texture = enemyBulletTexture;
        SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

        bullet->initObject(enemy->x + (enemy->w / 2) - (bullet->w / 2) ,enemy->y + (enemy->h / 2) - (bullet->h / 2) ,1,0,SIDE_ALIEN);

        SlopeCalculation(player.x + (player.w / 2), player.y + (player.h / 2) , enemy->x, enemy->y, &bullet->dx, &bullet->dy);
        bullet->dx *= ENEMY_BULLET_SPEED;
        bullet->dy *= ENEMY_BULLET_SPEED;

        enemy->reload = (rand() % FRAME_PER_SECOND * 2);
    }

    void handleEvents(int keyboard[] , Graphics graphics)
    {
        if (player.health == 0) return;

        player.dx = player.dy = 0;

        if (player.reload > 0) player.reload--;
        if (keyboard[SDL_SCANCODE_W])player.dy = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_S]) player.dy = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_A]) player.dx = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_D]) player.dx = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_UP] && player.reload == 0){
            PLAYER_ATTACK();
            graphics.play(gJump);
        }
    }

    bool bulletHitFighter(GameObject *b)
    {
        for (GameObject* fighter: fighters) {
            if (fighter->side != b->side && b->checkCollision(fighter)) {
                fighter->health = 0;
                return true;
            }
        }
        return false;
    }

    void doBullets()
    {
        auto it = bullets.begin();
        while (it != bullets.end()) {
            auto temp = it++;
            GameObject* b = *temp;
            b->move();
            if (bulletHitFighter(b) || b->offScreen()) {
                delete b;
                bullets.erase(temp);
            }
        }
    }

    void doEnemies() {
        for (GameObject* e: fighters) {
            if (e != &player && player.health != 0 && --e->reload <= 0)
                ENEMY_ATTACK(e);
        }
    }

    void spawnEnemies(void) {

        if (--enemySpawnTimer <= 0) {
            GameObject *enemy = new GameObject();
            fighters.push_back(enemy);
            enemy->x = SCREEN_WIDTH;
            enemy->y = rand() % SCREEN_HEIGHT;
            enemy->dx = -(2 + (rand() % 4));
            enemy->health = 1;
            enemy->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            enemy->side = SIDE_ALIEN;
            enemy->texture = enemyTexture;
            SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);

            enemySpawnTimer = 30 + (rand() % 60);
        }
    }

    void updateFighters(void)
    {
        auto it = fighters.begin();
        it++;

        for(auto it_ = it ; it_ != fighters.end() ;it_++) {
            GameObject* enemy = *it_;

            enemy->move();

            if (enemy->x < -enemy->w) enemy->health = 0;

            if (enemy->health == 0) {
                delete enemy;
                fighters.erase(it_);
                continue;
            }
        }

        player.move();
        if (player.x < 0) player.x = 0;
        else if (player.x >= SCREEN_WIDTH - player.w)
            player.x = SCREEN_WIDTH - player.w;
        if (player.y < 0) player.y = 0;
        else if (player.y >= SCREEN_HEIGHT - player.h)
            player.y = SCREEN_HEIGHT - player.h;
	}

	void scrollBackground(void) {
        if (--backgroundX < -SCREEN_WIDTH)
        {
            backgroundX = 0;
        }
    }

    void drawBackground(SDL_Renderer* renderer) {
        SDL_Rect dest;
        for (int x = backgroundX ; x < SCREEN_WIDTH ; x += SCREEN_WIDTH) {
            dest.x = x;
            dest.y = 0;
            dest.w = SCREEN_WIDTH;
            dest.h = SCREEN_HEIGHT;

            SDL_RenderCopy(renderer, background, NULL, &dest);
        }
    }

    void playGame(int keyboard[] , Graphics graphics) {
        scrollBackground();

        if (player.health == 0 && --stageResetTimer <= 0){
                newGame();
        }

        handleEvents(keyboard , graphics);
        updateFighters();
        doEnemies();
        doBullets();
        spawnEnemies();
    }

    void drawGame(Graphics& graphics)
    {
        drawBackground(graphics.renderer);

		for (GameObject* b: bullets)
            graphics.renderTexture(b->texture, b->x, b->y);

        for (GameObject* b: fighters)
            if (b->health > 0){
                graphics.renderTexture(b->texture, b->x, b->y);
            }
    }
};

#endif // _LOGIC__H
