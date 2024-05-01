#ifndef _SKILL__H
#define _SKILL__H

#include <SDL.h>
#include <cmath>

struct skill {
    int skillCooldownTimer;
    int skillCooldownDuration;
    bool used;
    SDL_Color cooldownColor;

    skill() : skillCooldownTimer(0), skillCooldownDuration(0), cooldownColor({255, 0, 0, 255}) , used(false) {}

    void updateSkillCooldown() {
        if (skillCooldownTimer > 0) {
            skillCooldownTimer--;
        }
        else used = false;
    }

    void startSkillCooldown(int cooldownDuration) {
        skillCooldownTimer = cooldownDuration;
        skillCooldownDuration = cooldownDuration;
    }

    void drawSkillCooldown(SDL_Renderer* renderer, int x, int y, int radius) {
        float progress = (float)skillCooldownTimer / skillCooldownDuration;
        int angle = static_cast<int>(360 * progress);

        int centerX = x + radius;
        int centerY = y + radius;
        int endPointX = centerX + static_cast<int>(radius * cos(angle * M_PI / 180));
        int endPointY = centerY + static_cast<int>(radius * sin(angle * M_PI / 180));

        SDL_SetRenderDrawColor(renderer, cooldownColor.r, cooldownColor.g, cooldownColor.b, cooldownColor.a);
        SDL_RenderDrawLine(renderer, centerX, centerY, endPointX, endPointY);
    }
};

#endif // _SKILL__H
