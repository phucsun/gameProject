#ifndef _LOGIC__H
#define _LOGIC__H
#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "GameObject.h"

void initPlayer(Entity& player) {
    player.x = SCREEN_WIDTH/2 - 50;
    player.y = SCREEN_HEIGHT - 130;
    player.health = 100;
    player.side = SIDE_PLAYER;
    player.reload = 0;
}

void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy)
{
	int steps = max(abs(x1 - x2), abs(y1 - y2));

	if (steps == 0)
	{
		*dx = *dy = 0;
		return;
	}

	*dx = (x1 - x2);
	*dx /= steps;

	*dy = (y1 - y2);
	*dy /= steps;
}

struct Game {
    Entity player;
    list<Entity*> bullets;
	list<Entity*> fighters;

	Star stars[MAX_STARS];

    SDL_Texture *bulletTexture, *enemyTexture, *enemyBulletTexture, *background, *rockTexture;
    int enemySpawnTimer;
    int stageResetTimer;

    int backgroundY = 0;

    void empty(list<Entity*>& entities) {
        while (!entities.empty()) {
            Entity* e = entities.front();
            entities.pop_front();
            if (e != &player) delete e;
        }
    }

    void initStarfield(void) {
        for (int i = 0 ; i < MAX_STARS ; i++)	{
            stars[i].x = rand() % SCREEN_WIDTH;
            stars[i].y = rand()%500-500;
            stars[i].speed = rand()%4 +4 ;
            stars[i].health = 1;
            SDL_QueryTexture(*rockTexture, NULL, NULL, stars[i].w, stars[i].h);
        }
    }

    void reset()
    {
        empty(fighters);
        empty(bullets);
        fighters.push_back(&player);
	    initPlayer(player);
	    initStarfield();
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
        background = graphics.loadTexture("space2.png");
        reset();
    }

    void fireBullet()
    {
        Entity *bullet = new Entity();
        bullets.push_back(bullet);

        bullet->x = player.x +40;
        bullet->y = player.y;
        bullet->y -= (player.h / 2) - (bullet->h / 2);
        bullet->dy = -PLAYER_BULLET_SPEED;
        bullet->health = 1;
        bullet->texture = bulletTexture;
        bullet->side = SIDE_PLAYER;
        SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

        player.reload = PLAYER_RELOAD;
    }

    void fireEnemyBullet(Entity* enemy)
    {
        Entity *bullet = new Entity();
        bullets.push_back(bullet);

        bullet->x = enemy->x;
        bullet->y = enemy->y;
        bullet->health = 1;
        bullet->texture = enemyBulletTexture;
        bullet->side = SIDE_ALIEN;
        SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

        bullet->x += (enemy->w / 2) - (bullet->w / 2);
        bullet->y += (enemy->h / 2) - (bullet->h / 2);

        calcSlope(player.x + (player.w / 2), player.y + (player.h / 2) , enemy->x, enemy->y, &bullet->dx, &bullet->dy);
        bullet->dx *= ENEMY_BULLET_SPEED;
        bullet->dy *= ENEMY_BULLET_SPEED;

        enemy->reload = (rand() % FRAME_PER_SECOND * 2);
    }

    void doPlayer(int keyboard[])
    {
        if (player.health == 0) return;

        player.dx = player.dy = 0;

        if (player.reload > 0) player.reload--;
        if (keyboard[SDL_SCANCODE_W]) player.dy = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_S]) player.dy = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_A]) player.dx = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_D]) player.dx = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_UP] && player.reload == 0) fireBullet();
    }

    bool bulletHitFighter(Entity *b)
    {
        for (Entity* fighter: fighters) {
            if (fighter->side != b->side && b->collides(fighter)) {
                fighter->health = 0;
                return true;
            }
        }
        return false;
    }
    bool bulletHitStar(Entity *b)
    {
        for(auto star : stars){
            if(b->collide(&star)){
                star->health=0;
                return true;
            }
        }
        return false;
    }
    void doBullets(void)
    {
        auto it = bullets.begin();
        while (it != bullets.end()) {
            auto temp = it++;
            Entity* b = *temp;
            b->move();
            if (bulletHitFighter(b) || b->offScreen() || bulletHitStar(b)) {
                delete b;
                bullets.erase(temp);
            }
        }
    }

    void doEnemies() {
        for (Entity* e: fighters) {
            if (e != &player && player.health != 0 && --e->reload <= 0)
                fireEnemyBullet(e);
        }
    }

    void spawnEnemies(void) {

        if (--enemySpawnTimer <= 0) {
            Entity *enemy = new Entity();
            fighters.push_back(enemy);
            enemy->x = rand() % SCREEN_WIDTH - 100;
            enemy->y = rand() % SCREEN_HEIGHT - SCREEN_HEIGHT;
            enemy->health = 1;
            enemy->dx=1;
            enemy->dy=1;
            enemy->moveDirection = 1;
            enemy->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            enemy->side = SIDE_ALIEN;
            enemy->texture = enemyTexture;
            SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);

            enemySpawnTimer = 60 + (rand() % 60);
        }
    }

    void doFighters(void)
    {
        auto it = fighters.begin();
        it++;

        while (it != fighters.end()) {
            auto temp = it++;
            Entity* fighter = *temp;

            fighter->move_(bullets);

            if (fighter->x < -fighter->w) fighter->health = 0;

            if (fighter->health == 0) {
                delete fighter;
                fighters.erase(temp);
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

	void doBackground(void) {
        backgroundY += BACKGROUND_SCROLL_SPEED;
        if (backgroundY >= SCREEN_HEIGHT) {
            backgroundY = 0;
        }
    }


    void doStarfield(void) {
        for (int i = 0; i < MAX_STARS; i++) {
            stars[i].y += stars[i].speed;
            if (stars[i].y > SCREEN_HEIGHT) {
                stars[i].x = rand() % SCREEN_WIDTH;
                stars[i].y = 0;
            }
        }
    }

    void doLogic(int keyboard[]) {
        doBackground();
        doStarfield();

        if (player.health == 0 && --stageResetTimer <= 0){
                reset();
        }

        doPlayer(keyboard);
        doFighters();
        doEnemies();
        doBullets();
        spawnEnemies();
    }

    void drawBackground(SDL_Renderer* renderer) {
        SDL_Rect dest;
        dest.x = 0;
        dest.y = backgroundY - SCREEN_HEIGHT;
        dest.w = SCREEN_WIDTH;
        dest.h = SCREEN_HEIGHT;

        SDL_RenderCopy(renderer, background, NULL, &dest);

        dest.y = backgroundY;
        SDL_RenderCopy(renderer, background, NULL, &dest);
    }

    void drawStarfield(Graphics graphics) {
		for (int i = 0 ; i < MAX_STARS ; i++) {
            rockTexture = graphics.loadTexture("Rock4.png");
            graphics.renderTexture(rockTexture , stars[i].x , stars[i].y);
        }
    }

    void draw(Graphics& graphics)
    {
        drawBackground(graphics.renderer);

        drawStarfield(graphics);

		for (Entity* b: bullets)
            graphics.renderTexture(b->texture, b->x, b->y);

        for (Entity* b: fighters)
            if (b->health > 0)
                graphics.renderTexture(b->texture, b->x, b->y);
    }
};

#endif // _LOGIC__H
