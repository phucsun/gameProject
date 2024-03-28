#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H


#include "SDL.h"


class GameManager{
public:
    static GameManager* GetGame(){
        return s_game = (s_game != nullptr) ? s_game : new GameManager();
    }

    void handleEvents();
    bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
    void update();
    void render();
    void cleanup();

    GameManager(){};
    static GameManager* s_game;
};
#endif // _GAMEMANAGER_H
