#include "BrokenEgg.h"

using namespace std;

void BrokenEgg::update()
{
    lifeTime -= 100;
    if (lifeTime <= 0) {
        isAlive=false;
    }
}

bool BrokenEgg::getIsAlive()
{
    return isAlive;
}
