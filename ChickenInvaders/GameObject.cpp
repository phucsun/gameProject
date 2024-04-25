#include "GameObject.h"

bool GameObject::checkCollision(GameObject* other){
    return (max(x, other->x) < min(x + w, other->x + other->w)) && (max(y, other->y) < min(y + h, other->y + other->h));
}

void GameObject::player_move(){
    if(y<=225) y = 225;
    if(y>= 672-77) y=672-77;
    x+=dx;
    y+=dy;
}
void GameObject::move(){
//    if(y-w <=  200) x = 200+w;
    x += dx;
    y += dy;
}

void GameObject::AI_move(list<GameObject*>& bullets){
    for(auto bullet : bullets) {
        if(bullet->side == 0){
            float distanceX = bullet->x - x;
            float distanceY = bullet->y - y;
            if(0<= distanceX and distanceX <= w and x-10>0 and x+w+10<SCREEN_WIDTH ){
                    x+= (rand()%3-2)*15;
            }
        }
    }
    x += moveDirection * 2;

    if (x <= 0 || x + w >= SCREEN_WIDTH){
        moveDirection *= -1;
    }

    y += 1;

    if (rand() % 100 < 2) {
        moveDirection *= -1;
    }

    if (y > SCREEN_HEIGHT || y < -h) {
        y = -h;
        x = rand() % (SCREEN_WIDTH - w);
        moveDirection = (rand() % 2 == 0) ? 1 : -1;
    }
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



