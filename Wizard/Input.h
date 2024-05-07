#ifndef _INPUT__H

#define _INPUT__H
#include <SDL.h>
#include "defs.h"
#include "GameObject.h"

struct Input {
    int keyboard[MAX_KEYBOARD_KEYS] = {0};
    bool mouseButtons[MAX_MOUSE_BUTTONS] = {false};
    int mouseX = 0;
    int mouseY = 0;

    void initKeyBoard() {
        for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
    }

    void initMouseButtons(){
        for(int i = 0 ;i< MAX_MOUSE_BUTTONS ;i++) mouseButtons[i] = false;
    }

    void getInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    if (event.key.repeat == 0 && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 1;
                    }
                    break;

                case SDL_KEYUP:
                    if (event.key.repeat == 0 && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 0;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    SDL_GetMouseState(&mouseX , &mouseY);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button < MAX_MOUSE_BUTTONS) {
                        mouseButtons[event.button.button] = true;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button < MAX_MOUSE_BUTTONS) {
                        mouseButtons[event.button.button] = false;
                    }
                    break;
                default:
                    break;
            }
        }
    }
};

#endif // _INPUT__H
