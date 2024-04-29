#ifndef _LOGIC__H
#define _LOGIC__H
#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "SDL_ttf.h"
#include "defs.h"
#include "graphics.h"
#include "GameObject.h"
#include "Function.h"
#include "heart.h"

struct GameLoop {

    int gameState = MENU_STATE;

    GameObject player;
    GameObject boom;

    Sprite TURN;
    Sprite BACK;
    Sprite SHOOTING;
    Sprite exploision;
    Sprite Skill;
    Sprite Skill_2;

    bool mixer;

    Heart hp;
    list<GameObject*> bullets;
	list<GameObject*> fighters;
	vector<Sprite*> animations;

    SDL_Texture *bulletTexture, *enemyTexture, *enemyBulletTexture, *background ,*boomTexture , *TURNTexture , *BACKTexture , *wizardTexture
    ,*UPTexture , *DOWNTexture , *SHOOTTexture , *exploreTexture , *skillTexture , *skill_2Texture,*deadTexture ,*scoreTexture , *helpTexture;
    Mix_Chunk *gShoot;
    Mix_Music *gMusic;
    Mix_Chunk *gExploision;
    TTF_Font* font;

    SDL_Color color = {255, 255, 0, 0};

    int enemySpawnTimer;
    int stageResetTimer;

    int backgroundX=0;
    bool collisionHandled = false;

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
        animations.push_back(&SHOOTING);
        animations.push_back(&exploision);
        animations.push_back(&Skill);
        animations.push_back(&Skill_2);
    }

    void newGame()
    {
        //cleanUp();
        clean(fighters);
        clean(bullets);
        fighters.push_back(&player);
	    player.initObject(POS_X , POS_Y , 10 , 0 , SIDE_PLAYER);
	    boom.initObject(player.x , 0 - (rand()%5)*15 , 1 , 0 , SIDE_ALIEN );
	    TURN.init(TURNTexture , TURN_FRAMES , TURN_CLIPS);
	    BACK.init(BACKTexture , BACK_FRAMES , BACK_CLIPS);
	    SHOOTING.init(SHOOTTexture , SHOOT_FRAMES , SHOOT_CLIPS);
	    exploision.init(exploreTexture , EX_FRAMES , EX_CLIPS);
	    Skill.init(skillTexture , SKILL_FRAMES , SKILL_CLIPS);
	    Skill_2.init(skill_2Texture , SKILL_2_FRAMES , SKILL_2_CLIPS);
	    hp.initHeart(10,10,300,25);
	    initAnimation();
	    player.state = STAND_STATE;
	    player.score = 0;
	    boom.health = 1;
	    boom.w = BOOM_WIDTH;
	    boom.h = BOOM_HEIGHT;
        enemySpawnTimer = 0;
        mixer = true;
        stageResetTimer = FRAME_PER_SECOND * 3;

	}

    void init(Graphics& graphics)
    {
        player.texture = graphics.loadTexture("face.png");
        SDL_QueryTexture(player.texture, NULL, NULL, &player.w, &player.h);
        wizardTexture = graphics.loadTexture("face.png");
        bulletTexture = graphics.loadTexture("arrow.png");
        enemyTexture = graphics.loadTexture("chickenwater.png");
        enemyBulletTexture = graphics.loadTexture("egg.png");
        background = graphics.loadTexture("hallo.jpg");
        boomTexture = graphics.loadTexture("boom.png");
        TURNTexture = graphics.loadTexture("move.png");
        BACKTexture = graphics.loadTexture("back.png");
        exploreTexture =graphics.loadTexture("ex.png");
        SHOOTTexture = graphics.loadTexture("shooting.png");
        UPTexture = graphics.loadTexture("Up.png");
        DOWNTexture = graphics.loadTexture("Down.png");
        skillTexture = graphics.loadTexture("skill.png");
        skill_2Texture = graphics.loadTexture("skill_2.png");
        gShoot = graphics.loadSound("jump.wav");
        gMusic = graphics.loadMusic("gamemusic.mp3");
        gExploision = graphics.loadSound("jump.wav");
        font = graphics.loadFont("Space Nation.ttf", 30);
        deadTexture = graphics.loadTexture("dead.png");
        helpTexture = graphics.loadTexture("help.jpg");
        newGame();
    }


    void PLAYER_ATTACK()
    {
        if(player.health >0 ){
            GameObject *bullet = new GameObject();
            bullets.push_back(bullet);
            bullet->texture = bulletTexture;
            SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

            bullet->initObject(player.x + player.w , player.y + player.h / 2,1,0,SIDE_PLAYER);
            bullet->dx = PLAYER_BULLET_SPEED;
            player.reload = PLAYER_RELOAD;
        }
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

        enemy->reload = (rand() % FRAME_PER_SECOND *4);
    }

    void handleEvents(int keyboard[] , Graphics graphics)
    {
        if(player.health>0){
            bool keyPRESSED = false;
            if (player.health == 0) return;

            player.dx = player.dy = 0;

            if (player.reload > 0) player.reload--;
            if (keyboard[SDL_SCANCODE_W]){
                player.dy = -PLAYER_SPEED;
                player.state = UP_STATE;
                keyPRESSED = true;
            }
            if (keyboard[SDL_SCANCODE_S]){
                player.dy = PLAYER_SPEED;
                player.state = DOWN_STATE;
                keyPRESSED = true;
            }
            if (keyboard[SDL_SCANCODE_A]){
                player.dx = -PLAYER_SPEED;
                BACK.tick();
                player.state = BACK_STATE;
                keyPRESSED = true;
            }
            if (keyboard[SDL_SCANCODE_D]){
                player.dx = PLAYER_SPEED;
                player.state = TURN_STATE;
                TURN.tick();
                keyPRESSED = true;
            }
            if(keyboard[SDL_SCANCODE_SPACE]){
                player.state = SKILL_STATE;
                if(mixer) graphics.play(gShoot);
            }
            if(keyboard[SDL_SCANCODE_DOWN]){
                    player.state = SKILL_2_STATE;
                    if(mixer) graphics.play(gShoot);
            }
            if (keyboard[SDL_SCANCODE_UP] && player.reload == 0){
                if(player.state != BACK_STATE and !keyPRESSED){
                    PLAYER_ATTACK();
                    player.state = ATTACK_STATE;
                    if(mixer) graphics.play(gShoot);
                }
            }
        }
    }

    bool playerCollideObject(GameObject* player , GameObject* object){
        if(player->health >0 and player->checkCollision(object)){
            player->health =0;
            return true;
        }
        return false;
    }

    bool bulletHitFighter(GameObject *b)
    {
        if(player.health > 0){
            for (GameObject* fighter: fighters) {
                if (fighter->side != b->side && b->checkCollision(fighter)) {
                    player.score+=10;
                    fighter->health = 0;
                    return true;
                }
            }
            return false;
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
        if(player.health > 0){
            auto it = fighters.begin();
            it++;

            for(auto it_ = it ; it_ != fighters.end() ;it_++) {
                GameObject* enemy = *it_;

                if(playerCollideObject(&player , enemy)){
                    it_ = fighters.erase(it_);
                }
            }
        }
    }

    void doCollision_Boom(GameObject& Boom){
        if(player.health > 0 and playerCollideObject(&player,&Boom)){
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
            enemy->y = (rand() % 360) + 220;
            enemy->dx = -1;
            enemy->health = 1;
            enemy->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            enemy->side = SIDE_ALIEN;
            enemy->texture = enemyTexture;
            SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);

            enemySpawnTimer = 100    + (rand() % 60);
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

        if(player.health >0 ) player.player_move();
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
        boom.y += BOOM_SPEED;

        if (boom.y >= SCREEN_HEIGHT)
        {
            boom.x = player.x;
            boom.y = 0 + boom.y - SCREEN_HEIGHT;
        }
    }

    void playGame(int keyboard[], Graphics graphics) {
        if(mixer) graphics.play(gMusic);
        upadteBoom();
        if (player.health == 0 && --stageResetTimer <= 0) {
            cerr << player.score << endl;
            newGame();
        }

        handleEvents(keyboard, graphics);
        updateFighters();
        doEnemies();
        doBullets();

        if (player.state == SKILL_STATE && player.health != 0) {
            for (GameObject *enemy : fighters) {
                if (enemy->side == SIDE_ALIEN) {
                    player.score+=10;
                    enemy->health = 0;
                }
            }

            clean(bullets);
        } else {
            doCollision_Boom(boom);
            doCollision_Enemy();
            spawnEnemies();
        }
    }

    void drawBoom(Graphics graphics) {
        if(boom.health!=0)graphics.renderTexture(boomTexture,boom.x,boom.y);
    }

    void drawGame(Graphics& graphics)
    {
        drawBackground(graphics.renderer);
        drawBoom(graphics);

        hp.drawHp(graphics);

		for (GameObject* b: bullets)
            graphics.renderTexture(b->texture, b->x, b->y);

        for (GameObject* b: fighters){
            if (b->health > 0 and b->side == SIDE_ALIEN){
                graphics.renderTexture(b->texture, b->x, b->y);
            }
            if(b->health ==0 and b->side == SIDE_ALIEN){
                static int frameCount = 0;
                const int FRAME_DELAY = 5;

                for (int i = 1; i <= 4; i++) {
                    graphics.render(b->x, b->y, *animations[3]);
                    if (frameCount >= FRAME_DELAY) {
                        exploision.tick();
                        frameCount = 0;
                    }
                    frameCount++;


                }
                if(mixer) graphics.play(gExploision);
            }
        }

        if(player.state == UP_STATE and player.health!=0) graphics.renderTexture(UPTexture , player.x , player.y);
        if(player.state == DOWN_STATE and player.health!=0) graphics.renderTexture(UPTexture , player.x , player.y);
        if(player.state == STAND_STATE and player.health !=0) graphics.renderTexture(player.texture , player.x , player.y);
        if(player.state == BACK_STATE and player.health!=0 ) graphics.render(player.x , player.y ,*animations[1]);
        if(player.state == TURN_STATE and player.health!=0) graphics.render(player.x , player.y ,*animations[0]);
        if (player.state == ATTACK_STATE && player.health != 0) {
            static int frameCount = 0;
            const int FRAME_DELAY = 10;

            for (int i = 1; i <= 5; i++) {
                graphics.render(player.x, player.y, *animations[2]);
                if (frameCount >= FRAME_DELAY) {
                    SHOOTING.tick();
                    frameCount = 0;
                }
                frameCount++;
            }
        }
        if(player.state == SKILL_STATE and player.health !=0){
            static int frameCount = 0;
            const int FRAME_DELAY = 10;
            const int SKILL_DURATION = 30;

            for (int i = 1; i <= 6; i++) {
                graphics.render(player.x, player.y, *animations[4]);
                if (frameCount >= FRAME_DELAY) {
                    Skill.tick();
                    frameCount = 0;
                }
                frameCount++;
            }
            graphics.renderTexture(deadTexture , player.x - 250 , player.y - 180);
            static int waitTime = 0;
            if (waitTime >= SKILL_DURATION) {
                player.state = STAND_STATE;
                waitTime = 0;
            } else {
                waitTime++;
            }
        }
        if(player.state == SKILL_2_STATE and player.health !=0 ){
            static int frameCount = 0;
            const int FRAME_DELAY = 10;
            const int SKILL_DURATION = 30;

            for (int i = 1; i <= 5; i++) {
                graphics.render(player.x, player.y, *animations[5]);
                if (frameCount >= FRAME_DELAY) {
                    Skill_2.tick();
                    frameCount = 0;
                }
                frameCount++;
            }
            for (GameObject* enemy : fighters) {
                if (enemy->side == SIDE_ALIEN && player.checkCollision_SKILL(enemy)) {
                    enemy->health = 0;
                    player.score += 10;
                }
            }
            static int waitTime = 0;
            if (waitTime >= SKILL_DURATION) {
                player.state = STAND_STATE;
                waitTime = 0;
            } else {
                waitTime++;
            }
        }
        string scoreText = "Score: " + to_string(player.score);
        scoreTexture = graphics.renderText(scoreText.c_str(), font, color);
        graphics.renderTexture(scoreTexture, SCREEN_WIDTH - 300 , 20);
        SDL_DestroyTexture(scoreTexture);
    }
};

#endif // _LOGIC__H
