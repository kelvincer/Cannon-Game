#pragma once

#include "../cannon/Cannon.h"
#include "../bullet/Bullet.h"
#include "../barrier/Barrier.h"
#include <list>

class Game
{
    void initGame();
    void updateGame();
    void drawGame();
    void unloadGame();
    void moveBarrier(Barrier &barrier);
    float shotAngle = INITIAL_FLOAT_VALUE;
    float initialDeltaR = INITIAL_FLOAT_VALUE;
    Cannon cannon;
    Bullet bullet;
    Barrier barrier;
    std::list<Barrier> objectives;
    bool inShot = false;
    Barrier explodedBarrier;

public:
    Game(Cannon cannon, Bullet bullet, Barrier barrier, std::list<Barrier> objectives);
    void startGame();
};