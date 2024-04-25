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
    GameObject boom;

    Sprite TURN;
    Sprite BACK;
    list<GameObject*> bullets;
	list<GameObject*> fighters;
	vector<Sprite*> animations;

    SDL_Texture *bulletTexture, *enemyTexture, *enemyBulletTexture, *background ,*boomTexture , *TURNTexture , *BACKTexture , *wizardTexture;
    Mix_Chunk *gShoot;
    Mix_Music *gMusic;

    int enemySpawnTimer;
    int stageResetTimer;

    int backgroundX=0;

    void clean(list<GameObject*>& entities) {
        while (!entities.empty()) {
            GameObject* e = entities.front();
            entities.pop_front();
            if (e != &player) delete e;
        }
    }

    void initAnimation(){
        animations.push_back(&TURN);
        animations.push_back(&BACK);
    }

    void newGame()
    {
        clean(fighters);
        clean(bullets);
// xóa animation
//        if (gMusic != nullptr) Mix_FreeMusic( gMusic );
//    if (gJump != nullptr) Mix_FreeChunk( gJump);
//        SDL_DestroyTexture( manTexture );
//        manTexture = nullptr;
        fighters.push_back(&player);
	    player.initObject(POS_X , POS_Y , 1 , 0 , SIDE_PLAYER);
	    boom.initObject(player.x , 0 - (rand()%5)*15 , 1 , 0 , SIDE_ALIEN );
	    TURN.init(TURNTexture , TURN_FRAMES , TURN_CLIPS);
	    BACK.init(BACKTexture , BACK_FRAMES , BACK_CLIPS);
	    initAnimation();
	    player.state = -1;
	    player.score = 0;
	    boom.health = 1;
	    boom.w = 55;
	    boom.h = 40;
        enemySpawnTimer = 0;
        stageResetTimer = FRAME_PER_SECOND * 3;

	}

    void init(Graphics& graphics)
    {
        player.texture = graphics.loadTexture("rocket4.png");
        SDL_QueryTexture(player.texture, NULL, NULL, &player.w, &player.h);
        wizardTexture = graphics.loadTexture("wizard_.png");
        bulletTexture = graphics.loadTexture("arrow.png");
        enemyTexture = graphics.loadTexture("chickenwater.png");
        enemyBulletTexture = graphics.loadTexture("egg.png");
        background = graphics.loadTexture("hallo.jpg");
        boomTexture = graphics.loadTexture("boom.png");
        TURNTexture = graphics.loadTexture("ANIMATION.png");
        BACKTexture = graphics.loadTexture("back_animation.png");
        gShoot = graphics.loadSound("jump.wav");
        gMusic = graphics.loadMusic("gamemusic.mp3");
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

        enemy->reload = (rand() % FRAME_PER_SECOND *2);
    }

    void handleEvents(int keyboard[] , Graphics graphics)
    {
        if (player.health == 0) return;

        player.dx = player.dy = 0;

        if (player.reload > 0) player.reload--;
        if (keyboard[SDL_SCANCODE_W])player.dy = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_S]) player.dy = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_A]){
            player.dx = -PLAYER_SPEED;
            BACK.tick();
            player.state = 1;
        }
        if (keyboard[SDL_SCANCODE_D]){
            player.dx = PLAYER_SPEED;
            player.state = 0;
            TURN.tick();
        }
        if (keyboard[SDL_SCANCODE_UP] && player.reload == 0){
            PLAYER_ATTACK();
            player.state = -1;

            graphics.play(gShoot);
        }
    }

    bool playerCollideObject(GameObject* player , GameObject* object){
        if(player->checkCollision(object)){
            player->health = 0;
            return true;
        }
        return false;
    }

    bool bulletHitFighter(GameObject *b)
    {
        for (GameObject* fighter: fighters) {
            if (fighter->side != b->side && b->checkCollision(fighter)) {
                player.score+=10;
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

    void doCollision_Enemy(){
        auto it = fighters.begin();
        it++;

        for(auto it_ = it ; it_ != fighters.end() ;it_++) {
            GameObject* enemy = *it_;

            if(playerCollideObject(&player , enemy)){
                it_ = fighters.erase(it_);
            }
        }
    }

    void doCollision_Boom(GameObject& Boom){
        if(playerCollideObject(&player,&Boom)){
            Boom.health = 0 ;
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
            enemy->x = SCREEN_WIDTH +(rand()%3)*enemy->w;
            enemy->y = (rand() % (630-270)) +270-62;
            enemy->dx = -1;
            enemy->health = 1;
            enemy->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            enemy->side = SIDE_ALIEN;
            enemy->texture = enemyTexture;
            SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);

            enemySpawnTimer = 200 + (rand() % 60);
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

        player.player_move();
        if (player.x < 0) player.x = 0;
        else if (player.x >= SCREEN_WIDTH - player.w)
            player.x = SCREEN_WIDTH - player.w;
        if (player.y < 0) player.y = 0;
        else if (player.y >= SCREEN_HEIGHT - player.h)
            player.y = SCREEN_HEIGHT - player.h;
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

    void upadteBoom(void) {
        boom.y += 12;

        if (boom.y >= SCREEN_HEIGHT)
        {
            boom.x = player.x;
            boom.y = 0 + boom.y - SCREEN_HEIGHT;
        }
    }

    void playGame(int keyboard[] , Graphics graphics) {
        graphics.play(gMusic);
        upadteBoom();
        if (player.health == 0 && --stageResetTimer <= 0){
                cerr<<player.score<<endl;
                newGame();
        }

        handleEvents(keyboard , graphics);
        updateFighters();
        doEnemies();
        doBullets();
        doCollision_Boom(boom);
        doCollision_Enemy();
        spawnEnemies();
    }

    void drawBoom(Graphics graphics) {
        if(boom.health!=0)graphics.renderTexture(boomTexture,boom.x,boom.y);
    }

    void drawGame(Graphics& graphics)
    {
        drawBackground(graphics.renderer);
        drawBoom(graphics);


		for (GameObject* b: bullets)
            graphics.renderTexture(b->texture, b->x, b->y);

        for (GameObject* b: fighters)
            if (b->health > 0 and b->side == SIDE_ALIEN){
                graphics.renderTexture(b->texture, b->x, b->y);
            }

        if(player.state == 1 and player.health!=0 ) graphics.render(player.x , player.y ,*animations[1]);
        if(player.state == 0 and player.health!=0) graphics.render(player.x , player.y ,*animations[0]);
        if(player.state == -1 and player.health!=0) graphics.renderTexture(wizardTexture , player.x , player.y);
    }
};

#endif // _LOGIC__H
