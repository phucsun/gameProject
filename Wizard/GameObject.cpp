#include "GameObject.h"
#include "defs.h"
#include "graphics.h"

bool GameObject::checkCollision(GameObject* other){
    return (max(x, other->x) < min(x + w, other->x + other->w)) && (max(y, other->y) < min(y + h, other->y + other->h));
}

bool GameObject::checkCollision_SKILL(GameObject *other){
    return (max(x, other->x) < min(x+2*SKILL_W + w, other->x + other->w)) && (max(y, other->y) < min(y + h, other->y + other->h));
}


bool GameObject::checkCollision_SKILL_BACK(GameObject* other){
    return (max(x - 2*SKILL_W, other->x) < min(x + w, other->x + other->w)) && (max(y, other->y) < min(y + h, other->y + other->h));
}


void GameObject::player_move(){
    if(y<=225) y = 225;
    if(y>=595) y = 595;
    x+=dx;
    y+=dy;
}
void GameObject::move(){
    x += dx;
    y += dy;
    sX-=dx;
    sY-=dy;
}

void GameObject::bullet_move(Sprite& e){
    x += dx;
    y += dy;
    e.tick();

}

void GameObject::move_(){
    x+=3*dx;
    y+=3*dy;
    sX-=dx;
    sY-=dy;
}

void GameObject::AI_move(list<GameObject*>& bullets) {
    for(auto& bullet : bullets) {
        if(bullet->side == SIDE_PLAYER && !bullet->avoided) {
            float distanceX =  - bullet->x + x;
            float distanceY = bullet->y - y;

            if(std::abs(distanceY) <= h && std::abs(distanceX) <= 100) {
                int randNum = rand() % 3;
                if(randNum == 1 && y >= 300) {
                    y -= 80;
                    x -= 30;
                    bullet->avoided = true;
                }
                else if(randNum == 0 && y < 550) {
                    y += 80;
                    x -= 30;
                    bullet->avoided = true;
                }
            }
        }
    }

    x += dx;
    sX -= dx;
}



bool GameObject::offScreen(){
    return x < -w || y < -h || x > SCREEN_WIDTH || y > SCREEN_HEIGHT;
}

void GameObject::initObject(int pos_x , int pos_y , int health_ , int reload_ , int side_){
    x = pos_x;
    y = pos_y;
    health = health_;
    reload = reload_;
    side = side_;
}



